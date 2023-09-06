/*constants.h is a part of MLiftBFKL 

usage: define some Physical and mathematical fundamental constants.

by:  Mohammed Maher Abdelrahim Mohammed
                                          */
     
#pragma once
#ifndef CONSTANTS_H
#define CONSTANTS_H
//#include<cmath>
/*=============================================================
                      Mathematical constants
=============================================================*/
const double ZETA_2 = M_PI*M_PI/6.;
//const double ZETA_2 = 1.6449340668482262;
const double ZETA_3 = 1.2020569031595942;
const double ZETA_4 = (pow(M_PI,4))/90.;
const double ZETA_5 = 1.0369277551433699;
const double GAMMA_E = 0.5772156649015329;
/*=============================================================
                      Physical constants
=============================================================*/
const double SPEED_OF_LIGHT = 299792458;            ///< PDG2008
const double PLANCK_CONSTANT = 6.62606896 * 1.e-34; ///< PDG2009
const double PLANCK_CONSTANT_REDUCED = 6.58211899 * 1.e-16;
const double FINE_STRUCTURE_CONSTANT = 1. / 137.035999679; ///< PDG2008
const double HIGGS_VEV = 246.22; ///< Higgs vacuum expectation value
/*=============================================================
                       Units convertors
=============================================================*/
const double HBarC = 197.3269631;                           ///< Conversion constant \f$\hbar c\f$ in \f$\mathrm{MeV}\cdot\mathrm{fm}\f$ @cite Amsler:2008zzb
const double HBarC2 = 0.389379304;                          ///< Conversion constant \f$(\hbar c)^2\f$ in \f$\mathrm{GeV}^2\cdot\mathrm{mbarn}\f$ @cite Amsler:2008zzb
const double CONV_GEVm1_TO_FM = 0.1973269631;               ///< Conversion constant \f$\mathrm{GeV}^{-1} \rightarrow \mathrm{fm}\f$.
const double CONV_GEVm2_TO_NBARN = 0.389379304e+6;          ///< Conversion constant \f$\mathrm{GeV}^{-2} \rightarrow \mathrm{nbarn}\f$.
const double CONV_GEVm2_TO_PBARN = 0.389379304e+9;          ///< Conversion constant \f$\mathrm{GeV}^{-2} \rightarrow \mathrm{pbarn}\f$.
/*=============================================================
                       QCD Parameters
=============================================================*/
//static int NF;
int const CA = 3;
//double CF = (CA*CA-1.)/(2*CA);
double const CF = 4./3.; 
const double TR = 0.5;
//static double BETA0 = 11.-2./3.*double(NF);
//static double BETA1 = 102.-38./3.*double(NF);
 

//static long double LAM_QCD;
long double const LAM3 = 0.3539245833714988;  ///< valid only for NF=3
long double const LAM4 = 0.30908371650324706; ///< valid only for NF=4
long double const LAM5 = 0.2146647485471248;  ///< valid only for NF=5
long double const LAM6 = 0.08652227263650401; ///< valid only for NF=6

//static double BLMT_BETA, BLMT ;
const double BLMI = 2.3439;
const double BLMT_CONF = (CA/8.)*17./2.*BLMI; //after set zi = 0 in: (CA/8.)*17./2.*BLMI +3./2.(BLMI-1.)*zi + (1.-1./3.*BLMI)*pow(zi,2) - 1./6.*pow(zi,3)
/*=============================================================
                        Particle masses
==============================================================*/
const double PROTON_MASS = 0.938272013;            ///< PDG2010

const double ELECTRON_MASS = 0.510998910e-3;       ///< PDG2008
const double MUON_MASS = 105.658367e-3;            ///< PDG2008
const double TAU_MASS = 1.77684;                   ///< PDG2008

const double QUARK_UP_MASS = 0.0024;                ///< PDG2010
const double QUARK_DOWN_MASS = 0.0049;              ///< PDG2010
const double QUARK_STRANGE_MASS = 0.1;              ///< PDG2010
const double QUARK_CHARM_MASS = 1.29;               ///< PDG2010
const double QUARK_BOTTOM_MASS = 4.19;              ///< PDG2010
const double QUARK_TOP_MASS = 173.21;           //172.9;  PDG2010

const double PI_ZERO_MASS = 0.1349766;              ///< PDG2010

const double W_BOSON_MASS = 80.1;
const double Z_BOSON_MASS = 91.1876;                ///< PDG2010
const double HIGGS_BOSON_MASS= 125.18 ;
/*============================================================= 
                     Particle electric charges
============================================================*/
const double U_ELEC_CHARGE = 2. / 3.; ///< Electric charge of up quark (in units of e)
const double D_ELEC_CHARGE = -1. / 3.;
const double S_ELEC_CHARGE = -1. / 3.;
const double C_ELEC_CHARGE = 2. / 3.;
const double B_ELEC_CHARGE = -1. / 3.;
const double T_ELEC_CHARGE = 2. / 3.;

const double U2_ELEC_CHARGE = 4. / 9.; ///< Square of electric charge of up quark
const double D2_ELEC_CHARGE = 1. / 9.; ///< Square of electric charge of down quark
const double S2_ELEC_CHARGE = 1. / 9.; ///< Square of electric charge of strange quark
const double C2_ELEC_CHARGE = 4. / 9.; ///< Square of electric charge of charm quark
const double B2_ELEC_CHARGE = 1. / 9.; ///< Square of electric charge of bottom quark
const double T2_ELEC_CHARGE = 1. / 9.; ///< Square of electric charge of top quark

const double POSITRON_CHARGE = 0.30282211985966434;

#endif /* FUNDAMENTAL_PHYSICAL_CONSTANTS_H */
