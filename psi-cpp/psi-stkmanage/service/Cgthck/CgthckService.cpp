#include "stdafx.h"
#include "CgthckService.h"
#include"domain/do/Cgthck/QueryCgthrkBillListDO.h"
#include"../../dao/Cgthck/CgthckDAO.h"
#include <FastDfsClient.h>
#include <ExcelComponent.h>
#include <CharsetConvertHepler.h>

PageVO<QueryCgthckBillVO> CgthckService::queryAllFitBill(const QueryCgthckBillQuery& query) {
    //构建返回对象
    PageVO<QueryCgthckBillVO> pages;
    pages.setPageIndex(query.getPageIndex());
    pages.setPageSize(query.getPageSize());

    //查询数据总条数
    QueryCgthrkBillListDO obj; //这是查询数据库的条件  封装成类//
    obj.setId(query.getBillNo());
    obj.setBeginData(query.getBeginData());
    obj.setEndData(query.getEndData());
    obj.setTheme(query.getSubject());
    obj.setStage(query.getBillStage());
    obj.setIsClosed(query.getIsClosed());
    obj.setIsEffective(query.getIsEff());
    obj.setIsVoided(query.getIsVoided());
    CgthckDAO dao;
    uint64_t count = dao.count(obj);
    if (count <= 0)
    {
        return pages;
    }

    //分页查询数据
    pages.setTotal(count);
    pages.calcPages();
    list<QueryCgthrkBillListReturnDO> result = dao.selectCgthckBillList(obj, query.getPageIndex(), query.getPageSize());
    list<QueryCgthckBillVO> vr;
    for (QueryCgthrkBillListReturnDO sub : result)
    {
        QueryCgthckBillVO vo;
        vo.setBillNo(sub.getBillNo());
        vo.setBillDate(sub.getBillDate());
        vo.setSubject(sub.getSubject());
        vo.setSrcNo(sub.getSrcNo());
        vo.setSupplierId(sub.getSupplierId());
        vo.setOptDept(sub.getOptDept());
        vo.setSrcOperator(sub.getSrcOperator());
        vo.setInAmt(sub.getInAmt());
        vo.setSettleAmt(sub.getSettleAmt());
        vo.setSettledAmt(sub.getSettledAmt());
        vo.setInvoicedAmt(sub.getInvoicedAmt());
        vo.setInvoiceType(sub.getInvoiceType());
        vo.setHandler(sub.getHandler());
        vo.setBillStage(sub.getBillStage());
        vo.setIsEff(sub.getIsEff());
        vo.setIsClosed(sub.getIsClosed());
        vo.setIsVoided(sub.getIsVoided());
        vo.setIsAuto(sub.getIsAuto());
        vo.setIsRubric(sub.getIsRubric());
        vo.setRemark(sub.getRemark());
        vo.setEffTime(sub.getEffTime());
        vo.setApprover(sub.getApprover());
        vo.setCreateTime(sub.getCreateTime());
        vo.setCreateBy(sub.getCreateBy());
        vo.setSysOrgCode(sub.getSysOrgCode());
        vo.setUpdateTime(sub.getUpdateTime());
        vo.setUpdateBy(sub.getUpdateBy());
        vr.push_back(vo);
    }
    pages.setRows(vr);
    return pages;
}



