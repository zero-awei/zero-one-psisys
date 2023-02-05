/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 15:38:30
 
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
#include "pch.h"
#include "../include/ExcelComponent.h"
#include "../include/CommonMacros.h"
#include <iostream>

void ExcelComponent::initWorkbook(const std::string& fileName /*= ""*/)
{
	wb = xlnt::workbook();
	if (!fileName.empty())
	{
		try
		{
			wb.load(fileName);
		}
		catch (xlnt::exception e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}

void ExcelComponent::createSheet(const std::string& sheetName)
{
	sheet = wb.active_sheet();
	sheet.title(sheetName);
}

void ExcelComponent::setRowHeight(double rowHeight)
{
	this->rowHeight = rowHeight;
}

void ExcelComponent::setColWidth(double colWidth)
{
	this->colWidth = colWidth;
}

std::vector<std::vector<std::string>> ExcelComponent::readIntoVector(const std::string& fileName, const std::string& sheetName)
{
	std::vector<std::vector<std::string>> result;
	initWorkbook(fileName);
	if (!wb.contains(sheetName))
	{
		return result;
	}
	auto sheet = wb.sheet_by_title(sheetName);
	for (auto row : sheet.rows(false))
	{
		std::vector<std::string> aSingleRow;
		for (auto cell : row)
		{
			aSingleRow.push_back(cell.to_string());
		}
		result.push_back(aSingleRow);
	}
	return result;
}

void ExcelComponent::writeVectorToFile(const std::string& fileName, const std::string& sheetName, const std::vector<std::vector<std::string>>& data)
{
	initWorkbook();
	createSheet(sheetName);
	int row = 1;
	int col = 1;
	for (auto aSignRow : data)
	{
		col = 1;
		for (auto cellVal : aSignRow)
		{
			//设置单元格值
			sheet.cell(xlnt::cell_reference(col, row)).value(cellVal);
			//设置列宽度
			sheet.column_properties(col).custom_width = true;
			sheet.column_properties(col).width = colWidth;
			col++;
		}
		//设置行高度
		sheet.row_properties(row).custom_height = true;
		sheet.row_properties(row).height = rowHeight;
		row++;
	}

	//判断目录是否存在，不存在创建目录
	auto dir = fileName.substr(0, fileName.find_last_of("/") + 1);
	const size_t dirLen = dir.length();
	if (dirLen > MAX_DIR_LEN)
	{
		std::cout << "表格保存失败<文件路径太长>" << std::endl;
		return;
	}
	char tmpDirPath[MAX_DIR_LEN] = { 0 };
	for (size_t i = 0; i < dirLen; i++)
	{
		tmpDirPath[i] = dir[i];
		if (tmpDirPath[i] == '/')
		{
			if (ACCESS(tmpDirPath, 0) != 0)
			{
				if (MKDIR(tmpDirPath) != 0)
				{
					std::cout << "表格保存失败<创建文件失败>：" << tmpDirPath << std::endl;
					return;
				}
			}
		}
	}

	//保存到文件
	wb.save(fileName);
}
