/*
 * panel_herarchy_browser.cpp
 *
 *  Created on: 24 mai 2021
 *      Author: pmx
 */

#include <wx/log.h>
#include <wx/filename.h>
#include <tool/tool_manager.h>
#include <tools/ee_actions.h>
#include <widgets/panel_hierarchy_browser.h>


 // Store an SCH_SHEET_PATH of each sheet in hierarchy.
 
class TreeItemData : public wxTreeItemData
{
public:
    SCH_SHEET_PATH m_SheetPath;

    TreeItemData( SCH_SHEET_PATH& sheet ) : wxTreeItemData()
    {
        m_SheetPath = sheet;
    }
};

panel_hierarchy_browser::panel_hierarchy_browser( SCH_EDIT_FRAME* aParent) :
							panel_hierarchy_browser_base( (wxWindow*)(aParent) )
{
	setPanelFonts();

	m_SchFrameEditor = aParent;
    m_currSheet 	 = m_SchFrameEditor->GetCurrentSheet();
    

//	wxImageList *ilist = new wxImageList( 16, 16 );
//	ilist->Add( wxIcon(wx_small_xpm) );
//	m_hierarchyTree->AssignImageList( ilist );

}

// Essentially based on code in hierarch.cpp
void panel_hierarchy_browser::switch_visible_sheet() {

    m_SchFrameEditor->GetToolManager()->RunAction( ACTIONS::cancelInteractive, true );
    m_SchFrameEditor->GetToolManager()->RunAction( EE_ACTIONS::clearSelection, true );

    // from hierarch.cpp. Doesn't seem necessry anymore - pmx-2021.06.17:
    // Store the current zoom level into the current screen before switching
    m_SchFrameEditor->GetScreen()->m_LastZoomLevel =
                m_SchFrameEditor->GetCanvas()->GetView()->GetScale();

    wxTreeItemId  itemSel = m_hierarchyTree->GetSelection();
    TreeItemData* itemData = static_cast<TreeItemData*>( m_hierarchyTree->GetItemData( itemSel ) );

  
    m_SchFrameEditor->SetCurrentSheet( itemData->m_SheetPath );

    m_SchFrameEditor->DisplayCurrentSheet();        // /!\ void SCH_EDIT_FRAME::DisplayCurrentSheet() is in file: hierarch.cpp

}

void panel_hierarchy_browser::recurseHierarchy(SCH_SHEET_PATH &aList, wxTreeItemId &prev) {

	std::vector<SCH_ITEM*> sheetChildren;
	aList.LastScreen()->GetSheets( &sheetChildren );

	for( SCH_ITEM* aItem : sheetChildren ) {

		SCH_SHEET* sheet = static_cast<SCH_SHEET*>( aItem );
		aList.push_back( sheet );
		wxFileName fn(sheet->GetFileName());

		m_nbsheets++;

		wxTreeItemId next  = m_hierarchyTree->AppendItem(prev, "" );
        m_hierarchyTree->SetItemData( next, new TreeItemData( aList ) );

		if (aList.LastScreen()->IsContentModified()) {
            m_hierarchyTree->SetItemText (next, wxString("*") + fn.GetName());
			m_hierarchyTree->SetItemBold( next, true );
			m_hierarchyTree->SetItemBackgroundColour( next, wxColour(240,255,120) );

            wxLogMessage("%d %s",m_nbsheets, wxString("*") + fn.GetName());

		} else {
            m_hierarchyTree->SetItemText (next, fn.GetName());
        }


		if( aList == m_currSheet ) {
			m_hierarchyTree->EnsureVisible( next );
			m_hierarchyTree->SelectItem( next );
		}

		recurseHierarchy(aList, next);

		aList.pop_back();

		if (m_nbsheets > 200) // Safety ?? Was in the original code, in hierarch.cpp
			return;
	}
}

