#include "Tests.h"

#include "Pipe.h"
#include "Chrono.h"
#include "V.h"
#include "Sample.h"
#include "Range.h"
#include "UniformGenerator.h"
#include "LinearCongruentialGenerator.h"
#include "MersenneTwisterGenerator.h"
#include "BoxMullerGenerator.h"
#include "MarsagliaGenerator.h"
#include "BlackScholes.h"
#include "BlackScholesSDE.h"
#include "Lognormal.h"
#include "Payoff.h"
#include "PathIndependantPayoff.h"
#include "Call.h"
#include "Put.h"
#include "LookbackCall.h"
#include "LookbackPut.h"
#include "ParisianCall.h"
#include "ParisianPut.h"
#include "ParasianCall.h"
#include "ParasianPut.h"
#include "MonteCarlo.h"
#include "QuickMonteCarlo.h"

#include <iostream>
#include <fstream>

void Tests::VTest(void) {
	V v1(5);
	V* pv1 = &v1;
	for (unsigned i=0; i<v1.Size(); i++)
		v1.Set(i,2*(i+1));
	pv1->SetLast(10.5);
	pv1->Push(12);
	V v2(0);
	v2 = (*pv1);
	pv1->SetLast(12.5);
	std::cout << v2 << std::endl;
	//should display "2,4,6,8,10.5,12"
}

void Tests::SampleTest(void) {
	Sample s(0);
	s.Push(3);s.Push(5);s.Push(100);
	std::cout << "Sample: " << std::endl << s << std::endl;
	std::cout << "Mean: " << s.Mean() << std::endl;
	std::cout << "MeanSq: " << s.MeanSq() << std::endl;
	std::cout << "Variance: " << s.Variance() << std::endl;
	std::cout << "Variance (unbiased): " << s.VarianceCorrected() << std::endl;
}

void Tests::BaseTests(void) {
	{Pipe p("_out-base-v.txt");
	Tests::VTest();}

	{Pipe p("_out-base-sample.txt");
	Tests::SampleTest();}
}

void Tests::LinearCongruentialGeneratorTest(unsigned N) {
	UniformGenerator* pUG = new LinearCongruentialGenerator();
	Sample s(N);
	for (unsigned n=0; n<N; n++)
		s.Set(n,pUG->Next());
	delete pUG;
	std::cout << s;
}

void Tests::MersenneTwisterGeneratorTest(unsigned N) {
	UniformGenerator* pUG = new MersenneTwisterGenerator();
	Sample s(N);
	for (unsigned n=0; n<N; n++)
		s.Set(n,pUG->Next());
	delete pUG;
	std::cout << s;
}

void Tests::BoxMullerGeneratorTest(unsigned N) {
	double mu = 5;
	double sigma = 2;
	GaussianGenerator* pGG = new BoxMullerGenerator();
	Sample s(N);
	for (unsigned n=0; n<N; n++)
		s.Set(n,pGG->Next(mu,sigma));
	delete pGG;
	std::cout << s;
}

void Tests::MarsagliaGeneratorTest(unsigned N) {
	double mu = 5;
	double sigma = 2;
	GaussianGenerator* pGG = new MarsagliaGenerator();
	Sample s(N);
	for (unsigned n=0; n<N; n++)
		s.Set(n,pGG->Next(mu,sigma));
	delete pGG;
	std::cout << s;
}

void Tests::MillionGaussSpeedTest(unsigned I) {
	unsigned N = 1000000;
	double mu = 0;
	double sigma = 1;
	Sample s(N);
	GaussianGenerator* pGG1 = new BoxMullerGenerator();
	GaussianGenerator* pGG2 = new MarsagliaGenerator();
	for (unsigned i=0; i<I; i++) {
		{Chrono c1;
		for (unsigned n=0; n<N; n++)
			s.Set(n,pGG1->Next(mu,sigma));}
		{Chrono c2;
		for (unsigned n=0; n<N; n++)
			s.Set(n,pGG2->Next(mu,sigma));}
	}
	delete pGG1, pGG2;
}

