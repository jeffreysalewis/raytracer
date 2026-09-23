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
	double kd, ks, ka, kt;
	Vect od;
	Vect os;
	double kgls;
	double refl = 0.0;
	double ior = 1.5;
	Vect luzdir;
	Punto luzpt;
	Vect luzdircolor;
	Vect luzptcolor;
	bool wasluzdirset = false;
	bool wasluzptset = false;
	//Vect luzdir2 = Vect(1/sqrt(3), 1/sqrt(3), 1/sqrt(3));
	//Vect luzdir2 = Vect(1, 1, 1);
	//Vect luzcolor = Vect(1.0, 1.0, 1.0);
	//Vect ambluz2 = Vect(0.1, 0.1, 0.1);
public:
	Sphere(Punto c, double r, double dk, double sk, double ak, Vect odd, Vect so, double kgloss);
	Sphere(Punto c, double r, double dk, double sk, double ak, Vect odd, Vect so, double kgloss, double ref);
	Sphere(Punto c, double r, double dk, double sk, double ak, double tk, Vect odd, Vect so, double kgloss, double ref, double refr);
	Sphere();
	Punto getcenter();
	double getradius();
	double getkd() override;
	double getks() override;
	double getka() override;
	double getkt() override;
	Vect getod() override;
	Vect getos() override;
	double getkgls() override;
	double getior() override;
	void setluces(Vect ldirs, Vect ldirscolor, Punto lpts, Vect lptscolor) override;
	bool intersect(Rayo r) override;
	bool intersect2(Rayo r) override;
	Rayo intersectray(Rayo r) override;
};
#endif