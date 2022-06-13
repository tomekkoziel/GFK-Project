#ifndef __GUIOtherSettings__
#define __GUIOtherSettings__

#include "GUI.h"
#include "GUIMyFrame.h"

class GUIMyFrame;

/**
 * @brief class resposible for the display of wxDialog with various options
 *
 * @param Parent variable resposible for changes made on higher instance window
 */
class GUIOtherSettings : public OtherSettings
{
protected:
	/**
	 * @brief based on "Show animation background" check mark, sets @ShowBg variable value
	 *
	 * @param event Settings -> Other settings -> "Show animation background" check mark ticked
	 */
	void IfCheck_ShowAnimationBackground(wxCommandEvent &event);

	/**
	 * @brief opens dialog box and lets user choose an image for animation background
	 *
	 * @param event Settings -> Other settings -> "Choose Animation Background" button click
	 */
	void OnButton_ChoseAnimationBackground(wxCommandEvent &event);

	/**
	 * @brief set the @FileNumeration value to true
	 *
	 * @param event Settings -> Other settings -> "0001" button click
	 */
	void setSavedFileNumeration0001(wxCommandEvent &event);

	/**
	 * @brief set the @FileNumeration value to false
	 *
	 * @param event Settings -> Other settings -> "1" button click
	 */
	void setSavedFileNumeration1(wxCommandEvent &event);

	/**
	 * @brief sets the name of saved files
	 *
	 * @param event Settings -> Other settings -> "Name of saved files" text field filled
	 */
	void ChangeSavedFileName(wxCommandEvent &event);

public:
	GUIOtherSettings(wxWindow *parent, GUIMyFrame *parentWindow);
	GUIMyFrame *Parent;
};

#endif // __GUIOtherSettings__
