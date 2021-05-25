///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "panel_component_libs_picker_base.h"

///////////////////////////////////////////////////////////////////////////

panel_component_libs_picker_base::panel_component_libs_picker_base( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	this->SetExtraStyle( wxWS_EX_PROCESS_UI_UPDATES );
	this->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxVERTICAL );

	m_splitter2 = new wxSplitterWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D|wxSP_LIVE_UPDATE );
	m_splitter2->SetSashGravity( 0.5 );
	m_splitter2->Connect( wxEVT_IDLE, wxIdleEventHandler( panel_component_libs_picker_base::m_splitter2OnIdle ), NULL, this );
	m_splitter2->SetMinimumPaneSize( 50 );

	m_splitter2->SetFont( wxFont( 9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	m_panel7 = new wxPanel( m_splitter2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxVERTICAL );

	m_browserNoteBook = new wxNotebook( m_panel7, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel9 = new wxPanel( m_browserNoteBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( m_panel9, wxID_ANY, _("Library") ), wxVERTICAL );

	m_libSearch = new wxSearchCtrl( sbSizer1->GetStaticBox(), wxID_ANY, _("Resistor"), wxDefaultPosition, wxDefaultSize, wxTE_LEFT|wxTE_PROCESS_ENTER|wxTE_PROCESS_TAB );
	#ifndef __WXMAC__
	m_libSearch->ShowSearchButton( true );
	#endif
	m_libSearch->ShowCancelButton( true );
	m_libSearch->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	sbSizer1->Add( m_libSearch, 0, wxALL|wxEXPAND, 5 );

	m_librarySearch = new wxComboBox( sbSizer1->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_READONLY|wxCB_SIMPLE|wxCB_SORT|wxTE_PROCESS_ENTER );
	m_librarySearch->Append( _("SMD Resistor") );
	m_librarySearch->Append( _("SMD Capacitor") );
	m_librarySearch->Append( _("SMD Transistor") );
	m_librarySearch->SetSelection( 1 );
	m_librarySearch->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	sbSizer1->Add( m_librarySearch, 0, wxALL, 5 );


	bSizer23->Add( sbSizer1, 0, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer5;
	sbSizer5 = new wxStaticBoxSizer( new wxStaticBox( m_panel9, wxID_ANY, _("Component") ), wxVERTICAL );

	m_componentSearch = new wxSearchCtrl( sbSizer5->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_LEFT );
	#ifndef __WXMAC__
	m_componentSearch->ShowSearchButton( true );
	#endif
	m_componentSearch->ShowCancelButton( true );
	sbSizer5->Add( m_componentSearch, 0, wxALL|wxEXPAND, 5 );

	m_hierarchyTree = new wxTreeCtrl( sbSizer5->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE|wxTR_FULL_ROW_HIGHLIGHT|wxTR_MULTIPLE|wxTR_TWIST_BUTTONS|wxBORDER_SIMPLE );
	sbSizer5->Add( m_hierarchyTree, 1, wxALL|wxEXPAND, 5 );

	m_textCtrl2 = new wxTextCtrl( sbSizer5->GetStaticBox(), wxID_ANY, _("res_0603"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	sbSizer5->Add( m_textCtrl2, 0, wxALL|wxEXPAND, 5 );


	bSizer23->Add( sbSizer5, 1, wxEXPAND, 5 );


	m_panel9->SetSizer( bSizer23 );
	m_panel9->Layout();
	bSizer23->Fit( m_panel9 );
	m_browserNoteBook->AddPage( m_panel9, _("Select"), true );
	m_panel10 = new wxPanel( m_browserNoteBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxVERTICAL );

	m_detailsTree = new wxTreeCtrl( m_panel10, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE|wxTR_FULL_ROW_HIGHLIGHT|wxTR_MULTIPLE|wxTR_TWIST_BUTTONS|wxBORDER_SIMPLE );
	bSizer21->Add( m_detailsTree, 1, wxALL|wxEXPAND, 5 );


	m_panel10->SetSizer( bSizer21 );
	m_panel10->Layout();
	bSizer21->Fit( m_panel10 );
	m_browserNoteBook->AddPage( m_panel10, _("Details"), false );

	bSizer16->Add( m_browserNoteBook, 1, wxEXPAND | wxALL, 5 );


	m_panel7->SetSizer( bSizer16 );
	m_panel7->Layout();
	bSizer16->Fit( m_panel7 );
	m_panel8 = new wxPanel( m_splitter2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer11;
	sbSizer11 = new wxStaticBoxSizer( new wxStaticBox( m_panel8, wxID_ANY, _("Parameters") ), wxVERTICAL );

	m_parameterSearch = new wxSearchCtrl( sbSizer11->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_LEFT );
	#ifndef __WXMAC__
	m_parameterSearch->ShowSearchButton( true );
	#endif
	m_parameterSearch->ShowCancelButton( true );
	sbSizer11->Add( m_parameterSearch, 0, wxALL|wxEXPAND, 5 );

	m_parameterValue = new wxGrid( sbSizer11->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE );

	// Grid
	m_parameterValue->CreateGrid( 5, 2 );
	m_parameterValue->EnableEditing( false );
	m_parameterValue->EnableGridLines( true );
	m_parameterValue->EnableDragGridSize( true );
	m_parameterValue->SetMargins( 5, 1 );

	// Columns
	m_parameterValue->SetColSize( 0, 82 );
	m_parameterValue->SetColSize( 1, 68 );
	m_parameterValue->AutoSizeColumns();
	m_parameterValue->EnableDragColMove( true );
	m_parameterValue->EnableDragColSize( true );
	m_parameterValue->SetColLabelSize( 50 );
	m_parameterValue->SetColLabelValue( 0, _("Parameter") );
	m_parameterValue->SetColLabelValue( 1, _("Value") );
	m_parameterValue->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_parameterValue->EnableDragRowSize( false );
	m_parameterValue->SetRowLabelSize( 0 );
	m_parameterValue->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance
	m_parameterValue->SetLabelFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	// Cell Defaults
	m_parameterValue->SetDefaultCellFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	m_parameterValue->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_CENTER );
	m_parameterValue->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	sbSizer11->Add( m_parameterValue, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );

	m_button1 = new wxButton( sbSizer11->GetStaticBox(), wxID_ANY, _("Edit"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button1->SetMinSize( wxSize( 45,-1 ) );

	bSizer10->Add( m_button1, 1, wxALL, 5 );

	m_button2 = new wxButton( sbSizer11->GetStaticBox(), wxID_ANY, _("Place"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button2->SetMinSize( wxSize( 45,-1 ) );

	bSizer10->Add( m_button2, 1, wxALL, 5 );


	bSizer10->Add( 0, 0, 1, wxEXPAND, 5 );


	sbSizer11->Add( bSizer10, 0, wxEXPAND, 5 );


	m_panel8->SetSizer( sbSizer11 );
	m_panel8->Layout();
	sbSizer11->Fit( m_panel8 );
	m_splitter2->SplitHorizontally( m_panel7, m_panel8, 350 );
	bSizer13->Add( m_splitter2, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer13 );
	this->Layout();

	// Connect Events
	this->Connect( wxEVT_SET_FOCUS, wxFocusEventHandler( panel_component_libs_picker_base::OnSetFocus ) );
	m_browserNoteBook->Connect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, wxNotebookEventHandler( panel_component_libs_picker_base::OnNotebookPageChanged ), NULL, this );
	m_browserNoteBook->Connect( wxEVT_SET_FOCUS, wxFocusEventHandler( panel_component_libs_picker_base::OnSetFocus ), NULL, this );
	m_hierarchyTree->Connect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( panel_component_libs_picker_base::OnTreeSelChanged ), NULL, this );
	m_detailsTree->Connect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( panel_component_libs_picker_base::OnTreeSelChanged ), NULL, this );
}

panel_component_libs_picker_base::~panel_component_libs_picker_base()
{
	// Disconnect Events
	this->Disconnect( wxEVT_SET_FOCUS, wxFocusEventHandler( panel_component_libs_picker_base::OnSetFocus ) );
	m_browserNoteBook->Disconnect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, wxNotebookEventHandler( panel_component_libs_picker_base::OnNotebookPageChanged ), NULL, this );
	m_browserNoteBook->Disconnect( wxEVT_SET_FOCUS, wxFocusEventHandler( panel_component_libs_picker_base::OnSetFocus ), NULL, this );
	m_hierarchyTree->Disconnect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( panel_component_libs_picker_base::OnTreeSelChanged ), NULL, this );
	m_detailsTree->Disconnect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( panel_component_libs_picker_base::OnTreeSelChanged ), NULL, this );

}
