#include "stdafx.h"
#include "ZdrkService.h"
#include "../psi-stkmanage/dao/CommonDAO.h"
#include "../psi-stkmanage/dao/Zdrk/ZdrkDao.h"
#include "../../../lib-common/include/SnowFlake.h"

int ZdrkService::saveBillData(const AddZdrkBillDTO& dto, const PayloadDTO& payload)
{
	// 数据校验
	if ((dto.getSave() != 0 && dto.getSave() != 1) ||
		[](const AddZdrkBillDTO& dto) {
			for (auto& list : dto.getDetail()) {
				if (list.getEntryNo() < 0 || list.getQty() < 0 || list.getCost() < 0 || list.getPrice() < 0) {
					return true;
				}
			}
			return false;
		}(dto)) {
		return -1;
	}

	// 定义DAO层对象
	ZdrkDAO zDao;
	CommonDAO cDao;

	// 上传附件
	// 定义传入数据库内的附件名称
	/*string attachment = "";
	for (auto& file : dto.getFiles()) {
		string fileName = cDao.insertAttachment(file);
		cout << fileName << endl;
		if (!fileName.empty()) {
			if (attachment.size() != 0) {
				attachment += ",";
			}
			attachment += fileName;
		}
		else {
			return -4;
		}
	}*/

	// 组装数据
	StkIoDO data1;
	SnowFlake sf(1, 5);
	string mid = to_string(sf.nextId());
	data1.setId(mid);
	data1.setBillNo(dto.getBillNo());
	data1.setBillDate(dto.getBillDate());
	data1.setSubject(dto.getSubject());
	data1.setStockIoType("198"); // "198":涨吨入库
	data1.setSupplierId(cDao.selectSupplyIdByAuxName(dto.getSupplier()));
	data1.setHandler(dto.getHandler());
	data1.setCost([](const list<ZdrkBillDetailDTO>& details) {
		double cost = 0;
		for (const auto& entry : details) {
			cost += entry.getCost();
		}
		return cost;
		}(dto.getDetail()));
	data1.setRemark(dto.getRemark());
	data1.setBillStage((dto.getSave() == 0 ? "12" : "14")); // "12":编制中, "14":编制完
	//data1.setAttachment(attachment);
	data1.setSysOrgCode(cDao.selectOrgCodeByUsername(payload.getUsername()));
	data1.setCreateBy(payload.getUsername());
	// 生成当前时间
	time_t rawtime;
	struct tm* info;
	char buffer[80];
	time(&rawtime);
	info = localtime(&rawtime);
	strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", info);

	data1.setCreateTime(string(buffer));
	// 事务开始
	zDao.getSqlSession()->beginTransaction();
	// 执行数据添加
	uint64_t row = zDao.insert(data1);
	/*if (row == 0) {//失败
		// 回滚
		zDao.getSqlSession()->rollbackTransaction();
		// 删除附件
		vector<string_view> fileNames = split(attachment, ",");
		if (!fileNames.empty()) {
			for (const auto& file : fileNames) {
				cDao.deleteAttachment(string(file));
			}
		}
		return -2;
	}*/

	// 组装明细数据
	StkIoEntryDO data2;
	for (auto& entry : dto.getDetail()) {
		data2.setId(to_string(sf.nextId()));
		data2.setMid(mid);
		data2.setBillNo(dto.getBillNo());
		data2.setEntryNo(to_string(entry.getEntryNo()));
		data2.setMaterialId(cDao.selectMaterialIdByAuxName(entry.getMaterial()));
		data2.setBatchNo((dto.getBillNo() + "-" + to_string(entry.getEntryNo())));
		data2.setWarehouseId(cDao.selectWarehouseIdByAuxName(entry.getWarehouse()));
		data2.setStockIoDirection("1");
		data2.setUnitId(cDao.selectUnitIdByName(entry.getUnit()));
		data2.setQty(entry.getQty());
		data2.setPrice(entry.getPrice());
		data2.setCost(entry.getCost());
		data2.setRemark(entry.getRemark());
		data2.setCustom1(entry.getCustom1());
		data2.setCustom2(entry.getCustom2());
		/*if (zDao.insert(data2) == 0) {
			// 回滚
			zDao.getSqlSession()->rollbackTransaction();
			// 删除附件
			vector<string_view> fileNames = split(attachment, ",");
			if (!fileNames.empty()) {
				for (const auto& file : fileNames) {
					cDao.deleteAttachment(string(file));
				}
			}
			return -3;
		}*/
	}
	// 提交
	zDao.getSqlSession()->commitTransaction();
	return row;
}

int ZdrkService::updateBillData(const ModifyZdrkBillDTO& dto, const PayloadDTO& payload)
{
    return 0;
}

int ZdrkService::removeBillById(const StringID& billNo)
{
    return 0;
}

int ZdrkService::updateBillState(const ModifyZdrkBillStateDTO& dto, const PayloadDTO& payload)
{
    return 0;
}
