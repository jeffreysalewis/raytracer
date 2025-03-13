#pragma once
#include "punto.h"
#include "vect.h"
#include "rayo.h"
#include <cmath>

#ifndef OBJ_H
#define OBJ_H


class Obj {
private:
	Punto vert1;
	Punto vert2;
	Punto vert3;
	Vect normal;
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
	Obj();
	virtual double getkd();
	virtual double getks();
	virtual double getka();
	virtual Vect getod();
	virtual Vect getos();
	virtual double getkgls();
	virtual bool intersect(Rayo r);
	virtual bool intersect2(Rayo r);
	virtual Rayo intersectray(Rayo r);
};
#endif
