#include "DegeneratedTrajectory.h"
#include <iostream>

DegeneratedTrajectory::DegeneratedTrajectory(void) : V(1) {}

DegeneratedTrajectory::DegeneratedTrajectory(Trajectory& T) : V(1) {
	this->SetLast(T.GetLast());
}

DegeneratedTrajectory::~DegeneratedTrajectory(void) {}