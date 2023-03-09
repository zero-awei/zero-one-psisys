/*
 * @Author: ali
 * @Date: 2023-02-19 17:03:44
 * @LastEditTime: 2023-02-21 16:01:44
 * @LastEditors: 160405103 1348313766@qq.com
 * @Description:
 * @FilePath: \psi-frontend\src\views\yingfuyufukuan\payables\methods.js
 * 可以输入预定的版权声明、个性签名、空行等
 */
import Request from '@/apis/request.js'

// 定义一个功能模块基础url，方便替换
const currBaseUrl = '/sysmanagement/rolemanagement/permission/'

// 7.1 系统管理 新增权限
export function handleSavePermission(data, success, fail) {
  Request.requestForm(Request.POST, currBaseUrl + 'add', data)
    .then((data) => {
      if (data.data === true) {
        console.log(data.data)
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
// const Data = {
//   permissionId: '1'
// }
// 7.2 系统管理 删除权限
export function handleDeletePermission(data, success, fail) {
  Request.requestForm(Request.DELETE, currBaseUrl + 'delete', data)
    .then((data) => {
      if (data.data === true) {
        console.log(data.data)
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
// const Data = {
//   RId: '00a2a0ae65cdca5e93209cdbde97cbe6'
// }
// 7.3 系统管理 查询权限
export function handleListPermission(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'list', data)
    .then((data) => {
      if (data.data.length > 0) {
        console.log(data.data)
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
