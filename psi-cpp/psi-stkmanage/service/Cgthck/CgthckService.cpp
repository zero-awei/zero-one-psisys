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
    // 辅助数据检验的函数
    auto check = [](const AddCgthckBillDTO& dto)
    {
        for (auto& ety : dto.getEntry())
        {
            // 分录号不能为负数并且红字单就数据不能为正数
            if (ety.getEntryNo() < 0 || ety.getSettleQty() > 0 || ety.getTax() > 0 || ety.getSettleAmt() > 0)
                return true;
        }
        return false;
    };

    // 数据校验
    if (check(dto))
        return -1;

    // 定义dao层对象
    CgthckDAO dao;

    // 上传附件
    string attachment{ "" };
    for (auto& f : dto.getFiles())
    {
        string fileName = dao.insertFile(f);
        if (!fileName.empty())
        {
            attachment += fileName + ',';
        }
        /*       
        else
        {
            return -2;
        }
        */
    }
    int len = attachment.size();

    // 辅助组装批次号函数
    auto getBanchNo = [](string billNO, string entryNo) -> std::string
    {
        string banchNo = billNO + '-' + entryNo;
        return banchNo;
    };

    // 生成雪花ID
    SnowFlake sf(1, 5);
    string id = to_string(sf.nextId());

    // 组装单据数据
    CgthckDO data;
    // id
    data.setId(id);
    // 单据编号
    data.setBillNo(dto.getBillNo());
    // 单据日期
    data.setBillDate(dto.getBillDate());
    // 供应商
    data.setSupplierId(dto.getSupplierId());
    // 源单类型
    data.setSrcBillType(dto.getSrcBillType());
    // 采购入库单编号
    data.setSrcNo(dto.getSrcNo());
    // 已生效
    data.setIsEffective(dto.getIsEff());
    // 已关闭
    data.setIsClosed(dto.getIsClosed());
    // 已作废
    data.setIsVoided(dto.getIsVoided());
    // 业务部门
    data.setOpDept(dto.getOpDept());
    // 主题
    data.setSubject(dto.getSubject());
    // 发票类型
    data.setInvoiceType(dto.getInvoiceType());
    // 出库经办
    data.setHandler(dto.getHandler());

    // 开启事务
    dao.getSqlSession()->beginTransaction();

    // 执行数据添加
     int cnt = 0; // 记录插入明细的总条数
    // 获取mid
    uint64_t mid = dao.insertIntoBill(data);
    if (mid > 0)
    {
        // 组装明细数据
        list<CgthckBillEntryDTO> entries = dto.getEntry();
        for (auto& ety : entries)
        {
            CgthckEntryDO entryData;
            // id
            entryData.setId(to_string(sf.nextId()));
            // 主表id
            entryData.setMid(to_string(mid));
            // 单据编号
            entryData.setBillNo(dto.getBillNo());
            // 分录号
            entryData.setEntryNo(to_string(ety.getEntryNo()));
            // 物料
            entryData.setMaterialId(ety.getMaterialId());
            // 批次号
            entryData.setBatchNo(getBanchNo(dto.getBillNo(), to_string(ety.getEntryNo())));
            // 仓库
            entryData.setWarehouseId(ety.getWarehouseId());
            // 出入方向
            entryData.setStockIoDirection("1"); // 暂时不知道哪个方向代表出库
            // 计量单位
            entryData.setUnitId(ety.getUnitId());
            // 结算数量
            entryData.setSettleQty(ety.getSettleQty());
            // 税率
            entryData.setTaxRate(ety.getTaxRate());
            // 含税单价
            entryData.setPrice(ety.getPrice());
            // 折扣率
            entryData.setDiscountRate(ety.getDiscountRate());
            // 税额
            entryData.setTax(ety.getTax());
            // 结算金额
            entryData.setSettleAmt(ety.getSettleAmt());
            // 入库数量
            entryData.setQty(ety.getQty());
            // 采购费用(成本)
            entryData.setCost(ety.getCost());
            // 入库金额
            entryData.setInvoicedAmt(ety.getInAmt());

            // 执行数据添加, 返回插入成功的条数
            cnt += dao.insertIntoEntry(entryData);
        }
    }
    if (mid <= 0 || cnt <= 0)
    {
        // 插入失败, 回滚
        dao.getSqlSession()->rollbackTransaction();
    }
    else
    {
        // 插入成功, 提交
        dao.getSqlSession()->commitTransaction();
    }
    return cnt;
}

bool CgthckService::updateData(const ModifyCgthckBillDTO& dto)
{
    return false;
}

bool CgthckService::removeData(uint64_t id)
{
    return false;
}
