#pragma once
#include "punto.h"
#include "vect.h"
#include "rayo.h"
#include <cmath>
#include "obj.h"
#include <vector>
using std::vector;

#ifndef BOUNDBOX_H
#define BOUNDBOX_H


class BoundBox: public Obj {
private:
	Punto vert1;
	Punto vert2;
	Punto vert3;
	Vect normal;
	double d;
	Obj* inside;
	vector<Obj> collection;
public:
	BoundBox();
	BoundBox(Punto bmin, Punto bmax, Obj* adentro);
	BoundBox(Punto bmin, Punto bmax, vector<Obj> cllctn);
	Punto getmin() override;
	Punto getmax() override;
	//Vect getnormal();
	void shrink();
	int getnumcollection();
	vector<BoundBox> split();
	bool intersect(Rayo r) override;
	bool intersect2(Rayo r) override;
	Rayo intersectray(Rayo r) override;
	Punto getpoint();
};
#endif
