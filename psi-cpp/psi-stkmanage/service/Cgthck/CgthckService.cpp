#include "stdafx.h"
#include "CgthckService.h"

list<QueryCgrkBillListsVO> CgthckService::listAll(const QueryCgrkBillQuery& query)
{
    // 组装查询数据
    CgthckEntryDO obj;
    // 单据编号
    obj.setBillNo(query.getBillNo());

    CgthckDAO dao;

    list<CgthckEntryDO> result = dao.selectWithId(obj);
    list< QueryCgrkBillListsVO> vr;
    for (auto sub : result)
    {
        QueryCgrkBillListsVO vo;
        vo.setEntryNo(sub.getEntryNo());
        vo.setSrcNo(sub.getSrcNo());
        vo.setWarehouseId(sub.getWarehouseId());
        vo.setBatchNo(sub.getBatchNo());
        vo.setUnitId(sub.getUnitId());
        vo.setSettleQty(sub.getSettleQty());
        vo.setTaxRate(sub.getTaxRate());
        vo.setPrice(sub.getPrice());
        vo.setDiscountRate(sub.getDiscountRate());
        vo.setTax(sub.getTax());
        vo.setSettleAmt(sub.getSettleAmt());
        vo.setQty(sub.getQty());
        vo.setCost(sub.getCost());
        vo.setInvoicedQty(sub.getInvoicedQty());
        vo.setInvoicedAmt(sub.getInvoicedAmt());
        vo.setRemark(sub.getRemark());
        vo.setCustom1(sub.getCustom1());
        vo.setCustom2(sub.getCustom2());
        vr.push_back(vo);
    }
    return vr;
}

int CgthckService::saveData(const AddCgthckBillDTO& dto)
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
    }


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
    uint64_t mid = dao.insert(data);
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
            cnt += dao.insert(entryData);
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

int CgthckService::updateData(const AddCgthckBillDTO& dto)
{
    // 数据检验
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

    // 如果单据处于"已生效"阶段 则不能修改
    if (dto.getIsClosed() || check(dto))
    {
        return -1;
    }
    
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
    }

    // 辅助组装批次号函数
    auto getBanchNo = [](string billNO, string entryNo) -> std::string
    {
        string banchNo = billNO + '-' + entryNo;
        return banchNo;
    };

    // 组装单据数据
    CgthckDO data;
    // 单据编号
    data.setBillNo(dto.getBillNo());
    // 单据日期
    data.setBillDate(dto.getBillDate());
    // 供应商
    data.setSupplierId(dto.getSupplierId());
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
    // 单据阶段
    data.setBillStage(dto.getBillStage());
    // 附件
    data.setAttachment(attachment);
    // 备注
    data.setRemark(dto.getRemark());

    // 开启事务
    dao.getSqlSession()->beginTransaction();

    // 执行数据添加
    int row = dao.update(data);
    if (row == 0)
    {
        dao.getSqlSession()->rollbackTransaction();
        // 删除新增的附件
        dao.deleteFile(attachment);
        return -2;
    }

    // 组装明细数据
    CgthckEntryDO entryData;
    list<CgthckBillEntryDTO> entries = dto.getEntry();
    for (auto& ety : entries)
    {
        // 批次编号
        entryData.setBatchNo(getBanchNo(dto.getBillNo(), to_string(ety.getEntryNo())));
        // 分录号
        entryData.setEntryNo(to_string(ety.getEntryNo()));
        // 结算数量
        entryData.setSettleQty(ety.getSettleQty());
        //税率
        entryData.setTaxRate(ety.getTaxRate());
        // 结算金额
        entryData.setSettleAmt(ety.getSettleAmt());
        // 采购费用
        entryData.setCost(ety.getCost());
        // 入库数量
        entryData.setQty(ety.getQty());
        // 备注
        entryData.setRemark(ety.getRemark());
        // 自定义1
        entryData.setCustom1(ety.getCustom1());
        // 自定义2
        entryData.setCustom2(ety.getCustom2());

        if (dao.update(entryData) == 0)
        {
            dao.getSqlSession()->rollbackTransaction();
            return -3;
        }
    }
    // 插入成功, 提交
    dao.getSqlSession()->commitTransaction();
    return row;
}

