#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "glm/glm.hpp"

/*
*
* Source of definitions used globally across whole program
*
*/

//Used to set how detailed of rotation from 4 - 512 variations
#define X1_Y1_Z4 glm::vec3(1.0,1.0,4.0)
#define X1_Y1_Z8 glm::vec3(1.0,1.0,8.0)
#define X1_Y4_Z1 glm::vec3(1.0,4.0,1.0)
#define X1_Y4_Z4 glm::vec3(1.0,4.0,4.0)
#define X1_Y4_Z8 glm::vec3(1.0,4.0,8.0)
#define X1_Y8_Z1 glm::vec3(1.0,8.0,1.0)
#define X1_Y8_Z4 glm::vec3(1.0,1.0,4.0)
#define X1_Y8_Z8 glm::vec3(1.0,8.0,8.0)
#define X4_Y1_Z1 glm::vec3(4.0,1.0,1.0)
#define X4_Y1_Z4 glm::vec3(4.0,1.0,4.0)
#define X4_Y1_Z8 glm::vec3(4.0,1.0,8.0)
#define X4_Y4_Z1 glm::vec3(4.0,4.0,1.0)
#define X4_Y4_Z4 glm::vec3(4.0,4.0,4.0)
#define X4_Y4_Z8 glm::vec3(4.0,4.0,8.0)
#define X4_Y8_Z1 glm::vec3(4.0,8.0,1.0)
#define X4_Y8_Z4 glm::vec3(4.0,8.0,4.0)
#define X4_Y8_Z8 glm::vec3(4.0,8.0,8.0)
#define X8_Y1_Z1 glm::vec3(8.0,1.0,1.0)
#define X8_Y1_Z4 glm::vec3(8.0,1.0,4.0)
#define X8_Y1_Z8 glm::vec3(8.0,1.0,8.0)
#define X8_Y4_Z1 glm::vec3(8.0,4.0,1.0)
#define X8_Y4_Z4 glm::vec3(8.0,4.0,4.0)
#define X8_Y4_Z8 glm::vec3(8.0,4.0,8.0)
#define X8_Y8_Z1 glm::vec3(8.0,8.0,1.0)
#define X8_Y8_Z4 glm::vec3(8.0,8.0,4.0)
#define X8_Y8_Z8 glm::vec3(8.0,8.0,8.0)