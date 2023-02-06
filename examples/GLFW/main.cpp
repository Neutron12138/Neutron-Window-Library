#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../../src/NWL.hpp"
#include "../../src/NWL.cpp"

class MyWindow : public nwl::GLFWWindow
{
public:
    MyWindow()
    {
        if (!create(640, 480, "GLFW Window"))
        {
            std::cout << "create(640, 480, \"GLFW Window\")" << std::endl;
            terminate_glfw();
            exit(EXIT_FAILURE);
        }
    }

    ~MyWindow() override = default;

public:
    void onCreated() override
    {
        std::cout << "onCreated()" << std::endl;

        make_context_current();

        if (glewInit() != GLEW_OK)
        {
            std::cout << "glewInit() != GLEW_OK" << std::endl;
            terminate_glfw();
            exit(EXIT_FAILURE);
        }
    }

    void onDestroyed() override
    {
        std::cout << "onDestroyed()" << std::endl;
    }

    void onResized(const glm::uvec2 &new_size) override
    {
        std::cout << "void onResized(const glm::uvec2 &new_size)" << std::endl;
        std::cout << "new_size:" << new_size.x << "," << new_size.y << std::endl;
    }
};

int main()
{
    if (!nwl::GLFWWindow::initialize_glfw())
    {
        std::cout << "nwl::GLFWWindow::initialize_glfw()" << std::endl;
        exit(EXIT_FAILURE);
    }
    nwl::GLFWWindow::init_opengl_context_hint(3, 3);

    MyWindow window;

    while (window.is_open())
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.1f, 0.1f, 0.1, 1.0f);
        window.display();
        window.process_events();
    }

    window.onDestroyed();
    nwl::GLFWWindow::terminate_glfw();

    return 0;
}