#pragma once
#include <future>

//This is the model class, containing your business logic
class Model
{
public:
	/*
		Simulate some form of computation that takes a long time.
		And notice how it returns std::future that is completely free from windows specific APIs.
	*/
	std::future<void> calculation();

	//Simulate getting the current value of your business logic
	winrt::hstring getValue() const;

private:
	//Simulate some internal states
	winrt::hstring m_string = L"not ready";
};

