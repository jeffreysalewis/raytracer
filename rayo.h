#pragma once
#include "vect.h"
#include "punto.h"
#ifndef RAYO_H
#define RAYO_H


class Rayo {
private:
	Punto origin;
	Vect direction;
	bool hit;
	Vect color;
public:
	Rayo(const Punto &o, const Vect &dir);
	Rayo(const Vect& dir);
	Rayo();
	Punto getorigin();
	Vect getdirection();
	void sethit(bool b);
	bool gethit();
	void setcolor(double r, double g, double b);
	Vect getcolor();
};
#endif