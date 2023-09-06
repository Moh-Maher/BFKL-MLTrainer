/********************************************************************************************************************************************
* Mathematical tools supports for MLiftBFKL package. 
*
* By: Mohammed Maher Abdelrahim Mohammed
*     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
*     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
*     mohammed.maher@unical.it
*
*********************************************************************************************************************************************/
#include"../include/mathfuns.h"

static const double pi = 3.1415926535897932384626433832795028841972 ;
/*-------------------------------------------------------------------------------------------
                            Gamma function Γ(z) 
-------------------------------------------------------------------------------------------*/
/*  using Lanczos approximation: http://en.wikipedia.org/wiki/Lanczos_approximation
    Translating the Python code to C++ gives the program after the signature. 
    Without any explicit or implied warranty ;-) source:https://bytes.com/topic/c/answers/576697-c-routine-complex-gamma-function */
/*
 static const int g=7;
 static const double pi = 3.1415926535897932384626433832795028841972 ;
 
 static const double p[g+2] = {0.99999999999980993, 676.5203681218851, -1259.1392167224028, 
                              771.32342877765313, -176.61502916214059, 12.507343278686905,
                              -0.13857109526572012, 9.9843695780195716e-6, 1.5056327351493116e-7};

  std::complex<double>gamma( std::complex<double> z){

  if ( real(z)<0.5 ) {
    return pi / (sin(pi*z)*gamma(1.0-z));
  }
  
  z -= 1.0;
  std::complex<double> x =p[0];
  
  for (int i=1; i<g+2; i++) {
   x += p[i]/(z+std::complex<double>(i,0));
  }
  
  std::complex<double>t = z + (g + 0.5);
  
  return sqrt(2*pi) * pow(t,z+0.5) * exp(-t) * x;
 }
 */
/*------------------------------------------------------------------------------------------
                        Gamma function Γ(z) Spouge's approximation
-------------------------------------------------------------------------------------------*/
// Calculate the coefficients used by Spouge's approximation
std::vector<double> CalculateCoefficients(int numCoeff)
{
	std::vector<double> c(numCoeff);
	double k1_factrl = 1.0;
	c[0] = sqrt(2.0 * M_PI);
	for(size_t k=1; k < numCoeff; k++)
	{
		c[k] = exp(numCoeff-k) * pow(numCoeff-k, k-0.5) / k1_factrl;
		k1_factrl *= -(double)k;
	}
	return c;
}
 
// The Spouge approximation
std::complex<double> gamma(std::complex<double> z)
{       
        if (real(z) < 0.5)
	{
        	return M_PI / (sin( M_PI * z) * gamma(1. - z));
	}
        else
        {
        	z -= 1.;
        	const std::vector<double>& coeffs= CalculateCoefficients(11);
        	const double numCoeff = coeffs.size();
        	std::complex<double> accm = coeffs[0];
        	for(size_t k=1; k < numCoeff; k++)
        	{
            		accm += coeffs[k] / ( z + double(k) );
        	}
        accm *= exp(-(z+numCoeff)) * pow(z+numCoeff, z+0.5);
        return accm;
        }
}
/*-------------------------------------------------------------------------------------------
                            Master integrals : I1
-------------------------------------------------------------------------------------------*/
std::complex<double>mastar_I1(double g1, double g2, int n, double nu, double pH, double phi_H, double epsilon)
{
 
	std::complex<double> factr = pow(pH*pH, (std::complex<double>(-0.5 - g1 - g2 - epsilon, nu)))
		             * exp(std::complex<double>(0.0, n*phi_H));
	std::complex<double> Numr = gamma( std::complex<double>(0.5 + g1 + g2 + n/2. + epsilon, -nu) )
		            * gamma( std::complex<double>(-0.5 -g1 + n/2. - epsilon, nu) )
		            * gamma( std::complex<double>(1. - g2 - epsilon, 0.0) );
	std::complex<double> Denr = gamma( std::complex<double>(3./2. + g1 + n/2., -nu) )
		            * gamma( std::complex<double>(0.5 - g1 - g2 + n/2. - 2*epsilon, nu) )
		            * gamma( std::complex<double>(g2, 0.0) );                         
	return (factr/(sqrt(2)*pow(pi,epsilon))) * (Numr/Denr);
    	//return  (Numr/Den);                      
}
/*-------------------------------------------------------------------------------------------
                            The real part of Polygamma function ψ(x)
-------------------------------------------------------------------------------------------*/
/*  For orignial code see: "Fortran Routines for Computation of Special Functions,
                             jin.ece.uiuc.edu/routines/routines.html".              
                               F90 Release By J-P Moreau, Paris. 
                               (www.jpmoreau.fr) */
