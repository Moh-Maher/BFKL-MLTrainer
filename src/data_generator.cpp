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
#include <cstdlib>
int main(void)
{
    BFKL_Kernel BFKL;

    std::ofstream mydataLLABFKL;
    std::ofstream mydataNLABFKL;
    
    std::string path_to_LLA_data{"data/data_preparation//LLA_Kernel.csv"};  
    std::string path_to_NLA_data{"data/data_preparation//NLA_Kernel.csv"};

    double Y_start, Y_end, Y_step;
    int MUR_start, MUR_end, MUR_step;
    int j_start, j_end;

    std::cout << "Enter Y start: ";
    std::cin >> Y_start;
    std::cout << "Enter Y end: ";
    std::cin >> Y_end;
    std::cout << "Enter Y steps: ";
    std::cin >> Y_step;
    std::cout << "Enter MUR start: ";
    std::cin >> MUR_start;
    std::cout << "Enter MUR end: ";
    std::cin >> MUR_end;
    std::cout << "Enter MUR steps: ";
    std::cin >> MUR_step;
    std::cout << "Enter nu-start: ";
    std::cin >> j_start;
    std::cout << "Enter nu-end: ";
    std::cin >> j_end;

        int choice;
    std::cout << "=================================="<< std::endl;
    std::cout << "Choose BFKL kernel:" << std::endl;
    std::cout << "=================================="<< std::endl;
    std::cout << "1. LLA kernel data" << std::endl;
    std::cout << "2. NLA kernel data" << std::endl;
    std::cout << "Enter your choice (1 or 2): ";
    std::cin >> choice;	
    if (choice == 1) {
     mydataLLABFKL.open(path_to_LLA_data);
     mydataLLABFKL<<"n,nu,Y,MuR,LLA_Kernel"<<std::endl;
    //#pragma omp parallel for collapse(2)
    for (int n = 0; n <= 2; ++n) {
        for (int Y_int = static_cast<int>(Y_start * 10); Y_int <= static_cast<int>(Y_end * 10); Y_int += static_cast<int>(Y_step * 10)) {
            double Y = static_cast<double>(Y_int) / 10.0; // Convert back to original floating-point value
            //#pragma omp parallel for
            for (int MUR = MUR_start; MUR <= MUR_end; MUR += MUR_step) {
                for (int j = j_start; j <= j_end; ++j) {
                    mydataLLABFKL << n << "," << j << "," << Y << "," << MUR << "," << std::setprecision(16) << std::real(BFKL.LLA_Kernel(n, j, Y, MUR)) << std::endl;
                }
            }
        }
    }
    

 
    mydataLLABFKL.close();
    std::cout << "Data has been saved in " << path_to_LLA_data << std::endl;
    std::system("python3 model_training/LLA_bfkl_training.py");     
    } else if (choice == 2) { 
    mydataNLABFKL.open(path_to_NLA_data);
    mydataNLABFKL<<"n,nu,Y,MuR,NLA_Kernel"<<std::endl;
    //#pragma omp parallel for collapse(2)
    for (int n = 0; n <= 2; ++n) {
        for (int Y_int = static_cast<int>(Y_start * 10); Y_int <= static_cast<int>(Y_end * 10); Y_int += static_cast<int>(Y_step * 10)) {
            double Y = static_cast<double>(Y_int) / 10.0; // Convert back to original floating-point value
          //  #pragma omp parallel for
            for (int MUR = MUR_start; MUR <= MUR_end; MUR+=MUR_step) {
                for (int j = j_start; j <= j_end; ++j) {    
                   	if(j==0){continue;}               
                   	else{
                   		mydataNLABFKL << n << "," << j << "," << Y << "," << MUR << "," << std::setprecision(16) << std::real(BFKL.NLA_Kernel(n, j, Y ,MUR, MUR, MUR*MUR))<<std::endl;
                   	}
                }
            }
        }
    }
    mydataNLABFKL.close();
    std::cout << "Data has been saved in " << path_to_NLA_data << std::endl;
    std::system("python3 model_training/NLA_bfkl_training.py");
    } else {
        std::cout << "Invalid choice. Please enter 1 or 2." << std::endl;
    }


    return 0;
}
