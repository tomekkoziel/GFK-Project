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

/**
 * @brief creates the main interface of the application
 */
class MyFrame : public wxFrame
{
private:
protected:
	/**
	 * @brief holds wxPanel on which the animation is displayed
	 *
	 */
	wxPanel *AnimationPanel;

	/**
	 * @brief shows current saving/reading progress (basically the progress bar)
	 *
	 */
	wxGauge *LoadingProgress;

	/**
	 * @brief allows user to choose the speed at which the animation should be displayed
	 *
	 */
	wxSlider *ChoiceSpeed;

	/**
	 * @brief allows user to skip a few frames backwards
	 *
	 */
	wxButton *AnimationGoBack;

	/**
	 * @brief allows user to start/pause the animation
	 *
	 */
	wxButton *PlayAndStop;

	/**
	 * @brief allows user to skip a few frames forwards
	 *
	 */
	wxButton *AnimationGoForward;

	/**
	 * @brief allows user to replay the animation
	 *
	 */
	wxButton *AnimationReplay;

	/**
	 * @brief menu bar
	 *
	 */
	wxMenuBar *MenuBar;

	/**
	 * @brief "File" drop down menu
	 *
	 */
	wxMenu *FileBar;

	/**
	 * @brief "Settings" drop down menu
	 *
	 */
	wxMenu *SettingsBar;

	/**
	 * @brief allows the user to choose the preferred file read option
	 *
	 */
	wxMenu *ReadingFileOption;

	// // methods descriptions in GUIMyFrame.h
	virtual void ChangeSizeOfAnimation(wxMoveEvent &event) { event.Skip(); }
	virtual void Repaint_AnimationPanel(wxUpdateUIEvent &event) { event.Skip(); }
	virtual void OnSlide_AnimationSpeed(wxScrollEvent &event) { event.Skip(); }
	virtual void OnClick_RewindAnimation(wxCommandEvent &event) { event.Skip(); }
	virtual void OnClick_PlayStopAnimation(wxCommandEvent &event) { event.Skip(); }
	virtual void OnClick_GoForwardAnimation(wxCommandEvent &event) { event.Skip(); }
	virtual void OnClick_RestartAnimation(wxCommandEvent &event) { event.Skip(); }
	virtual void OnClick_OpenFileOnMenuSelection(wxCommandEvent &event) { event.Skip(); }
	virtual void OnClick_SaveAnimationToFile(wxCommandEvent &event) { event.Skip(); }
	virtual void OnClick_SetBacgroundColor(wxCommandEvent &event) { event.Skip(); }
	virtual void OnClick_ShowSavingOptions(wxCommandEvent &event) { event.Skip(); }

public:
	MyFrame(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString &title = wxT("GFK Project - Animations"), const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxSize(-1, -1), long style = wxCAPTION | wxCLOSE_BOX | wxMINIMIZE_BOX | wxSYSTEM_MENU | wxTAB_TRAVERSAL);

	~MyFrame();
};

///////////////////////////////////////////////////////////////////////////////
/// Class OtherSettings
///////////////////////////////////////////////////////////////////////////////

/**
 * @brief creates the main interface of the "Other settings" dialog box
 */
class OtherSettings : public wxDialog
{
private:
protected:
	/**
	 * @brief allows the user to set if the background should be shown
	 *
	 */
	wxCheckBox *EnableAnimationBackground;

	/**
	 * @brief allows the user to choose a background which should be displayed
	 *
	 */
	wxButton *AnimationBackground;

	/**
	 * @brief constant text variable
	 *
	 */
	wxStaticText *m_staticText2;

	/**
	 * @brief allows the user to set the numeration to "0001" style
	 *
	 */
	wxButton *FileNum0001;

	/**
	 * @brief allows the user to set the numeration to "1" style
	 *
	 */
	wxButton *FileNum1;

	/**
	 * @brief constant text variable
	 *
	 */
	wxStaticText *m_staticText1;

	/**
	 * @brief allows the user to set the name of saved files
	 *
	 */
	wxTextCtrl *NameOfSavedFiles;

	// methods descriptions in GUIOtherSettings.h
	virtual void IfCheck_ShowAnimationBackground(wxCommandEvent &event) { event.Skip(); }
	virtual void OnButton_ChoseAnimationBackground(wxCommandEvent &event) { event.Skip(); }
	virtual void setSavedFileNumeration0001(wxCommandEvent &event) { event.Skip(); }
	virtual void setSavedFileNumeration1(wxCommandEvent &event) { event.Skip(); }
	virtual void ChangeSavedFileName(wxCommandEvent &event) { event.Skip(); }

public:
	OtherSettings(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString &title = wxT("Other Settings"), const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxSize(500, 320), long style = wxDEFAULT_DIALOG_STYLE);

	~OtherSettings();
};
