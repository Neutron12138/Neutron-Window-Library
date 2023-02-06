#ifndef __NEUTRONWL_IMPL_GLFW_GLFWWINDOW_CPP__
#define __NEUTRONWL_IMPL_GLFW_GLFWWINDOW_CPP__

#include <ntl/NTL.hpp>
#include "GLFWWindow.hpp"
#include "callbacks.hpp"

namespace nwl
{
    GLFWWindow::GLFWWindow(
        GLFWwindow *window)
        : m_window(window) {}

    GLFWwindow *
    GLFWWindow::get_window() const
    {
        return m_window;
    }

    void
    GLFWWindow::set_window(
        GLFWwindow *window)
    {
        m_window = window;
    }

    bool
    GLFWWindow::create(
        int width,
        int height,
        const std::string &title,
        GLFWmonitor *moniter,
        GLFWwindow *share)
    {
        GLFWwindow *window = glfwCreateWindow(width, height, title.data(), moniter, share);
        if (window != nullptr)
        {
            m_window = window;
            glfwSetWindowUserPointer(m_window, this);
            glfwSetFramebufferSizeCallback(m_window, nwl_glfw_framebuffer_size);
            onCreated();
            return true;
        }

        return false;
    }

    void
    GLFWWindow::destroy()
    {
        if (m_window != nullptr)
        {
            onDestroyed();
            glfwDestroyWindow(m_window);
            m_window = nullptr;
        }
        else
        {
            throw ntl::NullPointerException(NTL_STRING("void GLFWWindow::destroy()"));
        }
    }

    void
    GLFWWindow::make_context_current()
    {
        if (m_window != nullptr)
            glfwMakeContextCurrent(m_window);
        else
            throw ntl::NullPointerException(NTL_STRING("void GLFWWindow::make_context_current()"));
    }

    bool
    GLFWWindow::is_open()
    {
        if (m_window != nullptr)
            return !glfwWindowShouldClose(m_window);
        else
            throw ntl::NullPointerException(NTL_STRING("bool GLFWWindow::is_open()"));
    }

    void
    GLFWWindow::process_events()
    {
        glfwPollEvents();
    }

    glm::ivec2
    GLFWWindow::get_window_size()
    {
        if (m_window != nullptr)
        {
            int w, h;
            glfwGetWindowSize(m_window, &w, &h);
            return glm::ivec2(w, h);
        }
        else
        {
            throw ntl::NullPointerException(NTL_STRING("glm::ivec2 GLFWWindow::get_window_size()"));
        }
    }

    glm::dvec2
    GLFWWindow::get_mouse_pos()
    {
        if (m_window != nullptr)
        {
            double x, y;
            glfwGetCursorPos(m_window, &x, &y);
            return glm::dvec2(x, y);
        }
        else
        {
            throw ntl::NullPointerException(NTL_STRING("glm::dvec2 GLFWWindow::get_mouse_pos()"));
        }
    }

    void
    GLFWWindow::display()
    {
        if (m_window != nullptr)
            glfwSwapBuffers(m_window);
        else
            throw ntl::NullPointerException(NTL_STRING("void GLFWWindow::display()"));
    }

    bool
    GLFWWindow::initialize_glfw()
    {
        return glfwInit() == GLFW_TRUE;
    }

    void
    GLFWWindow::terminate_glfw()
    {
        glfwTerminate();
    }

    void
    GLFWWindow::init_opengl_context_hint(int major, int minor, int profile)
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
        glfwWindowHint(GLFW_OPENGL_PROFILE, profile);
    }
} // namespace nwl

#endif