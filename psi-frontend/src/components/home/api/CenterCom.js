import Request from '@/apis/request.js'
// 定义一个功能模块基础url，方便替换
const currBaseUrl = '/homepage/onl-cgreport-head/'
//j2
//2.5系统收支概况 CenterCom1组件中第一个
export function getSysList(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'query-Sys', data, {
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

//2.1 查询客户数量概况 CenterCom1组件第二个
export function getCusList(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'query-Customer', data, {
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

//2.3 查询销售概况  CenterDivCom 第一个
export function getSalList(data, success, fail) {
  Request.requestJson(Request.POST, currBaseUrl + 'query-Sale', data, {
    baseURL: import.meta.env.VITE_API_J2_TITLE
  })
    .then((data) => {
      if (data.data) {
        success(data.data)
        // console.log(data)
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

//2.2 查询采购概况  CenterDivCom 第二个
export function getPurList(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'query-Purchase', data, {
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

//2.4查询销售金额概况 CenterPicCom第一个
export function getSalmList(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'query-SalesAmount', data, {
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
