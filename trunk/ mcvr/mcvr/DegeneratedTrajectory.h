#pragma once
#include "V.h"
#include "Trajectory.h"

class DegeneratedTrajectory :
	public V
{
public:
	DegeneratedTrajectory(void);
	DegeneratedTrajectory(Trajectory&);
	~DegeneratedTrajectory(void);
};
