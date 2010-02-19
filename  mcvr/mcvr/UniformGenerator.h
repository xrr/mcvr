#pragma once
#include "RandomGenerator.h"


class UniformGenerator :
	public RandomGenerator
{
public:
	UniformGenerator(void) {};
	~UniformGenerator(void) {};
	virtual double Next(void)=0;
};
