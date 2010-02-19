#include "UnitTests.h"
#include "Sample.h"
#include "Range.h"
#include "BlackScholes.h"
#include "BlackScholesSDE.h"
#include "Lognormal.h"



//output randow draws from a normal distribution
//implemented via Marsaglia method
/* ---
system("mcvr.exe")
data <- scan("mcvr.out")
hist(data)
library(nortest)
shapiro.test(data)
--- */
void UnitTests::MarsagliaGeneratorTest (unsigned N) {
	GaussianGenerator* pGG = new MarsagliaGenerator();
	Sample 

	gsl_vector* pV = gsl_vector_alloc(N);
	for (unsigned n=0; n<N; n++) {
		gsl_vector_set(pV,n,pGG->Next(5,2));
	}
	Tools::FileOut(pV);
}

//output a Wiener process to a file
/* ---
system("mcvr.exe");
plot(seq(0,500,length=5001), scan("mcvr.out"), type="l");
--- */
void UnitTests::BlackScholesSDETest (void) {
	Range* pR = new Range();
	BlackScholes* pBS = new BlackScholesSDE();
	int S = pR->steps;
	gsl_vector* pV = gsl_vector_alloc(S+1);
	gsl_vector_set(pV,0,pBS->S0);
	for (int s=1; s<=S; s++) {
		gsl_vector_set(pV,s,pBS->NextValue(pR->StepSize()));
	}
	//Tools::FileOut(pV);


}

//output the value of random draws
//following a lognormal distribution
/* ---
system("mcvr.exe")
data<-log(scan("lognormal.txt")))
hist(data)
library(nortest)
shapiro.test(data)
--- */
void UnitTests::LognormalTest (unsigned N, double T) {
	Lognormal* pL = new Lognormal();
	gsl_vector* pV = gsl_vector_alloc(N);
	for (unsigned n=0; n<N; n++) {
		gsl_vector_set(pV,n,pL->Value(T));
	}
	Tools::FileOut(pV);

	Trajectory DT = Trajectory(N);
	DT << pV;
	std::cout << DT;
}