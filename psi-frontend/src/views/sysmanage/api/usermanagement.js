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
const currBaseUrl = '/sysmanagement/usermanagement/'

// const data = {
//   activitiSync: '', // 	选择是否同步工作流引擎，1为同步，0为不同步   	boolean
//   avatar: '', // 选择您的头像   string
//   birthday: '', // 	输入您的生日,示例值(2019-04-01 00:00:00)   	string(date-time)
//   clientId: '', // 输入您的设备ID  string
//   departName: '', // 选择您负责的部门   string
//   email: '', // 输入您的电子邮件   string
//   id: '', // id  string
//   orgCode: '', // 	选择您的登录会话的机构编码  string
//   password: '', // 输入您的密码 string
//   phone: '', // 输入您的电话   string
//   post: '', // 输入您的职务  string
//   realname: '', // 输入您的真实名字  string
//   relTenantIds: '', // 是否为多租户   string
//   sex: '', // 选择您的性别，1为男，2为女  intege
//   status: '', // 选择您的状态，1为正常，0为冻结   boolean
//   telephone: '', // 输入您的座机号  string
//   userIdentity: '', // 	选择您的身份，1为普通成员，2为上级  intege
//   username: '', // 	输入您的用户名  string
//   workNo: '' // 	输入您的工号  string
// }
// 2.1 角色管理 添加用户
export function handleSaveUser(data, success, fail) {
  Request.requestForm(Request.POST, currBaseUrl + 'add', data, {
    baseURL: import.meta.env.VITE_API_J1_SYS
  })
    .then((data) => {
      if (data.code === 10000) {
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

// 2.2 角色管理 删除用户
export function handleDeleteUser(data, success, fail) {
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

// 2.3 角色管理 导出用户
export function handleGetUser(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'get-user', data, {
    baseURL: import.meta.env.VITE_API_J1_SYS
  })
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
// 2.4 角色管理 导出所有用户
export function handleGetUsers(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'get-users', data, {
    baseURL: import.meta.env.VITE_API_J1_SYS
  })
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

// 2.5 角色管理 查询用户列表
export function handleListAll(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'list-all', data, {
    baseURL: import.meta.env.VITE_API_J1_SYS
  })
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

// 2.6 角色管理 下拉框获取部门列表
export function handleListDepart(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'list-depart', data, {
    baseURL: import.meta.env.VITE_API_J1_SYS
  })
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

// 3.7 角色管理 修改用户
export function handleModify(data, success, fail) {
  Request.requestForm(Request.PUT, currBaseUrl + 'modify', data, {
    baseURL: import.meta.env.VITE_API_J1_SYS
  })
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

// 3.8 角色管理 模糊查询用户
export function handleQueryUser(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'query-user', data, {
    baseURL: import.meta.env.VITE_API_J1_SYS
  })
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

// 3.9 角色管理 修改用户时的信息回显
export function handleReview(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'review', data, {
    baseURL: import.meta.env.VITE_API_J1_SYS
  })
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

// 3.10 角色管理 冻结-解冻用户
export function handleStatus(data, success, fail) {
  Request.requestForm(Request.PUT, currBaseUrl + 'status', data, {
    baseURL: import.meta.env.VITE_API_J1_SYS
  })
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
// 3.11 角色管理 导入用户
export function handleUpload(data, success, fail) {
  Request.requestForm(Request.POST, currBaseUrl + 'upload', data, {
    baseURL: import.meta.env.VITE_API_J1_SYS
  })
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
