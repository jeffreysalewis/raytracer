#pragma once
#include "vect.h"
#include "punto.h"
#ifndef RAYO_H
#define RAYO_H


class Rayo {
private:
	Punto origin;
	Vect direction;
public:
	Rayo(const Punto &o, const Vect &dir);
	Rayo(const Vect& dir);
	Rayo();
	Punto getorigin();
	Vect getdirection();
};
#endif