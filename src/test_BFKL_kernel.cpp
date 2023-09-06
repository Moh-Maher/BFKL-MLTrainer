
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
#include <omp.h>
 using namespace std;

 int main(void)
 {
  
  BFKL_Kernel BFKL;

  //int NF=5;
  //double BETA0 = 11.-2./3.*NF;
  //double Albar= ALPHA_S(HIGGS_BOSON_MASS,NF,2)*(CA/PI);
  //long double Gomega=0.0,NLAGomega=0.0;
  double MUR=Z_BOSON_MASS;//HIGGS_BOSON_MASS;
  std::ofstream mydataLLABFKL;
  std::ofstream mydataNLABFKL;
  //std::ofstream mydataNLABFKL;
   // std::ofstream datmydataLLABFKL;
  mydataLLABFKL.open ("input/LLA_Kernel.csv");
  mydataNLABFKL.open ("input/NLA_Kernel.csv");
  //datmydataLLABFKL.open ("input/LLA_Kernel.dat");
  //mydataNLABFKL.open ("input/NLA_Kernel.dat");
  //std::complex<long double> chi_n_nu;
  //const std:: complex<double> i(0.0,1.0);


///<- LLA case 
mydataLLABFKL<<"n,nu,Y,MuR,LLA_Kernel"<<std::endl;
mydataNLABFKL<<"n,nu,Y,MuR,NLA_Kernel"<<std::endl;
double Y_start = 2.5;
    double Y_end = 5.5;
    double Y_step = 0.5;

    int MUR_start = 1;
    int MUR_end = 125;

    int j_start = -10;
    int j_end = 10;

    //#pragma omp parallel for collapse(2)
    for (int n = 0; n <= 2; ++n) {
        for (int Y_int = static_cast<int>(Y_start * 10); Y_int <= static_cast<int>(Y_end * 10); Y_int += static_cast<int>(Y_step * 10)) {
            double Y = static_cast<double>(Y_int) / 10.0; // Convert back to original floating-point value
          //  #pragma omp parallel for
            for (int MUR = MUR_start; MUR <= MUR_end; ++MUR) {
                for (int j = j_start; j <= j_end; ++j) {
               //     mydataLLABFKL << n << "," << j << "," << Y << "," << MUR << "," << std::setprecision(16) << std::real(BFKL.LLA_Kernel(n, j, Y, MUR)) << std::endl;
                    
                    if(j==0){
                                continue;//mydataNLABFKL << n << "," << j << "," << Y << "," << MUR << "," << std::setprecision(16) << std::real(BFKL.NLA_Kernel(n, j, Y ,MUR, MUR, MUR*MUR))<<std::endl;
                    }
                    else{
                    mydataNLABFKL << n << "," << j << "," << Y << "," << MUR << "," << std::setprecision(16) << std::real(BFKL.NLA_Kernel(n, j, Y ,MUR, MUR, MUR*MUR))<<std::endl;
                    }
                }
            }
        }
    }

    mydataLLABFKL.close();
    mydataNLABFKL.close();

    
   // datmydataLLABFKL.close();
    //mydataNLABFKL.close();
/*
mydataLLABFKL<<"n,nu,Y,MuR,LLA_Kernel"<<std::endl;
  for(int j=-1000;j<=1000;j++){
     mydataLLABFKL<<1<<","<<j<<","<<2.4<<","<<MUR<<","<<std::setprecision(16)<<std::real(BFKL.LLA_Kernel(1, j, 2.4, MUR))<<std::endl;
     datmydataLLABFKL<<j<<"\t"<<std::setprecision(16)<<std::real(BFKL.LLA_Kernel(1, j, 2.4, MUR))<<std::endl;
       mydataNLABFKL<<j<<"\t"<<std::setprecision(16)<<std::real(BFKL.NLA_Kernel(1, j, 2.4,MUR,MUR, MUR*MUR))<<std::endl;
  }
   mydataLLABFKL.close(); 
      datmydataLLABFKL.close(); 
   mydataNLABFKL.close(); 
*/
/*
 cout <<"LLA BFKL green function = "<<std::setprecision(21)<<BFKL.LLA_Kernel(n, nu, 2.4, MUR)<<endl;
 //cout <<"alpha = "<<std::setprecision(21)<<ALPHA_S(Z_BOSON_MASS,NF,2)<<endl;
 
 

 cout <<"NLA BFKL green function = "<<std::setprecision(21)<<BFKL.NLA_Kernel(n, nu, 2.4,60.0,125., 60.*MUR)<<endl;
 cout<<endl;
 */
 return 0;

 }
