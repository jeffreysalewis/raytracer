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
	Vect shadow;
	double reflect;
	double refract;
	double kd, ks, kt;
	int bounce;
	int whichone;
public:
	Rayo(const Punto &o, const Vect &dir);
	Rayo(const Vect& dir);
	Rayo();
	void setorigin(Punto o);
	void setdirection(Vect dir);
	Punto getorigin();
	Vect getdirection();
	void setwhichone(int w);
	int getwhichone();
	void sethit(bool b);
	bool gethit();
	void setcolor(double r, double g, double b);
	void setshadow(double r, double g, double b);
	Vect getcolor();
	Vect getshadow();
	void setreflect(double r);
	void setrefract(double r);
	void setbounce(int b);
	double getreflect();
	double getrefract();
	void setkd(double d);
	void setks(double s);
	void setkt(double t);
	double getkd();
	double getks();
	double getkt();
	int getbounce();
};
#endif