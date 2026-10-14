#include "texture.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

Texture::Texture() {
	color = Vect();
	Vect black = Vect(0.1, 0.1, 0.1);
	Vect red = Vect(0.8, 0.1, 0.1);

	img = { {black, red, black, red, black, red, black, red}, {red, black, red, black, red, black, red, black}, {black, red, black, red, black, red, black, red}, {red, black, red, black, red, black, red, black}, {black, red, black, red, black, red, black, red}, {red, black, red, black, red, black, red, black}, {black, red, black, red, black, red, black, red}, {red, black, red, black, red, black, red, black} };
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