double Repsi(std::complex<double> z){
	double TH;
	double XPSI1,YPSI1,XPSI0,CT2,TM,TN,PSR,Z0,Z2,RR;
	double XPSI=real(z);
	double YPSI=imag(z);
	int N,k;
	double A[8]={-0.8333333333333e-01,0.83333333333333333e-02,
		-0.39682539682539683e-02, 0.41666666666666667e-02,
		-0.75757575757575758e-02,0.21092796092796093e-01,
		-0.83333333333333333e-01,0.4432598039215686e0 };
      
      XPSI1=0.0e0;
      YPSI1=0.0e0;
      if ((YPSI == 0.0e0) && (XPSI == int(XPSI)) && XPSI<=0.0e0) {
         PSR=1.0e+300;}   
      else
      {
        if (XPSI<0.0e0) {
            	XPSI1=XPSI;
            	YPSI1=YPSI;
            	XPSI=-XPSI;
            	YPSI=-YPSI;        
         }
         	XPSI0=XPSI;
         if (XPSI<8.0e0) 
         {
    		N=8-int(XPSI);
            	XPSI0=XPSI+N; 
         }
         if ((XPSI0==0.0e0) && (YPSI!=0.0e0)) {TH=0.5*M_PI;}
         if (XPSI0!=0.0e0) {TH=atan(YPSI/XPSI0);}
         
         Z2=pow(XPSI0,2)+pow(YPSI,2);
         Z0=sqrt(Z2);
         PSR=log(Z0)-0.5*(XPSI0/Z2);
         for( k=1; k<=8; k++){
            PSR+=A[k-1]*pow(Z2,-k)*cos(2.0e0*k*TH);             
         }
         if (XPSI<8.0e0) 
         {
		RR=0.0e0;
            	for( k=1; k<=N; k++){
               		RR+=(XPSI0-k)/(pow(XPSI0-k,2)+pow(YPSI,2));            
            	}
            	PSR=PSR-RR;  
         }        
         if (XPSI1<0.0e0) 
         {
            	TN=tan(M_PI*XPSI);
            	TM=tanh(M_PI*YPSI);
            	CT2=TN*TN+TM*TM;
            	PSR=(PSR+XPSI)/(pow(XPSI,2)+pow(YPSI,2))+M_PI*(TN-TN*pow(TM,2))/CT2;         
         }
     }
     return PSR;
}
/*-----------------------------------------------------------------------------------------
                        The imaginary part of Polygamma function ψ(x)
-----------------------------------------------------------------------------------------*/
 double Impsi(std::complex<double> z){
 double TH;
 double XPSI1,YPSI1,XPSI0,CT2,TM,TN,Z0,Z2,RI,PSI;
 double XPSI=real(z);
 double YPSI=imag(z);
 
 int N,k;
 double A[8]={-0.8333333333333e-01,0.83333333333333333e-02,-0.39682539682539683e-02,
               0.41666666666666667e-02, -0.75757575757575758e-02,0.21092796092796093e-01,
              -0.83333333333333333e-01,0.4432598039215686e0};
       
      XPSI1=0.0e0;
      YPSI1=0.0e0;
      if ((YPSI == 0.0e0) && (XPSI == int(XPSI)) && XPSI<=0.0e0) {
         PSI=0.0e0; 
         }
  
      else
{
if (XPSI<0.0e0) {
            XPSI1=XPSI;
            YPSI1=YPSI;
            XPSI=-XPSI;
            YPSI=-YPSI;     
         }
         XPSI0=XPSI;
         if (XPSI<8.0e0) {
            N=8-int(XPSI);
            XPSI0=XPSI+N;
         }
         if ((XPSI0==0.0e0) && (YPSI!=0.0e0)) {TH=0.5*M_PI;}
         if (XPSI0!=0.0e0) {TH=atan(YPSI/XPSI0);}
         Z2=pow(XPSI0,2)+pow(YPSI,2);
         Z0=sqrt(Z2);
          //PSR=log(Z0)-0.5*(XPSI0/Z2);
          PSI=TH+0.5e0*YPSI/Z2;
         for( k=1; k<=8; k++){             
             PSI+=-A[k-1]*pow(Z2,-k)*sin(2.0e0*k*TH);
         }
         if (XPSI<8.0e0) {         
            RI=0.0e0;     
            for( k=1; k<=N; k++){
               
                RI+=YPSI/(pow((XPSI0-k),2)+YPSI*YPSI);
            }
                PSI=PSI+RI;
         }
          
         if (XPSI1<0.0e0) {
            TN=tan(M_PI*XPSI);
            TM=tanh(M_PI*YPSI);
            CT2=TN*TN+TM*TM;           
            PSI=PSI-YPSI/(XPSI*XPSI+YPSI*YPSI)-M_PI*TM*(1.0e0+TN*TN)/CT2;       
           // XPSI=XPSI1;
            //YPSI=YPSI1;
         }
}
     return PSI;
}
/*-------------------------------------------------------------------------------------------
                             Complex Polygamma function ψ(x)
-------------------------------------------------------------------------------------------*/
std::complex<double>PSI(std::complex<double> z)
{
	std::complex<double> CPSI(Repsi(z),Impsi(z));
	return CPSI;
}

