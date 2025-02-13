#include "raytracer.h"
#include "sphere.h"

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    const int width = 32;
    const int height = 32;
    int img[width][height][3];
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) {
            img[i][j][0] = 128;
            img[i][j][1] = 128;
            img[i][j][2] = 255;
        }
    }
    ofstream Render("render.ppm");
    Render << "P3\n";
    Render << width << " " << height << "\n";
    Render << "255\n";
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) {
            Render << img[i][j][0] << " " << img[i][j][1] << " " << img[i][j][2] << "  ";
        }
        Render << "\n";
    }
    Render.close();
    //double s[3] = {0.0, 0.0, 0.0};
    //Sphere sph(s, 0.4, 0.7, 0.2, 0.1, {1.0, 0.0, 1.0}, {1.0, 1.0, 1.0}, 16.0);
    //cout << sph.getradius(); << endl;
    cout << "\nthis is a ray tracer!\n" << endl;
    return 0;
}