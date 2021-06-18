///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "panel_hierarchy_browser_base.h"

///////////////////////////////////////////////////////////////////////////

panel_hierarchy_browser_base::panel_hierarchy_browser_base( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	this->SetFont( wxFont( 9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxVERTICAL );

	m_splitter2 = new wxSplitterWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D|wxSP_LIVE_UPDATE );
	m_splitter2->SetSashGravity( 0 );
	m_splitter2->Connect( wxEVT_IDLE, wxIdleEventHandler( panel_hierarchy_browser_base::m_splitter2OnIdle ), NULL, this );
	m_splitter2->SetMinimumPaneSize( 80 );

	m_splitter2->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	m_panel7 = new wxPanel( m_splitter2, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel7->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxVERTICAL );

	m_browserNoteBook = new wxNotebook( m_panel7, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_browserNoteBook->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	m_panel9 = new wxPanel( m_browserNoteBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel9->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer( wxVERTICAL );


	bSizer23->Add( 0, 4, 0, wxEXPAND|wxSHAPED, 5 );

	m_hierarchyTree = new wxTreeCtrl( m_panel9, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE|wxTR_FULL_ROW_HIGHLIGHT|wxTR_MULTIPLE|wxTR_TWIST_BUTTONS );
	bSizer23->Add( m_hierarchyTree, 1, wxALL|wxEXPAND, 0 );


	m_panel9->SetSizer( bSizer23 );
	m_panel9->Layout();
	bSizer23->Fit( m_panel9 );
	m_browserNoteBook->AddPage( m_panel9, _("Hierarchy"), true );
	m_panel10 = new wxPanel( m_browserNoteBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel10->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxVERTICAL );

	m_filesTree = new wxTreeCtrl( m_panel10, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE|wxTR_MULTIPLE );
	bSizer21->Add( m_filesTree, 1, wxALL|wxEXPAND, 5 );


	m_panel10->SetSizer( bSizer21 );
	m_panel10->Layout();
	bSizer21->Fit( m_panel10 );
	m_browserNoteBook->AddPage( m_panel10, _("Files"), false );

	bSizer16->Add( m_browserNoteBook, 1, wxEXPAND | wxALL, 5 );


	m_panel7->SetSizer( bSizer16 );
	m_panel7->Layout();
	bSizer16->Fit( m_panel7 );
	m_panel8 = new wxPanel( m_splitter2, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel8->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxVERTICAL );


	bSizer17->Add( 0, 4, 0, wxEXPAND, 5 );

	m_treeCtrl1 = new wxTreeCtrl( m_panel8, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE );
	bSizer17->Add( m_treeCtrl1, 1, wxALL|wxEXPAND, 0 );


	m_panel8->SetSizer( bSizer17 );
	m_panel8->Layout();
	bSizer17->Fit( m_panel8 );
	m_splitter2->SplitHorizontally( m_panel7, m_panel8, 500 );
	bSizer13->Add( m_splitter2, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer13 );
	this->Layout();

	// Connect Events
	this->Connect( wxEVT_SET_FOCUS, wxFocusEventHandler( panel_hierarchy_browser_base::OnSetFocus ) );
	m_browserNoteBook->Connect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, wxNotebookEventHandler( panel_hierarchy_browser_base::OnNotebookPageChanged ), NULL, this );
	m_browserNoteBook->Connect( wxEVT_SET_FOCUS, wxFocusEventHandler( panel_hierarchy_browser_base::OnSetFocus ), NULL, this );
	m_hierarchyTree->Connect( wxEVT_COMMAND_TREE_ITEM_ACTIVATED, wxTreeEventHandler( panel_hierarchy_browser_base::OnTreeItemActivated ), NULL, this );
	m_hierarchyTree->Connect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( panel_hierarchy_browser_base::OnTreeSelChanged ), NULL, this );
	m_hierarchyTree->Connect( wxEVT_COMMAND_TREE_SEL_CHANGING, wxTreeEventHandler( panel_hierarchy_browser_base::OnTreeSelChanging ), NULL, this );
	m_hierarchyTree->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( panel_hierarchy_browser_base::OnUpdateUI ), NULL, this );
	m_filesTree->Connect( wxEVT_CHAR, wxKeyEventHandler( panel_hierarchy_browser_base::OnChar ), NULL, this );
	m_filesTree->Connect( wxEVT_SET_FOCUS, wxFocusEventHandler( panel_hierarchy_browser_base::OnSetFocus ), NULL, this );
	m_filesTree->Connect( wxEVT_COMMAND_TREE_ITEM_ACTIVATED, wxTreeEventHandler( panel_hierarchy_browser_base::OnTreeItemActivated ), NULL, this );
	m_filesTree->Connect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( panel_hierarchy_browser_base::OnTreeSelChanged ), NULL, this );
}

panel_hierarchy_browser_base::~panel_hierarchy_browser_base()
{
	// Disconnect Events
	this->Disconnect( wxEVT_SET_FOCUS, wxFocusEventHandler( panel_hierarchy_browser_base::OnSetFocus ) );
	m_browserNoteBook->Disconnect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, wxNotebookEventHandler( panel_hierarchy_browser_base::OnNotebookPageChanged ), NULL, this );
	m_browserNoteBook->Disconnect( wxEVT_SET_FOCUS, wxFocusEventHandler( panel_hierarchy_browser_base::OnSetFocus ), NULL, this );
	m_hierarchyTree->Disconnect( wxEVT_COMMAND_TREE_ITEM_ACTIVATED, wxTreeEventHandler( panel_hierarchy_browser_base::OnTreeItemActivated ), NULL, this );
	m_hierarchyTree->Disconnect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( panel_hierarchy_browser_base::OnTreeSelChanged ), NULL, this );
	m_hierarchyTree->Disconnect( wxEVT_COMMAND_TREE_SEL_CHANGING, wxTreeEventHandler( panel_hierarchy_browser_base::OnTreeSelChanging ), NULL, this );
	m_hierarchyTree->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( panel_hierarchy_browser_base::OnUpdateUI ), NULL, this );
	m_filesTree->Disconnect( wxEVT_CHAR, wxKeyEventHandler( panel_hierarchy_browser_base::OnChar ), NULL, this );
	m_filesTree->Disconnect( wxEVT_SET_FOCUS, wxFocusEventHandler( panel_hierarchy_browser_base::OnSetFocus ), NULL, this );
	m_filesTree->Disconnect( wxEVT_COMMAND_TREE_ITEM_ACTIVATED, wxTreeEventHandler( panel_hierarchy_browser_base::OnTreeItemActivated ), NULL, this );
	m_filesTree->Disconnect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( panel_hierarchy_browser_base::OnTreeSelChanged ), NULL, this );

}
