import Request from '../request'

// 定义一个功能模块基础url，方便替换

const currBaseUrl = '/paymentmanagement'

// j5.2(采购付款-有申请)付款申请查询
export function finPaymentReq(data, success, fail) {
    Request.requestForm(Request.GET, currBaseUrl + 'fin-payment-req', data)
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

//查询单据列表数据(无申请)
export function queryDocumentListFalse(data, success, fail) {
    Request.requestForm(Request.POST, currBaseUrl + 'queryDocumentListFalse', data)
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
//查询单据列表数据(红付)
export function queryDocumentListRed(data, success, fail) {
    Request.requestForm(Request.POST, currBaseUrl + 'queryDocumentListRed', data)
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

// j5.1查询单据列表数据(有申请)
export function queryDocumentListTrue(data, success, fail) {
    Request.requestForm(Request.POST, currBaseUrl + 'queryDocumentListTrue', data)
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

//(采购付款-无申请)采购入库单查询
export function stklo(data, success, fail) {
    Request.requestForm(Request.GET, currBaseUrl + 'stklo', data)
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

//(采购退货退款-红付)采购退货出库单
export function deliveryOrder(data, success, fail) {
    Request.requestForm(Request.GET, currBaseUrl + 'stklo/deliveryOrder', data)
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
//查看指定单据信息(无申请)
export function viewSpecifiedDocInfFalse(data, success, fail) {
    Request.requestForm(Request.GET, currBaseUrl + 'viewSpecifiedDocInfFalse', data)
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
// 查看指定单据信息(红付)
export function viewSpecifiedDocInfRed(data, success, fail) {
    Request.requestForm(Request.GET, currBaseUrl + 'viewSpecifiedDocInfRed', data)
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
// 查看指定单据信息(有申请)
export function viewSpecifiedDocInfTrue(data, success, fail) {
    Request.requestForm(Request.GET, currBaseUrl + 'viewSpecifiedDocInfTrue', data)
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
