#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "glm/glm.hpp"

#include "rotate.h"

using namespace std;

//parseFile is used to take in a ifstream and parse it for the values needed
void parseFile(ifstream *fileStream) {

	string fileLine;
	string vertexString;
	double vertexValue;

	//iterates through each line
	while (std::getline(*fileStream, fileLine)) {

		//checks for a vertex line
		if ((fileLine.substr(0, fileLine.find_first_of(" "))) == "v") {

			stringstream ss(fileLine); // Turn the string into a stream.
			getline(ss, vertexString, ' '); //gets rid of the "v"

			while (getline(ss, vertexString, ' ')) {
				cout << vertexString << "\n";
			}
		}

	}

}

int main()
{
	cudaError_t cudaStatus;

	ifstream MODEL_LIST("model_list.txt");
	ifstream *inputObjFilePtr;
	ifstream inputObjFile;
	inputObjFilePtr = &inputObjFile;
	string currentObjFile;
	string fileLine;

	//gets line with name of file then opens that file
	getline(MODEL_LIST, currentObjFile);
	inputObjFile.open(currentObjFile);
	if (!inputObjFile) { perror("File open error!\n"); } 
	
	parseFile(inputObjFilePtr);

	inputObjFile.close();
	inputObjFile.clear();

	getline(MODEL_LIST, currentObjFile);
	inputObjFile.open(currentObjFile);
	if (!inputObjFile) { perror("File open error!\n"); }

	//parseFile(inputObjFilePtr);
	

	// cudaDeviceReset must be called before exiting in order for profiling and
	// tracing tools such as Nsight and Visual Profiler to show complete traces.
	/*cudaStatus = cudaDeviceReset();
	if (cudaStatus != cudaSuccess) {
		fprintf(stderr, "cudaDeviceReset failed!");
		return 1;
	}*/

	scanf("");
	return 0;
}


