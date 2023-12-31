 /* plt_all.h file is part of QUANTAPLUS-x 

by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          */
#pragma once
#ifndef INCLUDE_PLT_H
#define INCLUDE_PLT_H
#include <cmath>
#include <vector>
#include <cstring>
//#include<fstream>
#include"utilities.h"
#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;

 
/********************************************************
               ploting LLA BFKL kernel
********************************************************/
void plot_LLA_output() {

	std::string path_to_data{"data/output_predictions/LLA_output.dat"};

	const unsigned n = countLinesInFile(path_to_data);

	Input infile(path_to_data);   


	std::vector<double> x(n), y(n);
	for (unsigned i = 0; i < n; i++) {
		infile.getData >> x[i];    
		infile.getData >> y[i]; 

	}

	//infile.close();
	Input meta_data("data/data_preparation/LLA_meta_data.txt");
	int N{0};
	double MU{0.0};
	meta_data.getData >> N;
	meta_data.getData >> MU;    
	
	std::string n_value = std::to_string(N);
	std::string mu_value = std::to_string(int(MU));
	plt::title("LLO BFKL kernel Plot at scale $\\mu = $"+mu_value+" GeV");
	plt::xlabel("$\\nu$");
	plt::ylabel("$\\omega(n="+n_value+", \\nu)$");
	//plt::text(0.,-0.01, "QUANTAPLUSv1.0");
	plt::xlim(-10, 10);
	//plt::ylim(0, 1);

	plt::plot(x, y, {{"color", "red"}, {"label", "LLA_predictions"}, {"linestyle", "--"}});
	// plt::scatter(w, z, {{"color", "blue"}, {"label", "Sine wave"}});
	plt::legend();
	plt::savefig("data/output_predictions/plots/LLA_predictions.pdf");
	printf("-----------------------------------------------------\n");
	printf("the plot has been saved in 'data/output_predictions/plots/' directory\n");
	printf("-----------------------------------------------------\n");
	plt::show();

}

