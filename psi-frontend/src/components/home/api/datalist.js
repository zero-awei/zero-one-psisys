import Request from '@/apis/request.js'
// 定义一个功能模块基础url，方便替换
const currBaseUrl = '/homepage/'
//j2
//3.2处理中主要单据 CenterTabCom组件
export function getTableList(data, success, fail) {
    Request.requestForm(Request.GET, currBaseUrl + 'queryHomeDoingBill', data,
    {
      baseURL: import.meta.env.VITE_API_J2_TITLE
    })
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

//3.1查询供应商 CenterCom1组件中第三个
export function getSupList(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'queryBasSupplier', data,
  {
    baseURL: import.meta.env.VITE_API_J2_TITLE
  })
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
//3.4查询毛利润 CenterPicCom第二个
export function getSaloList(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'querySalOrdel', data,
  {
    baseURL: import.meta.env.VITE_API_J2_TITLE
  })
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
//3.3查询采购金额 CenterPicCom第三个
export function getPuroList(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'queryPurOrder', data,
  {
    baseURL: import.meta.env.VITE_API_J2_TITLE
  })
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
//3.5查询库存结存金额 CenterPicCom第四个
export function getQussList(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'queryStkIoSum', data,
  {
    baseURL: import.meta.env.VITE_API_J2_TITLE
  })
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

