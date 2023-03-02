import Request from '@/apis/request.js'

// 定义一个功能模块基础url，方便替换
const currBaseUrl = '/systemmanagement/sys-depart/'

// j2 4.1 删除组织结构
export function delete(data, success, fail) {
  Request.requestForm(
    Request.DELETE,
    currBaseUrl + 'remove',
    data
  )
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


// j2 4.2 新增组织结构
export function insert(data, success, fail) {
    Request.requestForm(
      Request.POST,
      currBaseUrl + 'add',
      data
    )
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


// j2 4.2 修改组织结构
export function modify(data, success, fail) {
  Request.requestForm(
    Request.POST,
    currBaseUrl + 'modify',
    data
  )
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


// j2 4.2 查询组织列表
export function queryAll(data, success, fail) {
  Request.requestForm(
    Request.POST,
    currBaseUrl + 'query-all',
    data
  )
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


// j2 4.2 查询指定结构树
export function queryTree(data, success, fail) {
  Request.requestForm(
    Request.POST,
    currBaseUrl + 'query-tree',
    data
  )
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
  