void panel_hierarchy_browser::updateHierarchy( bool rebuild) {

	// DEBUG : Force rebuild for now, shadowing "rebuild" param  (pmx-2021.05.27)
	rebuild = true;

	m_rootSheet = &m_SchFrameEditor->Schematic().Root();
	m_currSheet =  m_SchFrameEditor->GetCurrentSheet();

	if (rebuild) {
		m_hierarchyTree->DeleteAllItems();
		m_nbsheets = 1;


	    m_list.clear();
	    m_list.push_back( &m_SchFrameEditor->Schematic().Root() );

		wxFileName fn(m_rootSheet->GetFileName());
		wxTreeItemId root =  m_hierarchyTree->AddRoot( "" );
        m_hierarchyTree->SetItemData( root, new TreeItemData( m_list ) );

		m_hierarchyTree->SetItemBold( root, true );

		if (m_list.LastScreen()->IsContentModified()) {
            m_hierarchyTree->SetItemText (root, wxString("*") + fn.GetName());
			m_hierarchyTree->SetItemBold( root, true );
			m_hierarchyTree->SetItemBackgroundColour( root, wxColour(240,255,120) );

//            wxLogMessage("%d %s",m_nbsheets, wxString("*") + fn.GetName());

		} else {
            m_hierarchyTree->SetItemText (root, fn.GetName());
        }

        if( m_currSheet.Last() == &m_SchFrameEditor->Schematic().Root() ) {

			m_hierarchyTree->SelectItem( root );
		}


		recurseHierarchy( m_list, root);


	} else {

// Find, compare, keep expanded/unexpanded status, insert "in place".
// May require more sophisticated control than wxTreeCtrl ?? (pmx-2021.05.27)

	}
	
}

void panel_hierarchy_browser::rebuildHierarchy() {

	updateHierarchy(true);

	m_hierarchyTree->ExpandAll ();


//    wxLogMessage("%s",  "panel_hierarchy_browser::rebuildHierarchy()");

}

// (pmx-2021.05.26) Returns a std::vector<wxWindow *> vector, and the calling function will
// do whaterver is needed on its elements.
// Where can I place this in the class hierarchy (Kicad) to reuse it ???
// cloned in class panel_component_libs_picker and class panel_hierarchy_browser
static void recurseSubWins(std::vector<wxWindow*> & wlist, wxWindowListNode *childNode, unsigned int &count) {
	while (childNode)
	{
		wxWindow *w = childNode->GetData();
		wlist.push_back(w);
		wxWindowList & wl= w->GetChildren();

		if (!wl.empty()) {
			wxWindowListNode *node = wl.GetFirst();
			count++;
			recurseSubWins(wlist, node, count);
		}
	childNode = childNode->GetNext();
	}
}

void panel_hierarchy_browser::getSubChilds(std::vector<wxWindow*> & wlist, unsigned int &count) {

	wxWindowList & firstChild = this->GetChildren();
	wxWindowListNode *childNode = firstChild.GetFirst();

	wlist.clear();
	wlist.push_back(this);

	recurseSubWins(wlist, childNode, count);
}

void panel_hierarchy_browser::setPanelFonts() {

	wxFont wxf = wxFont( 8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
			wxFONTWEIGHT_NORMAL, false, wxEmptyString );

	auto wl = std::vector<wxWindow*>();
	unsigned int count = 0;
	getSubChilds(wl, count);

	for (auto w : wl) {
		w->	SetFont( wxf );
	}
}


void panel_hierarchy_browser::OnUpdateUI( wxUpdateUIEvent& event ) {
	event.Skip();
}

// Double click
void panel_hierarchy_browser::OnTreeItemActivated( wxTreeEvent& event ) {

//    switch_visible_sheet();
    
   	event.Skip();

}

void panel_hierarchy_browser::OnTreeSelChanged( wxTreeEvent& event )  {

    switch_visible_sheet();
    
//   	event.Skip();

}