/********************************************************
               ploting NLA BFKL kernel
********************************************************/
void plot_NLA_output() {

	std::string path_to_data{"data/output_predictions/NLA_output.dat"};

	const unsigned n = countLinesInFile(path_to_data);

	Input infile(path_to_data);
 
	std::vector<double> x(n), y(n);
	for (unsigned i = 0; i < n; i++) {
		infile.getData >> x[i];    
		infile.getData >> y[i]; 

	}
	
	Input meta_data("data/data_preparation/NLA_meta_data.txt");
	int N;
	double MU;
	meta_data.getData >> N;
	meta_data.getData >> MU;    
	
	std::string n_value = std::to_string(N);
	std::string mu_value = std::to_string(int(MU));
	plt::title("NLO BFKL kernel Plot at scale $\\mu = $"+mu_value+" GeV");
	plt::xlabel("$\\nu$");
	plt::ylabel("$\\omega(n="+n_value+", \\nu)$");
	//plt::text(0.,-0.01, "QUANTAPLUSv1.0");
	plt::xlim(-10, 10);
	//plt::ylim(0, 1);

	plt::plot(x, y, {{"color", "red"}, {"label", "LLA_predictions"}, {"linestyle", "--"}});
	// plt::scatter(w, z, {{"color", "blue"}, {"label", "Sine wave"}});
	plt::legend();
	plt::savefig("data/output_predictions/plots/NLA_predictions.pdf");
	printf("-----------------------------------------------------\n");
	printf("the plot has been saved in 'data/output_predictions/plots/' directory\n");
	printf("-----------------------------------------------------\n");
	plt::show();
  
}
/********************************************************
ploting LLA/NLA kernrel
********************************************************/
void plot_LLA_NLA_kernel() {


	std::string path_to_data1{"data/output_predictions/LLA_output.dat"};
	std::string path_to_data2{"data/output_predictions/NLA_output.dat"};
	const unsigned n1 = countLinesInFile(path_to_data1);
	const unsigned n2 = countLinesInFile(path_to_data2);
	Input infile1(path_to_data1);     
	Input infile2(path_to_data2);     
	
	std::vector<double> x1(n1), y1(n1);
	for (unsigned i = 0; i < n1; i++) {

		infile1.getData >> x1[i];    
		infile1.getData >> y1[i]; 

	}

	std::vector<double> x2(n2), y2(n2);
	for (unsigned i = 0; i < n2; i++) {

		infile2.getData >> x2[i];    
		infile2.getData >> y2[i]; 

	}

 
	
	Input meta_data("data/data_preparation/LLA_meta_data.txt");
	int N{0};
	double MU{0.0};
	meta_data.getData >> N;
	meta_data.getData >> MU;    
	
	std::string n_value = std::to_string(N);
	std::string mu_value = std::to_string(int(MU));
	plt::title("LLO/NLO BFKL kernel Plot at scale $\\mu = $"+mu_value+" GeV");
	plt::xlabel("$\\nu$");
	plt::ylabel("$\\omega(n="+n_value+", \\nu)$");
		 

	plt::plot(x1, y1, {{"color", "red"}, {"marker", "o"}, {"label", "LLA_predictions"}, {"linestyle", "--"}});
	plt::plot(x2, y2, {{"color", "blue"}, {"label", "NLA_predictions"}, {"linestyle", "--"}});
	plt::legend();
	plt::savefig("data/output_predictions/plots/NLA_LLA_predictions.pdf");
	printf("-----------------------------------------------------\n");
	printf("the plot has been saved in 'data/output_predictions/plots/' directory\n");
	printf("-----------------------------------------------------\n");
	plt::show();

}
/********************************************************
               ploting LLA BFKL analytic kernel
********************************************************/
void plot_LLA_Analytic_output() {

	std::string path_to_data{"data/output_predictions/LLA_Analytic_Kernel.dat"};

	const unsigned n = countLinesInFile(path_to_data);

	Input infile(path_to_data);   


	std::vector<double> x(n), y(n);
	for (unsigned i = 0; i < n; i++) {
		infile.getData >> x[i];    
		infile.getData >> y[i]; 

	}

	//infile.close();
	Input meta_data("data/data_preparation/LLA_meta_data.txt");
	int N{0};
	double MU{0.0};
	meta_data.getData >> N;
	meta_data.getData >> MU;    
	
	std::string n_value = std::to_string(N);
	std::string mu_value = std::to_string(int(MU));
	plt::title("LLO BFKL kernel Plot at scale $\\mu = $"+mu_value+" GeV");
	plt::xlabel("$\\nu$");
	plt::ylabel("$\\omega(n="+n_value+", \\nu)$");
	//plt::text(0.,-0.01, "QUANTAPLUSv1.0");
	plt::xlim(-10, 10);
	//plt::ylim(0, 1);

	plt::plot(x, y, {{"color", "blue"}, {"label", "LLA_Analytic"}, {"linestyle", "--"}});
	// plt::scatter(w, z, {{"color", "blue"}, {"label", "Sine wave"}});
	plt::legend();
	plt::savefig("data/output_predictions/plots/LLA_Analytic.pdf");
	printf("-----------------------------------------------------\n");
	printf("the plot has been saved in 'data/output_predictions/plots/' directory\n");
	printf("-----------------------------------------------------\n");
	plt::show();

}

