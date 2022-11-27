#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>

double ro(double h, double T, double P0);
double F_drag(double v, double Cx, double Sm, double h, double T, double P0);
void trajectory(std::vector<int> &X, std::vector<int> &Y);
void scaling(std::vector<int> &x, int max_res);

int main()
{
    std::vector<int> x;
    std::vector<int> y;

    trajectory(x, y);

    scaling(x, 800);
    scaling(y, 800);

    for (unsigned long int i = 0; i < y.size(); i++)
    {
        x[i] += 50;
        y[i] += 30;
    }

    std::ofstream f("day_sky.txt");

    f << "900, 900" << std::endl
      << 1612 << std::endl;

    int j = 0, j1 = 0;
    int g = 100, r = 255, b = 0;

    std::vector<int> cloud_x = {604, 701, 732, 819};
    std::vector<int> cloud_y = {708, 738, 677, 710};
    int cloud_height = 50, cloud_width = 80;

    for (unsigned long int i = 0; i < x.size(); i += 32)
    {
        // number of frame, screentime of frame
        f << j << ", " << 1 << std::endl;

        j++;

        if (j >= 1088)
        {
            r = 128;
            g = 128;
            b = 128;
        }
        else if (j <= 835)
        {
            g = (g < 255) ? g + 1 : g;
        }
        else
        {
            g = (g > 100) ? g - 1 : g;
        }

        f << "KW 65 107 179" << std::endl;

        f << "KP 65 107 179" << std::endl;

        // drawing sky
        f << "PR 0, 70, 900, 900, 1" << std::endl;

        // color of sun / moon
        f << "KW " << r << " " << g << " " << b << std::endl;

        f << "KP " << r << " " << g << " " << b << std::endl;

        // drawing sun/ moon
        if (j >= 1088)
        {
            f << "EL " << x[i] << ", " << y[i] << ", 40, 40, 1" << std::endl;

            f << "KW " << 65 << " " << 107 << " " << 179 << std::endl;

            f << "KP " << 65 << " " << 107 << " " << 179 << std::endl;

            f << "EL " << x[i] + 18 << ", " << y[i] + 14 << ", 40, 40, 1" << std::endl;
        }
        else
        {
            f << "EL " << x[i] << ", " << y[i] << ", 40, 40, 1" << std::endl;
        }

        if (j >= 300)
        {
            // chmury
            f << "KW 200 200 200" << std::endl
              << "KP 200 200 200" << std::endl;

            for (unsigned long int k = 0; k < cloud_x.size(); k++)
            {
                f << "EL " << cloud_x[k] + (900 - x[k]) - j1 << ", " << cloud_y[k] << ", " << cloud_width << ", " << cloud_height << ", 1" << std::endl;
            }

            j1++;
        }

        // // color of cannon launcher
        // f << "KW 0 60 80" << std::endl;

        // // drawing cannon launcher - rectangle

        // // drawing cannon launcher - ellipse
        // f << "EL 50, 30, 40, 40, 1" << std::endl;

        // color of ground (grass)
        f << "KW 0 150 0" << std::endl;

        f << "KP 0 150 0" << std::endl;

        // drawing ground
        f << "PR 0, 0, 900, 70, 1" << std::endl;

        f << "ST" << std::endl;
    }

    f.close();

    return 0;
}

// Obliczanie g�sto�ci powietrza na danej wysoko�ci
double ro(double h, double T, double P0)
{
    return 0.0289644 / (8.31446 * (T - 0.0065 * h)) * P0 * pow((1 - 0.0065 * h / T), 5.255);
}

// Obliczanie oporu areodynamicznego
double F_drag(double v, double Cx, double Sm, double h, double T, double P0)
{
    return Cx * ro(h, T, P0) * Sm * pow(v, 2) / 2;
}

void trajectory(std::vector<int> &X, std::vector<int> &Y)
{
    // Zmienne
    double x, y, v, Time;
    double pi, g, Cx, diam, Sm, M, T, P0;
    double dt, v_tmp;
    double alfa = 50.8057;

    // Sta�e
    pi = 3.14159265358979; // Pi, tak +-
    g = 9.807;             // Przy�pieszenie ziemskie[m / s2]

    // Parametry pocisku i Armatochaubicy Krab
    Cx = 0.187; // Wsp�czynnik Tarcia Dla pocisku 155mm ERFB-BB
                //  T. Ku�nierz, METODA WYZNACZENIA WARTO�CI WSPӣCZYNNIKA AERODYNAMICZNEGO
                //  POCISK�W STABILIZOWANYCH OBROTOWO, WITU Kaliber pocisku [mm] powieżchnia przekroju [m2] Masa

    diam = 155;                          // Kaliber pocisku [mm]
    Sm = pi * pow((diam / 2 / 1000), 2); // Powierzchnia przekroju[m2]

    M = 48;    // Masa pocisku [kg]
    v = 958.0; // Pocz�tkowa pr�dko�� pocisku [m/s] 334-968

    // Parametry �rodowiskowe
    T = 273;     //  Temperatura [K]
    P0 = 101300; //  Ci�nienie znormalizowane [Pa]

    // alfa = 50;  // K�t wystrza�u [deg]
    alfa = alfa / 180 * pi; //  [deg --> rad]

    // Parametry obliczeniowe
    dt = 0.01; /*  krok czasowy [s] (Je�eli program b�dzie wykonywa� si� zbyt d�ugo,
               zrezygnuj z dynamicznego obliczania kroku czasowago na pocz�tku p�tli */

    //  Inicjalizacja warto�ciami pocz�tkowymi
    x = 0.0;    // wsp�rz�dna pozioma
    y = 1.0E-5; //  wsp pionowa
    Time = 0.0; // Czas lotu pocisku

    while (y > 0.0)
    {
        dt = 1.0 / v; // Dynamiczny krok czasowy, dla zwi�kszenia precyzji
                      //  Wykorzystujemy metod� Eulera do obliczenia zmiany po�o�enia,
                      //  szybko�ci i k�ta nachylenia stycznej do toru ruchu pocisku

        X.push_back(static_cast<int>(x));
        Y.push_back(static_cast<int>(y));

        x += v * cos(alfa) * dt; // Wsp. pozioma
        y += v * sin(alfa) * dt; // Wsp. pionowa (wysoko�� npm.)

        // Pr�dko�� tymczasowa
        v_tmp = v + (-F_drag(v, Cx, Sm, y, T, P0) / M - g * sin(alfa)) * dt;
        alfa -= g * cos(alfa) / v * dt;
        v = v_tmp;
    }
}

void scaling(std::vector<int> &x, int max_res)
{
    int max_val = *std::max_element(x.begin(), x.end());

    for (unsigned long int i = 0; i < x.size(); i++)
    {
        x[i] = x[i] * max_res / max_val;
    }
}
