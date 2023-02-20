#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:20:12

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _PAGE_VO_
#define _PAGE_VO_
#include "../GlobalInclude.h"
#include <list>

/**
 * 分页数据实体（service->web）
 */
template <class T>
class PageVO
{
	/**
	 * 当前页码
	 */
	CC_SYNTHESIZE(uint64_t, pageIndex, PageIndex);
	/**
	 * 每页显示最大数据条数
	 */
	CC_SYNTHESIZE(uint64_t, pageSize, PageSize);
	/**
	 * 数据的总条数
	 */
	CC_SYNTHESIZE(uint64_t, total, Total);
	/**
	 * 数据的总页数
	 */
	CC_SYNTHESIZE(uint64_t, pages, Pages);
	/**
	 * 当前页数据列表
	 */
	CC_SYNTHESIZE(std::list<T>, rows, Rows);
public:
	PageVO() {
		this->setPageIndex(1);
		this->setPageSize(1);
		this->setPages(0);
		this->setTotal(0);
	}

	PageVO(uint64_t pageIndex, uint64_t pageSize, uint64_t total, uint64_t pages, std::list<T> rows) {
		this->setPageIndex(pageIndex);
		this->setPageSize(pageSize);
		this->setTotal(total);
		this->setPages(pages);
		this->setRows(rows);
	}

	// 计算总页数
	void calcPages() {
		this->pages = total / pageSize;
		this->pages = total % pageSize == 0 ? this->pages : this->pages + 1;
	}

	// 绑定JSON转换方法
	friend void to_json(json& j, const PageVO<T>& t) { //NOLINT
		j = json{ {"pageIndex", t.pageIndex}, {"pageSize", t.pageSize}, {"total",t.total}, {"pages",t.pages}, {"rows",t.rows} };
	}
};

#endif // !_PAGE_VO_

