/* bfklkernel.h file is part of MLiftBFKL 

usage: For χ(n, ν), φ(n, ν) and χ̄ (n, ν) functions declarations and define the BFKL kernel class.

by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          */
     
#pragma once
#ifndef BFKLKERNEL_H 
#define BFKLKERNEL_H
#include<cmath>
#include<complex>
#include <functional>
#include"alphas.h"
#include"constants.h"
#include"mathfuns.h"
 
  
double chi(int n, double nu);
double phi(int n, double nu);
std:: complex<double> chi_bar(int n, double nu);
std:: complex<double> chi_1(int n, double nu);
double aSbr(double MuR);

class BFKL_Kernel{ 

	public:     
		//double  Dlt_Y(double yH, double yJ);
		std::complex<double> LLA_Kernel(int n, double nu,double Y, double MuR);
		std::complex<double> NLA_Kernel(int n, double nu,double Y,double Q1, double Q2,double MuR);

};
#endif
