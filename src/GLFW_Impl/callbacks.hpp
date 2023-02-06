#ifndef __NEUTRONWL_IMPL_GLFW_CALLBACKS_HPP__
#define __NEUTRONWL_IMPL_GLFW_CALLBACKS_HPP__

#include <GLFW/glfw3.h>

namespace nwl
{
    /// @brief GLFW的窗口大小调整的回调函数
    /// @param window GLFW窗口
    /// @param width 宽度
    /// @param height 高度
    void nwl_glfw_framebuffer_size(GLFWwindow *window, int width, int height);
} // namespace nwl

#endif