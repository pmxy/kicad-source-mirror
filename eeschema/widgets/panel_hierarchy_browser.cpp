/*
 * panel_herarchy_browser.cpp
 *
 *  Created on: 24 mai 2021
 *      Author: pmx
 */

#include <wx/log.h>
#include <wx/filename.h>

#include <widgets/panel_hierarchy_browser.h>


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

void panel_hierarchy_browser::recurseHierarchy(SCH_SHEET_PATH &aList, wxTreeItemId &prev) {

	std::vector<SCH_ITEM*> sheetChildren;
	aList.LastScreen()->GetSheets( &sheetChildren );

	for( SCH_ITEM* aItem : sheetChildren ) {

		SCH_SHEET* sheet = static_cast<SCH_SHEET*>( aItem );
		aList.push_back( sheet );
		wxFileName fn(sheet->GetFileName());

		wxTreeItemId next  = m_hierarchyTree->AppendItem(prev, fn.GetName() );
		if (aList.LastScreen()->IsModified()) {
			m_hierarchyTree->SetItemBold( next, true );
			m_hierarchyTree->SetItemBackgroundColour( next, wxColour(240,255,120) );
		}
		m_nbsheets++;

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
		wxTreeItemId root =  m_hierarchyTree->AddRoot( fn.GetName() );

		m_hierarchyTree->SetItemBold( root, true );

		if (m_list.LastScreen()->IsModified()) {
			m_hierarchyTree->SetItemBold( root, true );
			m_hierarchyTree->SetItemBackgroundColour( root, wxColour(240,255,120) );
		} else if( m_currSheet.Last() == &m_SchFrameEditor->Schematic().Root() ) {
			m_hierarchyTree->SelectItem( root );
		}


		recurseHierarchy( m_list, root);

		m_hierarchyTree->ExpandAll ();

	} else {

// Find, compare, keep expanded/unexpanded status, insert "in place".
// May require more sophisticated control than wxTreeCtrl ?? (pmx-2021.05.27)

	}

}

void panel_hierarchy_browser::rebuildHierarchy() {

	updateHierarchy(true);

	m_hierarchyTree->ExpandAll ();

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
