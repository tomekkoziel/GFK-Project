#include <iostream>
#include <fstream>
#include <cmath>

double y_fun(int x);

int main()
{
    std::ofstream file("rolling_circle.txt");

    file << 800 << ", " << 600 << std::endl
         << 860 << std::endl;

    int constant = 70; // need to find exact constant, but need to see it first

    for (int i = 0; i < 860; i++)
    {
        file << i << ", " << 10 << std::endl;

        file << "LN " << 0 << ", " << 599 << ", " << 799 << ", " << 128 << std::endl;

        file << "EL " << i << ", " << static_cast<int>(y_fun(i)) + constant << ", " << 60 << ", " << 60 << ", " << 1 << std::endl;

        file << "ST" << std::endl;
    }
}

/*
    @brief Linear function which returns y-coordinate value of the center of the circle
*/
double y_fun(int x)
{
    return (128 - 599) / 799.0 * x + 599;
}

// add after first frame: KW 0 0 255