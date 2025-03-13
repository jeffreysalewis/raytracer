#pragma once
#include "punto.h"
#include "vect.h"
#include "rayo.h"
#include <cmath>
#include "obj.h"

#ifndef TRIANGLE_H
#define TRIANGLE_H


class Triangle: public Obj {
private:
	Punto vert1;
	Punto vert2;
	Punto vert3;
	Vect normal;
	double kd, ks, ka;
	Vect od;
	Vect os;
	double kgls;
	double refl;
	Vect luzdir = Vect(0, 1, 0);
	//Vect luzdir2 = Vect(1/sqrt(3), 1/sqrt(3), 1/sqrt(3));
	//Vect luzdir2 = Vect(1, 1, 1);
	//Vect luzcolor = Vect(1.0, 1.0, 1.0);
	//Vect ambluz2 = Vect(0.1, 0.1, 0.1);
public:
	Triangle(Punto v1, Punto v2, Punto v3, double dk, double sk, double ak, Vect odd, Vect so, double kgloss, double ref);
	Triangle();
	Punto getvert1();
	Punto getvert2();
	Punto getvert3();
	Vect getnormal();
	double getkd();
	double getks();
	double getka();
	Vect getod();
	Vect getos();
	double getkgls();
	bool intersect(Rayo r);
	bool intersect2(Rayo r);
	Rayo intersectray(Rayo r);
};
#endif
