#pragma once
#include "punto.h"
#include "vect.h"
#include "rayo.h"
#include <cmath>
#include "obj.h"

#ifndef BOUNDBOX_H
#define BOUNDBOX_H


class BoundBox: public Obj {
private:
	Punto vert1;
	Punto vert2;
	Punto vert3;
	Vect normal;
	double d;
public:
	BoundBox();
	Punto getvert1();
	Punto getvert2();
	Punto getvert3();
	Vect getnormal();
	bool intersect(Rayo r) override;
	bool intersect2(Rayo r) override;
	Rayo intersectray(Rayo r) override;
	Punto getpoint();
};
#endif
