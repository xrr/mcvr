#pragma once
#include "UniformGenerator.h"
#include <math.h>



class LinearCongruentialGenerator:
	public UniformGenerator
{
	long _x,_a,_c,_m;
public:
	LinearCongruentialGenerator(long=0,long=1103,long=12345,long=pow((double)2,(int)15));
	~LinearCongruentialGenerator(void);
	double Next(void);
};
