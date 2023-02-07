#ifndef __NEUTRONWL_IMPL_SFML_SFMLWINDOW_CPP__
#define __NEUTRONWL_IMPL_SFML_SFMLWINDOW_CPP__

#include "SFMLWindow.hpp"

namespace nwl
{
    SFMLWindow::SFMLWindow(
        const ntl::SharedPointer<sf::RenderWindow> &window)
        : m_window(window) {}

    const ntl::SharedPointer<sf::RenderWindow> &
    SFMLWindow::get_window() const
    {
        return m_window;
    }

    void
    SFMLWindow::set_window(
        const ntl::SharedPointer<sf::RenderWindow> &window)
    {
        m_window = window;
    }

    bool
    SFMLWindow::is_open()
    {
        return m_window->isOpen();
    }

    void
    SFMLWindow::process_events()
    {
        sf::Event event;
        while (m_window->pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::EventType::Closed:
                m_window->close();
                break;

            case sf::Event::EventType::Resized:
                onResized(
                    glm::uvec2(
                        event.size.width,
                        event.size.height));
                break;

            default:
                break;
            }
        }
    }

    glm::ivec2
    SFMLWindow::get_window_size()
    {
        sf::Vector2u size = m_window->getSize();
        return glm::ivec2(size.x, size.y);
    }

    glm::dvec2
    SFMLWindow::get_mouse_pos()
    {
        sf::Vector2i pos = sf::Mouse::getPosition();
        return glm::dvec2(
            static_cast<double>(pos.x),
            static_cast<double>(pos.y));
    }

    void
    SFMLWindow::display()
    {
        m_window->display();
    }

    void
    SFMLWindow::create(
        unsigned int width,
        unsigned int height,
        const std::string &title)
    {
        m_window =
            ntl::make_shared<sf::RenderWindow>(
                sf::VideoMode(
                    width,
                    height),
                title);
    }

    void
    SFMLWindow::create(
        unsigned int width,
        unsigned int height,
        const std::string &title,
        unsigned int major,
        unsigned int minor)
    {
        m_window =
            ntl::make_shared<sf::RenderWindow>(
                sf::VideoMode(
                    width,
                    height),
                title,
                sf::Style::Default,
                sf::ContextSettings(16,
                                    8,
                                    4,
                                    major,
                                    minor,
                                    sf::ContextSettings::Attribute::Core | sf::ContextSettings::Attribute::Debug,
                                    false));
    }

    void
    SFMLWindow::create(
        const sf::VideoMode &mode,
        const sf::String &title,
        sf::Uint32 style,
        const sf::ContextSettings &settings)
    {
        m_window =
            ntl::make_shared<sf::RenderWindow>(
                mode,
                title,
                style,
                settings);
    }
} // namespace nwl

#endif