#include "texture.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

Texture::Texture() {
	color = Vect();
}

Texture::Texture(vector<vector<Vect>> i) {
	color = Vect();
	img = i;
}

Vect Texture::getcolor(double u, double v) {
	int y = img.size();
	int x = img[0].size();
	return img[(int)(v * y)][(int)(u * x)];
}