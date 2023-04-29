#ifndef __NEUTRONWL_WINDOWEDAPPLICATION_HPP__
#define __NEUTRONWL_WINDOWEDAPPLICATION_HPP__

#include <ntl/NTL.hpp>

namespace nwl
{
    template <typename m_WindowType>
    class WindowedApplication : public ntl::ConsoleApplication
    {
    public:
        using WindowType = m_WindowType;
        using WindowPointer = ntl::SharedPointer<WindowType>;

        using SelfType = WindowedApplication<WindowType>;
        using ParentType = ntl::ConsoleApplication;

    protected:
        WindowPointer m_window;

    public:
        WindowedApplication() = default;
        explicit WindowedApplication(const SelfType &from) = default;
        ~WindowedApplication() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        using ntl::Application::run;
        int run() override;

        void onIdle() override;

    public:
        virtual void onUpdate(const ntl::Time &delta_time);
        virtual void onDraw();
    };

} // namespace nwl

#endif