/*------------------------------------------------------------------------------------------
                         The first derivative of ψ(x) function
------------------------------------------------------------------------------------------*/
std::complex<double>dpsi(std::complex<double> z)
{
	// return boost::math::polygamma(1,x);
	return ((PSI(z+0.0001)-PSI(z-0.0001))/0.0002);
}  
/*-------------------------------------------------------------------------------------------
                         The second derivative of ψ(x) function
--------------------------------------------------------------------------------------------*/ 
std::complex<double> d2psi(std::complex<double> z)
{
	//return boost::math::polygamma(2,x);
	return (PSI(z+0.0002)-2.*PSI(z)+PSI(z-0.0002))/(pow(0.0002,2));
}
/*-------------------------------------------------------------------------------------------
                                     Kronecker Delta
-------------------------------------------------------------------------------------------*/
double kdelta(int i, int j){
	if  (i==j) {return (1);}
	else 
		return (0);
	//return (i==j) ? 1 : 0;
}
/*------------------------------------------------------------------------------------------------------
                       The longitudinal-momentum fraction  x
------------------------------------------------------------------------------------------------------*/  
/*
double Xfrc(double P, double scl, double S){
	return P*exp(scl)/sqrt(S);
 }*/
/*-------------------------------------------------------------------------------------------
                                     Brent method to finding roots
-------------------------------------------------------------------------------------------*/
double brents_fun(std::function<double (double)> f, double lower_bound, double upper_bound, double TOL, double MAX_ITER)
{
    double a = lower_bound;
    double b = upper_bound;
    double fa = f(a);   // calculated now to save function calls
    double fb = f(b);   // calculated now to save function calls
    double fs = 0;      // initialize 

    if (!(fa * fb < 0))
    {
        std::cout << "Signs of f(lower_bound) and f(upper_bound) must be opposites" << std::endl; // throws exception if root isn't bracketed
        return 0;
    }

    if (std::abs(fa) < std::abs(b)) // if magnitude of f(lower_bound) is less than magnitude of f(upper_bound)
    {
        std::swap(a,b);
        std::swap(fa,fb);
    }

    double c = a;           // c now equals the largest magnitude of the lower and upper bounds
    double fc = fa;         // precompute function evalutation for point c by assigning it the same value as fa
    bool mflag = true;      // boolean flag used to evaluate if statement later on
    double s = 0;           // Our Root that will be returned
    double d = 0;           // Only used if mflag is unset (mflag == false)

    for (unsigned int iter = 1; iter < MAX_ITER; ++iter)
    {
        // stop if converged on root or error is less than tolerance
        if (std::abs(b-a) < TOL)
        {
          // std::cout << "After " << iter << " iterations the root is: " << s << std::endl;
            return s;
        } // end if

        if (fa != fc && fb != fc)
        {
            // use inverse quadratic interopolation
            s =   ( a * fb * fc / ((fa - fb) * (fa - fc)) )
                + ( b * fa * fc / ((fb - fa) * (fb - fc)) )
                + ( c * fa * fb / ((fc - fa) * (fc - fb)) );
        }
        else
        {
            // secant method
            s = b - fb * (b - a) / (fb - fa);
        }

        /*
            Crazy condition statement!:
            -------------------------------------------------------
            (condition 1) s is not between  (3a+b)/4  and b or
            (condition 2) (mflag is true and |s−b| ≥ |b−c|/2) or
            (condition 3) (mflag is false and |s−b| ≥ |c−d|/2) or
            (condition 4) (mflag is set and |b−c| < |TOL|) or
            (condition 5) (mflag is false and |c−d| < |TOL|)
        */
        if (    ( (s < (3 * a + b) * 0.25) || (s > b) ) ||
                ( mflag && (std::abs(s-b) >= (std::abs(b-c) * 0.5)) ) ||
                ( !mflag && (std::abs(s-b) >= (std::abs(c-d) * 0.5)) ) ||
                ( mflag && (std::abs(b-c) < TOL) ) ||
                ( !mflag && (std::abs(c-d) < TOL))  )
        {
            // bisection method
            s = (a+b)*0.5;

            mflag = true;
        }
        else
        {
            mflag = false;
        }

        fs = f(s);  // calculate fs
        d = c;      // first time d is being used (wasnt used on first iteration because mflag was set)
        c = b;      // set c equal to upper bound
        fc = fb;    // set f(c) = f(b)

        if ( fa * fs < 0)   // fa and fs have opposite signs
        {
            b = s;
            fb = fs;    // set f(b) = f(s)
        }
        else
        {
            a = s;
            fa = fs;    // set f(a) = f(s)
        }

        if (std::abs(fa) < std::abs(fb)) // if magnitude of fa is less than magnitude of fb
        {
            std::swap(a,b);     // swap a and b
            std::swap(fa,fb);   // make sure f(a) and f(b) are correct after swap
        }

    } // end for

    std::cout<< "The solution does not converge or iterations are not sufficient" << std::endl;
return 0;
} // end brent_fun
/*------------------------------------------------------------------------------------------------------
                                       Splitting functions (regular part)
------------------------------------------------------------------------------------------------------*/
/*
double Pgq(double z) {

return CF*(1. + pow((1. - z),2))/z;

}

double Pqg(double z) {

return 0.5*(z*z + pow((1. - z),2));

}

double Pqq(double z) {

return CF*(1. + z*z)/(1. - z);

}

double Pgg(double z) {

return 2.*CA*(1./(1. - z) + 1./z - 2. + z*(1. - z));

}
*/
