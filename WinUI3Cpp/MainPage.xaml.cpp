#include "pch.h"
#include "MainPage.xaml.h"
#if __has_include("MainPage.g.cpp")
#include "MainPage.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

namespace winrt::WinUI3Cpp::implementation
{
    MainPage::MainPage()
    {
        InitializeComponent();
        //You may need extra code to initialize the view-model object here
    }

    winrt::Windows::Foundation::IAsyncAction MainPage::Button_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
    {
        //When the button is clicked, we start the processing, which is also an async function.
        co_await m_viewModel.StartProcess();
    }

    WinUI3Cpp::ViewModel MainPage::MainViewModel()
    {
        /*
            Simply return the view model, with value semantics.
            Because we write the view-model in idl, it will be a Windows Runtime class, that is internally a smart pointer.
        */
        return m_viewModel;
    }
}
