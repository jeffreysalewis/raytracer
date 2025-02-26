#pragma once
#include "punto.h"
#include "vect.h"
#include "rayo.h"
#include <cmath>

#ifndef SPHERE_H
#define SPHERE_H


class Sphere {
private:
	Punto center;
	double radius;
	double kd, ks, ka;
	Vect od;
	Vect os;
	double kgls;
	Vect luzdir = Vect(0, 1, 0);
	//Vect luzdir2 = Vect(1/sqrt(3), 1/sqrt(3), 1/sqrt(3));
	//Vect luzdir2 = Vect(1, 1, 1);
	//Vect luzcolor = Vect(1.0, 1.0, 1.0);
	//Vect ambluz2 = Vect(0.1, 0.1, 0.1);
public:
	Sphere(Punto c, double r, double dk, double sk, double ak, Vect odd, Vect so, double kgloss);
	Sphere();
	Punto getcenter();
	double getradius();
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