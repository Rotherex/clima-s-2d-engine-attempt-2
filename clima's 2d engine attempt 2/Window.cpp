#include "Window.h"

	Window::Window(const char* name, int width, int height)
	{
		m_Width = width;
		m_Height = height;
		m_Name = name;

		if (!init()) {
			glfwTerminate();
		}
	}

	bool Window::closed()
	{
		return glfwWindowShouldClose(m_Window);
	}

	bool Window::init()
	{
		if (!glfwInit())
		{
			std::cout << "Failed to initialise GLFW!" << std::endl;
			return false;
		}

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Name, NULL, NULL);

		if (!m_Window)
		{
			glfwTerminate();
			std::cout << "Failed to initialise GLFW window!" << std::endl;
			return false;
		}

		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, this);

		glViewport(0, 0, m_Width, m_Height);

		return true;
	}

	void Window::clear()
	{
		glClearColor(0.8f, 1.0f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::update()
	{
		glfwPollEvents();
		glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
		glfwSwapBuffers(m_Window);
	}