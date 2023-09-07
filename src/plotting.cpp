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
	      	plot_LLA_output();

    	} 
    
	else if (choice == 2) {
		plot_NLA_output();
		 
	} 
	else if(choice==3){
		plot_LLA_NLA_kernel();
	}
	else {
        	std::cout << "Invalid choice. Please enter 1 or 2." << std::endl;
	}
	
	return 0;
}
