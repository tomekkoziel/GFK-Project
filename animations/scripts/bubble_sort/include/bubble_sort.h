#pragma once

#include <vector>
#include <ostream>

/*
    \brief Function that uses bubble sort algorithm to sort given std::vector

    Bubble Sort - iterates through every element of the table, if the current element is greater that the previous one the elements are being swapped.
*/
std::vector<int> BubbleSort(std::ofstream &file, std::vector<int> v, int &num_of_frame)
{
    bool change = true;

    int x1 = 0, x2 = 7, y1 = 0, y2 = 0;

    while (change == true)
    {
        change = false;

        for (long unsigned int i = 1; i < v.size(); i++)
        {
            if (v[i] < v[i - 1])
            {
                std::swap(v[i - 1], v[i]);

                change = true;

                file << num_of_frame << ", " << 5 << std::endl;

                x1 = 0;

                for (long unsigned int j = 0; j < v.size(); j++)
                {
                    y2 = v[j];

                    if (j == i || j == i - 1)
                    {
                        file << "kolor_wypelnienia 255 0 0 255" << std::endl;
                    }
                    else
                    {
                        file << "kolor_wypelnienia 255 255 255 255" << std::endl;
                    }

                    file << "prostokat " << x1 << ", " << y1 << ", "
                         << x2 << ", " << y2 << ", 1" << std::endl;

                    x1 += 8;
                }

                file << "stop" << std::endl;

                num_of_frame++;
            }
        }
    }

    return v;
}