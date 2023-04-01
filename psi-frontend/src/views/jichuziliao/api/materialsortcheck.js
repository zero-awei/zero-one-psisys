import Request from '@/apis/request.js'

// 物料分类
// c2 普通查询
export function getBase(data, success, fail) {
  Request.requestForm(Request.GET, 'get-base', data, {
    baseURL: import.meta.env.VITE_API_C2
  })
    .then((data) => {
      console.log('后端返回data----', data)
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

// c2 查询子集列表
export function getChildren(data, success, fail) {
  Request.requestForm(Request.GET, 'ge-children', data)
    .then((data) => {
      console.log('后端返回data----', data)
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

// c2 查询指定分类详细信息
export function getDetail(data, success, fail) {
  Request.requestForm(Request.GET, 'get-detail', data)
    .then((data) => {
      console.log('后端返回data----', data)
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

// c2 新增分类
export function postAdd(data, success, fail) {
  Request.requestForm(Request.POST, 'post-add', data)
    .then((data) => {
      console.log('后端返回data----', data)
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

// c2 修改分类
export function putModify(data, success, fail) {
  Request.requestForm(Request.PUT, 'put-modify', data)
    .then((data) => {
      console.log('后端返回data----', data)
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

// c2 删除分类
export function deleteById(data, success, fail) {
  Request.requestForm(Request.DELETE, 'delete-by-id', data)
    .then((data) => {
      console.log('后端返回data----', data)
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

// c2 导入
export function postImport(data, success, fail) {
  Request.requestForm(Request.POST, 'post-import', data)
    .then((data) => {
      console.log('后端返回data----', data)
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

// c2 导出
export function getExport(data, success, fail) {
  Request.requestForm(Request.GET, 'get-export', data)
    .then((data) => {
      console.log('后端返回data----', data)
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
