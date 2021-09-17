#include "Window.h"

Window::Window(const char* name, int width, int height) :
	m_Width(width),
	m_Height(height),
	m_Name(name)
	{
		if (!init()) {
			glfwTerminate();
		}
	}

	bool Window::closed()
	{
		return glfwWindowShouldClose(this->m_Window);
	}

	bool Window::init()
	{

		if (!glfwInit())
		{
			std::cout << "Failed to initialise GLFW!" << std::endl;
			return false;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

		this->m_Window = glfwCreateWindow(this->m_Width, this->m_Height, this->m_Name, NULL, NULL);

		if (!this->m_Window)
		{
			glfwTerminate();
			std::cout << "Failed to initialise GLFW window!" << std::endl;
			return false;
		}

		glfwMakeContextCurrent(this->m_Window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
			return false;
		}

		glfwSetWindowUserPointer(this->m_Window, this);

		glViewport(0, 0, this->m_Width, this->m_Height);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

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
		glfwGetFramebufferSize(this->m_Window, &m_Width, &m_Height);
		glfwSwapBuffers(this->m_Window);
	}
