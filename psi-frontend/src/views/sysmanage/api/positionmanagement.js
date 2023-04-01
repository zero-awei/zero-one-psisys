import Request from '@/apis/request.js'

// 定义一个功能模块基础url，方便替换
const currBaseUrl = '/systemmanagement/sys-position/'
const currBaseUrlExcel = '/excel-positionmanagement'

// j2 4.1 添加职务（返回值data值表示插入成功与否）
export function addPosition(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'addPosition', data, {
    baseURL: import.meta.env.VITE_API_J2_SYS
  })
    .then((data) => {
      // console.log('后端返回data----', data)
      // data是后端的响应示例
      // 可以// console.log(data) 在浏览器控制台查看数据
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

// j2 4.3 删除职务（返回值data值表示删除成功与否）
export function deleteP(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'deletePosition', data)
    .then((data) => {
      // console.log('后端返回data----', data)
      // data是后端的响应示例
      // 可以// console.log(data) 在浏览器控制台查看数据
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

// j2 4.4 查询职级
export function queryRank(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'queryPostRank', data)
    .then((data) => {
      // console.log('后端返回data----', data)
      // data是后端的响应示例
      // 可以// console.log(data) 在浏览器控制台查看数据
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

// j2 4.3 查询职务列表
export function queryAll(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'queryall', data, {
    baseURL: import.meta.env.VITE_API_J2_SYS
  })
    .then((data) => {
      // console.log('后端返回data----', data)
      // data是后端的响应示例
      // 可以// console.log(data) 在浏览器控制台查看数据
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

// j2 4.4 修改职务（返回值data值表示更新成功与否）
export function updatePosition(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'updatePosition', data)
    .then((data) => {
      // console.log('后端返回data----', data)
      // data是后端的响应示例
      // 可以// console.log(data) 在浏览器控制台查看数据
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

// j2 4.5 获取导出文件
export function download(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrlExcel + 'get-file', data)
    .then((data) => {
      // console.log('后端返回data----', data)
      // data是后端的响应示例
      // 可以// console.log(data) 在浏览器控制台查看数据
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

// j2 4.6 获取导出链接
export function downloadUrl(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrlExcel + 'get-downloadurl', data)
    .then((data) => {
      // console.log('后端返回data----', data)
      // data是后端的响应示例
      // 可以// console.log(data) 在浏览器控制台查看数据
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

// j2 4.6 文件导入
export function upload(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrlExcel + 'upload', data)
    .then((data) => {
      // console.log('后端返回data----', data)
      // data是后端的响应示例
      // 可以// console.log(data) 在浏览器控制台查看数据
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
