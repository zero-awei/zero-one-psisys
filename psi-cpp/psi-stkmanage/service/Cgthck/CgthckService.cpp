#include "stdafx.h"
#include "CgthckService.h"


PageVO<QueryCgthckBillVO> CgthckService::listAll(const QueryCgthckBillQuery& query)
{
    // 构建返回对象
    PageVO<QueryCgthckBillVO> pages;
    pages.setPageIndex(query.getPageIndex());
    pages.setPageSize(query.getPageSize());

    // 查询数据总条数
    CgthckDO obj;
    obj.setBillNo(query.getBillNo());
    obj.setBillDate(query.getBillDate());
    obj.setSupplierId(query.getSupplierId());

    CgthckDAO dao;
    uint64_t count = dao.count(obj);
    if (count <= 0)
    {
        return pages;
    }

    // 分页查询数据
    pages.setTotal(count);
    pages.calcPages();
    list<CgthckDO> result = dao.selectById(query.getBillNo());
    list< QueryCgthckBillVO> vr;
    for (auto sub : result)
    {
        QueryCgthckBillVO vo;
        vo.setBillNo(sub.getBillNo());
        vo.setBillDate(sub.getBillDate());
        vo.setSupplierId(sub.getSupplierId());
        vr.push_back(vo);
    }
    pages.setRows(vr);
    return pages;
}

uint64_t CgthckService::saveData(const AddCgthckBillDTO& dto)
{
    // 组装单据数据
    CgthckDO data;
    string billNo = dto.getBillNo();
    data.setBillNo(billNo);
    // data.setBillNo(dto.getBillNo());
    data.setBillDate(dto.getBillDate());
    data.setSupplierId(dto.getSupplierId());
    data.setSrcBillType(dto.getSrcBillType());
    // TO DO

    // 执行数据添加
    CgthckDAO dao;
    uint64_t mid =  dao.insertIntoBill(data);
    if (mid > 0)
    {
        // 组装明细数据
        int cnt = 0;
        // 组装批次号
        auto getBanchNo = [](string billNO, string entryNo) -> std::string
        {
            string banchNo = billNO + '-' + entryNo;
            return banchNo;
        };
        list<CgthckBillEntryDTO> entries = dto.getEntry();
        for (auto ety : entries)
        {
            CgthckEntryDO entryData;
            // 主表id
            entryData.setMid(to_string(mid));
            // 分录号
            string entryNo = to_string(ety.getEntryNo());
            entryData.setEntryNo(entryNo);
            //entryData.setEntryNo(to_string(ety.getEntryNo()));
            // 物料
            entryData.setMaterialId(ety.getMaterialId());
            // 批次号
            entryData.setBatchNo(getBanchNo(billNo, entryNo));
            // 仓库
            entryData.setWarehouseId(ety.getWarehouseId());
            // 出入方向
            entryData.setStockIoDirection("1");
            // 计量单位
            entryData.setUnitId(ety.getUnitId());
            // TO DO

            // 执行数据添加
            cnt += dao.insertIntoEntry(entryData);
        }
        return cnt;
    }
    else
    {
        return mid;
    }
}

bool CgthckService::updateData(const ModifyCgthckBillDTO& dto)
{
    return false;
}

bool CgthckService::removeData(uint64_t id)
{
    return false;
}
