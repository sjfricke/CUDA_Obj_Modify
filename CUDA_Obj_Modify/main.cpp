#include "cuda_runtime.h"
#include "device_launch_parameters.h"


#include <fstream>
#include <sstream>

#include "UtilDefine.h"
#include "rotate.h"

using namespace std;

//parseFile is used to take in a ifstream and parse it for the values needed
void parseFile(ifstream *fileStream)
{
	string fileLine;
	string vertexString;
	//double vertexValue;

	std::vector<string> faces;
	std::vector<glm::vec3> originalVertices;

	//declared once here, reassigned many times
	string firstWord;
	glm::vec3 currentVertex;


	//iterates through each line
	while (std::getline(*fileStream, fileLine)) 
	{
		//OBJ always starts line with identifier string
		firstWord = (fileLine.substr(0, fileLine.find_first_of(" ")));

		//checks for a vertex line
		if (firstWord == "v") 
		{
			//gets the vertex and parses into a vec3
			stringstream ss(fileLine); // Turn the string into a stream.
			getline(ss, vertexString, ' '); //gets rid of the "v"
			
			getline(ss, vertexString, ' ');
			currentVertex.x = stod(vertexString);
			
			getline(ss, vertexString, ' ');
			currentVertex.y = stod(vertexString);
			
			getline(ss, vertexString, ' ');
			currentVertex.z = stod(vertexString);

			originalVertices.push_back(currentVertex);
		}
		else if(firstWord == "f" ) 
		{
			//saves all faces to array to be rewritten later
			faces.push_back(fileLine);
		}
		

	}

	//goes and gets all the vertices into a vector
	//from here a 2D array is assembled with the known size
	glm::vec3 *setOfVertices = (glm::vec3*) malloc( sizeof(glm::vec3) * originalVertices.size()); 
	if (setOfVertices == NULL) { perror("set of vertices malloc fail"); }

	//transfer original data over
	std::copy(originalVertices.begin(), originalVertices.end(), setOfVertices);

	glm::vec3 **allVertices_h;
	//allVertices_h = (glm::vec3**) malloc(sizeof(std::vector<glm::vec3>) * 64); //maxed at a 4x4x4 or 8x8x1 rotation atm

	cout << originalVertices.size() << endl;
	cout << sizeof(originalVertices) << endl;
	cout << sizeof(*setOfVertices) << endl;



	//cout << allVertices_h << endl;
	//cout << &allVertices_h[0] << endl;
	//cout << &allVertices_h[1] << endl;
	//cout << allVertices_h[0].at(1).x << endl;
	//cout << &allVertices_h[0].at(1).x << endl;
	//cout << allVertices_h[0].at(2).x << endl;
	//cout << &allVertices_h[0].at(2).x << endl;
	
	//rotateWithCuda(&orginalVertices, &allVertices, X4_Y4_Z4);
	
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

	parseFile(inputObjFilePtr);
	

	// cudaDeviceReset must be called before exiting in order for profiling and
	// tracing tools such as Nsight and Visual Profiler to show complete traces.
	/*cudaStatus = cudaDeviceReset();
	if (cudaStatus != cudaSuccess) {
		fprintf(stderr, "cudaDeviceReset failed!");
		return 1;
	}*/

	inputObjFile.close();

	scanf("");
	return 0;
}


