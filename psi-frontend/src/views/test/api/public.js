import {
    finPaymentReq,
    queryDocumentListTrue,
    queryDocumentListFalse,
    queryDocumentListRed, stklo, deliveryOrder, viewSpecifiedDocInfFalse
} from '../../../apis/test/test.js'
//参数说明
/**
 * billDate 单据日期
 * billNo 单据编号
 * supplierId 供应商
 *

 */
//(采购付款-有申请)付款申请查询
export function finPayment() {
    // 自定义请求参数
    let params = {}
    params.realname='单据日期'
    params.billNo = '单据编号'
    params.supplierId='供应商'
    finPaymentReq(
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
//(采购付款-有申请)付款申请查询
export function queryDocumentList() {
    // 自定义请求参数
    let params = {}
    params.billNo = '单据编号'
    params.subject='主题'
    queryDocumentListFalse(
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
//查询单据列表数据(红付)
export function queryDocumentList() {
    // 自定义请求参数
    let params = {}
    params.billNo = '单据编号'
    params.subject='主题'
    queryDocumentListRed(
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
// j5.1查询单据列表数据(有申请)
export function queryDocumentList() {
    // 自定义请求参数
    let params = {}
    params.billNo = '单据编号'
    params.subject='主题'
    queryDocumentListTrue(
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
//(采购付款-无申请)采购入库单查询
export function stkloList() {
    // 自定义请求参数
    let params = {}
    params.realname='单据日期'
    params.billNo = '单据编号'
    params.supplierId='供应商'
    stklo(
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
//(采购退货退款-红付)采购退货出库单
export function deliveryOrderList() {
    // 自定义请求参数
    let params = {}
    params.realname='单据日期'
    params.billNo = '单据编号'
    params.supplierId='供应商'
    deliveryOrder(
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
//查看指定单据信息(无申请)
export function viewSpecifiedDocInfFalseList() {
    // 自定义请求参数
    let params = {}
    params.billNo = '单据编号'
    viewSpecifiedDocInfFalse(
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
