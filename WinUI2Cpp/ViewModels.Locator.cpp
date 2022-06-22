#include "pch.h"
#include "ViewModels.Locator.h"

winrt::WinUI2Cpp::ViewModels::Main WinUI2Cpp::ViewModels::Locator::MainViewModel()
{
	static winrt::WinUI2Cpp::ViewModels::Main s_mainViewModel;
	return s_mainViewModel;
}
