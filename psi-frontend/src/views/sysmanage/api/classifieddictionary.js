import Request from '@/apis/request.js'

// 定义一个功能模块基础url，方便替换
const currBaseUrl = '/systemmanagement/sys-category/'

// j2 4.1 删除指定根字典（返回值data值表示删除成功与否）
export function deleteDict(data, success, fail) {
  Request.requestForm(Request.DELETE, currBaseUrl + 'delete-one', data, {
    baseURL: import.meta.env.VITE_API_J2_SYS
  })
    .then((data) => {
      // console.log('后端返回data----', data)
      // data是后端的响应示例
      // 可以console.log(data) 在浏览器控制台查看数据
      if ((data.code = '10000')) {
        success(data.message)
        return
      }
      fail(data.message)
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

// j2 4.2 插入根字典（返回值data值表示插入成功与否）
export function insert(data, success, fail) {
  Request.requestForm(Request.POST, currBaseUrl + 'insert-one', data, {
    baseURL: import.meta.env.VITE_API_J2_SYS
  })
    .then((data) => {
      // console.log('后端返回data----', data)
      // data是后端的响应示例
      // 可以console.log(data) 在浏览器控制台查看数据
      if ((data.code = '10000')) {
        success(data.message)
        return
      }
      fail(data.message)
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

// j2 4.3 查询所有根字典
export function queryAll(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'query-all', data, {
    baseURL: import.meta.env.VITE_API_J2_SYS
  })
    .then((data) => {
      // console.log('后端返回data----', data)
      // data是后端的响应示例
      // 可以console.log(data) 在浏览器控制台查看数据
      if (data.data) {
        success(data.data)
        return
      }
      fail(data.message)
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

// j2 4.4 查询指定根字典
export function queryOne(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'query-children', data, {
    baseURL: import.meta.env.VITE_API_J2_SYS
  })
    .then((data) => {
      // console.log('后端返回data----', data)
      // data是后端的响应示例
      // 可以console.log(data) 在浏览器控制台查看数据
      if (data.data) {
        success(data.data)
        return
      }
      fail(data.message)
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

// j2 4.5 更新指定根字典（返回值data值表示更新成功与否）
export function updateOne(data, success, fail) {
  Request.requestForm(Request.PUT, currBaseUrl + 'update-one', data, {
    baseURL: import.meta.env.VITE_API_J2_SYS
  })
    .then((data) => {
      // console.log('后端返回data----', data)
      // data是后端的响应示例
      // 可以console.log(data) 在浏览器控制台查看数据
      if ((data.code = '10000')) {
        success(data.message)
        return
      }
      fail(data.message)
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}
