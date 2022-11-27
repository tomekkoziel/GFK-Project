#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "include/bubble_sort.h"

/*
    \brief Function that prints given std::vector
*/
void print_vec(std::vector<int> v);

int main()
{
    std::vector<int> random_values;
    int num_of_frame = 0;

    for (int i = 0; i < 800 / 8; i++) // resolution of the window will be 800 x 600 (width x height), sorting will be visualized as rectangles which width will be equal to 4 px
    {
        random_values.push_back(rand() % 600 + 1);
    }

    std::ofstream file("bubble_sort.txt");

    int final_number_of_frames = 2865; // 2865

    file << "800, 600" << std::endl;

    file << final_number_of_frames << std::endl;

    file << num_of_frame << ", " << 10 << std::endl;

    int x1 = 0, x2 = 7, y1 = 0, y2 = 0;

    for (long unsigned int i = 0; i < random_values.size(); i++)
    {

        y2 = random_values[i];

        file << "kolor_wypelnienia 255 255 255 255" << std::endl;

        file << "prostokat " << x1 << ", " << y1 << ", " << x2 << ", " << y2 << ", 1" << std::endl;

        x1 += 8;
    }

    file << "stop" << std::endl;

    num_of_frame++;

    std::cout << num_of_frame << std::endl;

    random_values = BubbleSort(file, random_values, num_of_frame);

    std::cout << num_of_frame << std::endl;

    for (long unsigned int i = 0; i < random_values.size(); i++)
    {
        file << num_of_frame << ", " << 1 << std::endl;

        x1 = 0;

        for (long unsigned int j = 0; j < random_values.size(); j++)
        {

            y2 = random_values[j];

            if (j == i)
            {
                file << "kolor_wypelnienia 0 255 0 255" << std::endl;
            }
            else
            {
                file << "kolor_wypelnienia 255 255 255 255" << std::endl;
            }

            file << "prostokat " << x1 << ", " << y1 << ", " << x2 << ", " << y2 << ", 1" << std::endl;

            x1 += 8;
        }

        file << "stop" << std::endl;

        num_of_frame++;
    }

    std::cout << num_of_frame << std::endl;

    file.close();

    return 0;
}

void print_vec(std::vector<int> v)
{
    for (long unsigned int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << "\t";
    }

    std::cout << std::endl
              << std::endl;
}