#ifndef __NEUTRONWL_IMPL_SFML_SFMLWINDOW_CPP__
#define __NEUTRONWL_IMPL_SFML_SFMLWINDOW_CPP__

#include "SFMLWindow.hpp"

namespace nwl
{
    SFMLWindow::SFMLWindow(
        const typename SFMLWindow::WindowPointer &window)
        : m_window(window) {}

    glm::uvec2
    SFMLWindow::get_window_size() const
    {
        sf::Vector2u size = m_window->getSize();
        return glm::uvec2(size.x, size.y);
    }

    const typename SFMLWindow::WindowPointer &
    SFMLWindow::get_window() const
    {
        return m_window;
    }

    void
    SFMLWindow::set_window(
        const typename SFMLWindow::WindowPointer &window)
    {
        m_window = window;
    }

    bool
    SFMLWindow::is_open()
    {
        try
        {
            return m_window->isOpen();
        }
        catch (const ntl::CaughtException &exception)
        {
            throw ntl::CaughtException(
                exception,
                NTL_MAKE_STATEMENT_INFO("void SFMLWindow::is_open()")

            );
        }
        catch (const ntl::Exception &exception)
        {
            throw ntl::CaughtException(
                exception,
                NTL_MAKE_STATEMENT_INFO("void SFMLWindow::is_open()")

            );
        }
    }

    void
    SFMLWindow::process_events()
    {
        try
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

                case sf::Event::EventType::MouseMoved:
                    onMouseMoved(
                        glm::ivec2(
                            event.mouseMove.x,
                            event.mouseMove.y));
                    break;

                default:
                    break;
                }
            }
        }
        catch (const ntl::CaughtException &exception)
        {
            throw ntl::CaughtException(
                exception,
                NTL_MAKE_STATEMENT_INFO("void SFMLWindow::process_events()")

            );
        }
        catch (const ntl::Exception &exception)
        {
            throw ntl::CaughtException(
                exception,
                NTL_MAKE_STATEMENT_INFO("void SFMLWindow::process_events()")

            );
        }
    }

    void
    SFMLWindow::display()
    {
        try
        {
            m_window->display();
        }
        catch (const ntl::CaughtException &exception)
        {
            throw ntl::CaughtException(
                exception,
                NTL_MAKE_STATEMENT_INFO("void SFMLWindow::display()")

            );
        }
        catch (const ntl::Exception &exception)
        {
            throw ntl::CaughtException(
                exception,
                NTL_MAKE_STATEMENT_INFO("void SFMLWindow::display()")

            );
        }
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

    glm::ivec2
    SFMLWindow::get_mouse_pos()
    {
        sf::Vector2i pos = sf::Mouse::getPosition();
        return glm::ivec2(
            pos.x,
            pos.y);
    }

} // namespace nwl

#endif
