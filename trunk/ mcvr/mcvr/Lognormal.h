#pragma once
#include "BlackScholes.h"

class Lognormal :
	public BlackScholes
{
public:
	Lognormal(void);
	~Lognormal(void);
	double Value(double);
	double NextValue(double);
};
