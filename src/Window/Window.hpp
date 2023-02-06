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
        /// @brief 当窗口创建时调用
        virtual void onCreated();

        /// @brief 当窗口销毁时调用
        virtual void onDestroyed();

        /// @brief 当窗口大小改变时调用
        /// @param new_size 窗口新大小
        virtual void onResized(const glm::uvec2 &new_size);

    public:
        /// @brief 检查窗口是否正在运行
        /// @return 窗口是否正在运行
        virtual bool is_open() = 0;

        /// @brief 处理事件
        virtual void process_events() = 0;

        /// @brief 获取窗口大小
        /// @return 窗口大小
        virtual glm::ivec2 get_window_size() = 0;

        /// @brief 获取鼠标位置
        /// @return 鼠标位置
        virtual glm::dvec2 get_mouse_pos() = 0;

        /// @brief 把绘制的内容展示在屏幕上
        virtual void display() = 0;
    };
} // namespace nwl

#endif