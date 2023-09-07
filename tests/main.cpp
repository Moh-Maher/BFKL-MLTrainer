#include <iostream>
#include <cstdlib>
#include"../include/main.h"
int main() 
{
	int option;
	int scriptChoice;

	display_welcome_message();
	option = get_option_choice();

	if (option == 1 || option == 2) {
		scriptChoice = get_script_choice(option);
		if (scriptChoice == 1) {
	    		if (option == 1) {
	    			std::system("g++ src/controller.cpp -o test.out");
    				std::system("./test.out LLA");
				std::system("rm test.out");
				//run_python_script("inference/LLA_bfkl_predictor.py");
	    		} else {
				std::system("g++ src/data_generator.cpp src/alphas.cpp src/bfklkernel.cpp src/mathfuns.cpp -o run.out");
				std::system("./run.out");
				std::system("rm run.out");
	    		}
		} else if (scriptChoice == 2) {
	    		if (option == 1) {
	    			std::system("g++ src/controller.cpp -o test.out");
    				std::system("./test.out NLA");
				std::system("rm test.out");
				//run_python_script("inference/NLA_bfkl_predictor.py");
	    		} else {
				std::cout << "Choose a script for Training a model:" << std::endl;
				std::cout << "1. LLA" << std::endl;
				std::cout << "2. NLA" << std::endl;
				std::cout << "Enter your choice (1 or 2): ";
				std::cin >> scriptChoice;
				if (scriptChoice == 1) {
		    			run_python_script("model_training/LLA_bfkl_training.py");
				} else if (scriptChoice == 2) {
		    			run_python_script("model_training/NLA_bfkl_training.py");
				} else {
		    			std::cout << "Invalid choice. Please enter 1 or 2." << std::endl;
				}
	    		}
		} else {
	    		std::cout << "Invalid choice. Please enter 1 or 2." << std::endl;
		}
	} else if (option == 3) {
		std::system("g++ src/plotting.cpp -o run.out -I /usr/include/python3.10 -lpython3.10");
		std::system("./run.out");
		std::system("rm run.out");
	} else {
		std::cout << "Invalid option. Please enter 1, 2, or 3." << std::endl;
	}

	return 0;
}