int CgthckService::updateApproval(const ModifyCgthckBillDTO& dto, const PayloadDTO& payload)
{
    // 数据检验 只有处于编制完才能审核
    if (dto.getBillStage().compare("14")) // 12编制中, 14编制完 
    {
        return -1;
    }

    // 组装数据
    CgthckDO data;
    data.setBillNo(dto.getBillNo());
    data.setRemark(dto.getRemark());
    data.setApprovalRemark(dto.getApprovalRemark());
    data.setApprovalResultType(dto.getApprovalResultType());
    data.setApprover(payload.getUsername());

    // 生成当前时间
    time_t rawtime;
    struct tm* info;
    char buffer[80];
    time(&rawtime);
    info = localtime(&rawtime);
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", info);

    // 审批测试
    if (stoi(data.getApprovalResultType()) == 1) // 审核通过
    {
        data.setIsEffective(1);
        data.setEffectiveTime(string(buffer));
        data.setIsClosed(1);
        data.setBillStage("34"); // 34:执行完
    }
    else
    {
        data.setBillStage("24"); // 24:核批完
    }

    // 定义DAO层
    CgthckDAO dao;
    // 事务开始
    dao.getSqlSession()->beginTransaction();
    int row = dao.updateApproval(data);
    if (row == 0)
    {
        dao.getSqlSession()->rollbackTransaction();
        return -2;
    }
    dao.getSqlSession()->commitTransaction();
    return row;
}

int CgthckService::removeData(const DeleteCgthckBillDTO& dto)
{
    CgthckDAO dao;
    int row = -1;
    
    // 检查单据编号是否为空
    if (!dto.getBillNo().empty())
    {
        // 删除单据
        row = dao.deleteBillById(dto.getBillNo());
        // 删除明细
        row += dao.deleteEntryById(dto.getBillNo());
    }
    return row;
}

int CgthckService::removeEntry(const DeleteCgthckBillDTO& dto)
{
    CgthckDAO dao;

    int row = -1;
    // 检查明细列表是否为空
    if (!dto.getBillNo().empty() && !dto.getEntries().empty())
    {
        string billNo = dto.getBillNo();
        for (auto& entry : dto.getEntries())
        {
            // 删除明细
            row += dao.deleteEntryById(billNo, entry);
        }
    }
    return row;
}

int CgthckService::closed(const ModifyCgthckBillDTO& dto, const PayloadDTO& payload)
{
    // 组装数据
    CgthckDO data;
    data.setBillNo(dto.getBillNo());
    data.setIsClosed(1);

    // 生成当前时间
    time_t rawtime;
    struct tm* info;
    char buffer[80];
    time(&rawtime);
    info = localtime(&rawtime);
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", info);

    data.setEffectiveTime(string(buffer));
    data.setApprover(payload.getUsername());

    CgthckDAO dao;
    return dao.updateStatus(data);
}

int CgthckService::unclosed(const ModifyCgthckBillDTO& dto, const PayloadDTO& payload)
{
    // 组装数据
    CgthckDO data;
    data.setBillNo(dto.getBillNo());
    data.setIsClosed(0);

    // 生成当前时间
    time_t rawtime;
    struct tm* info;
    char buffer[80];
    time(&rawtime);
    info = localtime(&rawtime);
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", info);

    data.setEffectiveTime(string(buffer));
    data.setApprover(payload.getUsername());

    CgthckDAO dao;
    return dao.updateStatus(data);
}

int CgthckService::voided(const ModifyCgthckBillDTO& dto, const PayloadDTO& payload)
{
    // 组装数据
    CgthckDO data;
    data.setBillNo(dto.getBillNo());
    data.setIsVoided(1);

    // 生成当前时间
    time_t rawtime;
    struct tm* info;
    char buffer[80];
    time(&rawtime);
    info = localtime(&rawtime);
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", info);

    data.setEffectiveTime(string(buffer));
    data.setApprover(payload.getUsername());

    CgthckDAO dao;
    return dao.updateStatus(data);
}

