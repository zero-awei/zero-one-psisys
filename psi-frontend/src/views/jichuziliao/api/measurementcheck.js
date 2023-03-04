import Request from '@/apis/request.js'


// 计量单位
// c2 普通查询
export function measurementGet(data, success, fail) {
    Request.requestForm(Request.GET, 'Measurement-get', data)
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

// c2 查询指定单位子集列表
export function measurementGetKid(data, success, fail) {
    Request.requestForm(Request.GET, 'Measurement-get-kid', data)
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

// c2 查询指定单位详细信息
export function measurementGetDetail(data, success, fail) {
    Request.requestForm(Request.POST, 'Measurement-get-detail', data)
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

// c2 添加计量单位
export function measurementPost(data, success, fail) {
    Request.requestForm(Request.POST, 'Measurement-post', data)
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

// c2 修改计量单位
export function measurementPut(data, success, fail) {
    Request.requestForm(Request.PUT, 'Measurement-put', data)
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

// c2 删除计量单位
export function measurementDelete(data, success, fail) {
    Request.requestForm(Request.DELETE, 'Measurement-delete', data)
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
export function measurementAddfile(data, success, fail) {
    Request.requestForm(Request.POST, 'Measurement-addfile', data)
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
export function measurementExport(data, success, fail) {
    Request.requestForm(Request.GET, 'Measurement-export', data)
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
