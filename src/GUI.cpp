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
	this->SetSizeHints( wxSize( 500,-1 ), wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	AnimationPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( 800,600 ), wxTAB_TRAVERSAL );
	AnimationPanel->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	bSizer5->Add( AnimationPanel, 1, wxALIGN_CENTER|wxBOTTOM|wxFIXED_MINSIZE|wxLEFT|wxRIGHT|wxTOP, 5 );


	bSizer2->Add( bSizer5, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	LoadingProgress = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxSize( 600,-1 ), wxGA_HORIZONTAL );
	LoadingProgress->SetValue( 0 );
	LoadingProgress->Hide();

	bSizer6->Add( LoadingProgress, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer2->Add( bSizer6, 0, wxEXPAND, 5 );


	bSizer1->Add( bSizer2, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );

	ChoiceSpeed = new wxSlider( this, wxID_ANY, 4, 0, 7, wxDefaultPosition, wxSize( 230,-1 ), wxSL_HORIZONTAL );
	bSizer10->Add( ChoiceSpeed, 0, wxALL, 5 );


	bSizer3->Add( bSizer10, 0, wxEXPAND, 5 );


	bSizer3->Add( 0, 0, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	AnimationGoBack = new wxButton( this, wxID_ANY, wxT("<<"), wxDefaultPosition, wxDefaultSize, 0 );
	AnimationGoBack->Enable( false );

	bSizer4->Add( AnimationGoBack, 0, wxALIGN_RIGHT|wxALL, 5 );


	bSizer3->Add( bSizer4, 0, wxEXPAND, 5 );

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


	bSizer3->Add( bSizer8, 0, wxEXPAND, 5 );


	bSizer3->Add( 0, 0, 3, wxEXPAND, 5 );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );

	AnimationReplay = new wxButton( this, wxID_ANY, wxT("replay"), wxDefaultPosition, wxDefaultSize, 0 );
	AnimationReplay->Enable( false );

	bSizer9->Add( AnimationReplay, 0, wxALL, 5 );


	bSizer3->Add( bSizer9, 0, wxEXPAND, 5 );


	bSizer1->Add( bSizer3, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	MenuBar = new wxMenuBar( 0 );
	FileBar = new wxMenu();
	wxMenuItem* OpenFile;
	OpenFile = new wxMenuItem( FileBar, wxID_ANY, wxString( wxT("Open") ) + wxT('\t') + wxT("Ctrl+O"), wxEmptyString, wxITEM_NORMAL );
	FileBar->Append( OpenFile );

	wxMenuItem* SaveFile;
	SaveFile = new wxMenuItem( FileBar, wxID_ANY, wxString( wxT("Save") ) + wxT('\t') + wxT("Ctrl+S"), wxEmptyString, wxITEM_NORMAL );
	FileBar->Append( SaveFile );

	MenuBar->Append( FileBar, wxT("File") );

	SettingsBar = new wxMenu();
	wxMenuItem* BgColor;
	BgColor = new wxMenuItem( SettingsBar, wxID_ANY, wxString( wxT("Background color") ) , wxEmptyString, wxITEM_NORMAL );
	SettingsBar->Append( BgColor );

	ReadingFileOption = new wxMenu();
	wxMenuItem* ReadingFileOptionItem = new wxMenuItem( SettingsBar, wxID_ANY, wxT("Read animation from.."), wxEmptyString, wxITEM_NORMAL, ReadingFileOption );
	wxMenuItem* ReadTXT;
	ReadTXT = new wxMenuItem( ReadingFileOption, wxID_ANY, wxString( wxT("Command file") ) , wxEmptyString, wxITEM_RADIO );
	ReadingFileOption->Append( ReadTXT );

	wxMenuItem* ReadImages;
	ReadImages = new wxMenuItem( ReadingFileOption, wxID_ANY, wxString( wxT("Images") ) , wxEmptyString, wxITEM_RADIO );
	ReadingFileOption->Append( ReadImages );

	wxMenuItem* Read3D;
	Read3D = new wxMenuItem( ReadingFileOption, wxID_ANY, wxString( wxT("3D Animation") ) , wxEmptyString, wxITEM_RADIO );
	ReadingFileOption->Append( Read3D );

	SettingsBar->Append( ReadingFileOptionItem );

	wxMenuItem* OtherOptions;
	OtherOptions = new wxMenuItem( SettingsBar, wxID_ANY, wxString( wxT("Other options") ) , wxEmptyString, wxITEM_NORMAL );
	SettingsBar->Append( OtherOptions );

	MenuBar->Append( SettingsBar, wxT("Settings") );

	this->SetMenuBar( MenuBar );


	this->Centre( wxBOTH );

	// Connect Events
	AnimationPanel->Connect( wxEVT_MOVE, wxMoveEventHandler( MyFrame::ChangeSizeOfAnimation ), NULL, this );
	AnimationPanel->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame::Repaint_AnimationPanel ), NULL, this );
	ChoiceSpeed->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame::OnSlide_AnimationSpeed ), NULL, this );
	ChoiceSpeed->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame::OnSlide_AnimationSpeed ), NULL, this );
	ChoiceSpeed->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame::OnSlide_AnimationSpeed ), NULL, this );
	ChoiceSpeed->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame::OnSlide_AnimationSpeed ), NULL, this );
	ChoiceSpeed->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame::OnSlide_AnimationSpeed ), NULL, this );
	ChoiceSpeed->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame::OnSlide_AnimationSpeed ), NULL, this );
	ChoiceSpeed->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame::OnSlide_AnimationSpeed ), NULL, this );
	ChoiceSpeed->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame::OnSlide_AnimationSpeed ), NULL, this );
	ChoiceSpeed->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame::OnSlide_AnimationSpeed ), NULL, this );
	AnimationGoBack->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::OnClick_RewindAnimation ), NULL, this );
	PlayAndStop->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::OnClick_PlayStopAnimation ), NULL, this );
	AnimationGoForward->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::OnClick_GoForwardAnimation ), NULL, this );
	AnimationReplay->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::OnClick_RestartAnimation ), NULL, this );
	FileBar->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame::OnClick_OpenFileOnMenuSelection ), this, OpenFile->GetId());
	FileBar->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame::OnClick_SaveAnimationToFile ), this, SaveFile->GetId());
	SettingsBar->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame::OnClick_SetBacgroundColor ), this, BgColor->GetId());
	SettingsBar->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame::OnClick_ShowSavingOptions ), this, OtherOptions->GetId());
}

