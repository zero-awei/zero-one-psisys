// 采购付款

//采购付款无申请

import {stklo, viewSpecifiedDocInfFalse} from "../../../../apis/test/test";
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






