#include "stdafx.h"
#include "pch.h"
#include "../include/SimpleDateTimeFormat.h"
#include <chrono>
#include <sstream>
#include <iomanip>

std::string SimpleDateTimeFormat::format(const std::string& fmt /*= "%Y-%m-%d %H:%M:%S"*/)
{
	// 获取当前时间
	auto now = std::chrono::system_clock::now();
	
	// 格式时间
	std::stringstream ss;
	auto tNow = std::chrono::system_clock::to_time_t(now);
	ss << std::put_time(std::localtime(&tNow), fmt.c_str());
	return ss.str();
}

std::string SimpleDateTimeFormat::formatWithMilli(const std::string& fmt /*= "%Y-%m-%d %H:%M:%S"*/, const std::string msDelim /*= " "*/)
{
	// 获取当前时间
	auto now = std::chrono::system_clock::now();
	
	// 格式化时间
	std::stringstream ss;
	auto tNow = std::chrono::system_clock::to_time_t(now);
	ss << std::put_time(std::localtime(&tNow), fmt.c_str());

	// 获取当前时间的秒数
	auto tSeconds = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch());
	// 获取当前时间的毫秒
	auto tMilli = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch());
	// 作差求出毫秒数
	auto ms = tMilli - tSeconds;
	ss << msDelim << std::setfill('0') << std::setw(3) << ms.count();
	return ss.str();
}
