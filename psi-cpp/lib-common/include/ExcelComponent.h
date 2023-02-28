#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 15:33:44
 
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
#ifndef _EXCELCOMPONENT_H_
#define _EXCELCOMPONENT_H_
#include <xlnt/xlnt.hpp>
#include <string>
#include <vector>
/**
 * Excel组件
 */
class ExcelComponent
{
private:
	xlnt::workbook wb;
	xlnt::worksheet sheet;
	double rowHeight = 20;
	double colWidth = 20;
	//初始化工作薄
	void initWorkbook(const std::string& fileName = "");
	//创建Sheet
	void createSheet(const std::string& sheetName);
public:
	//设置行高
	void setRowHeight(double rowHeight);
	//设置列宽
	void setColWidth(double colWidth);
	//读取指定页签内容到容器,注意文件路径使用/
	std::vector<std::vector<std::string>> readIntoVector(const std::string& fileName, const std::string& sheetName);
	//保存指定页签内容到文件,注意文件路径使用/
	void writeVectorToFile(const std::string& fileName, const std::string& sheetName, const std::vector<std::vector<std::string>>& data);


//--十二
	// 清空工作薄
	void clearWorkbook();
	// 工作表命名
	void makeName(const std::string& title);
	// 合并单元格
	void mergeCell(std::string& sheetName, const xlnt::cell_reference& columnbegin, const xlnt::cell_reference& columnend);
	// 单元格赋值
	void cellVaule(const std::string& sheetName, std::string& cell, std::string value);
};
#endif // _EXCELCOMPONENT_H_
