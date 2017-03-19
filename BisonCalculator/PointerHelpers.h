#pragma once
#include <memory>

namespace calc
{
	template<class T>
	std::unique_ptr<T> Extract(T *& entry)
	{
		std::unique_ptr<T> ret(entry);
		entry = nullptr;
		return ret;
	}

	template<class T>
	void Push(T *& entry, std::unique_ptr<T> && value)
	{
		entry = value.release();
	}

	template<class T, class U, class ...TArgs>
	void Emplace(U *& entry, TArgs && ... args)
	{
		auto value = std::make_unique<T>(std::move(args)...);
		entry = value.release();
	}

}