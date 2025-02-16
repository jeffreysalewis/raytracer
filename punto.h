#pragma once
#include "vect.h"
#ifndef PUNTO_H
#define PUNTO_H


class Punto {
private:
	double x, y, z;
public:
	Punto(double a, double b, double c);
	Punto();
	double getx();
	double gety();
	double getz();
	Vect minus(Punto p);
};
#endif