
#!/usr/bin/env pythoni3
#
# Lists best candidates for adding to pre-compiled headers from an
# output list showing all the includes during a build.
# 
# By Noel Llopis - April 2005
# http://www.gamesfromwithin.com

# Modified fir Kicad e-Cad software and porte to python3
# by Pierre Demouveaux. 29 06 2021.
# Modified to generate a list of "#iclude" "/absolute/path/filename{.h,.hpp,.hxx}"
# ready for generation of the précompikled header.

import sys
import os
import string
import os.path
import re

HELP_USAGE = "Usage: list_precomp.py include_trace_file [ignore_path]\n"


class IncludeInfo:
    def __init__(self, name):
        self.name = name
    
    name = ""
    ocurrences = 1    
    ocurrences_directly = 0
    indent = 100
    includes = 0
    
  
def cleanup_path(path):
    path = path.replace("\\", "/")
    path = path.strip()
    return path
    

def read_file (filename):
    if not os.path.exists(filename):
        print ("File " + filename + " doesn't exist.")
        return ()
        
    f = open(filename, "r")
    lines = f.readlines()
    f.close()
    return lines
    
    
def ignore_file(inc, ignore_path):
    if ignore_path != "" and inc.find(ignore_path) != -1:
        return 1
        
    # Hack for gcc because it doesn't print full paths by default. 
    # Ignore anything without a / or starting with a . (relative path)
#    if string.find(inc, "/") == -1 or inc[0] == ".":
    if inc.find("/") == -1 or inc[0] == ".":
        return 1
        
    return 0
    
    
def parse_include (indent, inc, ignore_path, current_info, include_map):
    
    # Update the number of includes caused by the current include (only the first time we encounter that include though).
    direct_include = (indent <= current_info.indent)
    
    if (not direct_include):
        if (current_info.ocurrences_directly == 1):
            current_info.includes += 1
                    
    if ignore_file(inc, ignore_path):
        #print "Skip", indent, inc
        current_info = IncludeInfo("")
        return current_info
        
    if inc in include_map:
        info = include_map[inc]
        info.ocurrences += 1
        if direct_include:
            info.ocurrences_directly += 1
        # print "Add", indent, inc
    else:
        info = IncludeInfo(inc)
        info.indent = indent
        if direct_include:
            info.ocurrences_directly += 1        
        include_map[inc]=info      
        #print "New", indent, direct_include, inc
        rp ="#include \"" + inc + "\""
        if  (rp.find("/opencascade/") == -1) and (rp.find("/wx/") == -1) :
            print (rp)
        
        
    if direct_include:
        current_info = info            
#        print "OK", indent, os.path.realpath(inc)
        
    return current_info

    
def parse_includes(lines, ignore_path):
    
    include_map = {}
    
    include_regexp_vc  = re.compile('^Note\: including file\:(\s+)(.*)')
#    include_regexp_gcc = re.compile('^(\.+) (.*)')
#    include_regexp_gcc = re.compile('^(\.+) (.*)')

## Only first level includes (i.e. : the filenames actually in the source code),
##  but not the chained includes  reported by gcc -H.
## pmx-2021.06.30
    include_regexp_gcc = re.compile('^(\.) (.*)')


    current_info = IncludeInfo("")
    
    for line in lines:
        m = include_regexp_vc.search(line)
        if not m:
            m = include_regexp_gcc.search(line)
#        m = include_regexp_gcc.search(line)
             
        if m:
            indent = len(m.group(1))-1
            inc =  cleanup_path(m.group(2))
            if not os.path.isabs(inc) :
                inc =  os.path.realpath(inc)
            current_info = parse_include(indent, inc, ignore_path, current_info, include_map)
            
    return include_map

    
def count_cpp_files(lines):

    cpp_count = 0
    cpp_regexp = re.compile('\w+\.(cpp|c)\s*')
    
    for line in lines:
        m = cpp_regexp.search(line)
        if m:
            cpp_count += 1

    return cpp_count  

    
def print_top_includes( include_map, cpp_file_count, top_file_count ):
    
    print ("Cpp files: ", cpp_file_count)
    print ("(Header file, score, times included, includes caused by the header)")               
    
    result = []
    for key in include_map.keys():
        if include_map[key].ocurrences_directly > 0:
            score = include_map[key].ocurrences * (include_map[key].includes+1)
            result.append( (key, score, include_map[key].ocurrences, include_map[key].includes) )
       
    result.sort( lambda a,b: cmp(a[2], b[2]) )
    result.reverse()
    for i in xrange(min(top_file_count,len(result))):
        print (result[i])


def main(argv):
    num_args = len(sys.argv)-1
    if num_args < 1 or num_args > 2:
        print (HELP_USAGE)
        return
        
    filename = sys.argv[1]
    if num_args > 1:
        ignore_path = os.path.realpath(sys.argv[2])
#        print ("Path of files to exclude : ",ignore_path)
    else:
        ignore_path = ""

#    print "Counting includes in " + filename
    text = read_file(filename)
    if len(text) == 0:
        return
        
    include_map = parse_includes(text, ignore_path)
    cpp_file_count = count_cpp_files(text)
 #   print_top_includes( include_map, cpp_file_count, 1500 )
                        

if __name__ == "__main__":
    main( sys.argv )


