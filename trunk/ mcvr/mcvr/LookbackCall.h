#pragma once
#include "Payoff.h"

class LookbackCall :
	public Payoff
{
public:
	double K;
	LookbackCall(double=110);
	~LookbackCall(void);
	double operator()(Trajectory*);
};