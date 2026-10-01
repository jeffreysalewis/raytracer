#include "boundbox.h"
#include "raytracer.h"
#include <cmath>
#include <utility>
#include <vector>
using std::vector;
using namespace std;

BoundBox::BoundBox() {
	vert1 = Punto(-100000, -100000, -100000);
	vert2 = Punto(100000, 100000, 100000);
	vert3 = Punto(-1, 1, -1);
	normal = (vert2.minus(vert1).cross(vert3.minus(vert1)));
	normal.normalize();
	d = -1 * (normal.dot(Vect(vert1.getx(), vert1.gety(), vert1.getz())));
}

BoundBox::BoundBox(Punto bmin, Punto bmax, Obj* adentro) {
	vert1 = bmin;
	vert2 = bmax;
	inside = adentro;
}

BoundBox::BoundBox(Punto bmin, Punto bmax, vector<Obj> cllctn) {
	vert1 = bmin;
	vert2 = bmax;
	collection = cllctn;
	shrink();
}

Punto BoundBox::getmin() {
	return vert1;
}

Punto BoundBox::getmax() {
	return vert2;
}

void BoundBox::shrink() {
	double tempminx = 100000, tempminy = 100000, tempminz = 100000;
	double tempmaxx = -100000, tempmaxy = -100000, tempmaxz = -100000;
	for (int i = 0; i < collection.size(); i++) {
		if (collection[i].getmin().getx() < tempminx) {
			tempminx = collection[i].getmin().getx();
		}
		if (collection[i].getmin().gety() < tempminy) {
			tempminy = collection[i].getmin().gety();
		}
		if (collection[i].getmin().getz() < tempminz) {
			tempminz = collection[i].getmin().getz();
		}
		if (collection[i].getmax().getx() > tempmaxx) {
			tempmaxx = collection[i].getmax().getx();
		}
		if (collection[i].getmax().gety() > tempmaxy) {
			tempmaxy = collection[i].getmax().gety();
		}
		if (collection[i].getmax().getz() > tempmaxz) {
			tempmaxz = collection[i].getmax().getz();
		}
	}
	vert1 = Punto(tempminx, tempminy, tempminz);
	vert2 = Punto(tempmaxx, tempmaxy, tempmaxz);
	return;
}

int BoundBox::getnumcollection() {
	return collection.size();
}

vector<BoundBox> BoundBox::split() {
	Vect v = vert2.minus(vert1);
	int largestaxis = 0;
	double laxval = v.getx();
	if (v.gety() > laxval) {
		laxval = v.gety();
		largestaxis = 1;
	}
	if (v.getz() > laxval) {
		laxval = v.getz();
		largestaxis = 2;
	}
	double newminx, newmaxx, newminy, newmaxy, newminz, newmaxz, newminx2, newmaxx2, newminy2, newmaxy2, newminz2, newmaxz2;
	newminx = vert1.getx();
	newmaxx = vert2.getx();
	newminy = vert1.gety();
	newmaxy = vert2.gety();
	newminz = vert1.getz();
	newmaxz = vert2.getz();
	newminx2 = vert1.getx();
	newmaxx2 = vert2.getx();
	newminy2 = vert1.gety();
	newmaxy2 = vert2.gety();
	newminz2 = vert1.getz();
	newmaxz2 = vert2.getz();
	if (largestaxis == 0) {
		newminx2 = laxval / 2 + vert1.getx();
		newmaxx = laxval / 2 + vert1.getx();
	}
	else if (largestaxis == 1) {
		newminy2 = laxval / 2 + vert1.gety();
		newmaxy = laxval / 2 + vert1.gety();
	}
	else {
		newminz2 = laxval / 2 + vert1.getz();
		newmaxz = laxval / 2 + vert1.getz();
	}
	vector<Obj> a, b;
	for (int i = 0; i < collection.size(); i++) {
		if (collection[i].getmin().getx() < newmaxx || collection[i].getmax().getx() > newminx) {
			if (collection[i].getmin().gety() < newmaxy || collection[i].getmax().gety() > newminy) {
				if (collection[i].getmin().getz() < newmaxz || collection[i].getmax().getz() > newminz) {
					a.push_back(collection[i]);
				}
			}
		}
		if (collection[i].getmin().getx() < newmaxx2 || collection[i].getmax().getx() > newminx2) {
			if (collection[i].getmin().gety() < newmaxy2 || collection[i].getmax().gety() > newminy2) {
				if (collection[i].getmin().getz() < newmaxz2 || collection[i].getmax().getz() > newminz2) {
					b.push_back(collection[i]);
				}
			}
		}
	}
	vector<BoundBox> splitboxes = { BoundBox(Punto(newminx, newminy, newminz), Punto(newmaxx, newmaxy, newmaxz), a), BoundBox(Punto(newminx2, newminy2, newminz2), Punto(newmaxx2, newmaxy2, newmaxz2), b) };
	return splitboxes;
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