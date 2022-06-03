///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/gauge.h>
#include <wx/slider.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/frame.h>
#include <wx/checkbox.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame
///////////////////////////////////////////////////////////////////////////////
class MyFrame : public wxFrame
{
	private:

	protected:
		wxPanel* AnimationPanel;
		wxPanel* ProgressSlider;
		wxGauge* LoadingProgress;
		wxSlider* ChoiceSpeed;
		wxButton* AnimationGoBack;
		wxButton* PlayAndStop;
		wxButton* AnimationGoForward;
		wxButton* AnimationReplay;
		wxMenuBar* MenuBar;
		wxMenu* FileBar;
		wxMenu* SettingsBar;
		wxMenu* ReadingFileOption;

		// Virtual event handlers, override them in your derived class
		virtual void ChangeSizeOfAnimation( wxMoveEvent& event ) { event.Skip(); }
		virtual void Repaint_AnimationPanel( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void ChangeSizeOfProgressSlider( wxMoveEvent& event ) { event.Skip(); }
		virtual void Repaint_ProgressSlider( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnSlide_AnimationSpeed( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnClick_RewindAnimation( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClick_PlayStopAnimation( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClick_GoForwardAnimation( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClick_RestartAnimation( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClick_OpenFileOnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClick_SaveAnimationToFile( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClick_SetBacgroundColor( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClick_ShowSavingOptions( wxCommandEvent& event ) { event.Skip(); }


	public:

		MyFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("GFK Project - Animations"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxCAPTION|wxCLOSE_BOX|wxMINIMIZE_BOX|wxSYSTEM_MENU|wxTAB_TRAVERSAL );

		~MyFrame();

};

///////////////////////////////////////////////////////////////////////////////
/// Class OtherSettings
///////////////////////////////////////////////////////////////////////////////
class OtherSettings : public wxDialog
{
	private:

	protected:
		wxCheckBox* EnableAnimationBackground;
		wxButton* AnimationBackground;
		wxStaticText* m_staticText2;
		wxButton* FileNum0001;
		wxButton* FileNum1;
		wxStaticText* m_staticText1;
		wxTextCtrl* NameOfSavedFiles;

		// Virtual event handlers, override them in your derived class
		virtual void IfCheck_ShowAnimationBackground( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButton_ChoseAnimationBackground( wxCommandEvent& event ) { event.Skip(); }
		virtual void setSavedFileNumeration0001( wxCommandEvent& event ) { event.Skip(); }
		virtual void setSavedFileNumeration1( wxCommandEvent& event ) { event.Skip(); }
		virtual void ChangeSavedFileName( wxCommandEvent& event ) { event.Skip(); }


	public:

		OtherSettings( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,320 ), long style = wxDEFAULT_DIALOG_STYLE );

		~OtherSettings();

};

