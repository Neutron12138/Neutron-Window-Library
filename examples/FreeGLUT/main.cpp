#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "../../src/NWL.hpp"
#include "../../src/NWL.cpp"

class MyWindow : public nwl::FreeGLUTWindow
{
public:
    MyWindow()
    {
        create("FreeGLUT Window");

        if (glewInit() != GLEW_OK)
        {
            std::cout << "glewInit() != GLEW_OK" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    ~MyWindow() override = default;

public:
    void onResized(const glm::uvec2 &new_size) override
    {
        std::cout << "void onResized(const glm::uvec2 &new_size)" << std::endl;
        std::cout << "new_size:" << new_size.x << "," << new_size.y << std::endl;
    }
};

int main(int argc, char *argv[])
{
    nwl::FreeGLUTWindow::initialize_freeglut(&argc, argv);
    nwl::FreeGLUTWindow::init_context(3, 3);

    MyWindow window;

    while (window.is_open())
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.1f, 0.1f, 0.1, 1.0f);
        window.display();
        window.process_events();
    }

    return 0;
}