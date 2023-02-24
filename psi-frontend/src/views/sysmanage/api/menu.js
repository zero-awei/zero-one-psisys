import Request from '@/apis/request.js'

// 定义一个功能模块基础url，方便替换
const currBaseUrl = '/sysmanagement/menumanagement/sys-menu/'

// export function addMenu(data, success, fail) {
//   Request.requestForm().then().catch()
// }
// 4.1 新增菜单
export function addMenu(data, success, fail) {
  Request.requestForm(Request.POST, currBaseUrl + 'add', data)
    .then((data) => {
      // 可以console.log(data) 在浏览器控制台查看数据
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
// 4.2 删除菜单
export function deleteMenu(data, success, fail) {
  Request.requestForm(Request.DELETE, currBaseUrl + 'delete', data)
    .then((data) => {
      // 可以console.log(data) 在浏览器控制台查看数据
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

// 4.3 查询菜单 id
export function query(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'query', data)
    .then((data) => {
      // 可以console.log(data) 在浏览器控制台查看数据
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

// 4.4 查询菜单  参数parentId
export function queryMenus(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'queryMenus', data)
    .then((data) => {
      // 可以console.log(data) 在浏览器控制台查看数据
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
// 4.5 修改菜单
export function update(data, success, fail) {
  Request.requestForm(Request.PUT, currBaseUrl + 'update', data)
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
