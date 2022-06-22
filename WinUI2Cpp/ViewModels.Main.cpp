#include "pch.h"
#include "ViewModels.Main.h"
#if __has_include("ViewModels.Main.g.cpp")
#include "ViewModels.Main.g.cpp"
#endif
#include <winrt/Windows.ApplicationModel.Core.h> //for winrt::Windows::ApplicationModel::Core
#include <winrt/Windows.UI.Core.h> //for winrt::resume_foreground

namespace winrt::WinUI2Cpp::ViewModels::implementation
{
    Main::Main()
    {
        //Initialize the state
        m_thing = model.getValue();
    }

    winrt::hstring Main::thing()
    {
        return m_thing;
    }

    winrt::Windows::Foundation::IAsyncAction Main::StartProcess()
    {
        //Notice how you can simply co_await on std::future
        co_await model.calculation();
        //Update the states after the computation is done
        m_thing = model.getValue();

        //return to the UI thread to raise the property change event so that the UI would update
        co_await winrt::resume_foreground(winrt::Windows::ApplicationModel::Core::CoreApplication::MainView().Dispatcher());
        m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"thing" });
    }

    winrt::event_token Main::PropertyChanged(winrt::Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }

    void Main::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);
    }
}
