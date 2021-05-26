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
	this->SetFont( wxFont( 9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	this->SetMinSize( wxSize( 50,100 ) );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxVERTICAL );

	m_browserNoteBook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_browserNoteBook->SetFont( wxFont( 9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	m_browserNoteBook->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	m_panel9 = new wxPanel( m_browserNoteBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE );
	m_panel9->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	m_panel9->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer( wxVERTICAL );


	bSizer23->Add( 0, 4, 0, wxEXPAND|wxSHAPED, 5 );

	m_splitter2 = new wxSplitterWindow( m_panel9, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D|wxSP_LIVE_UPDATE );
	m_splitter2->SetSashGravity( 0 );
	m_splitter2->Connect( wxEVT_IDLE, wxIdleEventHandler( panel_component_libs_picker_base::m_splitter2OnIdle ), NULL, this );
	m_splitter2->SetMinimumPaneSize( 150 );

	m_splitter2->SetFont( wxFont( 9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	m_splitter2->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	m_panel7 = new wxPanel( m_splitter2, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel7->SetFont( wxFont( 9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	m_panel7->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( m_panel7, wxID_ANY, _("Library") ), wxVERTICAL );

	m_libSearch = new wxSearchCtrl( sbSizer1->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_LEFT|wxTE_PROCESS_ENTER|wxTE_PROCESS_TAB|wxBORDER_DEFAULT );
	#ifndef __WXMAC__
	m_libSearch->ShowSearchButton( true );
	#endif
	m_libSearch->ShowCancelButton( true );
	m_libSearch->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	sbSizer1->Add( m_libSearch, 0, wxALL|wxEXPAND, 5 );

	m_libraryComboList = new wxComboBox( sbSizer1->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_READONLY|wxCB_SIMPLE|wxCB_SORT|wxTE_PROCESS_ENTER|wxBORDER_DEFAULT );
	m_libraryComboList->Append( _("SMD Resistor Lib") );
	m_libraryComboList->Append( _("SMD Capacitor Lib") );
	m_libraryComboList->Append( _("SMD Transistor Lib") );
	m_libraryComboList->SetSelection( 1 );
	m_libraryComboList->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	sbSizer1->Add( m_libraryComboList, 0, wxALL|wxEXPAND, 5 );


	bSizer16->Add( sbSizer1, 0, wxEXPAND, 5 );


	bSizer16->Add( 0, 0, 0, wxALL|wxSHAPED, 4 );

	wxStaticBoxSizer* sbSizer5;
	sbSizer5 = new wxStaticBoxSizer( new wxStaticBox( m_panel7, wxID_ANY, _("Components") ), wxVERTICAL );

	m_componentSearch = new wxSearchCtrl( sbSizer5->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_LEFT|wxBORDER_DEFAULT );
	#ifndef __WXMAC__
	m_componentSearch->ShowSearchButton( true );
	#endif
	m_componentSearch->ShowCancelButton( true );
	m_componentSearch->SetFont( wxFont( 9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	sbSizer5->Add( m_componentSearch, 0, wxALL|wxEXPAND, 5 );

	m_libraryList = new wxDataViewListCtrl( sbSizer5->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxDV_HORIZ_RULES|wxDV_VERT_RULES|wxBORDER_DEFAULT );
	m_libraryList->SetFont( wxFont( 9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	m_libraryList->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	m_libraryList->SetMinSize( wxSize( -1,100 ) );

	m_componentsListName = m_libraryList->AppendTextColumn( _("Name"), wxDATAVIEW_CELL_INERT, -1, static_cast<wxAlignment>(wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALIGN_RIGHT), wxDATAVIEW_COL_REORDERABLE|wxDATAVIEW_COL_RESIZABLE|wxDATAVIEW_COL_SORTABLE );
	m_componentsListName->GetRenderer()->EnableEllipsize( wxELLIPSIZE_END );
	m_componentsListValue = m_libraryList->AppendTextColumn( _("Value"), wxDATAVIEW_CELL_INERT, -1, static_cast<wxAlignment>(wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALIGN_RIGHT), wxDATAVIEW_COL_REORDERABLE|wxDATAVIEW_COL_RESIZABLE|wxDATAVIEW_COL_SORTABLE );
	m_componentsListValue->GetRenderer()->EnableEllipsize( wxELLIPSIZE_END );
	m_componentsListFootprintShortname = m_libraryList->AppendIconTextColumn( _("Footprint"), wxDATAVIEW_CELL_INERT, -1, static_cast<wxAlignment>(wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALIGN_RIGHT), wxDATAVIEW_COL_REORDERABLE|wxDATAVIEW_COL_RESIZABLE|wxDATAVIEW_COL_SORTABLE );
	m_componentsListFootprintShortname->GetRenderer()->EnableEllipsize( wxELLIPSIZE_END );
	sbSizer5->Add( m_libraryList, 1, wxALL|wxEXPAND, 5 );

	m_description = new wxTextCtrl( sbSizer5->GetStaticBox(), wxID_ANY, _("Resistance 0603\n(Description...)"), wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxTE_MULTILINE|wxTE_READONLY|wxTE_WORDWRAP|wxBORDER_DEFAULT );
	m_description->SetFont( wxFont( 9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	sbSizer5->Add( m_description, 0, wxALL|wxEXPAND, 5 );


	bSizer16->Add( sbSizer5, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );

	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_button1 = new wxButton( m_panel7, wxID_ANY, _("Edit"), wxDefaultPosition, wxSize( 45,-1 ), 0 );
	fgSizer1->Add( m_button1, 1, wxALIGN_CENTER_VERTICAL|wxALL|wxSHAPED, 5 );

	m_button2 = new wxButton( m_panel7, wxID_ANY, _("Place"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	m_button2->SetMinSize( wxSize( 50,-1 ) );

	fgSizer1->Add( m_button2, 1, wxALIGN_CENTER_VERTICAL|wxALL|wxSHAPED, 5 );


	fgSizer1->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer10->Add( fgSizer1, 1, wxEXPAND, 5 );


	bSizer16->Add( bSizer10, 0, wxEXPAND, 5 );


	m_panel7->SetSizer( bSizer16 );
	m_panel7->Layout();
	bSizer16->Fit( m_panel7 );
	m_panel5 = new wxPanel( m_splitter2, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel5->SetFont( wxFont( 9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	m_panel5->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );

	m_collapsiblePane4 = new wxCollapsiblePane( m_panel5, wxID_ANY, _("Component Parameters"), wxDefaultPosition, wxDefaultSize, wxCP_DEFAULT_STYLE|wxBORDER_DEFAULT );
	m_collapsiblePane4->Collapse( true );

	m_collapsiblePane4->SetFont( wxFont( 9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	m_collapsiblePane4->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	m_parameterSearch = new wxSearchCtrl( m_collapsiblePane4->GetPane(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0|wxBORDER_DEFAULT );
	#ifndef __WXMAC__
	m_parameterSearch->ShowSearchButton( true );
	#endif
	m_parameterSearch->ShowCancelButton( true );
	bSizer6->Add( m_parameterSearch, 0, wxALL|wxEXPAND, 5 );

	m_parametersList = new wxDataViewListCtrl( m_collapsiblePane4->GetPane(), wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxDV_HORIZ_RULES|wxDV_VERT_RULES|wxBORDER_DEFAULT );
	m_parametersList->SetFont( wxFont( 9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	m_parametersList->SetMinSize( wxSize( -1,100 ) );

	m_dataViewListColumn4 = m_parametersList->AppendTextColumn( _("Parameter"), wxDATAVIEW_CELL_INERT, -1, static_cast<wxAlignment>(wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALIGN_RIGHT), wxDATAVIEW_COL_REORDERABLE|wxDATAVIEW_COL_RESIZABLE|wxDATAVIEW_COL_SORTABLE );
	m_dataViewListColumn4->GetRenderer()->EnableEllipsize( wxELLIPSIZE_END );
	m_dataViewListColumn5 = m_parametersList->AppendTextColumn( _("Value"), wxDATAVIEW_CELL_INERT, -1, static_cast<wxAlignment>(wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALIGN_RIGHT), wxDATAVIEW_COL_REORDERABLE|wxDATAVIEW_COL_RESIZABLE|wxDATAVIEW_COL_SORTABLE );
	m_dataViewListColumn5->GetRenderer()->EnableEllipsize( wxELLIPSIZE_END );
	bSizer6->Add( m_parametersList, 1, wxALL|wxEXPAND, 5 );


	m_collapsiblePane4->GetPane()->SetSizer( bSizer6 );
	m_collapsiblePane4->GetPane()->Layout();
	bSizer6->Fit( m_collapsiblePane4->GetPane() );
	bSizer8->Add( m_collapsiblePane4, 0, wxALL|wxEXPAND, 5 );

	m_collapsiblePane5 = new wxCollapsiblePane( m_panel5, wxID_ANY, _("Box 1"), wxDefaultPosition, wxDefaultSize, wxCP_DEFAULT_STYLE|wxBORDER_DEFAULT );
	m_collapsiblePane5->Collapse( true );

	m_collapsiblePane5->SetFont( wxFont( 9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	m_collapsiblePane5->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	wxBoxSizer* bSizer101;
	bSizer101 = new wxBoxSizer( wxVERTICAL );

	m_staticText1 = new wxStaticText( m_collapsiblePane5->GetPane(), wxID_ANY, _("Text"), wxDefaultPosition, wxDefaultSize, 0|wxBORDER_DEFAULT );
	m_staticText1->Wrap( -1 );
	m_staticText1->SetFont( wxFont( 9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer101->Add( m_staticText1, 1, wxALL|wxEXPAND, 5 );


	m_collapsiblePane5->GetPane()->SetSizer( bSizer101 );
	m_collapsiblePane5->GetPane()->Layout();
	bSizer101->Fit( m_collapsiblePane5->GetPane() );
	bSizer8->Add( m_collapsiblePane5, 0, wxALL|wxEXPAND, 5 );

	m_collapsiblePane1 = new wxCollapsiblePane( m_panel5, wxID_ANY, _("Box 2"), wxDefaultPosition, wxDefaultSize, wxCP_DEFAULT_STYLE|wxBORDER_DEFAULT );
	m_collapsiblePane1->Collapse( true );

	m_collapsiblePane1->SetFont( wxFont( 9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	m_collapsiblePane1->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );

	m_staticText2 = new wxStaticText( m_collapsiblePane1->GetPane(), wxID_ANY, _("Text"), wxDefaultPosition, wxDefaultSize, 0|wxBORDER_DEFAULT );
	m_staticText2->Wrap( -1 );
	m_staticText2->SetFont( wxFont( 9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer11->Add( m_staticText2, 1, wxALL|wxEXPAND, 5 );


	m_collapsiblePane1->GetPane()->SetSizer( bSizer11 );
	m_collapsiblePane1->GetPane()->Layout();
	bSizer11->Fit( m_collapsiblePane1->GetPane() );
	bSizer8->Add( m_collapsiblePane1, 0, wxALL|wxEXPAND, 5 );


	bSizer8->Add( 0, 0, 1, wxEXPAND, 5 );


	m_panel5->SetSizer( bSizer8 );
	m_panel5->Layout();
	bSizer8->Fit( m_panel5 );
	m_splitter2->SplitHorizontally( m_panel7, m_panel5, 350 );
	bSizer23->Add( m_splitter2, 1, wxEXPAND, 5 );


	m_panel9->SetSizer( bSizer23 );
	m_panel9->Layout();
	bSizer23->Fit( m_panel9 );
	m_browserNoteBook->AddPage( m_panel9, _("Select"), true );
	m_panel10 = new wxPanel( m_browserNoteBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel10->SetFont( wxFont( 9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	m_panel10->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxVERTICAL );


	m_panel10->SetSizer( bSizer21 );
	m_panel10->Layout();
	bSizer21->Fit( m_panel10 );
	m_browserNoteBook->AddPage( m_panel10, _("Details"), false );

	bSizer13->Add( m_browserNoteBook, 1, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer13 );
	this->Layout();

	// Connect Events
	this->Connect( wxEVT_SET_FOCUS, wxFocusEventHandler( panel_component_libs_picker_base::OnSetFocus ) );
	m_browserNoteBook->Connect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, wxNotebookEventHandler( panel_component_libs_picker_base::OnNotebookPageChanged ), NULL, this );
	m_browserNoteBook->Connect( wxEVT_SET_FOCUS, wxFocusEventHandler( panel_component_libs_picker_base::OnSetFocus ), NULL, this );
}

panel_component_libs_picker_base::~panel_component_libs_picker_base()
{
	// Disconnect Events
	this->Disconnect( wxEVT_SET_FOCUS, wxFocusEventHandler( panel_component_libs_picker_base::OnSetFocus ) );
	m_browserNoteBook->Disconnect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, wxNotebookEventHandler( panel_component_libs_picker_base::OnNotebookPageChanged ), NULL, this );
	m_browserNoteBook->Disconnect( wxEVT_SET_FOCUS, wxFocusEventHandler( panel_component_libs_picker_base::OnSetFocus ), NULL, this );

}
