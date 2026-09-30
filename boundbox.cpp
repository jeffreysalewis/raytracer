#include "boundbox.h"
#include "raytracer.h"
#include <cmath>
#include <utility>
using namespace std;

BoundBox::BoundBox() {
	vert1 = Punto(0, 0, 0);
	vert2 = Punto(-1, -1, -1);
	vert3 = Punto(-1, 1, -1);
	normal = (vert2.minus(vert1).cross(vert3.minus(vert1)));
	normal.normalize();
	d = -1 * (normal.dot(Vect(vert1.getx(), vert1.gety(), vert1.getz())));
}

bool BoundBox::intersect(Rayo r) {
	double tbottom = normal.dot(r.getdirection());
	if (tbottom == 0) {
		return false;
	}
	Vect o = Vect(r.getorigin().getx(), r.getorigin().gety(), r.getorigin().getz());
	double t = -1*(normal.dot(o)+d)/tbottom;
	if (t <= 0) {
		return false;
	}
	Vect inter = o.add((r.getdirection().multiply(t)));
	Punto inters = Punto(inter.getx(), inter.gety(), inter.getz());
	Vect lado1 = vert2.minus(vert1);
	Vect lado2 = vert3.minus(vert2);
	Vect lado3 = vert1.minus(vert3);
	Vect c1 = inters.minus(vert1);
	Vect c2 = inters.minus(vert2);
	Vect c3 = inters.minus(vert3);
	Vect inorm = normal.multiply(-1);
	if (normal.dot(lado1.cross(c1)) > 0 && normal.dot(lado2.cross(c2)) > 0 && normal.dot(lado3.cross(c3)) > 0) {
		return true;
	} else if (inorm.dot(lado1.cross(c1)) > 0 && inorm.dot(lado2.cross(c2)) > 0 && inorm.dot(lado3.cross(c3)) > 0) {
		return true;
	}
	return false;
}

bool BoundBox::intersect2(Rayo r) {
	return false;
}

Rayo BoundBox::intersectray(Rayo r) {
	double tbottom = normal.dot(r.getdirection());
	if (tbottom >= 0) {
		Rayo san = Rayo();
		san.sethit(false);
		return san;
	}
	Vect o = Vect(r.getorigin().getx(), r.getorigin().gety(), r.getorigin().getz());
	double t = -1*(normal.dot(o) + d) / tbottom;
	if (t <= 0) {
		Rayo san = Rayo();
		san.sethit(false);
		return san;
	}
	Vect inter = o.add((r.getdirection().multiply(t)));
	Punto hitpoint = Punto(inter.getx(), inter.gety(), inter.getz());
	Vect lado1 = vert2.minus(vert1);
	Vect lado2 = vert3.minus(vert2);
	Vect lado3 = vert1.minus(vert3);
	Vect c1 = hitpoint.minus(vert1);
	Vect c2 = hitpoint.minus(vert2);
	Vect c3 = hitpoint.minus(vert3);
	if (normal.dot(lado1.cross(c1)) > 0 && normal.dot(lado2.cross(c2)) > 0 && normal.dot(lado3.cross(c3)) > 0) {
		Vect luzdir4 = Vect(0.0, 1.0, 0.0);
		Vect luzdir3 = Vect(1.0, 0.0, 0.0);
		Vect luzdir5 = luzdir3;
		Vect luzdir2 = Vect(1.0 / sqrt(3.0), 1.0 / sqrt(3.0), 1.0 / sqrt(3.0));
		Vect ambluz2 = Vect(0.1, 0.1, 0.1);
		Vect ambluz = Vect(0, 0, 0);
		Vect luzcolor = Vect(1.0, 1.0, 1.0);

		Vect theluzdir = luzdir4;
		Vect theambluz = ambluz2;

		Rayo san = Rayo(hitpoint, normal);
		san.sethit(true);
		return san;
	}
	Rayo san = Rayo();
	san.sethit(false);
	return san;
}

Punto BoundBox::getpoint() {
	double rand1 = rand() / (double)RAND_MAX;
	double rand2 = (1.0-rand1) * (rand()/(double)RAND_MAX);
	double rand3 = 1.0 - rand1 - rand2;
	int randind = rand() % 6;
	if (randind % 3 == 1) {
		double temp = rand1;
		rand1 = rand2;
		rand2 = rand3;
		rand3 = temp;
	}
	else if (randind % 3 == 2) {
		double temp = rand1;
		rand1 = rand3;
		rand3 = rand2;
		rand2 = temp;
	}
	if (randind % 2 == 1) {
		double temp = rand1;
		rand1 = rand2;
		rand2 = temp;
	}
	double sumx = vert1.getx() * rand1 + vert2.getx() * rand2 + vert3.getx() * rand3;
	double sumy = vert1.gety() * rand1 + vert2.gety() * rand2 + vert3.gety() * rand3;
	double sumz = vert1.getz() * rand1 + vert2.getz() * rand2 + vert3.getz() * rand3;
	Punto randpt = Punto(sumx, sumy, sumz);
	return randpt;
}