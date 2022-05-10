#include "GUIMyFrame.h"


Frame::Frame(sf::Image& img, int time) : Time{ time }, Image{ img.getSize().x, img.getSize().y }
{
    unsigned char* wxdata = Image.GetData();
    Image.InitAlpha();
    unsigned char* wxalpha = Image.GetAlpha();
    const unsigned char* sfdata = img.getPixelsPtr();
    int size = Image.GetSize().x * Image.GetSize().y;
    for (int i = 0; i < size; i++)
    {
        wxdata[0] = sfdata[0];
        wxdata[1] = sfdata[1];
        wxdata[2] = sfdata[2];
        wxalpha[0] = sfdata[3];
        wxdata += 3;
        wxalpha++;
        sfdata += 4;
    }
}


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
    sf::Color fillColor, penColor;
    int a, b, c, d;
    bool flag;
    float thickness = 0.01;

    while (file >> time)
    {
        buffer.clear(sf::Color::Transparent);
        
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
        
        Animation.push_back(Frame(buffer.getTexture().copyToImage(), time));
    }

    file.close();
    return true;
}


void GUIMyFrame::setButtonsActive(bool active)
{
    AnimationGoBack->Enable(active);
    PlayAndStop->Enable(active);
    AnimationGoForward->Enable(active);
}


void GUIMyFrame::SaveAnimationToDir(wxString DirPath)
{
    for (unsigned i = 0; i < Animation.size(); i++)
        Animation[i].Image.SaveFile(DirPath + "image" + std::to_string(i) + ".bmp");
}