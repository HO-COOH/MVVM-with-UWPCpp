#include "pch.h"
#include "ViewModel.h"
#if __has_include("ViewModel.g.cpp")
#include "ViewModel.g.cpp"
#endif
#include <winrt/Windows.ApplicationModel.Core.h> //for winrt::Windows::ApplicationModel::Core
#include <winrt/Windows.UI.Core.h> //for winrt::resume_foreground

namespace winrt::WinUI2Cpp::implementation
{
    ViewModel::ViewModel()
    {
        //Initialize the state
        m_thing = model.getValue();
    }

    winrt::hstring ViewModel::thing()
    {
        return m_thing;
    }

    winrt::Windows::Foundation::IAsyncAction ViewModel::StartProcess()
    {
        //Notice how you can simply co_await on std::future
        co_await model.calculation();
        //Update the states after the computation is done
        m_thing = model.getValue();

        //return to the UI thread to raise the property change event so that the UI would update
        co_await winrt::resume_foreground(winrt::Windows::ApplicationModel::Core::CoreApplication::MainView().Dispatcher());
        m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"thing" });
    }

    winrt::event_token ViewModel::PropertyChanged(winrt::Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }

    void ViewModel::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);
    }
}
