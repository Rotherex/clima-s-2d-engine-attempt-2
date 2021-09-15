#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Window
{
public:

	Window(const char* name, int width, int height);

	void update();
	bool closed();

	void clear();

	inline int getWidth() const { return m_Width; };
	inline int getHeight() const { return m_Height; };

private:
	friend struct GLFWwindow;

	GLFWwindow* m_Window;
	const char* m_Name;

	int m_Width, m_Height;

	bool init();
	bool m_Closed;
};
