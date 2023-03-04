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
const currBaseUrl = '/sysmanagement/rolemanagement/menu/'

// const Data = {
//   icon: 'null',
//   id: '12345678',
//   name: '菜单1',
//   parentId: '00a2a0ae65cdca5e93209cdbde97cbe6',
//   sortNo: '1.1',
//   url: '/main/1'
// }
// 7.1 系统管理 新增菜单
export function handleSaveMenu(data, success, fail) {
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
//   id: '1'
// }
// 7.2 系统管理 删除菜单
export function handleDeleteMenu(data, success, fail) {
  Request.requestForm(Request.DELETE, currBaseUrl + 'delete', data)
    .then((data) => {
      if (data.data === true) {
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
//   RId: '043780fa095ff1b2bec4dc406d76f023'
// }
// 7.3 系统管理 查询菜单
export function handleListMenu(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'list', data)
    .then((data) => {
      if (data.data.length > 0) {
        console.log(data)
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
