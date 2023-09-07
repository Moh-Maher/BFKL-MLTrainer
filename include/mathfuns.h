/* function.h is a part of PARTON-x 

by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          */
#pragma once
#ifndef INCLUDE_FUNCTIONS_H
#define INCLUDE_FUNCTIONS_H
//#include<cmath>
#include<iostream>
#include<cmath>
#include<complex>
//#include <stdio.h>
#include <vector>
#include<algorithm> // needed for Brent method to finding roots
#include<functional> // needed for Brent method to finding roots
//#include"phys_conts.h"
#include <complex>

// Functions prototypes and declarations
   
double Repsi(std::complex<double> z);
double Impsi(std::complex<double> z);

std::complex<double>Gamma(std::complex<double> z);
std::complex<double>PSI(std::complex<double> z);
std::complex<double>dpsi(std::complex<double> z);
std::complex<double>d2psi(std::complex<double> z);

std::complex<double>mastar_I1(double g1, double g2, int n, double nu, double pH, double phi_H, double epsilon);
double kdelta(int i, int j);
double brents_fun(std::function<double (double)> f, double lower_bound, double upper_bound, double TOL, double MAX_ITER);
//double Xfrc(double P, double scl, double S);
/*
double Pgq(double z);
double Pqg(double z);
double Pqq(double z);
double Pgg(double z);
*/
#endif
