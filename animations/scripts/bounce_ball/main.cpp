#include <cmath>
#include <iostream>
#include <vector>
#include <fstream>

#include "include/trajectory.h"

int main()
{
    std::vector<int> h;
    std::vector<int> t;

    trajectory(h, t);

    std::ofstream f("bouncing_ball.txt");

    // Frame resolution \n total number of frames
    f << 800 << ", " << 600 << std::endl
      << 3458 << std::endl;

    int width = 20;
    int height = 20;
    int flaga = 1;
    int j = 0, k = 0;

    for (unsigned long int i = 0; i < h.size(); i += 2)
    {
        // std::cout << h[i] << "\t" << t[i] << "\t" << i << std::endl;
        // Frame number, display time (miliseconds)
        f << j << ", " << 1 << std::endl;

        if (i == 0)
        {
            f << "kolor_wypelnienia 255 0 0 255" << std::endl;
        }

        f << "elipsa ";

        if (t[i] == t[i - 2] + 10 || t[i] == t[i - 2] + 11)
        {
            i += 2;
            k++;
            // std::cout << j << "\t" << t[]
        }

        f << t[i] - k * 10 << ", ";

        // if y-coordinate is smaller than radius of the ball, the ball deforms itself by decreasing height (width stays the same), in other words it transformates into ellipse. The process repeats up until it reaches minimal y-coordinate value, than the deformation process stops.
        if (h[i] < height && t[i] < 595)
        {
            f << h[i] + 32 << ", " << width << ", " << h[i];
        }
        else if (t[i] < 605)
        {
            f << h[i] + 32 << ", " << width << ", " << height;
        }
        else
        {
            f << height + 32 << ", " << width << ", " << height;
        }

        f << ", " << flaga << std::endl
          << "stop" << std::endl;

        j++;
    }

    f.close();

    return 0;
}