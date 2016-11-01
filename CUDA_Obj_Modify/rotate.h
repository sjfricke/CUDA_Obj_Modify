#pragma once

#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <iostream>

#include "UtilDefine.h"

cudaError_t rotateWithCuda(std::vector<glm::vec3> *vertexIn, std::map<int, std::vector<glm::vec3>> *vertexOut, glm::vec3 rotation);
