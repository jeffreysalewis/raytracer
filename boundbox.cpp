#include "boundbox.h"
#include "raytracer.h"
#include "triangle.h"
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
	if (tempminz > 0.95) {
		tempminz = 0.95;
	}
	if (tempmaxz > 0.99) {
		tempmaxz = 0.98;
	}
	vert1 = Punto(tempminx, tempminy, tempminz);
	vert2 = Punto(tempmaxx, tempmaxy, tempmaxz);
	return;
}

int BoundBox::getnumcollection() {
	return collection.size();
}

vector<Obj> BoundBox::getcollection() {
	return collection;
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
	Punto p1, p2, p3, p4, p5, p6, p7, p8;
	p1 = vert1; //far bottom left
	p2 = Punto(vert1.getx(), vert1.gety(), vert2.getz()); //near bottom left
	p3 = Punto(vert1.getx(), vert2.gety(), vert1.getz()); //far top left
	p4 = Punto(vert1.getx(), vert2.gety(), vert2.getz()); //near top left
	p5 = Punto(vert2.getx(), vert1.gety(), vert1.getz()); //far bottom right
	p6 = Punto(vert2.getx(), vert1.gety(), vert2.getz()); //near bottom right
	p7 = Punto(vert2.getx(), vert2.gety(), vert1.getz()); //far top right
	p8 = vert2; //near top right
	Triangle t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12;
	t1 = Triangle(p1, p2, p3); //left face
	t2 = Triangle(p3, p2, p4); //left face
	t3 = Triangle(p1, p5, p3); //dont need back face
	t4 = Triangle(p5, p7, p3); //dont need back face
	t5 = Triangle(p2, p1, p5); //bottom face
	t6 = Triangle(p6, p2, p5); //bottom face
	t7 = Triangle(p8, p3, p4); //top face
	t8 = Triangle(p8, p7, p3); //top face
	t9 = Triangle(p8, p5, p7); //right face
	t10 = Triangle(p8, p6, p5); //right face
	t11 = Triangle(p4, p6, p2); //front face
	t12 = Triangle(p8, p4, p6); //front face
	return true;
	if (t12.intersect(r)) {
		return true;
	}
	if (t11.intersect(r)) {
		return true;
	}
	if (t10.intersect(r)) {
		return true;
	}
	if (t9.intersect(r)) {
		return true;
	}
	if (t2.intersect(r)) {
		return true;
	}
	if (t1.intersect(r)) {
		return true;
	}
	if (t8.intersect(r)) {
		return true;
	}
	if (t7.intersect(r)) {
		return true;
	}
	if (t6.intersect(r)) {
		return true;
	}
	if (t5.intersect(r)) {
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