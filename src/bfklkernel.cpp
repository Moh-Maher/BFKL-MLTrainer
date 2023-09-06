/*-------------------------------------------------------------------------------------------------------------------------------------------
*  
*  BFKL_KERNEL: Strongly depends on χ(n, ν), φ(n, ν) and χ̄ (n, ν) functions which are defined in "Functions_sources.cpp" file.
* 
*  ‪Information: 
*  calculate the BFKL kernel for fixed rapidity gap (Y) at leading-logarithmic-approximation (LLA) and next-to-leading one (NLA).
*   
*  
*
*
* Author: Mohammed Maher Abdelrahim Mohammed
*         UNIVERSITÀ DELLA NLABRIA, DIPARTIMENTO DI FISIN AND INFN-COSENZA
*         VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
*         mohammed.maher@uniNl.it
*
*-------------------------------------------------------------------------------------------------------------------------------------------*/
//#include<iomanip>
#include"../include/bfklkernel.h"
 
int nf=5;
double BETA0 = 11.-2./3.*nf;
double BETA1 = 102.-38./3.*nf;
/*-----------------------------------------------------------------------
                    Theoretical Rapidity gap 
-----------------------------------------------------------------------*/
/*  
double  BFKL_Kernel::Dlt_Y(double yH, double yJ){
	return abs(yH -yJ);
}*/
/*-----------------------------------------------------------------------
                              alphaS bar 
-----------------------------------------------------------------------*/
double aSbr(double MuR){
	MSbarAlphaS AlphaS;
	return CA/M_PI*AlphaS.Run(MuR,2);
}
/*-----------------------------------------------------------------------
                    BFKL Kernel at leading order 
-----------------------------------------------------------------------*/
std::complex<double> BFKL_Kernel::LLA_Kernel(int n, double nu, double Y, double MuR)
{       
       return exp(Y*aSbr(MuR)*chi(n,nu));
}
/*-----------------------------------------------------------------------
                    BFKL Kernel at Next-to-leading order 
-----------------------------------------------------------------------*/
std::complex<double> BFKL_Kernel::NLA_Kernel(int n, double nu, double Y, double Q1, double Q2 ,double MuR)
{           
	return (exp((Y)*aSbr(MuR)*(chi(n,nu) + aSbr(MuR)*(chi_bar(n,nu)+(BETA0/24.)
	*chi(n,nu)*(-chi(n,nu) + 10./3.+ 4.*log(sqrt(MuR)/sqrt(Q1*Q2)))))));
}
/*-----------------------------------------------------------------------
                    define chi(n,nu) function
          χ(n, ν) = 2ψ[1] - ψ[(n+1)/2+i*nu]- ψ[(n+1)/2-i*nu]
            Equation (17) of https://arxiv.org/abs/1211.7225
----------------------------------------------------------------------*/
double chi(int n, double nu)
{
	const std:: complex<double> i(0.0,1.0);
	return real(2.*(PSI(1) - PSI((n+1)/2.+i*nu))); ///<- χ(n, ν) = 2{ψ[1] - ψ[(n+1)/2+i*nu]}. psi is symmetric around its real part.
	//return 2*(-0.5772156649015329) - psi(n/2.+1./2.+i*nu)-psi(n/2.+1./2-i*nu);
}

/*-----------------------------------------------------------------------
                    define phi(n,nu) function
                             φ(n, ν)
           Equation (24) of https://arxiv.org/abs/1211.7225
----------------------------------------------------------------------*/
double phi(int n, double nu)
{
const std:: complex<double> i(0.0,1.0);
std::complex<double> phi(0.0,0.0);

	for(int k=0; k<=1000; k++) {
		phi+= (((pow(-1,k+1))/(double(k)+i*(0.+nu/100.)+n/2.+1./2.))*((dpsi(k+n+1)
		- dpsi(k+1))+((1./4.)*pow(-1,k+1)*(dpsi((k/2.)+(n/2.)+1)-dpsi((k/2.)
		+(n/2.)+(1./2.))+dpsi((k/2.)+1)-dpsi((k/2.)+(1./2.)))))
		-((pow(-1,k+1))/(pow(double(k)+i*(0.+nu/100.)+n/2.+1./2.,2)))*(PSI(k+n+1) - PSI(k+1)));
	}
	return 2.*real(phi);
}
/*-----------------------------------------------------------------------
                    define chi_bar(n,nu) function
                                χ̄ (n, ν)
             Equation (23) of https://arxiv.org/abs/1211.7225
----------------------------------------------------------------------*/
std::complex<double> chi_bar(int n, double nu)
{
	const std:: complex<double> i(0.0,1.0);
	// int  nf=5;
	double HY, d0, d2;

	HY= (pow(M_PI,2)*sinh(M_PI*nu))/(2*nu*pow(cosh(M_PI*nu),2));      //<--- Pi^2*Sinh[Pi nu])/(2* nu* Cosh[Pi nu]^2))
	d0 = 3.+(1.+nf/pow(CA,3))*((11.+12.*pow(nu,2))/(16.*(1.+pow(nu,2))));  //<--- 3 + (1 + nf/N^3)*((11 + 12*nu^2)/(16*(1 + nu^2))))
	d2 = (1.+nf/pow(CA,3))*((1.+4.*pow(nu,2))/(32.*(1.+pow(nu,2))));       //<--- 1 + nf/N^3)*((4*nu^2 + 1)/(32*(1 + nu^2)))

	return -(1./4.)*(-(4./3.- (2.*ZETA_2))*chi(n,nu) - (6.*ZETA_3)
	+ HY*(d0*kdelta(n,0) - d2*kdelta(n,2))
	- d2psi(1./2.+n/2.+i*nu )- d2psi(1./2.+n/2.-i*nu)
	+ 2.*phi(n,nu));
}
/*-----------------------------------------------------------------------
                    define chi_1(n,nu) function
                                 χ(1)(n,ν)
             Equation (22) of https://arxiv.org/abs/1211.7225
----------------------------------------------------------------------*/
/*
std:: complex<double>chi_1(int n, double nu)
{
	const std:: complex<double> i(0.0,1.0);
	return (-(BETA0/8*CA)*(pow(chi(n,nu),2)-(10./3.)*chi(n,nu)
	+dpsi(1./2.+n/2.-i*nu )-dpsi(1./2.+n/2.+i*nu ))+chi_bar(n,nu));
} */
