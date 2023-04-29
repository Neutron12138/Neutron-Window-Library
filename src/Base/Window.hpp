#ifndef __NEUTRONWL_WINDOW_WINDOW_HPP__
#define __NEUTRONWL_WINDOW_WINDOW_HPP__

#include <queue>
#include <ntl/NTL.hpp>

namespace nwl
{
    /// @brief 窗口类
    class Window : public ntl::Object
    {
    public:
        using SelfType = Window;
        using ParentType = ntl::Object;

    public:
        Window() = default;
        explicit Window(const SelfType &from) = default;
        ~Window() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        /// @brief 当窗口大小改变时调用
        /// @param new_size 窗口新大小
        virtual void onResized(const glm::uvec2 &new_size);

        /// @brief 当鼠标位置移动时调用
        /// @param mouse_pos 鼠标位置
        virtual void onMouseMoved(const glm::ivec2 &mouse_pos);

    public:
        /// @brief 检查窗口是否正在运行
        /// @return 窗口是否正在运行
        virtual bool is_open() = 0;

        /// @brief 处理事件
        virtual void process_events() = 0;

        /// @brief 把绘制的内容展示在屏幕上
        virtual void display() = 0;
    };

} // namespace nwl

#endif
