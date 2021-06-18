///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/treectrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/notebook.h>
#include <wx/splitter.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class panel_hierarchy_browser_base
///////////////////////////////////////////////////////////////////////////////
class panel_hierarchy_browser_base : public wxPanel
{
	private:

	protected:
		wxSplitterWindow* m_splitter2;
		wxPanel* m_panel7;
		wxNotebook* m_browserNoteBook;
		wxPanel* m_panel9;
		wxTreeCtrl* m_hierarchyTree;
		wxPanel* m_panel10;
		wxTreeCtrl* m_filesTree;
		wxPanel* m_panel8;
		wxTreeCtrl* m_treeCtrl1;

		// Virtual event handlers, overide them in your derived class
		virtual void OnSetFocus( wxFocusEvent& event ) { event.Skip(); }
		virtual void OnNotebookPageChanged( wxNotebookEvent& event ) { event.Skip(); }
		virtual void OnTreeItemActivated( wxTreeEvent& event ) { event.Skip(); }
		virtual void OnTreeSelChanged( wxTreeEvent& event ) { event.Skip(); }
		virtual void OnTreeSelChanging( wxTreeEvent& event ) { event.Skip(); }
		virtual void OnUpdateUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnChar( wxKeyEvent& event ) { event.Skip(); }


	public:

		panel_hierarchy_browser_base( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 150,700 ), long style = 0, const wxString& name = wxEmptyString );
		~panel_hierarchy_browser_base();

		void m_splitter2OnIdle( wxIdleEvent& )
		{
			m_splitter2->SetSashPosition( 500 );
			m_splitter2->Disconnect( wxEVT_IDLE, wxIdleEventHandler( panel_hierarchy_browser_base::m_splitter2OnIdle ), NULL, this );
		}

};

