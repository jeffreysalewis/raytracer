#include "triangle.h"
#include "raytracer.h"
#include <cmath>
#include <utility>
using namespace std;

Triangle::Triangle(Punto v1, Punto v2, Punto v3, double dk, double sk, double ak, Vect odd, Vect so, double kgloss, double ref) {
	vert1 = v1;
	vert2 = v2;
	vert3 = v3;
	normal = (v2.minus(v1).cross(v3.minus(v1)));
	normal.normalize();
	d = -1 * (normal.dot(Vect(v1.getx(), v1.gety(), v1.getz())));
	kd = dk;
	ks = sk;
	ka = ak;
	od = odd;
	os = so;
	kgls = kgloss;
	refl = ref;
}

Triangle::Triangle() {
	vert1 = Punto(0, 0, 0);
	vert2 = Punto(-1, -1, -1);
	vert3 = Punto(-1, 1, -1);
	kd = 0.7;
	ks = 0.2;
	ka = 0.1;
	od = Vect(1, 0, 1);
	os = Vect(-1, -1, -1);
	kgls = 16;
}

Punto Triangle::getvert1() {
	return vert1;
}

Punto Triangle::getvert2() {
	return vert2;
}

Punto Triangle::getvert3() {
	return vert3;
}

Vect Triangle::getnormal() {
	return normal;
}

double Triangle::getkd() {
	return kd;
}

double Triangle::getks() {
	return ks;
}

double Triangle::getka() {
	return ka;
}

Vect Triangle::getod() {
	return od;
}

Vect Triangle::getos() {
	return os;
}

double Triangle::getkgls() {
	return kgls;
}

bool Triangle::intersect(Rayo r) {
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

bool Triangle::intersect2(Rayo r) {
	return false;
}

Rayo Triangle::intersectray(Rayo r) {
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

		Vect theluzdir = luzdir5;
		Vect theambluz = ambluz2;

		Rayo san = Rayo(hitpoint, normal);
		san.sethit(true);
		Vect diffuse = od.multiply(kd).multiply(luzcolor).multiply(normal.dot(theluzdir));
		Vect rspec = normal.multiply((2.0 * theluzdir.dot(normal))).sub(theluzdir);
		rspec.normalize();
		Vect vspec = r.getdirection().multiply(-1.0);
		vspec.normalize();
		Vect spec = os.multiply(ks).multiply(luzcolor).multiply(pow(max(vspec.dot(rspec), 0.0), kgls));
		Vect ambient = od.multiply(theambluz.multiply(ka));
		Vect totluz = diffuse.add(spec).add(ambient);
		san.setcolor(totluz.getx(), totluz.gety(), totluz.getz());
		san.setshadow(ambient.getx(), ambient.gety(), ambient.getz());
		san.setreflect(refl);
		return san;
	}
	Rayo san = Rayo();
	san.sethit(false);
	return san;
}