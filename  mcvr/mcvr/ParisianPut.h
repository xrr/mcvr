#pragma once
#include "Payoff.h"

class ParisianPut :
	public Payoff
{
public:
	double K, B, L;
	ParisianPut(double=90, double=70, double=50);
	~ParisianPut(void);
	double operator()(Trajectory*);
};