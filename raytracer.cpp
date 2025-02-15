#include "raytracer.h"
#include "sphere.h"
#include "vect.h"
#include "punto.h"

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    const int width = 32;
    const int height = 32;
    Punto camlookat(0, 0, 0);
    Punto camlookfrom(0, 0, 1);
    Punto camlookup(0, 1, 0);
    const int fov = 90;

    Vect luzdir(0, 1, 0);
    Vect luzcolor(1, 1, 1);
    Vect ambluz(0, 0, 0);
    int backcolor[3] = {51, 51, 51};
    int img[height][width][3];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            img[i][j][0] = backcolor[0];
            img[i][j][1] = backcolor[1];
            img[i][j][2] = backcolor[2];
        }
    }
    ofstream Render("render.ppm");
    Render << "P3\n";
    Render << height << " " << width << "\n";
    Render << "255\n";
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            Render << img[i][j][0] << " " << img[i][j][1] << " " << img[i][j][2] << "  ";
        }
        Render << "\n";
    }
    Render.close();
    double s[3] = {0.0, 0.0, 0.0};
    double* sp = s;
    Sphere sph(sp, 0.4, 0.7, 0.2, 0.1, sp, sp, 16.0);
    cout << sph.getradius() << endl;
    Vect v(0, 0, 1);
    cout << v.getz() << endl;
    cout << "\nthis is a ray tracer!\n" << endl;
    return 0;
}