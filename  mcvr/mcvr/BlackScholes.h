#pragma once
#include "GaussianGenerator.h"
#include "MarsagliaGenerator.h"
#include "GSLGaussianGenerator.h"

class BlackScholes
{
protected:
	GaussianGenerator* _pGG;
	double _T;
public:
	double S0, sigma, mu;
	BlackScholes(double=100, double=0.2, double=0.05, GaussianGenerator* = new MarsagliaGenerator());
	~BlackScholes(void);
	virtual double NextValue(double=0.1)=0;
	double GetT(void);
	virtual void Reset(void);
};
