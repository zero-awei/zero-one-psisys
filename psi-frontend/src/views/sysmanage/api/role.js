/*
 * @Author: li.ziwei
 * @Date: 2023-02-19 17:03:44
 * @LastEditTime: 2023-03-05 20:21:33
 * @LastEditors: 160405103 1348313766@qq.com
 * @Description:
 * @FilePath: \psi-frontend\src\views\yingfuyufukuan\payables\methods.js
 * 可以输入预定的版权声明、个性签名、空行等
 */
import Request from '@/apis/request.js'

// 定义一个功能模块基础url，方便替换
const currBaseUrl = '/sysmanagement/rolemanagement/'

// 6.3 分页查询角色信息
export function getTableList(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'detail', data)
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

// // 7.5 普通查询
// export function getTableList(data, success, fail) {
//   Request.requestForm(Request.GET, currBaseUrl + 'detail', data)
//     .then((data) => {
//       if (data.data) {
//         success(data.data)
//         return
//       }
//       fail()
//     })
//     .catch((err) => {
//       // 打印错误信息
//       console.warn(err)
//       // 执行失败回调
//       fail()
//     })
// }
export function handleDeleteRole(data, success, fail) {
  Request.requestForm(Request.DELETE, currBaseUrl + 'delete', data)
    .then((data) => {
      if (data.code === 10000) {
        console.log('hello')
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

// 6.2 角色管理 新增角色
export function handleSaveRole(data, success, fail) {
  Request.requestForm(Request.POST, currBaseUrl + 'insert', data)
    .then((data) => {
      if (data.code === 10000) {
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
// const data = {
//   pageIndex: '1',
//   pageSize: '10',
//   roleCode: 'third_role',
//   roleName: '第三方登录角色'
// }
// 6.3 角色管理 分页查询角色权限
export function handleQueryAllROle(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'query-all', data)
    .then((data) => {
      if (data.code === 10000) {
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

// 6.4 角色管理 修改信息
export function handleUpdateRole(data, success, fail) {
  Request.requestForm(Request.PUT, currBaseUrl + 'update', data)
    .then((data) => {
      if (data.code === 10000) {
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
