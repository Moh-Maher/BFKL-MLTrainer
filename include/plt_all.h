 /* plt_all.h file is part of QUANTAPLUS-x 

by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          */
#pragma once
#ifndef PLT_H_INCLUDED
#define PLT_H_INCLUDED
#include <cmath>
#include <vector>
#include<fstream>

#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;


/********************************************************
               ploting LLA BFKL kernel
********************************************************/
void plot_LLA_output() {

  const unsigned n = 200;
  std::ifstream infile;   
  infile.open("data/output_predictions/LLA_output.dat");
  if(infile.fail()) ///<-- checks to see if file opended 
    { 
      std::cout << "error!, the needed output file doesn't exist yet. !" << std::endl; 
      exit (-1); ///<-- no point continuing if the file didn't open...
    } 
 
 std::vector<double> x(n), y(n);
   for (unsigned i = 0; i < n; i++) {
      
    infile >> x[i];    
    infile >> y[i]; 
     
  }
  
  infile.close();
 
  plt::title("LLO BFKL kernel Plot at scale $\\mu = 30$ GeV");
  plt::xlabel("$\\nu$");
  plt::ylabel("$\\omega(n=0, \\nu)$");
  //plt::text(0.,-0.01, "QUANTAPLUSv1.0");
   plt::xlim(-10, 10);
   //plt::ylim(0, 1);
   
  plt::plot(x, y, {{"color", "red"}, {"label", "LLA_predictions"}, {"linestyle", "--"}});
 // plt::scatter(w, z, {{"color", "blue"}, {"label", "Sine wave"}});
  plt::legend();
   plt::savefig("data/output_predictions/plots/LLA_predictions.pdf");
   printf("-----------------------------------------------------\n");
   printf("the plot has been saved in data/output_predictions/plots/ directory\n");
   printf("-----------------------------------------------------\n");
  plt::show();
  
}

/********************************************************
               ploting NLA BFKL kernel
********************************************************/
void plot_NLA_output() {

  const unsigned n = 200;
  std::ifstream infile;   
  infile.open("data/output_predictions/NLA_output.dat");
  if(infile.fail()) ///<-- checks to see if file opended 
    { 
      std::cout << "error!, the needed output file doesn't exist yet. !" << std::endl; 
      exit (-1); ///<-- no point continuing if the file didn't open...
    } 
 
 std::vector<double> x(n), y(n);
   for (unsigned i = 0; i < n; i++) {
      
    infile >> x[i];    
    infile >> y[i]; 
     
  }
  
  infile.close();
 
  plt::title("NLO BFKL kernel Plot at scale $\\mu = 30$ GeV");
  plt::xlabel("$\\nu$");
  plt::ylabel("$\\omega(n=0, \\nu)$");
  //plt::text(0.,-0.01, "QUANTAPLUSv1.0");
   plt::xlim(-10, 10);
   //plt::ylim(0, 1);
   
  plt::plot(x, y, {{"color", "red"}, {"label", "LLA_predictions"}, {"linestyle", "--"}});
 // plt::scatter(w, z, {{"color", "blue"}, {"label", "Sine wave"}});
  plt::legend();
   plt::savefig("data/output_predictions/plots/NLA_predictions.pdf");
   printf("-----------------------------------------------------\n");
   printf("the plot has been saved in data/output_predictions/plots/ directory\n");
   printf("-----------------------------------------------------\n");
  plt::show();
  
}
#endif
