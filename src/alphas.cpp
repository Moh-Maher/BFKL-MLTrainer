/********************************************************************************************************************************************
*  QCD RUNNING COUPLING COSTANT (ALPHA_S)
*
* The main and important used varibles:
* BETA0 , BETA1 : beta zero and beta one represent the first and second coefficients in the expansion of the QCD β-function, respectively.
* ALPHA_S : strong interaction coupling constant.
* MUR: Renormalization scale factor.
* LAM : Lambda QCD (QCD mass scale).
* NF: the number of active quarks flavours (it should be an unsigned integer between 3 - 6.)
* AS_LOOPS: the number of running loops (up to this point we have to options 1 or 2)
*
* By: Mohammed Maher Abdelrahim Mohammed
*     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
*     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
*     mohammed.maher@unical.it
*********************************************************************************************************************************************/
#include"../include/alphas.h"

/*-----------------------------------------------------------------------
                          Set the number of active quarks
----------------------------------------------------------------------*/
unsigned int RunningCoupling::NumberOfActiveQuarks(const double& energy_scale){

    if (energy_scale < QUARK_CHARM_MASS)
    {
        _nf = 3;
    }
    else if (energy_scale < QUARK_BOTTOM_MASS && energy_scale > QUARK_CHARM_MASS)
    {
        _nf = 4;
    }
    else if (energy_scale < QUARK_TOP_MASS && energy_scale > QUARK_BOTTOM_MASS)
    {
        _nf = 5;
    }
    else
    {
        _nf = 6;
    }
    return _nf;
}
//------------------------------------------------------------------------
//
//------------------------------------------------------------------------
double RunningCoupling::SetBeta0(const unsigned& nf ){
    _beta0 = 11.- (2./3.)*nf;
    //return  11.- (2./3.)*nf;
    return _beta0;
}
//------------------------------------------------------------------------
//
//------------------------------------------------------------------------
double RunningCoupling::SetBeta1(const unsigned& nf ){
    _beta1 = 102.- (38./3.)*nf;
    return _beta1;
}
//------------------------------------------------------------------------
//
//------------------------------------------------------------------------
double RunningCoupling::SetBeta2(const unsigned& nf ){
    _beta2 = 2857./2. - (5033./18.)*nf + (325./54.)*nf*nf;
    return _beta2;
}
//------------------------------------------------------------------------
//
//------------------------------------------------------------------------
double RunningCoupling::SetBeta3(const unsigned& nf ){
    _beta3 =  (149753./6. + 3564.*ZETA_3) -(1078361./162. +(6508./27.)*ZETA_3)*nf + (50065./162. + (6472./81.)*ZETA_3)*nf*nf
    +(1093./729.)*nf*nf*nf;
    return _beta3;
}
//------------------------------------------------------------------------
//
//------------------------------------------------------------------------
double RunningCoupling::LambdaQCD(const unsigned& nf){
    switch (nf)
    {
        case 3:
            LAM_QCD = LAM3;
            break;

        case 4:
            LAM_QCD = LAM4;
            break;

        case 5:
            LAM_QCD = LAM5;
            break;

        case 6:
            LAM_QCD = LAM6;
            break;

        default:
            std:: cout<<"Invalid Nf value!. Number of active flavours has to be an integer between 3 and 6."<<std::endl;
            break;
    }
    return LAM_QCD;
}

