/***
 * 根节点url 路径定义不同
 *
 */

//付款管理
import Request from '../request'

// 定义一个功能模块基础url，方便替换
const currBaseUrl = '/purchase-payment'
// 删除单据
export function deleteList(data, success, fail) {
    Request.requestForm(Request.DELETE, currBaseUrl + 'delete', data)
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
// 增加单据
export function saveList(data, success, fail) {
    Request.requestForm(Request.POST, currBaseUrl + 'save', data)
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
//修改单据
export function updateList(data, success, fail) {
    Request.requestForm(Request.POST, currBaseUrl + 'update', data)
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
