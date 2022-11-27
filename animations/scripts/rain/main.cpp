#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <random>

/*
    wszystkie osie zawierają współrzędne od -1 do 1
    x -> w prawo dodatnia półoś
    y -> w górę dodatnia półoś
    z -> za ekran (w przeciwną stronę niż do użytkownika) dodatnia półoś
*/

double RandD()
{
    double x1 = -1, x2 = 1;
    return x1 + (x2 - x1) * (static_cast<double>(rand()) / RAND_MAX); // choosing double value from range [-1, 1]
}

int main()
{
    std::vector<double> x1, y1, z1;
    // std:vector<double> sec_x, sec_y, sec_z;
    int g = 0;

    for (unsigned long int i = 0; i < 250; i++) // 250 - number of raindrops (lines) showed on the screen at the beginning
    {
        x1.push_back(RandD());
        y1.push_back(RandD());
        z1.push_back(RandD());

        while (x1[i] >= 0.5 * z1[i] + 1 || x1[i] <= -0.5 * z1[i] - 1)
        {
            // std::cout << g++ << "\t";
            x1[i] = RandD();
        }
    }

    int num_of_frames = 1500;

    std::ofstream f("rain_3D.txt");

    f << "600, 600" << std::endl
      << num_of_frames << std::endl;

    for (int i = 0; i < num_of_frames; i++)
    {
        f << i << ", 1" << std::endl;

        if (i == 0)
        {
            f << "KP 0 0 255" << std::endl; // ustawienie koloru pióra na niebieski (sprawdź czy dobra komenda)
        }

        for (unsigned long int j = 0; j < x1.size(); j++)
        {
            if (y1[j] + 0.01 - i * 0.003 <= 0.501 * z1[j] + 1.0019) // && y1[j] - i * 0.001 >= -0.5 * z1[j] - 1
            {
                f << "LN " << x1[j] << ", " << y1[j] - i * 0.003 << ", " << z1[j] << ", " << x1[j] << ", " << y1[j] + 0.05 - i * 0.003 << ", " << z1[j] << std::endl;
            }

            // if (y1[j] + 1 + 0.01 - i * 0.003 <= 0.501 * z1[j] + 1.0019 && y1[j] + 1 - i * 0.003 >= -0.5 * z1[j] - 1)
            // {
            //     f << "LN " << x1[j] << ", " << y1[j] + 1 - i * 0.003 << ", " << z1[j] << ", " << x1[j] << ", " << y1[j] + 1 + 0.05 - i * 0.003 << ", " << z1[j] << std::endl;
            // }

            // if (y1[j] + 2 + 0.01 - i * 0.003 <= 0.501 * z1[j] + 1.0019 && y1[j] + 2 - i * 0.003 >= -0.5 * z1[j] - 1)
            // {
            //     f << "LN " << x1[j] << ", " << y1[j] + 2 - i * 0.003 << ", " << z1[j] << ", " << x1[j] << ", " << y1[j] + 2 + 0.05 - i * 0.003 << ", " << z1[j] << std::endl;
            // }

            for (int k = 1; k < 8; k++)
            {
                if (y1[j] + k + 0.01 - i * 0.003 <= 0.501 * z1[j] + 1.0019 && y1[j] + k - i * 0.003 >= -0.5 * z1[j] - 1)
                {
                    f << "LN " << x1[j] << ", " << y1[j] + k - i * 0.003 << ", " << z1[j] << ", " << x1[j] << ", " << y1[j] + k + 0.05 - i * 0.003 << ", " << z1[j] << std::endl;
                }
            }
        }

        f << "ST" << std::endl;
    }

    f.close();
}