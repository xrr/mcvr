#pragma once
#include "BlackScholes.h"
#include "GaussianGenerator.h"

class BlackScholesSDE :
	public BlackScholes
{
	double _Wt;
	double _S;

public:
	BlackScholesSDE(double, double, double, GaussianGenerator*);
	BlackScholesSDE(void);
	~BlackScholesSDE(void);
	double NextValue(double=0.1);
	void Reset(void);
};