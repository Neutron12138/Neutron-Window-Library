#ifndef __NEUTRONWL_BASE_WINDOWEDAPPLICATION_CPP__
#define __NEUTRONWL_BASE_WINDOWEDAPPLICATION_CPP__

#include "WindowedApplication.hpp"

namespace nwl
{
    template <typename m_WindowType>
    int
    WindowedApplication<m_WindowType>::run()
    {
        try
        {
            m_is_running = true;
            onCreated();

            while (m_is_running)
                onIdle();

            m_is_running = false;
            onDestroyed();

            return m_exit_code;
        }
        catch (const ntl::CaughtException &exception)
        {
            std::cout << exception << std::endl;
        }
        catch (const ntl::Exception &exception)
        {
            std::cout << exception << std::endl;
        }

        return EXIT_FAILURE;
    }

    template <typename m_WindowType>
    void
    WindowedApplication<m_WindowType>::onIdle()
    {
        try
        {
            if (!m_window.is_nullptr())
            {
                if (!m_window->is_open())
                {
                    m_is_running = false;
                    return;
                }

                m_window->process_events();
                onUpdate(m_delta_time);
                onDraw();
                m_window->display();
            }
        }
        catch (const ntl::CaughtException &exception)
        {
            throw ntl::CaughtException(
                exception,
                NTL_MAKE_STATEMENT_INFO("template <typename m_WindowType> void WindowedApplication<m_WindowType>::onIdle()"));
        }
        catch (const ntl::Exception &exception)
        {
            throw ntl::CaughtException(
                exception,
                NTL_MAKE_STATEMENT_INFO("template <typename m_WindowType> void WindowedApplication<m_WindowType>::onIdle()"));
        }
    }

    template <typename m_WindowType>
    void WindowedApplication<m_WindowType>::onUpdate(const ntl::Time &delta_time) {}
    template <typename m_WindowType>
    void WindowedApplication<m_WindowType>::onDraw() {}

} // namespace nwl

#endif
