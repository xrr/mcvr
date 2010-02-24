#pragma once
#include "GaussianGenerator.h"
#include "UniformGenerator.h"

class MarsagliaGenerator :
	public GaussianGenerator
{
	bool _cached;
	double _cache;
	void Init(void);
public:
	MarsagliaGenerator(void);
	MarsagliaGenerator(UniformGenerator*);
	~MarsagliaGenerator(void);
	double Next(double, double);
};