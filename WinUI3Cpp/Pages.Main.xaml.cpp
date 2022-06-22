#include "pch.h"
#include "Pages.Main.xaml.h"
#if __has_include("MainPage.g.cpp")
#include "MainPage.g.cpp"
#endif
#include "ViewModels.Locator.h"

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
        co_await MainViewModel().StartProcess();
    }

    WinUI3Cpp::ViewModels::Main MainPage::MainViewModel()
    {
        /*
            Simply return the view model, with value semantics.
            Because we write the view-model in idl, it will be a Windows Runtime class, that is internally a smart pointer.
        */
        return ::WinUI3Cpp::ViewModels::Locator::MainViewModel();
    }
}
