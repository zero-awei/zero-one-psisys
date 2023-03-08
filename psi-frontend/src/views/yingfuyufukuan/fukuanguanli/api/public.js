
import {exportFile, importFile, importReq, updateBillStage, updateBillStageReq} from "../../../../apis/test/test2";
import {deleteList, saveList, updateList} from "../../../../apis/test/test3";

//公共模块

//参数说明
/**
 // amt 金额
 // billNo 单据编号
 // checkedAmt 已核销金额
 // finalPaymentEntryList 源单列表
 //
 // isAuto 是否自动单
 // isRubric 红字单据
 // paymentType 结算方式代
 // srcBillId 源单号
 // srcBillType 源单号类型
 // srcNo 源单号
 // subject 主题
 // supplierId 供应商ID
 // remark
 */
//TODO 文件操作

// 选择导出
export function exportList() {
    // 自定义请求参数
    //接口描述: 选择所需要导出的单据构成一张表导出
    let params = {}
    params.chosenExportDto = ''
    params.ids = ''
    exportFile(
        params,
        (data) => {
            console.log('全部请求data----', data)
            // 查询返回的是表格数据
            // 分页
            // pagination.value.currentPage = data.pageIndex
            // pagination.value.pageSize = data.pageSize
            // pagination.value.total = data.total
            // 表格数据
            // tableData.value = data.rows
        },
        (msg) => {
            ElMessage.warning(msg)
        }
    )
}

//导入
export function importFileList() {
    // 自定义请求参数
    //请求数据类型: multipart/form-data 响应数据类型: */*
    let params = {}
    params.file = ''
    importFile(
        params,
        (data) => {
            console.log('全部请求data----', data)
            // 查询返回的是表格数据
            // 分页
            // pagination.value.currentPage = data.pageIndex
            // pagination.value.pageSize = data.pageSize
            // pagination.value.total = data.total
            // 表格数据
            // tableData.value = data.rows
        },
        (msg) => {
            ElMessage.warning(msg)
        }
    )
}

//导入有申请
export function importReqList() {
    // 自定义请求参数
    //请求数据类型: multipart/form-data 响应数据类型: */*
    let params = {}
    params.file = ''
    importReq(
        params,
        (data) => {
            console.log('全部请求data----', data)
            // 查询返回的是表格数据
            // 分页
            // pagination.value.currentPage = data.pageIndex
            // pagination.value.pageSize = data.pageSize
            // pagination.value.total = data.total
            // 表格数据
            // tableData.value = data.rows
        },
        (msg) => {
            ElMessage.warning(msg)
        }
    )
}

//更新单据列表
export function updateBillStageList() {
    // 自定义请求参数
    let params = {}
    params.updateBillStageDto = ''
    params.billStage = ''
    params.id = ''
    updateBillStage(
        params,
        (data) => {
            console.log('全部请求data----', data)
            // 查询返回的是表格数据
            // 分页
            // pagination.value.currentPage = data.pageIndex
            // pagination.value.pageSize = data.pageSize
            // pagination.value.total = data.total
            // 表格数据
            // tableData.value = data.rows
        },
        (msg) => {
            ElMessage.warning(msg)
        }
    )
}
//更新单据列表
export function updateBillStageReqList() {
    // 自定义请求参数
    let params = {}
    params.updateBillStageDto = ''
    params.billStage = ''
    params.id = ''
    updateBillStageReq(
        params,
        (data) => {
            console.log('全部请求data----', data)
            // 查询返回的是表格数据
            // 分页
            // pagination.value.currentPage = data.pageIndex
            // pagination.value.pageSize = data.pageSize
            // pagination.value.total = data.total
            // 表格数据
            // tableData.value = data.rows
        },
        (msg) => {
            ElMessage.warning(msg)
        }
    )
}

// 删除单据
export function deleteListO() {
    // 自定义请求参数
    let params = {}
    params.billNo = ''
    deleteList(
        params,
        (data) => {
            console.log('全部请求data----', data)
            // 查询返回的是表格数据
            // 分页
            // pagination.value.currentPage = data.pageIndex
            // pagination.value.pageSize = data.pageSize
            // pagination.value.total = data.total
            // 表格数据
            // tableData.value = data.rows
        },
        (msg) => {
            ElMessage.warning(msg)
        }
    )
}
// 增加单据
export function saveListO() {
    // 自定义请求参数
    let params = {}
    //查看顶页参数说明
    params.amt = ''
    params.billNo = ''
    params.checkedAmt = ''
    params.finalPaymentEntryList = ''
    params.isAuto = ''
    params.isRubric = ''
    params.paymentType = ''
    params.srcBillId = ''
    params.srcBillType = ''
    params.srcNo = ''
    params.subject = ''
    params.supplierId = ''
    params.remark = ''
    saveList(
        params,
        (data) => {
            console.log('全部请求data----', data)
            // 查询返回的是表格数据
            // 分页
            // pagination.value.currentPage = data.pageIndex
            // pagination.value.pageSize = data.pageSize
            // pagination.value.total = data.total
            // 表格数据
            // tableData.value = data.rows
        },
        (msg) => {
            ElMessage.warning(msg)
        }
    )
}

// 修改单据
export function updateListO() {
    // 自定义请求参数
    let params = {}
    //参数说明和后端要文档吧 ，不好复制
    params.amt = ''
    params.approvalRemark = ''
    params.approvalResultType = ''
    params.approver = ''
    params.attachment = ''
    params.billDate = ''
    params.billNo = ''
    params.billStage = ''
    params.billStage_dictText = ''
    params.billType = ''
    params.bpmiInstanceId = ''
    params.checkedAmt = ''
    params.createBy = ''
    params.createBy_dictText = ''
    params.createTime = ''
    params.effectiveTime = ''
    params.finPaymentEntryList = ''
    params.id = ''
    params.isAuto = ''
    params.isAuto_dictText = ''
    params.isClosed = ''
    params.isClosed_dictText = ''
    params.isEffective = ''
    params.isEffective_dictText = ''
    params.isRubric = ''
    params.isRubric_dictText = ''
    params.isVoided = ''
    params.isVoided_dictText = ''
    params.paymentType = ''
    params.paymentType_dictText = ''
    params.remark = ''
    params.srcBillId = ''
    params.srcBillType = ''
    params.srcNo = ''
    params.subject = ''
    params.supplierId = ''
    params.supplierId_dictText = ''
    params.sysOrgCode = ''
    params.sysOrgCode_dictText = ''
    params.uncheckedAmt = ''
    params.updateBy = ''
    params.updateTime = ''
    params.version = ''
    updateList(
        params,
        (data) => {
            console.log('全部请求data----', data)
            // 查询返回的是表格数据
            // 分页
            // pagination.value.currentPage = data.pageIndex
            // pagination.value.pageSize = data.pageSize
            // pagination.value.total = data.total
            // 表格数据
            // tableData.value = data.rows
        },
        (msg) => {
            ElMessage.warning(msg)
        }
    )
}