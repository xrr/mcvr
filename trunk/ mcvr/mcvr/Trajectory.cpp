#include "Trajectory.h"
#include "DegeneratedTrajectory.h"

Trajectory::Trajectory(unsigned size) : V(size) {}

Trajectory::~Trajectory(void) {}

Trajectory::operator DegeneratedTrajectory() {
	DegeneratedTrajectory DT;
	DT.SetLast(GetLast());
	return DT;
}
