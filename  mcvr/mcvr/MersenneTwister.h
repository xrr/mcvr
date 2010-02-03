#pragma once
#include "RandomGenerator.h"
#include "MersenneTwisterSource.h"


class MersenneTwister :	public RandomGenerator
{
private:
	MTRand* pMT;


public:
	MersenneTwister(void);
	~MersenneTwister(void);

	double Nextdouble(void);

};
