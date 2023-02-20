#include "stdafx.h"
#include "CgthckService.h"

//PageVO<QueryCgthckBillDetailVO> CgthckService::listAll(const QueryCgthckBillQuery& query)
//{
//    //// 构建返回对象
//    //PageVO<QueryCgthckBillDetailVO> pages;
//    //pages.setPageIndex(query.getPageIndex());
//    //pages.setPageSize(query.getPageSize());
//
//    //// 查询数据总条数
//    //CgthckBillDetailDO obj;
//    //obj.setBillNo(query.getBillNo());
//    //obj.setBillDate(query.getBillDate());
//
//    //// 分页查询数据
//    //pages.setTotal(0);
//    //pages.calcPages();
//    //list<CgthckBillDetailDO> result = 
//}
//
//uint64_t CgthckService::saveData(const AddCgthckBillDTO& dto)
//{
//    //// 组装数据
//    //CgthckBillDetailDO data;
//    //data.setBillNo(dto.getBillNo());
//    //data.setBillDate(dto.getBillDate());
//    //data.setSupplierId(dto.getSupplierId());
//    //data.setSrcNo(dto.getSrcNo());
//    //// 执行数据添加
//
//}

bool CgthckService::updateData(const ModifyCgthckBillDTO& dto)
{
    return false;
}

bool CgthckService::removeData(uint64_t id)
{
    return false;
}