QueryCgthrkDetailedBillVO CgthckService::queryBillDetial(const CgthckBillDetailedDTO& query) {
    //构建返回对象
    QueryCgthrkDetailedBillVO vo;

    BillDetailedDO obj; //这是查询数据库的条件  封装成类
    obj.setBillNo(query.getBillNo());
    CgthckDAO dao;

    QueryCgthrkBillDetailedReturnDO sub = dao.selectCgthckBillListDetailed(obj);
    //分页查询数据
    vo.setBillNo(sub.getBillNo());
    vo.setBillDate(sub.getBillDate());
    vo.setSubject(sub.getSubject());
    vo.setSrcNo(sub.getSrcNo());
    vo.setSupplierId(sub.getSupplierId());
    vo.setOptDept(sub.getOptDept());
    vo.setSrcOperator(sub.getSrcOperator());
    vo.setInAmt(sub.getInAmt());
    vo.setSettleAmt(sub.getSettleAmt());
    vo.setSettledAmt(sub.getSettledAmt());
    vo.setInvoicedAmt(sub.getInvoicedAmt());
    vo.setInvoiceType(sub.getInvoiceType());
    vo.setHandler(sub.getHandler());
    vo.setBillStage(sub.getBillStage());
    vo.setIsEff(sub.getIsEff());
    vo.setIsClosed(sub.getIsClosed());
    vo.setIsVoided(sub.getIsVoided());
    vo.setIsAuto(sub.getIsAuto());
    vo.setIsRubric(sub.getIsRubric());
    vo.setRemark(sub.getRemark());
    vo.setEffTime(sub.getEffTime());
    vo.setApprover(sub.getApprover());
    vo.setCreateTime(sub.getCreateTime());
    vo.setCreateBy(sub.getCreateBy());
    vo.setSysOrgCode(sub.getSysOrgCode());
    vo.setUpdateTime(sub.getUpdateTime());
    vo.setUpdateBy(sub.getUpdateBy());


    list<BillEntryDetailedVO> vr;
    for (const auto& entry : sub.getDetail()) {
        BillEntryDetailedVO v;
        v.setSrcNo(entry.getSrcNo());
        v.setMaterialId(entry.getMaterialId());
        v.setSize("");
        v.setWarehouseId(entry.getWarehouseId());
        v.setUnit(entry.getUnitId());
        v.setSettleQty(entry.getSettleQty());
        v.setTaxRate(entry.getTaxRate());
        v.setPrice(entry.getPrice());
        v.setDiscountRate(entry.getDiscountRate());
        v.setTax(entry.getTax());
        v.setSettleAmt(entry.getSettleAmt());
        v.setInNum(entry.getQty());
        v.setBuyCost(entry.getCost());
        v.setInMoney(entry.getCost());
        v.setInvoicedQty(entry.getInvoicedQty());
        v.setInvoicedAmt(entry.getInvoicedAmt());
        v.setRemarks(entry.getRemark());
        v.setCustom1(entry.getCustom1());
        v.setCustom2(entry.getCustom2());

        vr.push_back(v);
    }
    vo.setDetail(vr);

    return vo;

}
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

#ifdef LINUX
// 定义客户端对象
    FastDfsClient client("conf/client.conf", 3);
#else
    // 定义客户端对象
    FastDfsClient client("1.15.240.108");
