#pragma once
#include "Payoff.h"

class LookbackPut :
	public Payoff
{
public:
	double K;
	LookbackPut(double=90);
	~LookbackPut(void);
	double operator()(Trajectory*);
};