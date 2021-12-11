#pragma once

#include "MainPage.g.h"
#include "ViewModel.h"  //include the view model header file

namespace winrt::WinUI3Cpp::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage();

        /*
            This is the button click event handler method that Visual Studio automatically generated when you write the event in xaml
            The default return type is void, but it can also be an async function, similar to our case here.
        */
        winrt::Windows::Foundation::IAsyncAction Button_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        
        /*
            This is the getter method for getting the view-model.
            REMEMBER to use the one from "<Your App Name> namespace" instead of "<Your App Name>::implementation namespace"!
            The one in the implementation namespace is your implementation written in your view-model header file and cpp file and they are NOT complete! (has virtual functions... etc)
            This one is the class generated from the view-model idl file, and has only methods declared in the idl file and is the correct one to use.
            Same as the view-model private member.
        */
        WinUI3Cpp::ViewModel MainViewModel();
    private:
        //view-model as the page's property
        WinUI3Cpp::ViewModel m_viewModel;
    };
}

namespace winrt::WinUI3Cpp::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
