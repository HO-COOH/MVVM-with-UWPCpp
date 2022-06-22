#include "pch.h"
#include "ViewModels.Locator.h"

winrt::WinUI3Cpp::ViewModels::Main WinUI3Cpp::ViewModels::Locator::MainViewModel()
{
	static winrt::WinUI3Cpp::ViewModels::Main s_mainViewModel;
	return s_mainViewModel;
}
