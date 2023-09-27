#include <iostream>
#include <iomanip>
#include"../include/utilities.h"
#include"../include/alphas.h"

double ProtoIF(const double& Q0, const double& q , const double& delta){
	MSbarAlphaS AlphaS;
	
	return 2.0*M_PI*AlphaS.Run(Z_BOSON_MASS,2)*sqrt(2.0*CF/CA)*(1.0+CA/CF)*std::pow((q*q)/(Q0*Q0), delta)*exp(-(q*q)/(Q0*Q0) );
}

int main() {
     
	Output mydataLLABFKL("../data/output_predictions/ProtonIF.dat");
	double q_start = 0.0;
	double q_end = 1.0;

	for (double q = q_start; q <= q_end; q=q+0.0001) {
		mydataLLABFKL.takeData << q << "\t" << ProtoIF(sqrt(0.04),q,1.4) << std::endl;
	}
	return 0;
}

