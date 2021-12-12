#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::WinUI2Cpp::implementation
{
    MainPage::MainPage()
    {
        InitializeComponent();
        //You may need extra code to initialize the view-model object here
    }

    winrt::Windows::Foundation::IAsyncAction MainPage::Button_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
    {
        //When the button is clicked, we start the processing, which is also an async function.
        co_await m_viewModel.StartProcess();
    }

    WinUI2Cpp::ViewModel MainPage::MainViewModel()
    {
        /*
            Simply return the view model, with value semantics.
            Because we write the view-model in idl, it will be a Windows Runtime class, that is internally a smart pointer.
        */
        return m_viewModel;
    }
}
