#pragma once
#ifndef _IDDTO_H_
#define _IDDTO_H_

#include "../GlobalInclude.h"

/**
 * 整形类型编号对象
 */
class IntID
{
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, IntID& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, id);
	}
};

/**
 * 整形类型编号对象集合
 */
class IntIDs
{
	// 编号
	CC_SYNTHESIZE(std::list<uint64_t>, id, Id);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, IntIDs& t) { // NOLINT
		BIND_FROM_TO_OBJ(j, t, id, std::list<uint64_t>);
	}
};

/**
 * 字符串类型编号对象
 */
class StringID
{
	// 编号
	CC_SYNTHESIZE(std::string, id, Id);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, StringID& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, id);
	}
};

/**
 * 字符串类型编号对象集合
 */
class StringIDs
{
	// 编号
	CC_SYNTHESIZE(std::list<std::string>, id, Id);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, StringIDs& t) { // NOLINT
		BIND_FROM_TO_OBJ(j, t, id, std::list<std::string>);
	}
};

#endif // !_IDDTO_H_
