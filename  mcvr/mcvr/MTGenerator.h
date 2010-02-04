#pragma once
#include "RandomGenerator.h"
#include "MersenneTwisterSource.h"

class MTGenerator :	public RandomGenerator
{
	MTRand* pMT;
public:
	MTGenerator(void);
	~MTGenerator(void);
	double Next(void);

};