/********************************************************
               ploting NLA BFKL analytic kernel
********************************************************/
void plot_NLA_Analytic_output() {

	std::string path_to_data{"data/output_predictions/NLA_Analytic_Kernel.dat"};

	const unsigned n = countLinesInFile(path_to_data);

	Input infile(path_to_data);   


	std::vector<double> x(n), y(n);
	for (unsigned i = 0; i < n; i++) {
		infile.getData >> x[i];    
		infile.getData >> y[i]; 

	}

	//infile.close();
	Input meta_data("data/data_preparation/NLA_meta_data.txt");
	int N{0};
	double MU{0.0};
	meta_data.getData >> N;
	meta_data.getData >> MU;    
	
	std::string n_value = std::to_string(N);
	std::string mu_value = std::to_string(int(MU));
	plt::title("LLO BFKL kernel Plot at scale $\\mu = $"+mu_value+" GeV");
	plt::xlabel("$\\nu$");
	plt::ylabel("$\\omega(n="+n_value+", \\nu)$");
	//plt::text(0.,-0.01, "QUANTAPLUSv1.0");
	plt::xlim(-10, 10);
	//plt::ylim(0, 1);

	plt::plot(x, y, {{"color", "blue"}, {"label", "NLA_Analytic"}, {"linestyle", "--"}});
	// plt::scatter(w, z, {{"color", "blue"}, {"label", "Sine wave"}});
	plt::legend();
	plt::savefig("data/output_predictions/plots/NLA_Analytic.pdf");
	printf("-----------------------------------------------------\n");
	printf("the plot has been saved in 'data/output_predictions/plots/' directory\n");
	printf("-----------------------------------------------------\n");
	plt::show();

}
/********************************************************
ploting LLA/NLA kernrel
********************************************************/
void plot_NLA_comparison() {


	std::string path_to_data1{"data/output_predictions/NLA_Analytic_Kernel.dat"};
	std::string path_to_data2{"data/output_predictions/NLA_output.dat"};
	const unsigned n1 = countLinesInFile(path_to_data1);
	const unsigned n2 = countLinesInFile(path_to_data2);
	Input infile1(path_to_data1);     
	Input infile2(path_to_data2);     
	
	std::vector<double> x1(n1), y1(n1);
	for (unsigned i = 0; i < n1; i++) {

		infile1.getData >> x1[i];    
		infile1.getData >> y1[i]; 

	}

	std::vector<double> x2(n2), y2(n2);
	for (unsigned i = 0; i < n2; i++) {

		infile2.getData >> x2[i];    
		infile2.getData >> y2[i]; 

	}

 
	
	Input meta_data("data/data_preparation/NLA_meta_data.txt");
	int N{0};
	double MU{0.0};
	meta_data.getData >> N;
	meta_data.getData >> MU;    
	
	std::string n_value = std::to_string(N);
	std::string mu_value = std::to_string(int(MU));
	plt::title("NLO BFKL kernel at scale $\\mu = $"+mu_value+" GeV");
	plt::xlabel("$\\nu$");
	plt::ylabel("$\\omega(n="+n_value+", \\nu)$");
		 

	plt::plot(x1, y1, {{"color", "red"}, {"marker", "o"}, {"label", "Analytic"}, {"linestyle", "--"}});
	plt::plot(x2, y2, {{"color", "blue"}, {"label", "predictions"}, {"linestyle", "--"}});
	plt::legend();
	plt::savefig("data/output_predictions/plots/NLA_comparison.pdf");
	printf("-----------------------------------------------------\n");
	printf("the plot has been saved in 'data/output_predictions/plots/' directory\n");
	printf("-----------------------------------------------------\n");
	plt::show();

}
/********************************************************
ploting LLA kernrel
********************************************************/
void plot_LLA_comparison() {


	std::string path_to_data1{"data/output_predictions/LLA_Analytic_Kernel.dat"};
	std::string path_to_data2{"data/output_predictions/LLA_output.dat"};
	const unsigned n1 = countLinesInFile(path_to_data1);
	const unsigned n2 = countLinesInFile(path_to_data2);
	Input infile1(path_to_data1);     
	Input infile2(path_to_data2);     
	
	std::vector<double> x1(n1), y1(n1);
	for (unsigned i = 0; i < n1; i++) {

		infile1.getData >> x1[i];    
		infile1.getData >> y1[i]; 

	}

	std::vector<double> x2(n2), y2(n2);
	for (unsigned i = 0; i < n2; i++) {

		infile2.getData >> x2[i];    
		infile2.getData >> y2[i]; 

	}

 
	
	Input meta_data("data/data_preparation/LLA_meta_data.txt");
	int N{0};
	double MU{0.0};
	meta_data.getData >> N;
	meta_data.getData >> MU;    
	
	std::string n_value = std::to_string(N);
	std::string mu_value = std::to_string(int(MU));
	plt::title("LLO BFKL kernel at scale $\\mu = $"+mu_value+" GeV");
	plt::xlabel("$\\nu$");
	plt::ylabel("$\\omega(n="+n_value+", \\nu)$");
		 

	plt::plot(x1, y1, {{"color", "red"}, {"marker", "o"}, {"label", "Analytic"}, {"linestyle", "--"}});
	plt::plot(x2, y2, {{"color", "blue"}, {"label", "predictions"}, {"linestyle", "--"}});
	plt::legend();
	plt::savefig("data/output_predictions/plots/LLA_comparison.pdf");
	printf("-----------------------------------------------------\n");
	printf("the plot has been saved in 'data/output_predictions/plots/' directory\n");
	printf("-----------------------------------------------------\n");
	plt::show();

}
#endif
