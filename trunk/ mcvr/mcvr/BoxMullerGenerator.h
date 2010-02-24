#pragma once
#include "GaussianGenerator.h"
#include "UniformGenerator.h"

class BoxMullerGenerator :
	public GaussianGenerator
{
	bool _cached;
	double _cache;
	void Init(void);
public:
	BoxMullerGenerator(void);
	BoxMullerGenerator(UniformGenerator*);
	~BoxMullerGenerator(void);
	double Next(double, double);
};