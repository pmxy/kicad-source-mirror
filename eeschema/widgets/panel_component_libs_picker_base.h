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
#include <wx/string.h>
#include <wx/srchctrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/combobox.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/treectrl.h>
#include <wx/textctrl.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/notebook.h>
#include <wx/grid.h>
#include <wx/button.h>
#include <wx/splitter.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class panel_component_libs_picker_base
///////////////////////////////////////////////////////////////////////////////
class panel_component_libs_picker_base : public wxPanel
{
	private:

	protected:
		wxSplitterWindow* m_splitter2;
		wxPanel* m_panel7;
		wxNotebook* m_browserNoteBook;
		wxPanel* m_panel9;
		wxSearchCtrl* m_libSearch;
		wxComboBox* m_librarySearch;
		wxSearchCtrl* m_componentSearch;
		wxTreeCtrl* m_hierarchyTree;
		wxTextCtrl* m_textCtrl2;
		wxPanel* m_panel10;
		wxTreeCtrl* m_detailsTree;
		wxPanel* m_panel8;
		wxSearchCtrl* m_parameterSearch;
		wxGrid* m_parameterValue;
		wxButton* m_button1;
		wxButton* m_button2;

		// Virtual event handlers, overide them in your derived class
		virtual void OnSetFocus( wxFocusEvent& event ) { event.Skip(); }
		virtual void OnNotebookPageChanged( wxNotebookEvent& event ) { event.Skip(); }
		virtual void OnTreeSelChanged( wxTreeEvent& event ) { event.Skip(); }


	public:

		panel_component_libs_picker_base( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 164,593 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );
		~panel_component_libs_picker_base();

		void m_splitter2OnIdle( wxIdleEvent& )
		{
			m_splitter2->SetSashPosition( 350 );
			m_splitter2->Disconnect( wxEVT_IDLE, wxIdleEventHandler( panel_component_libs_picker_base::m_splitter2OnIdle ), NULL, this );
		}

};

