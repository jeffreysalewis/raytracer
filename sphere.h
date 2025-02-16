#pragma once
#include "punto.h"
#include "vect.h"
#include "rayo.h"

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
};
#endif