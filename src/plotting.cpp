#include<iostream>
#include"../include/plt_all.h"
//#include"plot.h"
int main() 
{
	int choice;
	std::cout << "=================================="<< std::endl;
	std::cout << "Choose BFKL kernel to be plotted :" << std::endl;
	std::cout << "=================================="<< std::endl;
	std::cout << "1. Plot LLA kernel" << std::endl;
	std::cout << "2. Plot NLA kernel" << std::endl;
	std::cout << "3. Plot LLA/NLA kernel" << std::endl;
	std::cout << "Enter your choice (1,2 or 3): ";
	std::cin >> choice;	
    
	if (choice == 1) {
		std::cout << "1. Analytic results" << std::endl;
		std::cout << "2. Model predictions" << std::endl;
		std::cin >> choice;
		if(choice ==1){
	      		plot_LLA_Analytic_output();
	      	} else if (choice==2){
	      		plot_LLA_output();
	      	}else{
      	        	std::cout << "Invalid choice. Please enter 1 or 2." << std::endl;
	      	}

    	} 
    
	else if (choice == 2) {
		std::cout << "1. Analytic results" << std::endl;
		std::cout << "2. Model predictions" << std::endl;
		std::cin >> choice;
		if(choice ==1){
	      		plot_NLA_Analytic_output();
	      	} else if (choice==2){
	      		plot_NLA_output();
	      	}else{
      	        	std::cout << "Invalid choice. Please enter 1 or 2." << std::endl;
	      	}
		 
	} 
	else if(choice==3){
		/*std::cout << "1. Analytic results" << std::endl;
		std::cout << "2. Model predictions" << std::endl;
		std::cin >> choice;
		if(choice ==1){
	      		plot_NLA_comparison();
	      		plot_LLA_comparison();
	      	} else if (choice==2){
	      		plot_LLA_NLA_kernel();
	      	}else{
      	        	std::cout << "Invalid choice. Please enter 1 or 2." << std::endl;
	      	}*/
	      	plot_NLA_comparison();
	      	plot_LLA_comparison();
	
	}
	else {
        	std::cout << "Invalid choice. Please enter 1 or 2." << std::endl;
	}
	
	return 0;
}
