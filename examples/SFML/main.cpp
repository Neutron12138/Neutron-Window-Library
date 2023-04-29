#include <iostream>
#include <GL/glew.h>
#include <SFML/Graphics.hpp>
#define NEUTRONTL_CONFIG_USE_APPLICATION
#define NEUTRONWL_CONFIG_USE_SFML
#include "../../src/NWL.hpp"
#include "../../src/NWL.cpp"

class MyWindow : public nwl::SFMLWindow
{
public:
    void onResized(const glm::uvec2 &new_size) override
    {
        std::cout << "void onResized(const glm::uvec2 &new_size)" << std::endl;
        std::cout << "new_size:" << new_size.x << "," << new_size.y << std::endl;
    }
};

class MyApp : public nwl::WindowedApplication<MyWindow>
{
public:
    void onCreated() override
    {
        m_window = ntl::make_shared<MyWindow>();
        m_window->create(640, 480, "SFML Window", 3, 3);

        if (glewInit() != GLEW_OK)
        {
            std::cout << "glewInit() != GLEW_OK" << std::endl;
            quit(EXIT_FAILURE);
        }
    }

    void onDraw() override
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.1f, 0.1f, 0.1, 1.0f);
    }
};

ntl::Application &get_application()
{
    static MyApp app;
    return app;
}
