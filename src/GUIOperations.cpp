#include "GUIMyFrame.h"


std::istream& rd2EOL(std::istream& str)
{
    int ch;

    while ((ch = str.get()) != EOF && ch != '\n');
    return str;
}

bool GUIMyFrame::ReadDataToVector(const char* FileName)
{
    std::fstream file;
    file.open(FileName, std::ios::in);
    if (!file.is_open()) return false;


    file.close();
    return true;
}

void GUIMyFrame::setButtonsActive(bool active)
{
    AnimationGoBack->Enable(active);
    PlayAndStop->Enable(active);
    AnimationGoForward->Enable(active);
}