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
#include <wx/dataview.h>
#include <wx/textctrl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/collpane.h>
#include <wx/stattext.h>
#include <wx/splitter.h>
#include <wx/notebook.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class panel_component_libs_picker_base
///////////////////////////////////////////////////////////////////////////////
class panel_component_libs_picker_base : public wxPanel
{
	private:

	protected:
		wxNotebook* m_browserNoteBook;
		wxPanel* m_panel9;
		wxSplitterWindow* m_splitter2;
		wxPanel* m_panel7;
		wxSearchCtrl* m_libSearch;
		wxComboBox* m_libraryComboList;
		wxSearchCtrl* m_componentSearch;
		wxDataViewListCtrl* m_libraryList;
		wxDataViewColumn* m_componentsListName;
		wxDataViewColumn* m_componentsListValue;
		wxDataViewColumn* m_componentsListFootprintShortname;
		wxTextCtrl* m_description;
		wxButton* m_button1;
		wxButton* m_button2;
		wxPanel* m_panel5;
		wxCollapsiblePane* m_collapsiblePane4;
		wxSearchCtrl* m_parameterSearch;
		wxDataViewListCtrl* m_parametersList;
		wxDataViewColumn* m_dataViewListColumn4;
		wxDataViewColumn* m_dataViewListColumn5;
		wxCollapsiblePane* m_collapsiblePane5;
		wxStaticText* m_staticText1;
		wxCollapsiblePane* m_collapsiblePane1;
		wxStaticText* m_staticText2;
		wxPanel* m_panel10;

		// Virtual event handlers, overide them in your derived class
		virtual void OnSetFocus( wxFocusEvent& event ) { event.Skip(); }
		virtual void OnUpdateUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnNotebookPageChanged( wxNotebookEvent& event ) { event.Skip(); }


	public:

		panel_component_libs_picker_base( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 190,700 ), long style = wxBORDER_NONE|wxNO_FULL_REPAINT_ON_RESIZE, const wxString& name = wxEmptyString );
		~panel_component_libs_picker_base();

		void m_splitter2OnIdle( wxIdleEvent& )
		{
			m_splitter2->SetSashPosition( 350 );
			m_splitter2->Disconnect( wxEVT_IDLE, wxIdleEventHandler( panel_component_libs_picker_base::m_splitter2OnIdle ), NULL, this );
		}

};