/*-----------------------------------------------------------------------
  Calculate LAMBDA_QCD as a function of the number of active flavours
----------------------------------------------------------------------*/
double RunningCoupling::ComputedLambdaQCD(const unsigned& nf){

    double scl= 91.1876;//91.2;
    double a;               ///<- lower bound
    double b;               ///<- upper bound
    double TOL = 0.0001;    ///<- tolerance
    double MAX_ITER = 1000;
    double almZ =0.11707;//0.118; //0.11707;  ///<- aS at Z bosson mass

/*-------------------------------------LAM[nf=5]----------------------------------------
Starting from the value of aS at Z bosson mass, we solve the equation als(Z_BOZON_MASS, LAM_nf5, 5) = almZ between a and b.*/

    a = 0.05;
    b = 0.5;
    auto f5 = [scl,almZ](double x)
    { return (4.*M_PI*(1./(7.666666666666667*2.*log(scl/x))
              - (38.666666666666664*log(2.*log(scl/x)))/(pow(7.666666666666667,3)*pow(2.*log(scl/x),2)))
              - almZ);
    };

    double LAM_nf5 = brents_fun(f5,a,b,TOL,MAX_ITER);

/*-------------------------------------LAM[nf=4]----------------------------------------
solve als(QUARK_BOTTOM_MASS, LAM_nf4, 4) = als(QUARK_BOTTOM_MASS, LAM_nf5, 5) between LAM_nf5 and b.*/

    double aSlam5 = als(4.25,LAM_nf5,5);

    auto f4 = [aSlam5](double x)
    { return (4.*M_PI*(1./(8.333333333333334*2.*log(4.25/x))
              - ( 51.333333333333336*log(2.*log(4.25/x)))/(pow(8.333333333333334,3)*pow(2.*log(4.25/x),2)))
              -aSlam5);
    };

    double LAM_nf4 = brents_fun(f4,LAM_nf5,b,TOL,MAX_ITER);

/*-------------------------------------LAM[nf=3]----------------------------------------
solve als(QUARK_CHARM_MASS, LAM_nf3, 3) = als(QUARK_CHARM_MASS, LAM_nf4, 4) between LAM_nf4 and b.*/

    double aSla4 = als(1.25,LAM_nf4, 4);
    auto f3 = [aSla4](double x)
    { return (4.*M_PI*(1./(9.*2.*log(1.25/x))
              - (64.*log(2.*log(1.25/x)))/(pow(9.,3)*pow(2.*log(1.25/x),2)))
              -aSla4 );
    };

    double LAM_nf3  = brents_fun(f3,LAM_nf4,b,TOL,MAX_ITER);

/*-------------------------------------LAM[nf=6]----------------------------------------
solve als(QUARK_TOP_MASS, LAM_nf6, 6) = als(QUARK_TOP_MASS, LAM_nf5, 5) between a and LAM_nf5.*/

    double aSla = als(170,LAM_nf5, 5);
    auto f6 = [aSla](double x)
    { return (4.*M_PI*(1./(7.*2.*log(170./x))
              - (26.*log(2.*log(170./x)))/(pow(7.,3)*pow(2.*log(170./x),2)))
              -aSla);
    };

    double LAM_nf6 = brents_fun(f6,a,LAM_nf5,TOL,MAX_ITER);
/*--------------------------------------------------------------------------------------*/
//Set the computed LAMBDA_QCD value accourding to nf value
    switch (nf)
    {
        case 3:
            LAM_QCD = LAM_nf3;
            break;

        case 4:
            LAM_QCD = LAM_nf4;
            break;

        case 5:
            LAM_QCD = LAM_nf5;
            break;

        case 6:
            LAM_QCD = LAM_nf6;
            break;

        default:
            std:: cout<<"Invalid Nf value!. Number of active flavours has to be an integer between 3 and 6."<<std::endl;
            break;
    }
    return LAM_QCD;
}
//------------------------------------------------------------------------
//
//------------------------------------------------------------------------
double MSbarAlphaS::Run(const double& energy_scale, const unsigned int& loopNum){
    RunningCoupling::NumberOfActiveQuarks(energy_scale);
    SetBeta0(_nf);
    SetBeta1(_nf);
    SetBeta2(_nf);
    SetBeta3(_nf);
    double L = log(pow(energy_scale,2)/pow(ComputedLambdaQCD(_nf),2));
    double commonfactor = 4.*M_PI/(_beta0*L);
    double twoLoop = 0.0;
    double threeLoop = 0.0;
    double fourLoop  = 0.0;

    if(loopNum < 1) return _almZ;

    if(loopNum > 1) { 
		twoLoop = 1.-(_beta1*log(L))/(pow(_beta0,2)*L); 
    }
    if(loopNum > 2) {
		threeLoop =  pow(_beta1,2)/(pow(_beta0,4)*L*L)*(pow(log(L),2) - log(L) -1.
		+ (_beta2*_beta0)/pow(_beta1,2));
    }
    if(loopNum >3) {
            fourLoop =  + pow(_beta1,3)/(pow(_beta0,6)*L*L*L)*(-pow(log(L),3) + (5./2.)*pow(log(L),2)
           + 2.*log(L) - 0.5 - 3.*((_beta2*_beta0)/(_beta1*_beta1))*log(L)
           + (_beta3*_beta0*_beta0)/(2.*pow(_beta1,3)) );
           }
    /*
 double L = log(pow(energy_scale,2)/pow(LambdaQCD(_nf),2));
  // double L = log(pow(energy_scale,2)/pow(RunningCoupling::ComputedLambdaQCD(_nf),2));
    double res = 4.*M_PI/(_beta0*L)*(
               1.-(_beta1*log(L))/(pow(_beta0,2)*L)
               + pow(_beta1,2)/(pow(_beta0,4)*L*L)*(pow(log(L),2) - log(L) -1.
               + (_beta2*_beta0)/pow(_beta1,2))
               + pow(_beta1,3)/(pow(_beta0,6)*L*L*L)*(-pow(log(L),3) + (5./2.)*pow(log(L),2)
               + 2.*log(L) - 0.5 - 3.*((_beta2*_beta0)/(_beta1*_beta1))*log(L)
               + (_beta3*_beta0*_beta0)/(2.*pow(_beta1,3)) )
                                     );
    return res;*/
//return 4.*M_PI*(1./(_beta0*L) - (_beta1*log(L))/(pow(_beta0,3)*pow(L,2)));


  // double L = log(pow(energy_scale,2)/pow(RunningCoupling::ComputedLambdaQCD(_nf),2));
    return ( commonfactor*(twoLoop+threeLoop+fourLoop) );

}
//------------------------------------------------------------------------
//
//------------------------------------------------------------------------
double MSbarAlphaS::Run2(const double& energy_scale, const unsigned int& loopNum){
    RunningCoupling::NumberOfActiveQuarks(energy_scale);
    switch(loopNum){
        case 1:
            SetBeta0(_nf);
            break;
        case 2:
            SetBeta0(_nf);
            SetBeta1(_nf);
            break;
    }
  //double L = log(pow(energy_scale,2)/pow(LambdaQCD(_nf),2));
    double L = 2.*log(energy_scale/MSbarAlphaS::ComputedLambdaQCD(_nf));
    double res = 4.*M_PI/(_beta0*L)*(
               1.-((_beta1*log(L))/(pow(_beta0,2)*L)));

    return res;
//return 4.*M_PI*(1./(_beta0*L) - (_beta1*log(L))/(pow(_beta0,3)*pow(L,2)));
}
//------------------------------------------------------------------------
//
//------------------------------------------------------------------------
double MSbarAlphaS::ComputedLambdaQCD(const unsigned& nf){
    return RunningCoupling::ComputedLambdaQCD(nf);
}
//------------------------------------------------------------------------
//
//------------------------------------------------------------------------
double MOMAlphaS::Run(const double& energy_scale,  const unsigned int& loopNum){

    RunningCoupling::NumberOfActiveQuarks(energy_scale);
   // double L = log(pow(energy_scale,2)/pow(LambdaQCD(_nf),2));
    double L = 2.*log(pow(energy_scale,1)/pow(MOMAlphaS::ComputedLambdaQCD(_nf),1));
    double    BLMT_BETA = (-_beta0/2.)*(1.+ 2./3.*BLMI);
    double BLMT = BLMT_BETA + BLMT_CONF;
    RunningCoupling::NumberOfActiveQuarks(energy_scale);

    RunningCoupling::SetBeta0(_nf);
    RunningCoupling::SetBeta1(_nf);
    MOMAlphaS::SetBeta2(_nf);
    MOMAlphaS::SetBeta3(_nf);
    double commonfactor = 4.*M_PI/(_beta0*L);
    double twoLoop = 0.0;
    double threeLoop = 0.0;
    double fourLoop  = 0.0;

    if(loopNum < 1){return _almZ;}

    if(loopNum > 1)
            twoLoop = 1.-(_beta1*log(L))/(pow(_beta0,2)*L);
    if(loopNum > 2)
            {threeLoop =  pow(_beta1,2)/(pow(_beta0,4)*L*L)*(pow(log(L),2) - log(L) -1.
           + (_beta2*_beta0)/pow(_beta1,2));}
    if(loopNum >3)
            fourLoop =  + pow(_beta1,3)/(pow(_beta0,6)*L*L*L)*(-pow(log(L),3) + (5./2.)*pow(log(L),2)
           + 2.*log(L) - 0.5 - 3.*((_beta2*_beta0)/(_beta1*_beta1))*log(L)
           + (_beta3*_beta0*_beta0)/(2.*pow(_beta1,3)) );

    double res = commonfactor*(twoLoop+threeLoop+fourLoop); //0.088485085115065268
    // return (-M_PI/(2.*BLMT))*(1.-sqrt(1. + 4.*(BLMT/M_PI)*MSbarAlphaS::Run(energy_scale,loopNum))); //0.092986504586076518
    return (-M_PI/(2.*BLMT))*(1.-sqrt(1. + 4.*(BLMT/M_PI)*res));
}
//------------------------------------------------------------------------
//
//------------------------------------------------------------------------
double MOMAlphaS::Run2(const double& energy_scale,  const unsigned int& loopNum){
//double scl= 91.1876;//91.2;
    double a;               ///<- lower bound
    double b;               ///<- upper bound
    double TOL = 1.0e-5;    ///<- tolerance
    double MAX_ITER = 1000;
    const double alMSbar = MSbarAlphaS::Run(energy_scale,loopNum);//0.118; //0.11707;  ///<- aS at Z bosson mass
    RunningCoupling::SetBeta0(_nf);
    const double BLMT_BETA = (-_beta0*0.5)*(1.+ 2./3.*BLMI);
    const double BLMT = BLMT_BETA + BLMT_CONF;
    a = 0.001;
    b = 0.9;

    auto tempres = [BLMT,alMSbar](double x)
    {
        return (x *(1.+ (x*(BLMT)/(M_PI)))- alMSbar);
        //return (x*x-4);
    };

    double res = brents_fun(tempres,a,b,TOL,MAX_ITER);
    return res;
   // return  (0.12530475389881102 *(1.+ (0.12530475389881102*(BLMT)/(M_PI)))- alMSbar);
}
//------------------------------------------------------------------------
//
//------------------------------------------------------------------------
double MOMAlphaS::ComputedLambdaQCD(const unsigned& nf){
    return RunningCoupling::ComputedLambdaQCD(nf)*exp((507-40.*nf)/(792.-32.*nf/3.));
}
//------------------------------------------------------------------------
//
//------------------------------------------------------------------------
double MOMAlphaS::SetBeta2(const unsigned& nf ){
    _mombeta2 = 3040.48 - 625.387*nf + 19.3833*nf*nf;
    return _mombeta2;
}
//------------------------------------------------------------------------
//
//------------------------------------------------------------------------
double MOMAlphaS::SetBeta3(const unsigned& nf ){
    _mombeta3 = 100541 - 24423.3*nf + 1625.4*nf*nf-27.493*nf*nf*nf;
    return _mombeta3;
}
//------------------------------------------------------------------------
//
//------------------------------------------------------------------------
 double  RunningCoupling::als(const double& MUR, const double& LAM, const unsigned int& NF){

    double BETA0 = 11.-2./3.*double(NF);
    double BETA1 = 102.-38./3.*double(NF);
    return 4.*M_PI*(1./(BETA0*2.*log(MUR/LAM)) - (BETA1*log(2.*log(MUR/LAM)))/(pow(BETA0,3)*pow(2.*log(MUR/LAM),2)));
 }
