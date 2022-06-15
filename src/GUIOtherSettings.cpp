#include "GUIOtherSettings.h"

GUIOtherSettings::GUIOtherSettings( wxWindow* parent, GUIMyFrame *parentWindow)
:
	OtherSettings(parent), Parent{ parentWindow }
{
	EnableAnimationBackground->SetValue(Parent->ShowBg);
	
	if (Parent->FileNumeration) FileNum0001->Enable(false);
	else FileNum1->Enable(false);

	NameOfSavedFiles->SetValue(Parent->FileName);
}

void GUIOtherSettings::IfCheck_ShowAnimationBackground( wxCommandEvent& event )
{
// TODO: Implement IfCheck_ShowAnimationBackground
	if(EnableAnimationBackground->IsChecked()) Parent->ShowBg = true;
	else Parent->ShowBg = false;
}

void GUIOtherSettings::OnButton_ChoseAnimationBackground( wxCommandEvent& event )
{
// TODO: Implement OnButton_ChoseAnimationBackground
	wxFileDialog OpenFileDialog(this, wxT("Choose a file"), wxT(""), wxT(""), wxT("Chose image (*.png, *jpg)|*jpg"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);

	if (OpenFileDialog.ShowModal() == wxID_OK) Parent->Background.loadFromFile(OpenFileDialog.GetPath().ToStdString());
}

void GUIOtherSettings::setSavedFileNumeration0001( wxCommandEvent& event )
{
// TODO: Implement setSavedFileNumeration0001
	Parent->FileNumeration = true;
	FileNum0001->Enable(false);
	FileNum1->Enable(true);
}

void GUIOtherSettings::setSavedFileNumeration1( wxCommandEvent& event )
{
// TODO: Implement setSavedFileNumeration1
	Parent->FileNumeration = false;
	FileNum0001->Enable(true);
	FileNum1->Enable(false);
}

void GUIOtherSettings::ChangeSavedFileName( wxCommandEvent& event )
{
// TODO: Implement ChangeSavedFileName
	Parent->FileName = NameOfSavedFiles->GetValue();
}
