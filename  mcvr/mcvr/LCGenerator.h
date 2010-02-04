#pragma once
#include "RandomGenerator.h"
#include <math.h>



class LCGenerator:public RandomGenerator {
	long _x,_a,_c,_m;
public:
	LCGenerator(long=0,long=1103,long=12345,long=pow((double)2,(int)15));
	~LCGenerator(void);
	double Next(void);
};
