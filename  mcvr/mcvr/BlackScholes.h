#pragma once
#include "NormalGenerator.h"

class BlackScholes
{
	NormalGenerator* _pNG;
public:
	double S0, sigma, mu;
	BlackScholes(double=100, double=0.2, double=0.05, NormalGenerator* = new NormalGenerator());
	~BlackScholes(void);
	double ClosedFormula(double=1);
};
