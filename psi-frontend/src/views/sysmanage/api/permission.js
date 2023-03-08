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
const currBaseUrl = '/sysmanagement/permissionmanagement/'

// const Data = {
//   fatherPermissionName: '性能监控',
//   fatherUrl: '/monitor',
//   instruction: '拥有该权限的人可以对后台redis进行监控',
//   permissionId: '00a2a0ae65cdca5e93209cdbde97cbe6',
//   permissionName: 'Redis监控',
//   permissionType: 1,
//   url: '/monitor/redis/info'
// }
// 2.1 系统管理 添加权限
export function handleSavePermission(data, success, fail) {
  Request.requestForm(Request.POST, currBaseUrl + 'add', data, {
    baseURL: import.meta.env.VITE_API_J1_SYS
  })
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

// 2.2 系统管理 删除权限
export function handleDeletePermission(data, success, fail) {
  Request.requestForm(Request.DELETE, currBaseUrl + 'delete', data, {
    baseURL: import.meta.env.VITE_API_J1_SYS
  })
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

// 2.3 系统管理 查询权限
export function handleListPermission(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'query', data, {
    baseURL: import.meta.env.VITE_API_J1_SYS
  })
    .then((data) => {
      if (data.code === 10000) {
        // console.log(data)
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
// 2.4 系统管理 更新权限信息
export function handleUpdatePermission(data, success, fail) {
  Request.requestForm(Request.PUT, currBaseUrl + 'update', data, {
    baseURL: import.meta.env.VITE_API_J1_SYS
  })
    .then((data) => {
      if (data.code === 10000) {
        // console.log(data)
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
