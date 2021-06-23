/*
 * panel_herarchy_browser.cpp
 *
 *  Created on: 24 mai 2021
 *      Author: pmx
 */

#include <vector>
#include <widgets/panel_component_libs_picker.h>


panel_component_libs_picker::panel_component_libs_picker( wxWindow* aParent ) : panel_component_libs_picker_base( aParent ) {

	wxFont wxf = wxFont( 8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
			wxFONTWEIGHT_NORMAL, false, wxEmptyString );

	auto wl = std::vector<wxWindow*>();
	unsigned int count = 0;
	getSubChilds(wl, count);

	for (auto w : wl) {
		w->	SetFont( wxf );
	}

	
    m_componentSearch->SetHint(_("Component Name"));
    m_libSearch      ->SetHint(_("Library Name"));
    //m_parametersSearch->SetHint(_("Parameter Name"));


}

// (pmx-20210526) Returns a std::vector<wxWindow *> vector, and the calling function will
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

void panel_component_libs_picker::getSubChilds(std::vector<wxWindow*> & wlist, unsigned int &count) {

	wxWindowList & firstChild = this->GetChildren();
	wxWindowListNode *childNode = firstChild.GetFirst();

	wlist.clear();
	wlist.push_back(this);

	recurseSubWins(wlist, childNode, count);
}

// void panel_component_libs_picker::OnUpdateUI( wxUpdateUIEvent& event ) {
// 	event.Skip();

// }


void panel_component_libs_picker::OnNotebookPageChanged( wxNotebookEvent& event ) {
	event.Skip();
}

//void panel_hierarchy_browser::OnNotebookPageChanged( wxNotebookEvent& event ) {
//	panel_hierarchy_browser_base::OnNotebookPageChanged( event )
//}
//
//void panel_hierarchy_browser::OnSetFocus( wxFocusEvent& aEvent ) {
//
//}

//void panel_hierarchy_browser::OnSize( wxSizeEvent& aEvent ) {
//
//	Refresh();
//	Update();
//
//	panel_hierarchy_browser_base::OnSize( aEvent );
//
//}
