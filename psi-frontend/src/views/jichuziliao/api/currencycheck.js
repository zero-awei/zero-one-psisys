import Request from '@/apis/request.js'

// 币种
// c2 普通查询
export function currencyQuery(data, success, fail) {
    Request.requestForm(Request.GET, 'currency-query', data)
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

// c2 查询指定币种详细信息
export function currencyDetail(data, success, fail) {
    Request.requestForm(Request.GET, 'currency-detail', data)
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

// c2 添加币种
export function currencyExecAddCurrency(data, success, fail) {
    Request.requestForm(Request.POST, 'currency-execAddCurrency', data)
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

// c2 修改币种信息
export function currencyModify(data, success, fail) {
    Request.requestForm(Request.PUT, 'currency-modify', data)
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

// c2 删除币种信息
export function currencyRemove(data, success, fail) {
    Request.requestForm(Request.DELETE, 'currency-remove', data)
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
export function currencyAddCurrencys(data, success, fail) {
    Request.requestForm(Request.POST, 'currency-add-Currencys', data)
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
export function currencyExport(data, success, fail) {
    Request.requestForm(Request.GET, 'currency-export', data)
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
