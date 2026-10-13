#include "texture.h"
#include <iostream>
#include <fstream>

Texture::Texture() {
	color = Vect();
}

Vect Texture::getcolor(double u, double v) {
	return color;
}