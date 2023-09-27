//-----------------------------------------------------------------------
// By: Mohammed Maher Abdelrahim Mohammed
// mohammed.maher@unical.it
//
//
//
//-----------------------------------------------------------------------
#include<iostream>
#include<iomanip>
#include<cmath>
#include<complex>
#include"../include/alphas.h"
#include"../include/constants.h"
#include"../include/mathfuns.h"
#include"../include/bfklkernel.h"
#include"../include/utilities.h"
#include<fstream>

int main(void)
{
  
	BFKL_Kernel BFKL;

	Output mydataLLABFKL("../data/output_predictions/LLA_Analytic_Kernel.dat");

	int j_start = -100;
	int j_end = 100;

	for (int j = j_start; j <= j_end; ++j) {
		mydataLLABFKL.takeData << j << "\t" << std::setprecision(16) << std::real(BFKL.LLA_Kernel(1, j, 4.6,35.5)) << std::endl;
	}
 

	return 0;
 }