int CgthckService::importData(const ImportCgthckFileDTO& dto)
{
    // 解析Excel中的数据
    ExcelComponent excel;
    string fileName = dto.getFiles().front();
    string sheetName = CharsetConvertHepler::ansiToUtf8("出入库单");
    string entrySheetName = CharsetConvertHepler::ansiToUtf8("明细");
    // 将文件的数据转换成二维数组, 谨记:二维数组的第一行是header(文字), 不需要载入数据库
    vector<vector<string>> data = excel.readIntoVector(fileName, sheetName);
    vector<vector<string>> entryData = excel.readIntoVector(fileName, entrySheetName);

    // 将二维数组转换为DO模型
    list<CgthckDO> cgthckDo;
    if (data.size() > 1)
    {
        for (int i = 1; i < data.size(); i++)
        {
            CgthckDO tmp_do;
            int j = 0;
            auto tmp_data = data[i];
            // 出入库类型
            tmp_do.setStockIoType(tmp_data[j++]);
            // 是否有往来
            tmp_do.setStockIoType(tmp_data[j++]);
            // 是否有涨吨
            tmp_do.setStockIoType(tmp_data[j++]);
            // 供应商
            tmp_do.setStockIoType(tmp_data[j++]);
            // 客户
            tmp_do.setStockIoType(tmp_data[j++]);
            // 发票类型
            tmp_do.setStockIoType(tmp_data[j++]);
            // 业务部门
            tmp_do.setStockIoType(tmp_data[j++]);
            // 业务员
            tmp_do.setStockIoType(tmp_data[j++]);
            // 出入库经办
            tmp_do.setStockIoType(tmp_data[j++]);
            // 成本
            tmp_do.setStockIoType(tmp_data[j++]);
            // 结算金额
            tmp_do.setStockIoType(tmp_data[j++]);
            // 已结算金额
            tmp_do.setStockIoType(tmp_data[j++]);
            // 已开票金额
            tmp_do.setStockIoType(tmp_data[j++]);
            // 是否生效
            tmp_do.setStockIoType(tmp_data[j++]);
            // 附件
            tmp_do.setStockIoType(tmp_data[j++]);
            // 源单id
            tmp_do.setStockIoType(tmp_data[j++]);
            // 单据主题
            tmp_do.setStockIoType(tmp_data[j++]);
            // 单据阶段
            tmp_do.setStockIoType(tmp_data[j++]);
            // 源单号
            tmp_do.setStockIoType(tmp_data[j++]);
            // 是否自动生成
            tmp_do.setStockIoType(tmp_data[j++]);
            // 备注
            tmp_do.setStockIoType(tmp_data[j++]);
            // 审批实例id
            tmp_do.setStockIoType(tmp_data[j++]);
            // 已作废
            tmp_do.setStockIoType(tmp_data[j++]);
            // 单据编号
            tmp_do.setStockIoType(tmp_data[j++]);
            // 是否红字
            tmp_do.setStockIoType(tmp_data[j++]);
            // 源单类型
            tmp_do.setStockIoType(tmp_data[j++]);
            // 制单时间
            tmp_do.setStockIoType(tmp_data[j++]);
            // 生效时间
            tmp_do.setStockIoType(tmp_data[j++]);
            // 核批人
            tmp_do.setStockIoType(tmp_data[j++]);
            // 修改人
            tmp_do.setStockIoType(tmp_data[j++]);
            // 制单部门
            tmp_do.setStockIoType(tmp_data[j++]);
            // 已关闭
            tmp_do.setStockIoType(tmp_data[j++]);
            // 核批结合类型
            tmp_do.setStockIoType(tmp_data[j++]);
            // 单据日期
            tmp_do.setStockIoType(tmp_data[j++]);
            // 制单人
            tmp_do.setStockIoType(tmp_data[j++]);
            // 核批意见
            tmp_do.setStockIoType(tmp_data[j++]);
        }
    }
    
    return 0;
}

int CgthckService::exportData(const ExportCgthckFileDTO& dto)
{
    return 0;
}
