#pragma once
#include "GaussianGenerator.h"
#include "BoxMullerGenerator.h"

class BlackScholes
{
protected:
	GaussianGenerator* _pGG;
	double _T;
public:
	double S0, sigma, mu;
	BlackScholes(double=100, double=0.2, double=0.05, GaussianGenerator* = new BoxMullerGenerator());
	~BlackScholes(void);
	void AdjustRates(void);
	virtual double NextValue(double)=0;
	double GetT(void);
	virtual void Reset(void);
};
