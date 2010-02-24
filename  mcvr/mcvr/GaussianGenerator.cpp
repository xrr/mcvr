#include "GaussianGenerator.h"


GaussianGenerator::GaussianGenerator(UniformGenerator* pUG) : _pUG(pUG) {}

GaussianGenerator::~GaussianGenerator(void) {}

double GaussianGenerator::Next(void) {
	return Next(0,1); 
}