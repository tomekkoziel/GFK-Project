#include "GUIMyFrame.h"

GUIMyFrame::GUIMyFrame( wxWindow* parent )
:
	MyFrame(parent), Panel{ (HWND)AnimationPanel->GetHandle() }, ReadingOption{ false }, AnimationState{ States::NoInBuffer },
	ShowBg{ false }, FileNumeration{ false }, FileName{ "output" }
{
}

void GUIMyFrame::ChangeSizeOfAnimation( wxMoveEvent& event )
{
// TODO: Implement ChangeSizeOfAnimation
}

void GUIMyFrame::Repaint_AnimationPanel( wxUpdateUIEvent& event )
{
// TODO: Implement Repaint_AnimationPanel
}

void GUIMyFrame::OnSlide_AnimationSpeed( wxScrollEvent& event )
{
// TODO: Implement OnSlide_AnimationSpeed
}

void GUIMyFrame::OnClick_RewindAnimation( wxCommandEvent& event )
{
// TODO: Implement OnClick_RewindAnimation
}

void GUIMyFrame::OnClick_PlayStopAnimation( wxCommandEvent& event )
{
// TODO: Implement OnClick_PlayStopAnimation
}

void GUIMyFrame::OnClick_GoForwardAnimation( wxCommandEvent& event )
{
// TODO: Implement OnClick_GoForwardAnimation
}

void GUIMyFrame::OnClick_RestartAnimation( wxCommandEvent& event )
{
// TODO: Implement OnClick_RestartAnimation
}

void GUIMyFrame::OnClick_OpenFileOnMenuSelection(wxCommandEvent& event)
{
	// TODO: Implement OnClick_OpenFileOnMenuSelection
	if (ReadingFileOption->FindItemByPosition(1)->IsChecked())
	{
		wxFileDialog OpenFileDialog(this, wxT("Choose a files"), wxT(""), wxT(""), wxT(""), wxFD_MULTIPLE | wxFD_FILE_MUST_EXIST);


		if (OpenFileDialog.ShowModal() == wxID_OK)
		{
			Animation.clear();
			AnimationState = States::LoadingToBuffer;
			setButtonsActive();
			wxArrayString Images;
			OpenFileDialog.GetPaths(Images);
			Images.Sort();
			if (ReadImagesToVector(Images)) AnimationState = States::ReadyToDisplay;
		}
	}
	else
	{
		wxFileDialog OpenFileDialog(this, wxT("Choose a file"), wxT(""), wxT(""), wxT("Text file (*.txt)|*.txt"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);

		if (OpenFileDialog.ShowModal() == wxID_OK)
		{
			Animation.clear();
			AnimationState = States::LoadingToBuffer;
			setButtonsActive();
			if (ReadingFileOption->FindItemByPosition(0)->IsChecked())
			{
				if (ReadDataToVector(OpenFileDialog.GetPath())) AnimationState = States::ReadyToDisplay;
			}
			else
			{
				if (Read3DToVector(OpenFileDialog.GetPath())) AnimationState = States::ReadyToDisplay;
			}
		}
	}
	setButtonsActive();
}

void GUIMyFrame::OnClick_SaveAnimationToFile( wxCommandEvent& event )
{
// TODO: Implement OnClick_SaveAnimationToFile
	wxDirDialog OpenDirDialog(this, _("Choose a directory"), "", wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);
	if (OpenDirDialog.ShowModal() == wxID_OK)
		SaveAnimationToDir(OpenDirDialog.GetPath());
}

void GUIMyFrame::OnClick_SetBacgroundColor(wxCommandEvent& event)
{
	// TODO: Implement OnClick_SetBacgroundColor
	wxColourDialog ChooseColor(this);
	if (ChooseColor.ShowModal() == wxID_OK)
		this->SetBackgroundColour(ChooseColor.GetColourData().GetColour());
	Refresh();
}

void GUIMyFrame::OnClick_ShowSavingOptions(wxCommandEvent& event)
{
	// TODO: Implement OnClick_ShowSavingOptions
	GUIOtherSettings dialog(this, this);
	dialog.ShowModal();
}