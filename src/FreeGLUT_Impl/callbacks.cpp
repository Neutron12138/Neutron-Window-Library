#ifndef __NEUTRONWL_IMPL_FREEGLUT_CALLBACKS_CPP__
#define __NEUTRONWL_IMPL_FREEGLUT_CALLBACKS_CPP__

#include <GL/freeglut.h>
#include "callbacks.hpp"
#include "FreeGLUTWindow.hpp"

namespace nwl
{
    void nwl_freeglut_display() {}

    void
    nwl_freeglut_reshape(
        int width,
        int height)
    {
        FreeGLUTWindow::m_window_size =
            glm::ivec2(
                width,
                height);

        void *userData = glutGetWindowData();
        if (userData != nullptr)
        {
            FreeGLUTWindow *window = static_cast<FreeGLUTWindow *>(userData);
            window->onResized(
                glm::uvec2(
                    static_cast<unsigned int>(width),
                    static_cast<unsigned int>(height)));
        }
    }
} // namespace nwl

#endif