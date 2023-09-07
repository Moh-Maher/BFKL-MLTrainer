#include <iostream>
#include <cstdlib>
#include <cstring>
#include"../include/utilities.h"
int main(int argc, char* argv[]) {
	// Check the number of command-line arguments
	if (argc < 2) {
	std::cerr << "Usage: " << argv[0] << " <mode>" << std::endl;
	return 1; // Exit with an error code
	}

	// Define the input values for new_feature_values
	// Define variables to store user input
	int n;
	int nu_start;
	int nu_end;
	double Y;
	double MuR;

	// Prompt the user to enter values for new_feature_values
	std::cout << "Enter the value for n: ";
	std::cin >> n;

	std::cout << "Enter the value for nu_start: ";
	std::cin >> nu_start;

	std::cout << "Enter the value for nu_end: ";
	std::cin >> nu_end;

	std::cout << "Enter the value for Y: ";
	std::cin >> Y;

	std::cout << "Enter the value for MuR: ";
	std::cin >> MuR;
	// Compare the command-line argument with a string
	if (strcmp(argv[1], "LLA") == 0) {
	       Output meta_data("data/data_preparation/LLA_meta_data.txt"); 
		meta_data.takeData <<n <<"\t"<<MuR<<std::endl;
		std::cout << "Mode LLA selected." << std::endl;
		std::string command = "python3 python/LLA_bfkl_controller.py " +
				  std::to_string(n) + " " +
				  std::to_string(nu_start) + " " +
				  std::to_string(nu_end) + " " +
				  std::to_string(Y) + " " +
				  std::to_string(MuR);
		int exitCode = std::system(command.c_str());

		if (exitCode == 0) {
			std::cout << "Python script executed successfully." << std::endl;
		} else {
			std::cerr << "Error: Failed to execute Python script." << std::endl;
		    }
	} else if (strcmp(argv[1], "NLA") == 0) {
	 	Output meta_data("data/data_preparation/NLA_meta_data.txt"); 
		meta_data.takeData <<n <<"\t"<<MuR<<std::endl;
		std::cout << "Mode NLA selected." << std::endl;
		std::string command = "python3 python/NLA_bfkl_controller.py " +
			          std::to_string(n) + " " +
			          std::to_string(nu_start) + " " +
			          std::to_string(nu_end) + " " +
			          std::to_string(Y) + " " +
			          std::to_string(MuR);
		int exitCode = std::system(command.c_str());

		if (exitCode == 0) {
			std::cout << "Python script executed successfully." << std::endl;
		} else {
			std::cerr << "Error: Failed to execute Python script." << std::endl;
		}
	} else {
		std::cerr << "Invalid mode. Use 'L' or 'M'." << std::endl;
		return 1; // Exit with an error code
	}


	return 0;
}

