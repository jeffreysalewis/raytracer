#include "raytracer.h"
#include "sphere.h"
#include "vect.h"
#include "punto.h"
#include "rayo.h"

#include <iostream>
#include <fstream>
using namespace std;

const int width = 1280;
const int height = 720;
int img[height][width][3];
Punto camlookat(0, 0, 0);
Punto camlookfrom(0, 0, 1);
Punto camlookup(0, 1, 0);
const int fov = 90;
Vect luzdir(0, 1, 0);
Vect luzcolor(1, 1, 1);
Vect ambluz(0, 0, 0);
Sphere sph = Sphere();

int main() {
    int backcolor[3] = {51, 51, 51};
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            img[i][j][0] = backcolor[0];
            img[i][j][1] = backcolor[1];
            img[i][j][2] = backcolor[2];
        }
    }
    trace();
    ofstream Render("render.ppm");
    Render << "P3\n";
    Render << width << " " << height << "\n";
    Render << "255\n";
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            Render << img[i][j][0] << " " << img[i][j][1] << " " << img[i][j][2] << "  ";
        }
        Render << "\n";
    }
    Render.close();
    Vect bwvar = Punto(1, 1, 0).minus(Punto(0, 1, 0));
    cout << bwvar.getx() << bwvar.gety() << bwvar.getz() << endl;
    cout << sph.getradius() << endl;
    Vect v(0, 0, 1);
    cout << v.getz() << endl;
    cout << "\nthis is a ray tracer!\n" << endl;
    return 0;
}

void trace() {
    double stepx = 1.77778/width;
    double stepy = 1.0/height;
    double initx = -0.88889 + stepx/2;
    double inity = 0.5 - stepy/2;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            Vect di = Punto(initx + stepx*j, inity - stepy*i, 0).minus(camlookfrom);
            di.normalize();
            //Punto ppp = Punto(0, 0, 1);
            Rayo ray = Rayo(camlookfrom, di);
            //cout << ray.getdirection().getx() << ray.getdirection().gety() << endl;
            //algo = ray.getlen();
            //algo = ray.getz();
            //cout << algo << "\n" << endl;
            if (inity - stepy * i > 0) {
                img[i][j][2] = (int)((inity - stepy * i) * 255);
            }
            else {
                img[i][j][2] = (int)((inity - stepy * i) * -255);
            }
            if (sph.intersect(ray)) {
                img[i][j][0] = 255;
                
            }
        }
        
    }
    return;
}