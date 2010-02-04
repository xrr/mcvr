#include "Range.h"
#include "MonteCarlo.h"
#include "Functors.h"
#include "FunctorOps.h"

#include <gsl/gsl_math.h>

#include <iostream>
#include <vector>




int main() {

	Range r (-4,5);

	FunctorD1 pdf1;
	MonteCarlo<FunctorD1> mc1 (pdf1,r);

	std::cout << "D1(D1(3)): " << apply2x(pdf1, 3) << std::endl;
	std::cout << mc1.GetRange() << std::endl;
	

	FunctorGauss pdfgauss (2,3);
	MonteCarlo<FunctorGauss> mcgauss (pdfgauss,r);

	std::cout << "Result before Sim: " << mcgauss.GetResult() << std::endl;
	mcgauss.RunSim(1000);
	std::cout << "Resultat after Sim: " << mcgauss.GetResult() << std::endl;
	
	std::cout << "N(2,3)(2): " << apply(pdfgauss,2) << std::endl;

	system("pause");
	return 0;

}