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
#include <wx/slider.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/frame.h>

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
		wxSlider* ChoiceSpeed;
		wxButton* AnimationGoBack;
		wxButton* PlayAndStop;
		wxButton* AnimationGoForward;
		wxButton* AnimationReplay;
		wxMenuBar* MenuBar;
		wxMenu* FileBar;

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


	public:

		MyFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MyFrame();

};

