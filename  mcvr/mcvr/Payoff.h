#pragma once
#include "Trajectory.h"

class Payoff
{
public:
	Payoff(void) {};
	~Payoff(void) {};
	virtual double operator()(Trajectory*)=0;
};
