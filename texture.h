#pragma once
#include "vect.h"
#ifndef TEXTURE_H
#define TEXTURE_H

class Texture
{
private:
	Vect color;
public:
	Texture();
	Vect getcolor(double u, double v);
};
#endif
