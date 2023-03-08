import Request from '@/apis/request.js'

// 定义一个功能模块基础url，方便替换
const currBaseUrl = '/purorder/'

// c4 1.查询单据列表
export function listPurOrder(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'purOrder/list', data)
    .then((data) => {
      // console.log('后端返回data----', data)
      // data是后端的响应示例
      // 可以console.log(data) 在浏览器控制台查看数据
      // console.log(data)

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

// c4 2.查看指定单据详细信息
export function queryPurOrderEntryByMainId(data, success, fail) {
  Request.requestForm(
    Request.GET,
    currBaseUrl + 'purOrder/queryEntryByMainId',
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

// c4 3.采购申请单列表
export function queryPurReqEntryByMainId(data, success, fail) {
  Request.requestForm(
    Request.GET,
    currBaseUrl + 'purReq/queryEntryByMainId',
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

// c4 4.采购申请单分录列表
export function listPurReq(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'purReq/list', data)
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

// c3 采购询价单列表
// c3 采购询价单分录列表
// c3 报价单列表
// c3 报价单分录列表

// c4 5.比价单列表
export function listPurCom(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'purCom/list', data)
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

// c4 6.比价单分录列表
export function listEntrysPurCom(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'purCom/listEntrys', data)
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

// c4 7.添加采购订单（保存/提交）
export function addPurOrder(data, success, fail) {
  Request.requestForm(Request.POST, currBaseUrl + 'purOrder/add', data)
    .then((data) => {
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

// c4 8.修改采购订单（保存/提交/审核）
export function editPurOrder(data, success, fail) {
  Request.requestForm(Request.PUT, currBaseUrl + 'purOrder/edit', data)
    .then((data) => {
      console.log('后端返回data----', data)
      // data是后端的响应示例
      // 可以console.log(data) 在浏览器控制台查看数据
      console.log(data)

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

// c4 9.删除采购订单
//根据单据编号删除
export function deletePurOrder(data, success, fail) {
  Request.requestForm(Request.DELETE, currBaseUrl + 'purOrder/delete', data)
    .then((data) => {
      console.log('后端返回data----', data)
      // data是后端的响应示例
      // 可以console.log(data) 在浏览器控制台查看数据
      console.log(data)

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
//根据ID删除
export function deleteByIdPurOrder(data, success, fail) {
  Request.requestForm(Request.DELETE, currBaseUrl + 'purOrder/deleteById', data)
    .then((data) => {
      console.log('后端返回data----', data)
      // data是后端的响应示例
      // 可以console.log(data) 在浏览器控制台查看数据
      console.log(data)

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

// c4 10.修改单据状态（关闭/作废/反关闭）
export function modifyStatusPurOrder(data, success, fail) {
  Request.requestForm(Request.PUT, currBaseUrl + 'purOrder/modifyStatus', data)
    .then((data) => {
      console.log('后端返回data----', data)
      // data是后端的响应示例
      // 可以console.log(data) 在浏览器控制台查看数据
      console.log(data)

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

// c4 11.导入（砍掉了没搞）
// c4 12.导出（砍掉了没搞）
