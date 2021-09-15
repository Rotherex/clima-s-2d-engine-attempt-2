#include "Window.h"
#include "shader.h"
#include "ResourceManager.h"
#include "Renderer.h"

Renderer* renderer;

int main()
{

    Window window("this will not work", 800, 600);
    glClearColor(0.2f, 0.3f, 0.1f, 1.0f);

    ResourceManager::LoadShader("shader.vs", "shader.fs", nullptr, "shader");

    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(window.getWidth()), static_cast<float>(window.getHeight()), 0.0f, -1.0f, 1.0f);
    ResourceManager::GetShader("sprite").Use().SetInteger("sprite", 0);
    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);

    Shader drawShader = ResourceManager::GetShader("shader");

    renderer = new Renderer(drawShader);

    while (!window.closed())
    {
        window.clear();

        renderer->Draw(glm::vec2(10.0f, 10.0f), glm::vec2(30.0f, 30.0f), 0.0f, glm::vec3(255.0f, 255.0f, 255.0f));

        window.update();
    }

    return 0;
}