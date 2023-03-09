//  采购付款（有申请）
import {
    finPaymentReq,
    queryDocumentListFalse,
    queryDocumentListTrue,
    viewSpecifiedDocInfTrue
} from '../../../../apis/test/test.js';

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

// 查看指定单据信息(有申请)
export function viewSpecifiedDocInfTrueList() {
    // 自定义请求参数
    let params = {}
    params.billNo = '单据编号'
    viewSpecifiedDocInfTrue(
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

