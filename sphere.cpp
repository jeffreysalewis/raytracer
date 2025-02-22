#include "sphere.h"
#include <cmath>

Sphere::Sphere(Punto c, double r, double dk, double sk, double ak, Vect odd, Vect so, double kgloss) {
	center = c;
	radius = r;
	kd = dk;
	ks = sk;
	ka = ak;
	od = odd;
	os = so;
	kgls = kgloss;
}

Sphere::Sphere() {
	center = Punto(0, 0, 0);
	radius = 0.4;
	kd = 0.7;
	ks = 0.2;
	ka = 0.1;
	od = Vect(1, 0, 1);
	os = Vect(1, 1, 1);
	kgls = 16;
}

Punto Sphere::getcenter() {
	return center;
}

double Sphere::getradius() {
	return radius;
}

double Sphere::getkd() {
	return kd;
}

double Sphere::getks() {
	return ks;
}

double Sphere::getka() {
	return ka;
}

Vect Sphere::getod() {
	return od;
}

Vect Sphere::getos() {
	return os;
}

double Sphere::getkgls() {
	return kgls;
}

bool Sphere::intersect(Rayo r) {
	Vect oc = center.minus(r.getorigin());
	double tca = r.getdirection().dot(oc);
	double oclen = oc.getlen();
	bool inside = oclen < radius;
	if (inside) {
		return true;
	}
	if (!inside && tca < 0) {
		return false;
	}
	double thc2 = (radius * radius) - (oclen * oclen) + (tca * tca);
	if (thc2 < 0) {
		return false;
	}
	double t = tca - sqrt(thc2);
	return true;
}

bool Sphere::intersect2(Rayo r) {
	double xo = r.getorigin().getx();
	double yo = r.getorigin().gety();
	double zo = r.getorigin().getz();
	/*xo = 0;
	yo = 0;
	zo = 1;*/
	double xd = r.getdirection().getx();
	double yd = r.getdirection().gety();
	double zd = r.getdirection().getz();
	/*xd = 0;
	yd = 0;
	xd = -1;*/
	double xc = center.getx();
	double yc = center.gety();
	double zc = center.getz();
	double b = 2 * (xd*xo - xd*xc + yd*yo - yd*yc + zd*zo - zd*zc);
	double c = xo*xo - 2*xo*xc + xc*xc + yo*yo - 2*yo*yc + yc*yc + zo*zo - 2*zo*zc + zc*zc - radius*radius;
	double discriminant = b * b - 4 * c;
	if (discriminant < 0) {
		return false;
	}
	return true;
}

Rayo Sphere::intersectray(Rayo r) {
	Vect oc = center.minus(r.getorigin());
	double tca = r.getdirection().dot(oc);
	double oclen = oc.getlen();
	bool inside = oclen < radius;
	if (inside) {
		Rayo fal = Rayo();
		fal.sethit(true);
		return fal;
	}
	if (!inside && tca < 0) {
		Rayo fal = Rayo();
		fal.sethit(false);
		return fal;
	}
	double thc2 = (radius * radius) - (oclen * oclen) + (tca * tca);
	if (thc2 < 0) {
		Rayo fal = Rayo();
		fal.sethit(false);
		return fal;
	}
	double t = tca - sqrt(thc2);
	Punto hitpoint = Punto(r.getorigin().getx() + r.getdirection().getx()*t, r.getorigin().gety() + r.getdirection().gety() * t, r.getorigin().getz() + r.getdirection().getz() * t);
	Vect hitnormal = Vect((hitpoint.getx() - center.getx())/radius, (hitpoint.gety() - center.gety()) / radius, (hitpoint.getz() - center.getz()) / radius);
	Rayo fal = Rayo(hitpoint, hitnormal);
	fal.sethit(true);
	return fal;
}