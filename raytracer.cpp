#include "raytracer.h"

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream Render("render.ppm");
    Render << "P3\n";
    Render << "32 32\n";
    Render << "255\n";
    for(int i =0; i<32; i++) {
        for(int j=0; j<32; j++) {
            Render << "255 0 255  ";
        }
        Render << "\n";
    }
    Render.close();
    cout << "\nthis is a ray tracer!\n" << endl;
    return 0;
}
