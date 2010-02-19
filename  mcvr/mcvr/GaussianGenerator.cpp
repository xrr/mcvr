#include "GaussianGenerator.h"


GaussianGenerator::GaussianGenerator(UniformGenerator* pUG) : _pUG(pUG) {}
GaussianGenerator::~GaussianGenerator(void) {}

//également possible de faire l'inverse...
//1) définir Next(void)
//2) définir Next(double, double) relativement à Next(void) 

double GaussianGenerator::Next(void) {
	return Next(0,1); 
}
