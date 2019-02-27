#pragma once
#include<vector>
#include "shader.h"
#include "Move.h"
#include "Mesh.h"
#include <Windows.h>
#include <iostream>
#include "display.h"
#include "mesh.h"
#include "shader.h"
#include "inputManager.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <vector>
#include "Cube.h"
#include "stb_image.h"


class scene
{
	private:
		bool text=false;
		std::vector<Shader*> shaders;
		std::vector<Cube*>* cubearray;
		Cube* bigCube;
		int n;
		GLuint textures[1];
		GLuint textures1[1];
public:
	int width, height, width1, height1, numComponents, numComponents1;
	unsigned char* data;
	unsigned char* data1;
	float rotate_y = 0;
	glm::mat4 m = glm::mat4();
	float rotate_x = 0;
	glm::mat4 cubepos;
	void printmvp(glm::mat4 mvp);
	int getN() { return this->n; }
	void update_rotate_x(float x);
	void update_rotate_y(float y);
	scene();
	~scene();
	void set_shader(std::vector<Shader*> shader)
	{
		this->shaders = shader;
	}
	void insertBigCube(Cube* bigCube);
	void insertn(int n);
	void insertCubeArray(std::vector<Cube*>* cubearray);
	std::vector<Shader*> get_shader() {
		return this->shaders;
	}
	std::vector<glm::mat4> draw(int numshader,Display* display, glm::mat4 M, glm::mat4 P);
	void drawAxis();
};