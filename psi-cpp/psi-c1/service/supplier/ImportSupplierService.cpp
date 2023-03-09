#include "stdafx.h"
#include "ImportSupplierService.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include "SnowFlake.h"

uint64_t ImportSupplierService::saveData(const FileDTO& dto)
{
	ExcelComponent excel;
	uint64_t res = 0;
	//输出测试上传文件路径列表
	for (auto file : dto.getFiles()) {
		std::cout << "path " << file << std::endl;
		//从文件中读取
		ImportSupplierDO data;
		std::string sheetName = CharsetConvertHepler::ansiToUtf8("supplier");
		auto readData = excel.readIntoVector(file, sheetName);
		int rows = 0;
		for (auto row : readData)
		{
			if (rows < 2)
			{
				rows++;
				continue;
			}
			if (!row.empty())
			{
				int i = 0;
				SnowFlake sf(1, 1);
				data.setId(sf.nextId());
				data.setCode(row.at(i++));
				data.setName(row.at(i++));
				data.setShortName(row.at(i++));
				data.setAuxName(row.at(i++));
				data.setSupplierCategory(row.at(i++));
				data.setSupplierLevel(row.at(i++));
				data.setTaxScale(row.at(i++));
				data.setHeadquarters(row.at(i++));
				data.setArea(row.at(i++));
				data.setBizArea(row.at(i++));
				data.setAddress(row.at(i++));
				data.setWebsite(row.at(i++));
				data.setLegalPerson(row.at(i++));
				data.setLegalPersonPhone(row.at(i++));
				data.setFinancialContacts(row.at(i++));
				data.setFinancialPhone(row.at(i++));
				data.setInvoiceCompany(row.at(i++));
				data.setInvoiceTaxCode(row.at(i++));
				data.setInvoiceBankName(row.at(i++));
				data.setInvoiceBankCode(row.at(i++));
				data.setInvoiceAccount(row.at(i++));
				data.setInvoicePhone(row.at(i++));
				data.setInvoiceAddress(row.at(i++));
				data.setReceiptCompany(row.at(i++));
				data.setReceiptBankName(row.at(i++));
				data.setReceiptBankCode(row.at(i++));
				data.setReceiptAccount(row.at(i++));
				data.setRecvName(row.at(i++));
				data.setRecvPhone(row.at(i++));
				data.setRecvFax(row.at(i++));
				data.setRecvEmail(row.at(i++));
				data.setRecvAddress(row.at(i++));
				data.setRecvPostcode(row.at(i++));
				data.setAttachment(row.at(i++));
				if (CharsetConvertHepler::utf8ToAnsi(row.at(i++)) == "是") {
					data.setIsEnabled(1);
				}
				data.setAlterSuppliers(row.at(i++));
				data.setRemark(row.at(i++));
				int n;
				stringstream ss;
				ss << row.at(i++);
				ss >> n;
				data.setVersion(n);
							
				//执行数据添加
				ImportSupplierDAO dao;
				dao.insert(data);
				res++;
			}
		}
		
	}

	return res;
}
