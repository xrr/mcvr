#pragma once
#include "UniformGenerator.h"
#include "MersenneTwisterSource.h"

class MersenneTwisterGenerator :
	public UniformGenerator
{
	MTRand* _pMTR;
public:
	MersenneTwisterGenerator(void);
	~MersenneTwisterGenerator(void);
	double Next(void);

};
