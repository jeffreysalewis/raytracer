#pragma once
#include "punto.h"
#include "vect.h"
#include "rayo.h"
#include <cmath>
#include "obj.h"

#ifndef SPHERE_H
#define SPHERE_H


class Sphere: public Obj {
private:
	Punto center;
	double radius;
	double kd, ks, ka;
	Vect od;
	Vect os;
	double kgls;
	double refl = 0.0;
	Vect luzdir = Vect(0, 1, 0);
	//Vect luzdir2 = Vect(1/sqrt(3), 1/sqrt(3), 1/sqrt(3));
	//Vect luzdir2 = Vect(1, 1, 1);
	//Vect luzcolor = Vect(1.0, 1.0, 1.0);
	//Vect ambluz2 = Vect(0.1, 0.1, 0.1);
public:
	Sphere(Punto c, double r, double dk, double sk, double ak, Vect odd, Vect so, double kgloss);
	Sphere(Punto c, double r, double dk, double sk, double ak, Vect odd, Vect so, double kgloss, double ref);
	Sphere();
	Punto getcenter();
	double getradius();
	double getkd() override;
	double getks() override;
	double getka() override;
	Vect getod() override;
	Vect getos() override;
	double getkgls() override;
	bool intersect(Rayo r) override;
	bool intersect2(Rayo r) override;
	Rayo intersectray(Rayo r) override;
};
#endif