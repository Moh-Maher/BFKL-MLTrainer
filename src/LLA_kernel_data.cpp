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
#include<fstream>

int main(void)
{
  
	BFKL_Kernel BFKL;

	std::ofstream mydataLLABFKL;

	mydataLLABFKL.open ("input/LLA_Kernel.csv");

	mydataLLABFKL<<"n,nu,Y,MuR,LLA_Kernel"<<std::endl;

	double Y_start = 2.5;
	double Y_end = 5.5;
	double Y_step = 1.0;//0.5;

	int MUR_start = 1;
	int MUR_end = 125;
	int MUR_step = 1;

	int j_start = -100;
	int j_end = 100;

	//#pragma omp parallel for collapse(2)
	for (int n = 0; n <= 2; ++n) {
		for (int Y_int = static_cast<int>(Y_start * 10); Y_int <= static_cast<int>(Y_end * 10); Y_int += static_cast<int>(Y_step * 10)) {
			double Y = static_cast<double>(Y_int) / 10.0; // Convert back to original floating-point value
	//  #pragma omp parallel for
			for (int MUR = MUR_start; MUR <= MUR_end; MUR +=MUR_step) {
				for (int j = j_start; j <= j_end; ++j) {
					mydataLLABFKL << n << "," << j << "," << Y << "," << MUR << "," << std::setprecision(16) << std::real(BFKL.LLA_Kernel(n, j, Y, MUR)) << std::endl;

				}
			}
		}
	}

	mydataLLABFKL.close();

	return 0;
 }
