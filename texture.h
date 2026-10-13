#pragma once
#include "vect.h"
#include <vector>
#ifndef TEXTURE_H
#define TEXTURE_H

using namespace std;

class Texture
{
private:
	Vect color;
	vector<vector<Vect>> img;
public:
	Texture();
	Texture(vector<vector<Vect>> i);
	Vect getcolor(double u, double v);
};
#endif
