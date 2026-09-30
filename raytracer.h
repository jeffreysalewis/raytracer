#pragma once
#include <string>
#include <vector>
#include "rayo.h"
#include "boundbox.h"

void trace();
void tracemany(bool isluzdir);
void tracemanyluz(int luz);
Rayo reflect(Rayo r);
Rayo refract(Vect i, Rayo r);
void readscene(std::string filename);
bool mediansplit(int subdivs, vector<BoundBox> bbox);