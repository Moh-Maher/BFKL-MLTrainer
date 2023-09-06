#include <iostream>
#include <cstdlib>

int main() {
	int option, scriptChoice;

	std::cout << "=================================="<< std::endl;
	std::cout << "Choose an option:" << std::endl;
	std::cout << "=================================="<< std::endl;
	std::cout << "1. Predict data " << std::endl;
	std::cout << "2. Training data" << std::endl;
	std::cout << "3. Plotting LLA/NLA predictions" << std::endl;
	std::cout << "Enter your choice (1,2 or 3): ";
	std::cin >> option;

	if (option == 1) {
		std::cout << "=================================="<< std::endl;
		std::cout << "Choose a script for Predictions :" << std::endl;
		std::cout << "=================================="<< std::endl;
		std::cout << "1. LLA BFKL Predictions" << std::endl;
		std::cout << "2. NLA BFKL Predictions" << std::endl;
		std::cout << "Enter your choice (1 or 2): ";
		std::cin >> scriptChoice;

		if (scriptChoice == 1) {
		// Run script1.py for Option 1
			std::system("python3 inference/LLA_bfkl_predictor.py");
		} else if (scriptChoice == 2) {
		// Run script2.py for Option 1
			std::system("python3 inference/NLA_bfkl_predictor.py");
		} else {
			std::cout << "Invalid choice for Option 1. Please enter 1 or 2." << std::endl;
		}
	} else if (option == 2) {
		std::cout << "=================================="<< std::endl;
		std::cout << "Choose a script for Training a model:" << std::endl;
		std::cout << "=================================="<< std::endl;
		std::cout << "1. New data" << std::endl;
		std::cout << "2. Preexist data" << std::endl;
		std::cout << "Enter your choice (1 or 2): ";
		std::cin >> scriptChoice;

		if (scriptChoice == 1) {
			// Run script1.py for Option 2
			std::system("g++ src/data_generator.cpp src/alphas.cpp src/bfklkernel.cpp src/mathfuns.cpp -o run.out");
			std::system("./run.out");
			std::system("rm run.out");
		} else if (scriptChoice == 2) {
			std::cout << "=================================="<< std::endl;
			std::cout << "Choose a script for Training a model:" << std::endl;
			std::cout << "=================================="<< std::endl;
			std::cout << "1. LLA" << std::endl;
			std::cout << "2. NLA" << std::endl;
			std::cout << "Enter your choice (1 or 2): ";
			std::cin >> scriptChoice;
			if (scriptChoice == 1) {
				// Run script1.py for Option
				std::system("python3 model_training/LLA_bfkl_training.py");
			} else if (scriptChoice == 2) {
				// Run script2.py for Option 1
				std::system("python3 model_training/NLA_bfkl_training.py");
			} else {
				std::cout << "Invalid choice for Option 1. Please enter 1 or 2." << std::endl;
			}

		} else {
			std::cout << "Invalid choice for Option 2. Please enter 1 or 2." << std::endl;
		}
	} else if(option == 3) {
		std::system("g++ src/plotting.cpp -o run.out -I /usr/include/python3.10 -lpython3.10");
		std::system("./run.out");
		std::system("rm run.out");
		 
	} else {
		std::cout << "Invalid option. Please enter 1 or 2." << std::endl;
	}


	return 0;
}

