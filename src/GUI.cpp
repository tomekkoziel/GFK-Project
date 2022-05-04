///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MyFrame::MyFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	AnimationPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	AnimationPanel->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	bSizer5->Add( AnimationPanel, 1, wxALL|wxEXPAND, 5 );


	bSizer2->Add( bSizer5, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	ProgressSlider = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( -1,40 ), wxTAB_TRAVERSAL );
	ProgressSlider->SetBackgroundColour( wxColour( 255, 255, 255 ) );
	ProgressSlider->Hide();

	bSizer6->Add( ProgressSlider, 1, wxEXPAND | wxALL, 5 );


	bSizer2->Add( bSizer6, 0, wxEXPAND, 5 );


	bSizer1->Add( bSizer2, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );

	ChoiceSpeed = new wxSlider( this, wxID_ANY, 1, 0, 5, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	ChoiceSpeed->Enable( false );

	bSizer10->Add( ChoiceSpeed, 0, wxALL, 5 );


	bSizer3->Add( bSizer10, 2, wxEXPAND, 5 );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	AnimationGoBack = new wxButton( this, wxID_ANY, wxT("<<"), wxDefaultPosition, wxDefaultSize, 0 );
	AnimationGoBack->Enable( false );

	bSizer4->Add( AnimationGoBack, 0, wxALIGN_RIGHT|wxALL, 5 );


	bSizer3->Add( bSizer4, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );

	PlayAndStop = new wxButton( this, wxID_ANY, wxT("play"), wxDefaultPosition, wxDefaultSize, 0 );
	PlayAndStop->Enable( false );

	bSizer7->Add( PlayAndStop, 0, wxALL, 5 );


	bSizer3->Add( bSizer7, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );

	AnimationGoForward = new wxButton( this, wxID_ANY, wxT(">>"), wxDefaultPosition, wxDefaultSize, 0 );
	AnimationGoForward->Enable( false );

	bSizer8->Add( AnimationGoForward, 0, wxALL, 5 );


	bSizer3->Add( bSizer8, 3, wxEXPAND, 5 );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );

	AnimationReplay = new wxButton( this, wxID_ANY, wxT("replay"), wxDefaultPosition, wxDefaultSize, 0 );
	AnimationReplay->Enable( false );

	bSizer9->Add( AnimationReplay, 0, wxALL, 5 );


	bSizer3->Add( bSizer9, 0, wxEXPAND, 5 );


	bSizer1->Add( bSizer3, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
	MenuBar = new wxMenuBar( 0 );
	FileBar = new wxMenu();
	wxMenuItem* OpenFile;
	OpenFile = new wxMenuItem( FileBar, wxID_ANY, wxString( wxT("Open") ) , wxEmptyString, wxITEM_NORMAL );
	FileBar->Append( OpenFile );

	wxMenuItem* SaveFile;
	SaveFile = new wxMenuItem( FileBar, wxID_ANY, wxString( wxT("Save") ) , wxEmptyString, wxITEM_NORMAL );
	FileBar->Append( SaveFile );

	MenuBar->Append( FileBar, wxT("File") );

	this->SetMenuBar( MenuBar );


	this->Centre( wxBOTH );
}

MyFrame::~MyFrame()
{
}
