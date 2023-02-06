#ifndef __NEUTRONWL_IMPL_GLFW_GLFWWINDOW_HPP__
#define __NEUTRONWL_IMPL_GLFW_GLFWWINDOW_HPP__

#include <string>
#include <GLFW/glfw3.h>
#include <ntl/NTL.hpp>
#include "../Window/Window.hpp"

namespace nwl
{
    /// @brief 窗口类的GLFW实现
    class GLFWWindow : public Window
    {
    public:
        using SelfType = GLFWWindow;
        using ParentType = Window;

    protected:
        /// @brief 窗口
        GLFWwindow *m_window = nullptr;

    public:
        constexpr GLFWWindow() = default;
        explicit GLFWWindow(GLFWwindow *window);
        explicit GLFWWindow(const SelfType &from) = default;
        ~GLFWWindow() override = default;

    public:
        constexpr SelfType &operator=(const SelfType &from) = default;

    public:
        /// @brief 获取窗口
        /// @return 窗口
        GLFWwindow *get_window() const;

        /// @brief 设置窗口
        /// @param window 窗口
        virtual void set_window(GLFWwindow *window);

    public:
        /// @brief 创建一个GLFW窗口
        /// @param width 窗口宽度
        /// @param height 窗口高度
        /// @param title 窗口标题
        /// @param moniter 显示器
        /// @param share 共享上下文
        /// @return 是否创建成功
        virtual bool create(int width, int height, const std::string &title, GLFWmonitor *moniter = nullptr, GLFWwindow *share = nullptr);

        /// @brief 销毁持有的GLFW窗口
        virtual void destroy();

        /// @brief 绑定为当前上下文
        virtual void make_context_current();

    public:
        bool is_open() override;
        void process_events() override;
        glm::ivec2 get_window_size() override;
        glm::dvec2 get_mouse_pos() override;
        void display() override;

    public:
        /// @brief 初始化GLFW
        static bool initialize_glfw();

        /// @brief 销毁GLFW
        static void terminate_glfw();

        /// @brief 初始化OpenGL上下文提示
        /// @param major 主版本
        /// @param minor 副版本
        /// @param profile 代理模式
        static void init_opengl_context_hint(int major, int minor, int profile = GLFW_OPENGL_CORE_PROFILE);
    };
} // namespace nwl

#endif