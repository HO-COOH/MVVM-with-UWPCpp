#include "pch.h"
#include "Models.Main.h"
#include <chrono>

namespace Models
{
    std::future<void> Main::calculation()
    {
        return std::async(std::launch::async, [this]
            {
                //This simulates some compuatation that takes a long time
                std::this_thread::sleep_for(std::chrono::seconds{ 2 });
                m_string = L"ready";
            });
    }

    winrt::hstring Main::getValue() const
    {
        return m_string;
    }
}