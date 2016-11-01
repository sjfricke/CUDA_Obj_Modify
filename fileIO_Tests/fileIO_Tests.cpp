// fileIO_Tests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdint.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "glm/glm.hpp"

using namespace std;

int main()
{

	cout << sizeof(vector<glm::vec3>[256]) << endl;
	cout << sizeof(vector<int>) << endl;

	fstream fileStream;
	string fileLine;
	string firstWord;
	long lineCount = 0;

	fileStream.open("TestFile.txt", ios::out | ios::in);
	//ofstream newFile("result.txt");
	if (!fileStream) { perror("File open error!\n"); }
	//if (!newFile) { perror("File open error!\n"); }

	while (!fileStream.eof())
	{
		getline(fileStream, fileLine);
		lineCount++;

		firstWord = (fileLine.substr(0, fileLine.find_first_of(" ")));

		//checks for a vertex line
		if (firstWord == "v") {
			
		}
		else {

		}
	}


	fileStream.close();
	//newFile.close();
	return 0;
}

