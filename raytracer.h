#pragma once
#include <string>
//#include <vector>
#include "rayo.h"
#include "boundbox.h"
#include "texture.h"
//using std::vector;
//using namespace std;

void trace();
void tracemany(bool isluzdir);
void tracemanyluz(int luz);
void pathtrace();
Rayo diffuse(Rayo r);
Rayo reflect(Rayo r1, Rayo r2);
Rayo refract(Vect i, Rayo r);
void readscene(std::string filename);
Texture readtexture(string filename);
bool mediansplit(int subdivs, int bboxind);