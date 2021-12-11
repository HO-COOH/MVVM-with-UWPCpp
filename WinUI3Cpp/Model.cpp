#include "pch.h"
#include "Model.h"
#include <chrono>

std::future<void> Model::calculation()
{
    return std::async(std::launch::async, [this] 
    {
        //This simulates some compuatation that takes a long time
        std::this_thread::sleep_for(std::chrono::seconds{ 2 });
        m_string = L"ready";
    });
}

winrt::hstring Model::getValue() const
{
    return m_string;
}