MyFrame::~MyFrame()
{
	// Disconnect Events
	AnimationPanel->Disconnect( wxEVT_MOVE, wxMoveEventHandler( MyFrame::ChangeSizeOfAnimation ), NULL, this );
	AnimationPanel->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame::Repaint_AnimationPanel ), NULL, this );
	ChoiceSpeed->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame::OnSlide_AnimationSpeed ), NULL, this );
	ChoiceSpeed->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame::OnSlide_AnimationSpeed ), NULL, this );
	ChoiceSpeed->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame::OnSlide_AnimationSpeed ), NULL, this );
	ChoiceSpeed->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame::OnSlide_AnimationSpeed ), NULL, this );
	ChoiceSpeed->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame::OnSlide_AnimationSpeed ), NULL, this );
	ChoiceSpeed->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame::OnSlide_AnimationSpeed ), NULL, this );
	ChoiceSpeed->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame::OnSlide_AnimationSpeed ), NULL, this );
	ChoiceSpeed->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame::OnSlide_AnimationSpeed ), NULL, this );
	ChoiceSpeed->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame::OnSlide_AnimationSpeed ), NULL, this );
	AnimationGoBack->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::OnClick_RewindAnimation ), NULL, this );
	PlayAndStop->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::OnClick_PlayStopAnimation ), NULL, this );
	AnimationGoForward->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::OnClick_GoForwardAnimation ), NULL, this );
	AnimationReplay->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::OnClick_RestartAnimation ), NULL, this );

}

OtherSettings::OtherSettings( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );


	bSizer11->Add( 0, 0, 1, wxEXPAND, 5 );

	EnableAnimationBackground = new wxCheckBox( this, wxID_ANY, wxT("Show animation backgroud"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( EnableAnimationBackground, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	AnimationBackground = new wxButton( this, wxID_ANY, wxT("Chose Animation\nBackground"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( AnimationBackground, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer11->Add( 0, 0, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxHORIZONTAL );


	bSizer16->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Chose numeration of saved files"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer16->Add( m_staticText2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	FileNum0001 = new wxButton( this, wxID_ANY, wxT("0001"), wxDefaultPosition, wxSize( 60,25 ), 0 );
	bSizer16->Add( FileNum0001, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	FileNum1 = new wxButton( this, wxID_ANY, wxT("1"), wxDefaultPosition, wxSize( 60,25 ), 0 );
	bSizer16->Add( FileNum1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer16->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer11->Add( bSizer16, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );


	bSizer15->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Name of saved files"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer15->Add( m_staticText1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	NameOfSavedFiles = new wxTextCtrl( this, wxID_ANY, wxT("output"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( NameOfSavedFiles, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer15->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer11->Add( bSizer15, 1, wxEXPAND, 5 );


	bSizer11->Add( 0, 0, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer11 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	EnableAnimationBackground->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( OtherSettings::IfCheck_ShowAnimationBackground ), NULL, this );
	AnimationBackground->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( OtherSettings::OnButton_ChoseAnimationBackground ), NULL, this );
	FileNum0001->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( OtherSettings::setSavedFileNumeration0001 ), NULL, this );
	FileNum1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( OtherSettings::setSavedFileNumeration1 ), NULL, this );
	NameOfSavedFiles->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( OtherSettings::ChangeSavedFileName ), NULL, this );
}

OtherSettings::~OtherSettings()
{
	// Disconnect Events
	EnableAnimationBackground->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( OtherSettings::IfCheck_ShowAnimationBackground ), NULL, this );
	AnimationBackground->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( OtherSettings::OnButton_ChoseAnimationBackground ), NULL, this );
	FileNum0001->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( OtherSettings::setSavedFileNumeration0001 ), NULL, this );
	FileNum1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( OtherSettings::setSavedFileNumeration1 ), NULL, this );
	NameOfSavedFiles->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( OtherSettings::ChangeSavedFileName ), NULL, this );

}
