#pragma once
#include "RandomGenerator.h"
#include "MTGenerator.h"

class NormalGenerator :
	public RandomGenerator
{
	RandomGenerator* _pRG;
	bool _cached;
	double _cache;
public:
	NormalGenerator(RandomGenerator* = new MTGenerator());
	~NormalGenerator(void);
	double Next(void);
	double Next(double=0, double=1);
};