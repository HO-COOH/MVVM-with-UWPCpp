#pragma once
#include "ViewModel.g.h"
#include "Model.h"
#include <winrt/Windows.UI.Xaml.Controls.h>

namespace winrt::WinUI2Cpp::implementation
{
    struct ViewModel : ViewModelT<ViewModel>
    {
        ViewModel();

        //Returning the states when "view" code quries 
        winrt::hstring thing();

        //Methods that this view-model supports
        winrt::Windows::Foundation::IAsyncAction StartProcess();

        //These following 2 methods are for supporting property change events
        winrt::event_token PropertyChanged(winrt::Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;

    private:
        //model as the view-model's property
        Model model;

        //Data members recording the states of the view
        winrt::hstring m_thing;

        //This is for supporting property change events
        winrt::event<winrt::Windows::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
    };
}

namespace winrt::WinUI2Cpp::factory_implementation
{
    struct ViewModel : ViewModelT<ViewModel, implementation::ViewModel>
    {
    };
}
