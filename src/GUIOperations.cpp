#include "GUIMyFrame.h"

#include <wx/dcclient.h>
Frame::Frame(sf::RenderTexture& buf, int time) : Time{ time }, Image{ buf.getTexture() } {}
Frame::Frame(sf::Texture& img, int time) : Time{time}, Image{img} {}

bool GUIMyFrame::ReadDataToVector(const char* FileName)
{
    std::fstream file;
    file.open(FileName, std::ios::in);
    if (!file.is_open()) return false;

    sf::RenderTexture buffer;
    int w, h, frameNum, time;
    std::string figure;

    file >> w >> h >> frameNum;
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    buffer.create(w, h, settings);
    Animation.reserve(frameNum);

    sf::VertexArray point(sf::Points, 1);
    sf::CircleShape elipse(0, 100);
    sf::RectangleShape rectangle;
    sf::VertexArray line(sf::Lines, 2);
    sf::Color fillColor = sf::Color(0, 0, 0), penColor = sf::Color(0, 0, 0);
    int a, b, c, d;
    bool flag;
    float thickness = 1;

    while (file >> time)
    {
        buffer.clear(sf::Color(255, 255, 255, 0));
        
        while (file >> figure && figure != "stop" && figure != "ST")
        {
            if (figure == "punkt" || figure == "PT")
            {
                file >> a >> b;
                point[0].position = sf::Vector2f(a, b);
                point[0].color = penColor;
                buffer.draw(point);
            }
            else if (figure == "elipsa" || figure == "EL")
            {
                file >> a >> b >> c >> d >> flag;
                elipse.setPosition(a - c, b - d);
                elipse.setRadius(1);
                elipse.setScale(sf::Vector2f(c, d));
                elipse.setOutlineThickness(thickness);
                elipse.setOutlineColor(penColor);
                elipse.setFillColor((flag) ? fillColor : sf::Color::Transparent);
                buffer.draw(elipse);
            }
            else if (figure == "prostokat" || figure == "PR")
            {
                file >> a >> b >> c >> d >> flag;
                rectangle.setPosition(a, b);
                rectangle.setSize(sf::Vector2f(c, d));
                rectangle.setOutlineThickness(thickness);
                rectangle.setOutlineColor(penColor);
                rectangle.setFillColor((flag) ? fillColor : sf::Color::Transparent);
                buffer.draw(rectangle);
            }
            else if (figure == "linia" || figure == "LN")
            {
                file >> a >> b >> c >> d;
                line[0].position = sf::Vector2f(a, b);
                line[0].color = penColor;
                line[1].position = sf::Vector2f(c, d);
                line[1].color = penColor;
                buffer.draw(line);
            }
            else if (figure == "rozmiar_piora" || figure == "RP")
            {
                file >> thickness;
            }
            else if (figure == "kolor_piora" || figure == "KP")
            {
                file >> a >> b >> c;
                penColor = sf::Color(a, b, c);
            }
            else if (figure == "kolor_wypelnienia" || figure == "KW")
            {
                file >> a >> b >> c;
                fillColor = sf::Color(a, b, c);
            }
        }
        buffer.display();


        Animation.push_back(Frame(buffer, time));
    }
    file.close();

    wxClientDC(AnimationPanel).DrawText("Animation is ready\n", w / 2, h / 2);
    return true;
}


void GUIMyFrame::setButtonsActive()
{
    switch (AnimationState)
    {
    case States::NoInBuffer:
    case States::LoadingToBuffer:
        AnimationGoBack->Enable(false);
        PlayAndStop->Enable(false);
        AnimationGoForward->Enable(false);
        AnimationReplay->Enable(false);
        break;
    case States::ReadyToDisplay:
        AnimationGoBack->Enable(true);
        PlayAndStop->Enable(true);
        AnimationGoForward->Enable(true);
        AnimationReplay->Enable(false);
        break;
    case States::DuringDisplay:
        AnimationGoBack->Enable(true);
        PlayAndStop->Enable(true);
        AnimationGoForward->Enable(true);
        AnimationReplay->Enable(true);
        break;
    case States::AfterDisplay:
        AnimationGoBack->Enable(true);
        PlayAndStop->Enable(true);
        AnimationGoForward->Enable(false);
        AnimationReplay->Enable(true);
        break;
    }
    Layout();
}


void GUIMyFrame::SaveAnimationToDir(const char *DirPath)
{
    for(unsigned i=0; i<Animation.size(); i++)
        Animation[i].Image.copyToImage().saveToFile(std::string(DirPath) + "\\image" + std::to_string(i) + ".bmp");
}


bool GUIMyFrame::ReadImagesToVector(wxArrayString& paths)
{
    sf::Texture ReadImage;
    for (wxString &it : paths)
    {
        if (!ReadImage.loadFromFile(std::string(it))) return false;
        Animation.push_back(Frame(ReadImage, 5));
    }
    return true;
}