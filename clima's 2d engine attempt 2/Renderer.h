#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>

#include "shader.h"

class Renderer
{
public:
	Renderer(Shader& shader);

	~Renderer();

	void Draw(glm::vec2 pos, glm::vec2 size, float rotate, glm::vec3 color);

private:
	Shader shader;
	unsigned int quadVAO;

	void initRenderData();
};

