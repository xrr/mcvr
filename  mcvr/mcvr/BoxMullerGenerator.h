#pragma once
#include "GaussianGenerator.h"
#include "UniformGenerator.h"

class BoxMullerGenerator :
	public GaussianGenerator
{
	bool _cached;
	double _cache;
public:
	BoxMullerGenerator(void);
	BoxMullerGenerator(UniformGenerator*);
	~BoxMullerGenerator(void);
	double Next(double, double);
};