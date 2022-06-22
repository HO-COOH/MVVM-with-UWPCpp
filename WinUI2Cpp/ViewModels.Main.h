#pragma once
#include "ViewModels.Main.g.h"
#include "Models.Main.h"
#include <winrt/Windows.UI.Xaml.Controls.h>

namespace winrt::WinUI2Cpp::ViewModels::implementation
{
    struct Main : MainT<Main>
    {
        Main();

        //Returning the states when "view" code quries 
        winrt::hstring thing();

        //Methods that this view-model supports
        winrt::Windows::Foundation::IAsyncAction StartProcess();

        //These following 2 methods are for supporting property change events
        winrt::event_token PropertyChanged(winrt::Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;

    private:
        //model as the view-model's property
        Models::Main model;

        //Data members recording the states of the view
        winrt::hstring m_thing;

        //This is for supporting property change events
        winrt::event<winrt::Windows::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
    };
}

namespace winrt::WinUI2Cpp::ViewModels::factory_implementation
{
    struct Main : MainT<Main, implementation::Main>
    {
    };
}
