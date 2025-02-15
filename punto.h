#pragma once
#pragma once
#ifndef PUNTO_H
#define PUNTO_H


class Punto {
private:
	double x, y, z;
public:
	Punto(double a, double b, double c);
	double getx();
	double gety();
	double getz();
};
#endif