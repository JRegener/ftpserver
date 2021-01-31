#pragma once

#include <memory>
#include <cstdint>
#include <iostream>
#include <functional>

#if defined(_MSC_VER) && _MSC_VER >= 1400 
#pragma warning(disable : 4996)

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#define WINVER _WIN32_WINNT
#endif
#endif


namespace ftp {

	template <typename T>
	using Scope = std::unique_ptr<T>;

	template <typename T, typename ... Args>
	constexpr Scope<T> CreateScope (Args&& ... args) {
		return std::make_unique<T> (std::forward<Args> (args)...);
	}



	template <typename T>
	using Ref = std::shared_ptr<T>;

	template <typename T, typename ... Args>
	constexpr Ref<T> CreateRef (Args&& ... args) {
		return std::make_shared<T> (std::forward<Args> (args)...);
	}

}