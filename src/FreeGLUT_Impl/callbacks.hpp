#ifndef __NEUTRONWL_IMPL_FREEGLUT_CALLBACKS_HPP__
#define __NEUTRONWL_IMPL_FREEGLUT_CALLBACKS_HPP__

namespace nwl
{
    /// @brief 窗口需要更新时调用
    void nwl_freeglut_display();

    /// @brief 窗口形状调整时调用
    /// @param width 宽度
    /// @param height 高度
    void nwl_freeglut_reshape(int width,int height);
} // namespace nwl


#endif