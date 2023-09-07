/*main.h is a part of BFKL-MLTrainer 

usage: defines functions to make the code more modular and easier to read

by:  Mohammed Maher Abdelrahim Mohammed
                                          */
#pragma once
#ifndef INCLUDE_MAIN_H
#define INCLUDE_MAIN_H

//------------------------------------------------------------------------
//	function clears the console screen
//------------------------------------------------------------------------
void clear_screen() {
	#ifdef _WIN32
		std::system("cls");
	#else
		std::system("clear");
	#endif
}
//------------------------------------------------------------------------
//	displays the initial welcome message
//------------------------------------------------------------------------
void display_welcome_message() {
	clear_screen();
	std::cout << "Welcome to BFKL-MLTrainer!" << std::endl;
	std::cout << "=================================" << std::endl;
	std::cout << "This is a tool for using machine learning models" << std::endl;
	std::cout << "to work with the BFKL (Balitsky-Fadin-Kuraev-Lipatov) kernel." << std::endl;
	std::cout << "Please select an option from the following:" << std::endl;
	std::cout << "1. Predict data" << std::endl;
	std::cout << "2. Train data" << std::endl;
	std::cout << "3. Plot LLA/NLA predictions" << std::endl;
	std::cout << "=================================" << std::endl;
}
//------------------------------------------------------------------------
// 	function handle user input for options.
//------------------------------------------------------------------------
int get_option_choice() {
	int option;
	std::cout << "Enter your choice (1, 2, or 3): ";
	std::cin >> option;
	return option;
}
//------------------------------------------------------------------------
//	function handle user input for script choices.
//------------------------------------------------------------------------
int get_script_choice(int option) {
	int scriptChoice;
	if (option == 1) {
		std::cout << "Choose a script for Predictions :" << std::endl;
		std::cout << "1. LLA BFKL Predictions" << std::endl;
		std::cout << "2. NLA BFKL Predictions" << std::endl;
		std::cout << "Enter your choice (1 or 2): ";
	} else if (option == 2) {
		std::cout << "Choose a script for Training a model:" << std::endl;
		std::cout << "1. New data" << std::endl;
		std::cout << "2. Preexist data" << std::endl;
		std::cout << "Enter your choice (1 or 2): ";
	} else {
		return -1; // Invalid option
	}
	
	std::cin >> scriptChoice;
	return scriptChoice;
}
//------------------------------------------------------------------------
//	function runs Python scripts using the std::system()
//------------------------------------------------------------------------
void run_python_script(const std::string& scriptPath) {
	std::string command = "python3 " + scriptPath;
	std::system(command.c_str());
}

#endif
