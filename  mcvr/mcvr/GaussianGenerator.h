#pragma once
#include "RandomGenerator.h"
#include "UniformGenerator.h"
#include "MersenneTwisterGenerator.h"

class GaussianGenerator :
	public RandomGenerator
{
protected:
	UniformGenerator* _pUG;
public:
	GaussianGenerator(UniformGenerator* = new MersenneTwisterGenerator());
	~GaussianGenerator(void);
	double Next(void);
	virtual double Next(double, double)=0;
};