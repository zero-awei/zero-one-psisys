/***
 * 根节点url 路径定义不同
 *
 */

//付款管理
import Request from '../request'

// 定义一个功能模块基础url，方便替换
const currBaseUrl = '/paymentmanager'

// 选择导出
export function exportFile(data, success, fail) {
    Request.requestForm(Request.POST, currBaseUrl + 'export', data)
        .then((data) => {
            if (data.data) {
                success(data.data)
                return
            }
            fail()
        })
        .catch((err) => {
            // 打印错误信息
            console.warn(err)
            // 执行失败回调
            fail()
        })
}
//导入
export function importFile(data, success, fail) {
    Request.requestForm(Request.POST, currBaseUrl + 'import', data)
        .then((data) => {
            if (data.data) {
                success(data.data)
                return
            }
            fail()
        })
        .catch((err) => {
            // 打印错误信息
            console.warn(err)
            // 执行失败回调
            fail()
        })
}
//导入有申请
export function importReq(data, success, fail) {
    Request.requestForm(Request.POST, currBaseUrl + 'importReq', data)
        .then((data) => {
            if (data.data) {
                success(data.data)
                return
            }
            fail()
        })
        .catch((err) => {
            // 打印错误信息
            console.warn(err)
            // 执行失败回调
            fail()
        })
}
//更新单据列表
export function updateBillStage(data, success, fail) {
    Request.requestForm(Request.POST, currBaseUrl + 'updateBillStage', data)
        .then((data) => {
            if (data.data) {
                success(data.data)
                return
            }
            fail()
        })
        .catch((err) => {
            // 打印错误信息
            console.warn(err)
            // 执行失败回调
            fail()
        })
}
//更新单据列表(有申请)
export function updateBillStageReq(data, success, fail) {
    Request.requestForm(Request.POST, currBaseUrl + 'updateBillStageReq', data)
        .then((data) => {
            if (data.data) {
                success(data.data)
                return
            }
            fail()
        })
        .catch((err) => {
            // 打印错误信息
            console.warn(err)
            // 执行失败回调
            fail()
        })
}

