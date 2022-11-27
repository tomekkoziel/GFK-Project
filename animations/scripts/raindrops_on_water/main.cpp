#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

int RandColor()
{
    return rand() % 256;
}

int main()
{
    std::vector<int> rand_x;
    std::vector<int> rand_y;

    for (int i = 0; i < 250; i++)
    {
        rand_x.push_back(rand() % 800 + 1);
        rand_y.push_back(rand() % 800 + 1);
    }

    int num_of_frames = 1000;

    std::ofstream f("raindrops_on_water.txt");

    f << "800, 800" << std::endl
      << num_of_frames << std::endl;

    bool check = false;

    std::vector<int> num_of_circles; // is also height and width in ellipses
    // std::vector<int> pen_size;
    std::vector<int> r, g, b;

    for (int i = 0; i < num_of_frames; i++)
    {
        f << i << ", 5" << std::endl;

        // f << "KP " << RandColor() << " " << RandColor() << " " << RandColor() << std::endl;

        check = (i % 5 == 0) ? true : false;

        if (check == true)
        {
            num_of_circles.push_back(20);
            // pen_size.push_back(4);
            r.push_back(RandColor());
            g.push_back(RandColor());
            b.push_back(RandColor());
        }

        for (unsigned long int j = 0; j < num_of_circles.size(); j++)
        {
            // if (num_of_circles[j] > 50 && num_of_circles[j] <= 70)
            // {
            //     pen_size[j] = 3;
            // }
            // else if (num_of_circles[j] > 70 && num_of_circles[j] <= 90)
            // {
            //     pen_size[j] = 2;
            // }
            // else if (num_of_circles[j] > 90 && num_of_circles[j] <= 100)
            // {
            //     pen_size[j] = 1;
            // }

            // if (j == 0)
            // {
            //     f << "RP " << pen_size[j] << std::endl;
            // }
            // else if (pen_size[j] != pen_size[j - 1])
            // {
            //     f << "RP " << pen_size[j] << std::endl;
            // }

            f << "KW " << r[j] << " " << g[j] << " " << b[j] << std::endl;

            f << "EL " << rand_x[j] << ", " << rand_y[j] << ", " << num_of_circles[j] << ", " << num_of_circles[j] << ", 1" << std::endl;

            num_of_circles[j]++;
        }

        f << "ST" << std::endl;
    }

    f.close();

    return 0;
}