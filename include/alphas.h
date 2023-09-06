 
#ifndef ALPHAS_H
#define ALPHAS_H
#include<iostream>
#include<cmath>
#include"constants.h"
#include"mathfuns.h"

class RunningCoupling{
	public:
		unsigned int NumberOfActiveQuarks(const double& energy_scale);
		double SetBeta0(const unsigned& nf );
		double SetBeta1(const unsigned& nf );
		double SetBeta2(const unsigned& nf );
		double SetBeta3(const unsigned& nf );
		double LambdaQCD(const unsigned& nf);
		virtual double ComputedLambdaQCD(const unsigned& nf);
		virtual double Run(const double& energy_scale, const unsigned int& loopNum)=0;
		double als(const double& MUR, const double& LAM, const unsigned int& NF);
	protected:
		unsigned int _nf;
		double  LAM_QCD;
		double _almZ = 0.118;
		double _beta0=0;
		double _beta1=0;
		double _beta2=0;
		double _beta3=0;
};

class MSbarAlphaS: public RunningCoupling{
	public:
		double Run(const double& energy_scale, const unsigned int& loopNum);
		double Run2(const double& energy_scale, const unsigned int& loopNum);
		double ComputedLambdaQCD(const unsigned& nf);
};

class MOMAlphaS: public MSbarAlphaS{
	public:
		double Run(const double& energy_scale, const unsigned int& loopNum);
		double Run2(const double& energy_scale, const unsigned int& loopNum);
		double ComputedLambdaQCD(const unsigned& nf);
		double SetBeta2(const unsigned& nf );
		double SetBeta3(const unsigned& nf );

	protected:
		double _mombeta2=0;
		double _mombeta3=0;
};
#endif // end of ALPHAS_H