#endif

    string attachment{ "" };
    for (auto& f : dto.getFiles())
    {
        string fileName = client.uploadFile(f);
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
            entryData.setEntryNo(ety.getEntryNo());
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

#ifdef LINUX
    // 定义客户端对象
    FastDfsClient client("conf/client.conf", 3);
#else
    // 定义客户端对象
    FastDfsClient client("1.15.240.108");
#endif

    string attachment{ "" };
    for (auto& f : dto.getFiles())
    {
        string fileName = client.uploadFile(f);
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
        client.deleteFile(attachment);
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
        entryData.setEntryNo(ety.getEntryNo());
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
    // 生成雪花id
    SnowFlake sf(1, 5);

    // 用来记录单据表编号 提供给其对应的明细Mid
    map<string, string> billToMid;
    vector<string> noList;
    // 检验明细表的主表是谁
    auto check = [](const map<string, string> mp, const string& batchNo)
    {
        // 获取明细的源点编号
        int pos = batchNo.find_last_of('-');
        string srcBillNo = batchNo.substr(0, pos);

        // 查找srcBillNo是否存在
        auto it = mp.find(srcBillNo);
        if (it != mp.end())
        {
            return it->second;
        }
        return string{ "" };
    };

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
            CgthckDO tmpDo;
            int j = 0;
            auto tmpData = data[i];

            // 生成id
            string id = to_string(sf.nextId());

            // ID
            tmpDo.setId(id);
            // 出入库类型
            tmpDo.setStockIoType(tmpData[j++]);
            // 是否有往来
            tmpDo.setHasRp(stoi(tmpData[j++]));
            // 是否有涨吨
            tmpDo.setHasSwell(stoi(tmpData[j++]));
            // 供应商
            tmpDo.setSupplierId(tmpData[j++]);
            // 客户
            tmpDo.setCustomerId(tmpData[j++]);
            // 发票类型
            tmpDo.setInvoiceType(tmpData[j++]);
            // 业务部门
            tmpDo.setOpDept(tmpData[j++]);
            // 业务员
            tmpDo.setOperator1(tmpData[j++]);
            // 出入库经办
            tmpDo.setHandler(tmpData[j++]);
            // 成本
            tmpDo.setCost(stod(tmpData[j++]));
            // 结算金额
            tmpDo.setSettleAmt(stod(tmpData[j++]));
            // 已结算金额
            tmpDo.setSettledAmt(stod(tmpData[j++]));
            // 已开票金额
            tmpDo.setInvoicedAmt(stod(tmpData[j++]));
            // 是否生效
            tmpDo.setIsEffective(stod(tmpData[j++]));
            // 附件
            tmpDo.setAttachment(tmpData[j++]);
            // 源单id
            tmpDo.setSrcBillId(tmpData[j++]);
            // 单据主题
            tmpDo.setSubject(tmpData[j++]);
            // 单据阶段
            tmpDo.setBillStage(tmpData[j++]);
            // 源单号
            tmpDo.setSrcNo(tmpData[j++]);
            // 是否自动生成
            tmpDo.setIsAuto(stoi(tmpData[j++]));
            // 备注
            tmpDo.setRemark(tmpData[j++]);
            // 审批实例id
            tmpDo.setBpmiInstanceId(tmpData[j++]);
            // 已作废
            tmpDo.setIsVoided(stoi(tmpData[j++]));
            // 单据编号
            string billNo = tmpData[j++];
            tmpDo.setBillNo(billNo);
            // 是否红字
            tmpDo.setIsRubric(stoi(tmpData[j++]));
            // 源单类型
            tmpDo.setSrcBillType(tmpData[j++]);
            // 制单时间
            tmpDo.setCreateTime(tmpData[j++]);
            // 生效时间
            tmpDo.setEffectiveTime(tmpData[j++]);
            // 核批人
            tmpDo.setApprover(tmpData[j++]);
            // 修改人
            tmpDo.setUpdateBy(tmpData[j++]);
            // 制单部门
            tmpDo.setSysOrgCode(tmpData[j++]);
            // 已关闭
            tmpDo.setIsClosed(stoi(tmpData[j++]));
            // 核批结合类型
            tmpDo.setApprovalResultType(tmpData[j++]);
            // 单据日期
            tmpDo.setBillDate(tmpData[j++]);
            // 制单人
            tmpDo.setCreateBy(tmpData[j++]);
            // 核批意见
            tmpDo.setApprovalRemark(tmpData[j++]);

            // 构建pair(billNo, id) 放入map中
            billToMid[billNo] = id;

            //
            cgthckDo.push_back(tmpDo);
        }
    }
    list<CgthckEntryDO> cgthckEntryDo;
    for (int i = 1; i < entryData.size(); i++)
    {
        CgthckEntryDO tmpEntryDo;
        auto tmpData = entryData[i];
        int j = 0;

        // id
        tmpEntryDo.setId(to_string(sf.nextId()));
        // 物料
        tmpEntryDo.setMaterialId(tmpData[j++]);
        // 批次号
        string batchNo = tmpData[j++];
        tmpEntryDo.setBatchNo(batchNo);
        // 仓库
        tmpEntryDo.setWarehouseId(tmpData[j++]);
        // 出入方向
        tmpEntryDo.setStockIoDirection(tmpData[j++]);
        // 供应商
        tmpEntryDo.setSupplierId(tmpData[j++]);
        // 计量单位
        tmpEntryDo.setUnitId(tmpData[j++]);
        // 涨吨数量
        tmpEntryDo.setSwellQty(stod(tmpData[j++]));
        // 数量
        tmpEntryDo.setQty(stod(tmpData[j++]));
        // 计入成本数量
        tmpEntryDo.setExpense(stod(tmpData[j++]));
        // 成本
        tmpEntryDo.setCost(stod(tmpData[j++]));
        // 结算数量
        tmpEntryDo.setSettleQty(stod(tmpData[j++]));
        // 税率%
        tmpEntryDo.setTaxRate(stod(tmpData[j++]));
        // 含税单价
        tmpEntryDo.setPrice(stod(tmpData[j++]));
        // 折扣率%
        tmpEntryDo.setDiscountRate(stod(tmpData[j++]));
        // 税额
        tmpEntryDo.setTax(stod(tmpData[j++]));
        // 结算金额
        tmpEntryDo.setSettleAmt(stod(tmpData[j++]));
        // 已开票数量
        tmpEntryDo.setInvoicedQty(stod(tmpData[j++]));
        // 已开票金额
        tmpEntryDo.setInvoicedAmt(stod(tmpData[j++]));
        // 自定义1
        tmpEntryDo.setCustom1(tmpData[j++]);
        // 源点分录号
        tmpEntryDo.setSrcNo(tmpData[j++]);
        // 分录号
        tmpEntryDo.setEntryNo(stoi(tmpData[j++]));
        // 自定义2
        tmpEntryDo.setCustom2(tmpData[j++]);
        // 源单分录id
        tmpEntryDo.setSrcEntryId(tmpData[j++]);
        // 源单类型
        tmpEntryDo.setSrcBillType(tmpData[j++]);
        // 备注
        tmpEntryDo.setRemark(tmpData[j++]);
        // 单据编号
        tmpEntryDo.setBillNo(tmpData[j++]);
        // 源单id
        tmpEntryDo.setSrcBillId(tmpData[j++]);
        // mid
        tmpEntryDo.setMid(check(billToMid, batchNo));

        // 
        cgthckEntryDo.push_back(tmpEntryDo);
    }
    // 处理list<CgthckDO>
    CgthckDAO dao;
    int result = 0;
    for (auto& sub : cgthckDo)
    {
        result += dao.importData(sub);
    }
    // 处理list<CgthckEntryDO>
    for (auto& sub : cgthckEntryDo)
    {
        result += dao.importData(sub);
    }
    return result;
}

