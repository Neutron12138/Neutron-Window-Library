#ifndef __NEUTRONWL_IMPL_SFML_SFMLWINDOW_HPP__
#define __NEUTRONWL_IMPL_SFML_SFMLWINDOW_HPP__

#include <SFML/Graphics.hpp>
#include <ntl/NTL.hpp>
#include "../Window/Window.hpp"

namespace nwl
{
    /// @brief 窗口类的SFML实现
    class SFMLWindow : public Window
    {
    public:
        using SelfType = SFMLWindow;
        using ParentType = Window;

    public:
        /// @brief 窗口，sf::RenderWindow是一个NonCopyable
        ntl::SharedPointer<sf::RenderWindow> m_window;

    public:
        SFMLWindow() = default;
        explicit SFMLWindow(const ntl::SharedPointer<sf::RenderWindow> &window);
        explicit SFMLWindow(const SelfType &from) = default;
        ~SFMLWindow() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        /// @brief 获取窗口
        /// @return 指向窗口的智能指针
        const ntl::SharedPointer<sf::RenderWindow> &get_window() const;

        /// @brief 设置窗口
        /// @return 指向窗口的智能指针
        virtual void set_window(const ntl::SharedPointer<sf::RenderWindow> &window);

    public:
        bool is_open() override;
        void process_events() override;
        glm::ivec2 get_window_size() override;
        glm::dvec2 get_mouse_pos() override;
        void display() override;

    public:
        /// @brief 创建窗口
        /// @param width 窗口宽度
        /// @param height 窗口高度
        /// @param title 窗口标题
        void create(unsigned int width, unsigned int height, const std::string &title);

        /// @brief 创建窗口
        /// @param width 窗口宽度
        /// @param height 窗口高度
        /// @param title 窗口标题
        /// @param major 主版本
        /// @param minor 副版本
        void create(unsigned int width, unsigned int height, const std::string &title, unsigned int major, unsigned int minor);

        /// @brief 创建窗口
        /// @param mode 显示模式
        /// @param title 窗口标题
        /// @param style 窗口风格
        /// @param settings 上下文设置
        void create(const sf::VideoMode &mode, const sf::String &title, sf::Uint32 style, const sf::ContextSettings &settings);
    };
} // namespace nwl

#endif