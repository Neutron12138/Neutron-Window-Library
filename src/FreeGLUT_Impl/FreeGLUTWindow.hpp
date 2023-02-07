#ifndef __NEUTRONWL_IMPL_FREEGLUT_FREEGLUTWINDOW_HPP__
#define __NEUTRONWL_IMPL_FREEGLUT_FREEGLUTWINDOW_HPP__

#include <GL/freeglut.h>
#include "../Window/Window.hpp"

namespace nwl
{
    /// @brief 窗口类的FreeGLUT实现
    class FreeGLUTWindow : public Window
    {
    public:
        using SelfType = FreeGLUTWindow;
        using ParentType = Window;

        /// @brief 窗口大小
        static glm::ivec2 m_window_size;
        /// @brief 鼠标位置
        static glm::dvec2 m_mouse_pos;

    protected:
        /// @brief 窗口索引
        int m_window_index = 0;

    public:
        FreeGLUTWindow() = default;
        explicit FreeGLUTWindow(int window_index);
        explicit FreeGLUTWindow(const SelfType &from) = default;
        ~FreeGLUTWindow() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        /// @brief 获取窗口索引
        /// @return 窗口索引
        int get_window_index() const;

        /// @brief 设置窗口索引
        /// @param window_index 窗口索引
        virtual void set_window_index(int window_index);

    public:
        bool is_open() override;
        void process_events() override;
        glm::ivec2 get_window_size() override;
        glm::dvec2 get_mouse_pos() override;
        void display() override;

    public:
        /// @brief 初始化FreeGLUT
        /// @param argc 入口参数数量
        /// @param argv 入口参数
        static void initialize_freeglut(int *argc, char *argv[]);

        /// @brief 创建窗口
        /// @param title 窗口标题
        /// @param display_mode 显示模式
        void create(const std::string &title, int display_mode = GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);

        /// @brief 创建窗口
        /// @param width 窗口宽度
        /// @param height 窗口高度
        /// @param title 窗口标题
        /// @param display_mode 显示模式
        void create(int width, int height, const std::string &title, int display_mode = GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);

        /// @brief 初始化上下文
        /// @param major 主版本
        /// @param minor 副版本
        /// @param profile 代理模式
        /// @param flags 标签
        static void init_context(int major, int minor, int profile = GLUT_CORE_PROFILE, int flags = GLUT_FORWARD_COMPATIBLE | GLUT_DEBUG);
    };
} // namespace nwl

#endif