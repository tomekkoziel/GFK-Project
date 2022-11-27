#include <cmath>
#include <iostream>
#include <vector>

/*
    @brief Changes the coordinates of given vectors to those imitating the bouncing movement of a rubber ball.
    @param H vector that consists of y coordinates (represents height)
    @param T vector that consists of x coordinates (represents time)
*/
void trajectory(std::vector<int> &H, std::vector<int> &T)
{
    double h0 = 5, v = 0, g = 10, t = 0, dt = 0.001, rho = 0.75, tau = 0.1;
    double hmax = h0, h = h0, hstop = 0.001;
    bool freefall = true;
    double t_last = -sqrt(2 * h0 / g);
    double vmax = sqrt(2 * hmax * g);

    double hnew;

    while (hmax > hstop)
    {
        if (freefall)
        {
            hnew = h + v * dt - 0.5 * g * dt * dt;
            if (hnew < 0)
            {
                t = t_last + 2 * sqrt(2 * hmax / g);
                freefall = false;
                t_last = t + tau;
                h = 0;
            }
            else
            {
                t = t + dt;
                v = v - g * dt;
                h = hnew;
            }
        }
        else
        {
            t = t + tau;
            vmax = vmax * rho;
            v = vmax;
            freefall = true;
            h = 0;
        }

        hmax = 0.5 * vmax * vmax / g;
        H.push_back(static_cast<int>(h * 100 + 15)); // times 100 for resolution purpose, plus 15 because we want to get trajectory of the center of the ball
        T.push_back(static_cast<int>(t * 100));
    }
}