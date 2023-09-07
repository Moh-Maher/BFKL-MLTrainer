/*-----------------------------------------------------------------------
by:  Mohammed Maher Abdelrahim Mohammed                                         
-----------------------------------------------------------------------*/
#pragma once
#ifndef INCLUDE_UTILITIES_H
#define INCLUDE_UTILITIES_H
 
#include<string>
#include<sstream>

#include<complex>
#include<iostream>
#include<cmath>
#include<ctime>
#include<fstream>

#include <stdexcept>

//--------------------------------------------------------------------
/*! \class Output
* \brief Class to handle output operations and files.
*/
//--------------------------------------------------------------------
class Output
{
public:
    std::ofstream takeData; ///< Output stream class object to operate on files

    /*! Constructor to receive the output file name and file format.
    * @param fileName is the name of the output file without the extension.
    * @param fileFormat is the format of the output file (e.g., ".dat", ".txt").
    */
    Output(const std::string& fileName)
    {
        takeData.open(fileName);
        if (!takeData.is_open())
        {
            throw std::runtime_error("Error opening output file.");
        }
    }

    // Add move constructor and move assignment operator (optional)

    ~Output()
    {
        if (takeData.is_open())
        {
            takeData.close();
        }
    } ///< Destructor to close the output file

    /*! Function to write output to file.
    *@param output represents the received data contents.
    */
    void writeOutput(const std::string& output)
    {
        if (takeData.is_open())
        {
            takeData << output << std::endl;
        }
    }

    // Overload the stream insertion operator to simplify writing data.
    Output& operator<<(const std::string& data)
    {
        writeOutput(data);
        return *this;
    }
};

//--------------------------------------------------------------------
/*! \class Input
* \brief Class to handle input operations and files.
*/
//--------------------------------------------------------------------
class Input
{
public:
    std::ifstream getData; ///< Input stream class object to read from files

    /*! Constructor to receive the input file name and file format.
    * @param fileName is the name of the input file without the extension.
    * @param fileFormat is the format of the input file (e.g., ".dat", ".txt").
    */
    Input(const std::string& fileName)
    {
        getData.open(fileName);
        if (!getData.is_open())
        {
            throw std::runtime_error("Error opening input file.");
        }
    }

    // Add move constructor and move assignment operator (optional)

    ~Input()
    {
        if (getData.is_open())
        {
            getData.close();
        }
    } ///< Destructor to close the input file

    /*! Function to read data from the input file and return it as a string.
    * @return The contents of the input file as a string.
    */
    std::string readInput()
    {
        std::string data;
        std::string line;
        while (std::getline(getData, line))
        {
            data += line + "\n";
        }
        return data;
    }

    // Overload the stream extraction operator to simplify reading data.
    Input& operator>>(std::string& data)
    {
        data = readInput();
        return *this;
    }
};


//--------------------------------------------------------------------
/*! \class ElapsedTime
* \brief Class to displays information about the execution time.
*/
//--------------------------------------------------------------------
class ElapsedTime{
	public:
		void Start(){
			start = std::clock();
		}
		void End()
		{
			std::cout<<"------------------------------------------"<<std::endl;
			duration = static_cast<double>(std::clock() - start) /static_cast<double> CLOCKS_PER_SEC;
			
			if (duration < 60.0) {
				std::cout << "Elapsed time: " << duration << " seconds !!" << std::endl;
			}
			else {
				std::cout << "Elapsed time: " << duration/60.0 << " mins" << std::endl;
			}
		}
	private:
		std::clock_t start;
		double duration;
};

//------------------------------------------------------------------
//
//------------------------------------------------------------------
int countLinesInFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return -1; // Return -1 to indicate an error
    }

    int lineCount = 0;
    std::string line;
    while (std::getline(file, line)) {
        lineCount++;
    }

    file.close();
    return lineCount;
}
 
#endif
