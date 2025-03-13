#include "raytracer.h"
#include "sphere.h"
#include "vect.h"
#include "punto.h"
#include "rayo.h"
#include "obj.h"
#include "triangle.h"

#include <iostream>
#include <fstream>
#include <cmath>
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
Vect luzdir2(1/sqrt(3), 1/sqrt(3), 1/sqrt(3));
Vect ambluz2(0.1, 0.1, 0.1);
Vect luzdir3 = Vect(1.0, 0.0, 0.0);
Vect luzdir4 = Vect(0.0, 1.0, 0.0);
Sphere sph = Sphere();

Sphere blanco = Sphere(Punto(0.45, 0.0, - 0.15), 0.15, 0.8, 0.1, 0.3, Vect(1.0, 1.0, 1.0), Vect(1.0, 1.0, 1.0), 4.0);
Sphere rojo = Sphere(Punto(0.0, 0.0, -0.1), 0.2, 0.6, 0.3, 0.1, Vect(1.0, 0.0, 0.0), Vect(1.0, 1.0, 1.0), 32.0);
Sphere verde = Sphere(Punto(-0.6, 0.0, 0.0), 0.3, 0.7, 0.2, 0.1, Vect(0.0, 1.0, 0.0), Vect(0.5, 1.0, 0.5), 64.0);
Sphere azul = Sphere(Punto(0.0, -10000.5, 0.0), 10000.0, 0.9, 0.0, 0.1, Vect(0.0, 0.0, 1.0), Vect(1.0, 1.0, 1.0), 16.0);
Obj* escena1[1] = {&sph};
Obj* escena2[4] = {&blanco, &azul, &rojo, &verde};
//Obj test[3] = { blanco, azul, rojo };

Sphere ball1 = Sphere(Punto(-0.1, 0.0, -0.15), 0.15, 0.8, 0.2, 0.3, Vect(1.0, 1.0, 0.0), Vect(1.0, 1.0, 1.0), 4.0);
Sphere ball2 = Sphere(Punto(0.1, 0.0, -0.15), 0.1, 0.8, 0.2, 0.3, Vect(1.0, 1.0, 1.0), Vect(1.0, 1.0, 1.0), 16.0);
Sphere ball3 = Sphere(Punto(0.45, 0.0, -0.15), 0.05, 0.8, 0.2, 0.3, Vect(0.0, 1.0, 1.0), Vect(1.0, 1.0, 1.0), 8.0);
Sphere ball4 = Sphere(Punto(-0.5, 0.0, -0.15), 0.15, 0.8, 0.2, 0.3, Vect(0.0, 0.5, 1.0), Vect(1.0, 1.0, 1.0), 8.0);
Sphere ball5 = Sphere(Punto(0.0, 0.5, -0.15), 0.15, 0.8, 0.2, 0.3, Vect(0.5, 0.0, 1.0), Vect(1.0, 1.0, 1.0), 8.0);
Obj* escena3[5] = { &ball1, &ball2, &ball3, &ball4, &ball5 };

Sphere refsph = Sphere(Punto(0.0, 0.3, -1.0), 0.25, 0.0, 0.1, 0.1, Vect(0.75, 0.75, 0.75), Vect(1.0, 1.0, 1.0), 10.0, 0.9);
Triangle bluetri = Triangle(Punto(0.0, -0.7, -0.5), Punto(1.0, 0.4, -1.0), Punto(0.0, -0.7, -1.5), 0.9, 1.0, 0.1, Vect(0.0, 0.0, 1.0), Vect(1.0, 1.0, 1.0), 4.0, 0.0);
Triangle yellowtri = Triangle(Punto(0.0, -0.7, -0.5), Punto(0.0, -0.7, -1.5), Punto(-1.0, 0.4, -1.0), 0.9, 1.0, 0.1, Vect(1.0, 1.0, 0.0), Vect(1.0, 1.0, 1.0), 4.0, 0.0);
Obj* escena4[3] = { &refsph, &bluetri, &yellowtri };

