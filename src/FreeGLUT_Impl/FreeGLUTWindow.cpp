#ifndef __NEUTRONWL_IMPL_FREEGLUT_FREEGLUTWINDOW_CPP__
#define __NEUTRONWL_IMPL_FREEGLUT_FREEGLUTWINDOW_CPP__

#include "FreeGLUTWindow.hpp"
#include "callbacks.hpp"

namespace nwl
{
    glm::ivec2 FreeGLUTWindow::m_window_size = glm::ivec2(-1, -1);
    glm::dvec2 FreeGLUTWindow::m_mouse_pos = glm::dvec2(-1.0, -1.0);

    FreeGLUTWindow::FreeGLUTWindow(
        int window_index)
        : m_window_index(window_index) {}

    int
    FreeGLUTWindow::get_window_index() const
    {
        return m_window_index;
    }

    void
    FreeGLUTWindow::set_window_index(
        int window_index)
    {
        m_window_index = window_index;
    }

    bool
    FreeGLUTWindow::is_open()
    {
        return true;
    }

    void
    FreeGLUTWindow::process_events()
    {
        glutMainLoopEvent();
    }

    glm::ivec2
    FreeGLUTWindow::get_window_size()
    {
        return m_window_size;
    }

    glm::dvec2
    FreeGLUTWindow::get_mouse_pos()
    {
        return m_mouse_pos;
    }

    void
    FreeGLUTWindow::display()
    {
        glutSwapBuffers();
    }

    void
    FreeGLUTWindow::initialize_freeglut(
        int *argc,
        char *argv[])
    {
        glutInit(argc, argv);
    }

    void
    FreeGLUTWindow::create(
        const std::string &title,
        int display_mode)
    {
        glutInitDisplayMode(display_mode);
        glutCreateWindow(title.data());

        glutDisplayFunc(nwl_freeglut_display);
        glutReshapeFunc(nwl_freeglut_reshape);

        glutSetWindowData(this);
    }

    void
    FreeGLUTWindow::create(
        int width,
        int height,
        const std::string &title,
        int display_mode)
    {
        glutInitWindowSize(width, height);
        create(title, display_mode);
    }

    void
    FreeGLUTWindow::init_context(
        int major,
        int minor,
        int profile,
        int flags)
    {
        glutInitContextVersion(major, minor);
        glutInitContextProfile(profile);
        glutInitContextFlags(flags);
    }
} // namespace nwl

#endif