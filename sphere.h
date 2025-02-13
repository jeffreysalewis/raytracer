#pragma once

#ifndef SPHERE_H
#define SPHERE_H


class Sphere {
private:
	double* center;
	double radius;
	double kd, ks, ka;
	double* od;
	double* os;
	double kgls;
public:
	Sphere(double* c, double r, double dk, double sk, double ak, double* odd, double* so, double kgloss);
	double* getcenter();
	double getradius();
	double getkd();
	double getks();
	double getka();
	double* getod();
	double* getos();
	double getkgls();
};
#endif