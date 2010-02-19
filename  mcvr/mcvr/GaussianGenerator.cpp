#include "GaussianGenerator.h"


GaussianGenerator::GaussianGenerator(UniformGenerator* pUG) : _pUG(pUG) {}
GaussianGenerator::~GaussianGenerator(void) {}

//�galement possible de faire l'inverse...
//1) d�finir Next(void)
//2) d�finir Next(double, double) relativement � Next(void) 

double GaussianGenerator::Next(void) {
	return Next(0,1); 
}
