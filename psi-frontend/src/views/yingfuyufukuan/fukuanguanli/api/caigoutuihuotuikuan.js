/*
 * @Author: 160405103 1348313766@qq.com
 * @Date: 2023-03-03 16:11:53
 * @LastEditors: 160405103 1348313766@qq.com
 * @LastEditTime: 2023-03-03 16:16:47
 * @FilePath: \psi-frontend\src\views\yingfuyufukuan\fukuanguanli\api\caigoutuihuotuikuan.js
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
// 采购退货退款（红付）
//查询单据列表数据(红付)
import {deliveryOrder, queryDocumentListRed, viewSpecifiedDocInfRed} from "../../../../apis/test/test";

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

// 查看指定单据信息(红付)
export function viewSpecifiedDocInfRedList() {
    // 自定义请求参数
    let params = {}
    params.billNo = '单据编号'
    viewSpecifiedDocInfRed(
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