void Tests::RNGTests(void) {
	{Pipe p("_out-rng-lc.txt");
	Tests::LinearCongruentialGeneratorTest();}
	{Pipe p("_out-rng-mt.txt");
	Tests::MersenneTwisterGeneratorTest();}
	{Pipe p("_out-rng-boxmu.txt");
	Tests::BoxMullerGeneratorTest();}
	{Pipe p("_out-rng-marsa.txt");
	Tests::MarsagliaGeneratorTest();}
	{Pipe p("_out-rng-million.txt");
	Tests::MillionGaussSpeedTest();}
}

void Tests::LognormalTest(unsigned N) {
	double T = 50;
	Lognormal* pL = new Lognormal();
	Sample s(N);
	for (unsigned n=0; n<N; n++)
		s.Set(n,pL->Value(T));
	std::cout << s;
	delete pL;
}

void Tests::BlackScholesSDETest(void) {
	Range* pR = new Range(0,100,1000);
	GaussianGenerator* pGG = new BoxMullerGenerator();
	BlackScholesSDE* pBS = new BlackScholesSDE(100,0.2,0.05, pGG);
	unsigned S = pR->steps;
	double dt = pR->StepSize();
	Trajectory T(S+1);
	T.Set(0,pBS->S0);
	for (unsigned s=1; s<=S; s++)
		T.Set(s,pBS->NextValue(dt));
	std::cout << T;
	delete pBS, pGG, pR;
}

void Tests::BSTests(void) {
	{Pipe p("_out-bs-lnorm.txt");
	Tests::LognormalTest();}
	{Pipe p("_out-bs-sde.txt");
	Tests::BlackScholesSDETest();}
}

void Tests::PayoffTest(Payoff* pP, const char* c) {
	Trajectory* pT = new Trajectory(0);
	c >> (*pT);
	std::cout << (*pP)(pT) << std::endl;
	delete pT;
}

void Tests::PayoffTests(void) {
	const char* fc = "_in-payoff-c.txt";
	const char* fp = "_in-payoff-p.txt";

	Pipe p("_out-payoff-all.txt");

	std::cout << "Call: "; Tests::PayoffTest(&Call(),fc);
	std::cout << "Lookback Call: "; Tests::PayoffTest(&LookbackCall(),fc);
	std::cout << "Parisian Call: "; Tests::PayoffTest(&ParisianCall(),fc);
	std::cout << "Parasian Call: "; Tests::PayoffTest(&ParasianCall(),fc);
	std::cout << std::endl;

	std::cout << "Put: "; Tests::PayoffTest(&Put(),fp);
	std::cout << "Lookback Put: "; Tests::PayoffTest(&LookbackPut(),fp);
	std::cout << "Parisian Put: "; Tests::PayoffTest(&ParisianPut(),fp);
	std::cout << "Parasian Put: "; Tests::PayoffTest(&ParasianPut(),fp);
	std::cout << std::endl;
}

void Tests::MonteCarloTest(void) {

	Range* pR = new Range(0,10,100);
	UniformGenerator* pUG = new MersenneTwisterGenerator();
	GaussianGenerator* pGG = new BoxMullerGenerator(pUG);
	BlackScholesSDE* pSDE = new BlackScholesSDE(100, 0.2, 0.05, pGG);
	Lognormal* pLN = new Lognormal(100, 0.2, 0.05, pGG);
	PathIndependantPayoff* pPIP = new Put(105);
	Payoff* pP = pPIP;
	
	MonteCarlo* pMC = new MonteCarlo(pR,pSDE,pP);
	QuickMonteCarlo* pQMC = new QuickMonteCarlo(pR,pLN,pPIP);

	int n = 10000;

	std::cout << "--- Monte Carlo ---" << std::endl;
	{Chrono c(1,1);
	pMC->Run(n);
	}
	std::cout << std::endl;
	std::cout << "--- Quick Monte Carlo ---" << std::endl;
	{Chrono c(1,1);
	pQMC->Run(n);
	}

	delete pMC, pQMC, pPIP, pP, pLN, pSDE, pGG, pUG, pR;
}

void Tests::MCTests(void) {
	{Pipe p("_out-mc.txt");
	Tests::MonteCarloTest();}
}