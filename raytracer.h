#pragma once
#include <string>
#include "rayo.h"

void trace();
void tracemany(bool isluzdir);
Rayo reflect(Rayo r);
Rayo refract(Rayo r);
void readscene(std::string filename);