ExportCgthckVO CgthckService::exportData(const ExportCgthckFileDTO& dto)
{
    // 创建查询对象
    CgthckDAO dao;
    CgthckDO cgthckDo;
    CgthckEntryDO cgthckEntryDo;

    // 设置sql语句的查询条件
    cgthckDo.setBillNo(dto.getBillNo());
    cgthckEntryDo.setBillNo(dto.getBillNo());

    // 返回正确的查询对象
    list<CgthckDO> listDo = dao.exportData(cgthckDo);
    list<CgthckEntryDO> listEntryDo = dao.exportData(cgthckEntryDo);

    // 报表的抽象 ---> 二维数组
    vector<vector<std::string>> data;
    vector<vector<std::string>> entryData;

    // 表头 用来填充第一行数据
    vector<string> header{
        CharsetConvertHepler::ansiToUtf8("出入库类型"),
        CharsetConvertHepler::ansiToUtf8("是否有往来"),
        CharsetConvertHepler::ansiToUtf8("是否有涨吨"),
        CharsetConvertHepler::ansiToUtf8("供应商"),
        CharsetConvertHepler::ansiToUtf8("客户"),
        CharsetConvertHepler::ansiToUtf8("发票类型"),
        CharsetConvertHepler::ansiToUtf8("业务部门"),
        CharsetConvertHepler::ansiToUtf8("业务员"),
        CharsetConvertHepler::ansiToUtf8("出入库经办"),
        CharsetConvertHepler::ansiToUtf8("成本"),
        CharsetConvertHepler::ansiToUtf8("结算金额"),
        CharsetConvertHepler::ansiToUtf8("已结算金额"),
        CharsetConvertHepler::ansiToUtf8("已开票金额"),
        CharsetConvertHepler::ansiToUtf8("是否生效"),
        CharsetConvertHepler::ansiToUtf8("附件"),
        CharsetConvertHepler::ansiToUtf8("源单id"),
        CharsetConvertHepler::ansiToUtf8("单据主题"),
        CharsetConvertHepler::ansiToUtf8("单据阶段"),
        CharsetConvertHepler::ansiToUtf8("源单号"),
        CharsetConvertHepler::ansiToUtf8("是否自动生成"),
        CharsetConvertHepler::ansiToUtf8("备注"),
        CharsetConvertHepler::ansiToUtf8("审批实例id"),
        CharsetConvertHepler::ansiToUtf8("已作废"),
        CharsetConvertHepler::ansiToUtf8("单据编号"),
        CharsetConvertHepler::ansiToUtf8("是否红字"),
        CharsetConvertHepler::ansiToUtf8("源单类型"),
        CharsetConvertHepler::ansiToUtf8("制单时间"),
        CharsetConvertHepler::ansiToUtf8("生效时间"),
        CharsetConvertHepler::ansiToUtf8("核批人"),
        CharsetConvertHepler::ansiToUtf8("修改人"),
        CharsetConvertHepler::ansiToUtf8("制单部门"),
        CharsetConvertHepler::ansiToUtf8("已关闭"),
        CharsetConvertHepler::ansiToUtf8("核批结果类型"),
        CharsetConvertHepler::ansiToUtf8("单据日期"),
        CharsetConvertHepler::ansiToUtf8("制单人"),
        CharsetConvertHepler::ansiToUtf8("核批意见"),
    };
    data.push_back(header);
    // 如果查询对象不为空
    if (!listDo.empty())
    {
        for (auto& tmpDo : listDo)
        {
            vector<string> sub{
                tmpDo.getStockIoType(),
                to_string(tmpDo.getHasRp()),
                to_string(tmpDo.getHasSwell()),
                tmpDo.getSupplierId(),
                tmpDo.getCustomerId(),
                tmpDo.getInvoiceType(),
                tmpDo.getOpDept(),
                tmpDo.getOperator1(),
                tmpDo.getHandler(),
                to_string(tmpDo.getCost()),
                to_string(tmpDo.getSettleAmt()),
                to_string(tmpDo.getSettledAmt()),
                to_string(tmpDo.getInvoicedAmt()),
                to_string(tmpDo.getIsEffective()),
                tmpDo.getAttachment(),
                tmpDo.getSrcBillId(),
                tmpDo.getSubject(),
                tmpDo.getBillStage(),
                tmpDo.getSrcNo(),
                to_string(tmpDo.getIsAuto()),
                tmpDo.getRemark(),
                tmpDo.getBpmiInstanceId(),
                to_string(tmpDo.getIsVoided()),
                tmpDo.getBillNo(),
                to_string(tmpDo.getIsRubric()),
                tmpDo.getSrcBillType(),
                tmpDo.getCreateTime(),
                tmpDo.getEffectiveTime(),
                tmpDo.getApprover(),
                tmpDo.getUpdateBy(),
                tmpDo.getSysOrgCode(),
                to_string(tmpDo.getIsClosed()),
                tmpDo.getApprovalResultType(),
                tmpDo.getBillDate(),
                tmpDo.getCreateBy(),
                tmpDo.getApprovalRemark()
            };
            data.push_back(sub);
        }
    }

    vector<string> entryHeader{
        CharsetConvertHepler::ansiToUtf8("物料"),
        CharsetConvertHepler::ansiToUtf8("批次号"),
        CharsetConvertHepler::ansiToUtf8("仓库"),
        CharsetConvertHepler::ansiToUtf8("出入方向"),
        CharsetConvertHepler::ansiToUtf8("供应商"),
        CharsetConvertHepler::ansiToUtf8("计量单位"),
        CharsetConvertHepler::ansiToUtf8("涨吨数量+/-"),
        CharsetConvertHepler::ansiToUtf8("数量"),
        CharsetConvertHepler::ansiToUtf8("计入成本费用"),
        CharsetConvertHepler::ansiToUtf8("成本"),
        CharsetConvertHepler::ansiToUtf8("结算数量"),
        CharsetConvertHepler::ansiToUtf8("税率%"),
        CharsetConvertHepler::ansiToUtf8("含税单价"),
        CharsetConvertHepler::ansiToUtf8("折扣率%"),
        CharsetConvertHepler::ansiToUtf8("税额"),
        CharsetConvertHepler::ansiToUtf8("结算金额"),
        CharsetConvertHepler::ansiToUtf8("已开票数量"),
        CharsetConvertHepler::ansiToUtf8("已开票金额"),
        CharsetConvertHepler::ansiToUtf8("自定义1"),
        CharsetConvertHepler::ansiToUtf8("源单分录号"),
        CharsetConvertHepler::ansiToUtf8("分录号"),
        CharsetConvertHepler::ansiToUtf8("自定义2"),
        CharsetConvertHepler::ansiToUtf8("源单分录id"),
        CharsetConvertHepler::ansiToUtf8("源单类型"),
        CharsetConvertHepler::ansiToUtf8("备注"),
        CharsetConvertHepler::ansiToUtf8("单据编号"),
        CharsetConvertHepler::ansiToUtf8("源单id")
    };
    data.push_back(entryHeader);

    if (!listEntryDo.empty())
    {
        for (auto& tempEntryDo : listEntryDo)
        {
            vector<string> sub
            {
                tempEntryDo.getMaterialId(),
                tempEntryDo.getBatchNo(),
                tempEntryDo.getWarehouseId(),
                tempEntryDo.getStockIoDirection(),
                tempEntryDo.getSupplierId(),
                tempEntryDo.getUnitId(),
                to_string(tempEntryDo.getSwellQty()),
                to_string(tempEntryDo.getQty()),
                to_string(tempEntryDo.getExpense()),
                to_string(tempEntryDo.getCost()),
                to_string(tempEntryDo.getSettleQty()),
                to_string(tempEntryDo.getTaxRate()),
                to_string(tempEntryDo.getPrice()),
                to_string(tempEntryDo.getDiscountRate()),
                to_string(tempEntryDo.getTax()),
                to_string(tempEntryDo.getSettleAmt()),
                to_string(tempEntryDo.getInvoicedQty()),
                to_string(tempEntryDo.getInvoicedAmt()),
                tempEntryDo.getCustom1(),
                tempEntryDo.getSrcNo(),
                to_string(tempEntryDo.getEntryNo()),
                tempEntryDo.getCustom2(),
                tempEntryDo.getSrcEntryId(),
                tempEntryDo.getSrcBillType(),
                tempEntryDo.getRemark(),
                tempEntryDo.getBillNo(),
                tempEntryDo.getSrcBillId()
            };
            data.push_back(sub);
        }
    }
    
    //定义保存数据位置和页签名称
    string fileName = "./public/excel/c5-cgthck.xlsx";
    string sheetName = CharsetConvertHepler::ansiToUtf8("出入库单");
 /*   string entrySheetName = CharsetConvertHepler::ansiToUtf8("明细");*/

    // 保存文件
    ExcelComponent excel;
    excel.writeVectorToFile(fileName, sheetName, data);
    //excel.writeVectorToFile(fileName, entrySheetName, entryData);

//    // 定义fastdfs客户端对象
//#ifdef LINUX
//    FastDfsClient client("conf/client.conf", 3);
//#else
//    FastDfsClient client("1.15.240.108");
//#endif
//    // 将文件上传到fastdfs
//    string fieldName = client.uploadFile(fileName);
//    // 删除本地文件
//    std::remove(fieldName.c_str());
//    // 返回下载地址
//    fieldName = "http://1.15.240.108:8888/" + fieldName;

    ExportCgthckVO result(fileName);
    return result;
}
