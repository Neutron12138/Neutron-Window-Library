#ifndef __NEUTRONWL_IMPL_GLFW_CALLBACKS_CPP__
#define __NEUTRONWL_IMPL_GLFW_CALLBACKS_CPP__

#include "callbacks.hpp"
#include "GLFWWindow.hpp"

namespace nwl
{
    void
    nwl_glfw_framebuffer_size(
        GLFWwindow *window,
        int width,
        int height)
    {
        void *userData = glfwGetWindowUserPointer(window);
        if (userData != nullptr)
        {
            GLFWWindow *window = static_cast<GLFWWindow *>(userData);
            window->onResized(
                glm::uvec2(
                    width,
                    height));
        }
    }
} // namespace nwl

#endif