Sphere whitesph = Sphere(Punto(0.5, 0.0, -0.15), 0.05, 0.8, 0.1, 0.3, Vect(1.0, 1.0, 1.0), Vect(1.0, 1.0, 1.0), 4.0, 0.0);
Sphere redsph = Sphere(Punto(0.3, 0.0, -0.1), 0.08, 0.8, 0.8, 0.1, Vect(1.0, 0.0, 0.0), Vect(0.5, 1.0, 0.5), 32.0, 0.0);
Sphere greensph = Sphere(Punto(-0.6, 0.0, 0.0), 0.3, 0.7, 0.5, 0.1, Vect(0.0, 1.0, 0.0), Vect(0.5, 1.0, 0.5), 64.0, 0.0);
Sphere refsph2 = Sphere(Punto(0.1, -0.55, 0.25), 0.3, 0.0, 0.1, 0.1, Vect(0.75, 0.75, 0.75), Vect(1.0, 1.0, 1.0), 10.0, 0.9);
Triangle azultri = Triangle(Punto(0.3, -0.3, -0.4), Punto(0.0, 0.3, -0.1), Punto(-0.3, -0.3, 0.2), 0.9, 0.9, 0.1, Vect(0.0, 0.0, 1.0), Vect(1.0, 1.0, 1.0), 32.0, 0.0);
Triangle amarillotri = Triangle(Punto(-0.2, 0.1, 0.1), Punto(-0.2, -0.5, 0.2), Punto(-0.2, 0.1, -0.3), 0.9, 0.5, 0.1, Vect(1.0, 1.0, 0.0), Vect(1.0, 1.0, 1.0), 4.0, 0.0);
Obj* escena5[6] = { &whitesph, &redsph, &greensph, &refsph2, &azultri, &amarillotri };

//auto laescena = escena4;
int numobj = 3;
Vect theluzdir = luzdir4;

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
    ofstream Render("render4shadow.ppm");
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
    Vect multvecttest = Punto(1, 1, 0).minus(Punto(0, 1, 0));
    cout << multvecttest.multiply(2.5).getx() << endl;
    cout << sph.getradius() << endl;
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
            Rayo ray = Rayo(camlookfrom, di);
            /*if (inity - stepy * i > 0) {
                img[i][j][2] = (int)((inity - stepy * i) * 255);
            }
            else {
                img[i][j][2] = (int)((inity - stepy * i) * -255);
            }*/

            //change escena1 to escena2 for the second scene
            //Rayo newrays[4];
            Rayo zbuf;
            Punto mindist = Punto(0, 0, -100000000);
            zbuf = Rayo(mindist, theluzdir);
            int b = 0;
            int bbuf = 0;
            for (auto* pelota:escena4) {
                //newrays[b] = pelota.intersectray(ray);
                Rayo newray = pelota->intersectray(ray);
                if (newray.gethit()) {
                    if (newray.getorigin().getz() > zbuf.getorigin().getz()) {
                        zbuf = newray;
                        bbuf = b;
                    }
                    //img[i][j][0] = 255;
                    //newray.getcolor().normalize();
                    /*img[i][j][0] = (int)max(0.0, min(255.0, newrays[b].getcolor().getx() * 255));
                    img[i][j][1] = (int)max(0.0, min(255.0, newrays[b].getcolor().gety() * 255));
                    img[i][j][2] = (int)max(0.0, min(255.0, newrays[b].getcolor().getz() * 255));*/
                }
                b++;
            }
            bool maria = true;
            if (zbuf.gethit()) {
                Rayo shadowthehedgehog(zbuf.getorigin(), theluzdir);
                for (int k = 0; k < numobj; k++) {
                    if (k != bbuf) {
                        if (escena4[k]->intersect(shadowthehedgehog)) {
                            maria = false;
                        }
                    }
                }
                if (maria) {
                    img[i][j][0] = (int)max(0.0, min(255.0, zbuf.getcolor().getx() * 255));
                    img[i][j][1] = (int)max(0.0, min(255.0, zbuf.getcolor().gety() * 255));
                    img[i][j][2] = (int)max(0.0, min(255.0, zbuf.getcolor().getz() * 255));
                }
                else {
                    img[i][j][0] = (int)max(0.0, min(255.0, zbuf.getshadow().getx() * 255));
                    img[i][j][1] = (int)max(0.0, min(255.0, zbuf.getshadow().gety() * 255));
                    img[i][j][2] = (int)max(0.0, min(255.0, zbuf.getshadow().getz() * 255));
                }
            }
            /*Rayo zbuf = Rayo();
            for (int k = 0; k < 5; k++) {
                if (newrays[k].gethit()) {

                }
            }*/
        }
        
    }
    return;
}