/*
 * panel_hierarchy_browser.h
 *
 *  Created on: 24 mai 2021
 *      Author: pmx
 */



#ifndef EESCHEMA_WIDGETS_PANEL_HIERARCHY_BROWSER_H_
#define EESCHEMA_WIDGETS_PANEL_HIERARCHY_BROWSER_H_

#include <sch_sheet.h>
#include <schematic.h>
#include <sch_sheet_path.h>
#include <sch_edit_frame.h>

#include <widgets/panel_hierarchy_browser_base.h>


class panel_hierarchy_browser : public panel_hierarchy_browser_base
{
public :
	panel_hierarchy_browser( SCH_EDIT_FRAME* aParent );
//	~panel_hierarchy_browser();

	void rebuildHierarchy();
	void updateHierarchy(bool rebuild = false);

protected:

	virtual void OnUpdateUI( wxUpdateUIEvent& event ) override;

//    void OnNotebookPageChanged( wxNotebookEvent& event ) override;
//
//    void OnSetFocus( wxFocusEvent& aEvent ) override;

//    void OnSize( wxSizeEvent& aEvent ) override;

private :

	void setFontSubChilds(wxWindowListNode* childNode, wxFont &wxf);

	void getSubChilds(std::vector<wxWindow*> & wlist, unsigned int &count);

	void setPanelFonts();

// Use same names than HIERARCHY_NAVIG_DLG in hierarch.cpp

    SCH_SHEET_PATH  	m_currSheet;
    SCH_SHEET_PATH  	m_list;
    SCH_EDIT_FRAME* 	m_SchFrameEditor;
    int             	m_nbsheets;

    SCH_SHEET*   		m_rootSheet;
};

#endif /* EESCHEMA_WIDGETS_PANEL_HIERARCHY_BROWSER_H_ */

