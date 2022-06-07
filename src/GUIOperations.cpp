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
    int w, h, frameNum, time, num;
    std::string figure;
    char comma;

    file >> w >> comma >> h >> frameNum;
    if(w<600) SetSize(600, h + 130);
    else SetSize(w + 26, h + 130);
    Centre();

    buffer.create(w, h);
    Animation.reserve(frameNum);

    LoadingProgress->SetRange(frameNum);
    LoadingProgress->SetValue(0);
    LoadingProgress->Show();
    Layout();

    sf::VertexArray point(sf::Points, 1);
    sf::CircleShape elipse(0, 100);
    sf::RectangleShape rectangle;
    sf::VertexArray line(sf::Lines, 2);
    sf::Color fillColor = sf::Color(0, 0, 0), penColor = sf::Color(0, 0, 0);
    int a, b, c, d;
    bool flag;
    float thickness = 1;

    while (file >> num >> comma >> time)
    {
        buffer.clear(sf::Color(255, 255, 255, 0));
        
        while (file >> figure && figure != "stop" && figure != "ST")
        {
            if (figure == "punkt" || figure == "PT")
            {
                file >> a >> comma >> b;
                point[0].position = sf::Vector2f(a, h - b);
                point[0].color = penColor;
                buffer.draw(point);
            }
            else if (figure == "elipsa" || figure == "EL")
            {
                file >> a >> comma >> b >> comma >> c >> comma >> d >> comma >> flag;
                elipse.setPosition(a - c, h - b - d);
                elipse.setRadius(1);
                elipse.setScale(sf::Vector2f(c, d));
                elipse.setOutlineThickness(thickness - 1);
                elipse.setOutlineColor(penColor);
                elipse.setFillColor((flag) ? fillColor : sf::Color::Transparent);
                buffer.draw(elipse);
            }
            else if (figure == "prostokat" || figure == "PR")
            {
                file >> a >> comma >> b >> comma >> c >> comma >> d >> comma >> flag;
                rectangle.setPosition(a, h - b);
                rectangle.setSize(sf::Vector2f(c, -d));
                rectangle.setOutlineThickness(thickness);
                rectangle.setOutlineColor(penColor);
                rectangle.setFillColor((flag) ? fillColor : sf::Color::Transparent);
                buffer.draw(rectangle);
            }
            else if (figure == "linia" || figure == "LN")
            {
                file >> a >> comma >> b >> comma >> c >> comma >> d;
                line[0].position = sf::Vector2f(a, h - b);
                line[0].color = penColor;
                line[1].position = sf::Vector2f(c, h - d);
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
        LoadingProgress->SetValue(LoadingProgress->GetValue() + 1);
    }
    file.close();

    LoadingProgress->Hide();
    wxClientDC(AnimationPanel).DrawText(wxString::Format("%d, %d", AnimationPanel->GetSize().x, AnimationPanel->GetSize().y), w / 2, h / 2);
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


sf::Image &MakeImageWithBackground(sf::Image& Animation, const sf::Image& Background)
{
    for (int i = 0; i < Animation.getSize().x; i++)
        for (int j = 0; j < Animation.getSize().y; j++)
            if (Animation.getPixel(i, j).a == 0) Animation.setPixel(i, j, Background.getPixel(i, j));
    const unsigned char* data = Animation.getPixelsPtr();
    return Animation;
}


void GUIMyFrame::SaveFrame(const char* DirPath, int start, int end)
{
    std::string numeration;
    sf::Image tmp;

    for (unsigned i = start; i < end; i++)
    {
        if (FileNumeration)
        {
            std::stringstream str;
            str << std::setw(log10(Animation.size()) + 1) << std::setfill('0') << i;
            numeration = str.str();
        }
        else numeration = std::to_string(i);
        tmp = Animation[i].Image.copyToImage();
        tmp.createMaskFromColor(sf::Color(255, 255, 255, 0), 255);
        tmp.saveToFile(std::string(DirPath) + "\\" + FileName + numeration + ".bmp");
        LoadingProgress->SetValue(LoadingProgress->GetValue() + 1);
    }

    if (LoadingProgress->GetValue() == Animation.size() - 1)
    {
        LoadingProgress->Hide();
        Layout();
    }
};

void GUIMyFrame::SaveAnimationToDir(const char *DirPath)
{
    LoadingProgress->SetRange(Animation.size());
    LoadingProgress->SetValue(0);
    LoadingProgress->Show();
    Layout();

    std::string numeration;
    sf::Image tmp;

    for (unsigned i = 0; i < Animation.size(); i++)
    {
        if (FileNumeration)
        {
            std::stringstream str;
            str << std::setw(log10(Animation.size()) + 1) << std::setfill('0') << i;
            numeration = str.str();
        }
        else numeration = std::to_string(i);

        if (ShowBg) tmp = MakeImageWithBackground(Animation[i].Image.copyToImage(), Background);
        else
        {
            tmp = Animation[i].Image.copyToImage();
            tmp.createMaskFromColor(sf::Color(255, 255, 255, 0), 255);
        }
        //std::thread(&sf::Image::saveToFile, &tmp, std::string(DirPath) + "\\" + FileName + numeration + ".bmp").detach();
        tmp.saveToFile(std::string(DirPath) + "\\" + FileName + numeration + ".bmp");
        LoadingProgress->SetValue(LoadingProgress->GetValue() + 1);
    }
    LoadingProgress->Hide();
    Layout();
    
    //std::thread(&GUIMyFrame::SaveFrame, this, DirPath, 0, Animation.size() / 2).detach();
    //std::thread(&GUIMyFrame::SaveFrame, this, DirPath, Animation.size() / 2, Animation.size()).detach();
}


bool GUIMyFrame::ReadImagesToVector(wxArrayString& paths)
{
    sf::Texture ReadImage;
    LoadingProgress->SetRange(Animation.size());
    LoadingProgress->SetValue(0);
    LoadingProgress->Show();
    Layout();
    for (wxString &it : paths)
    {
        if (!ReadImage.loadFromFile(std::string(it))) return false;
        Animation.push_back(Frame(ReadImage, 5));
        LoadingProgress->SetValue(LoadingProgress->GetValue() + 1);
    }
    LoadingProgress->Hide();
    Layout();

    return true;
}

bool GUIMyFrame::Read3DToVector(const char* FileName)
{
    std::fstream file;
    file.open(FileName, std::ios::in);
    if (!file.is_open()) return false;

    sf::RenderTexture buffer;
    int w, h, frameNum, time, num;
    std::string figure;
    char comma;

    file >> w >> comma >> h >> frameNum;
    if (w < 600) SetSize(600, h + 130);
    else SetSize(w + 26, h + 130);

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    buffer.create(w, h, settings);
    Animation.reserve(frameNum);

    LoadingProgress->SetRange(frameNum);
    LoadingProgress->SetValue(0);
    LoadingProgress->Show();
    Layout();
    
    sf::VertexArray line(sf::Lines, 2);
    sf::Color FirstColor = sf::Color(0, 0, 0), SecColor= sf::Color(0, 0, 0);
    double a, b, c, d, e, f;

    while (file >> num >> comma >> time)
    {
        buffer.clear(sf::Color(255, 255, 255, 0));

        while (file >> figure && figure != "stop" && figure != "ST")
        {
            if (figure == "linia" || figure == "LN")
            {
                file >> a >> comma >> b >> comma >> c >> comma >> d >> comma >> e >> comma >> f;
                line[0].position = sf::Vector2f(w / 2 * (1 + (a * 2.0) / (c + 2.0)), h / 2 * (1 - (b * 2.0) / (c + 2.0)));
                line[0].color = FirstColor;
                line[1].position = sf::Vector2f(w / 2 * (1 + (d * 2.0) / (f + 2.0)), h / 2 * (1 - (e * 2.0) / (f + 2.0)));
                line[1].color = SecColor;
                buffer.draw(line);
            }
            else if (figure == "kolor_1_konca" || figure == "KP")
            {
                file >> a >> b >> c;
                FirstColor = sf::Color(a, b, c);
            }
            else if (figure == "kolor_2_konca" || figure == "KE")
            {
                file >> a >> b >> c;
                SecColor = sf::Color(a, b, c);
            }
        }
        buffer.display();


        Animation.push_back(Frame(buffer, time));
        LoadingProgress->SetValue(LoadingProgress->GetValue() + 1);
    }
    file.close();

    LoadingProgress->Hide();
    wxClientDC(AnimationPanel).DrawText(wxString::Format("%d, %d", AnimationPanel->GetSize().x, AnimationPanel->GetSize().y), w / 2, h / 2);
    return true;
}