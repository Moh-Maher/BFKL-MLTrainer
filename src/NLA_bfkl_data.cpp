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

	Output mydataNLABFKL("../data/output_predictions/NLA_Analytic_Kernel.dat");
	int n = 0;
	double Y = 5.5;
	double MUR = 65.0;

	int j_start = -10;
	int j_end = 10;

	for (int j = j_start; j <= j_end; ++j) {
		if(j==0){continue;}               
		else{
			mydataNLABFKL.takeData << j << "\t" << std::setprecision(16) << std::real(BFKL.NLA_Kernel(n, j, Y ,MUR, MUR, MUR*MUR))<<std::endl;
		}
	}
 

	return 0;
 }
