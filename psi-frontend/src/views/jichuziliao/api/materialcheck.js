import Request from '@/apis/request.js'

// 物料
// c2 普通查询
export function getBasmaterial(data, success, fail) {
    Request.requestForm(Request.GET, 'get-basmaterial', data)
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

// c2 查询指定物料详细信息
export function getBasmaterialDetail(data, success, fail) {
    Request.requestForm(Request.GET, 'get-basmaterial-detail', data)
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

// c2 添加物料
export function postAddBasmaterial(data, success, fail) {
    Request.requestForm(Request.POST, 'post-add-basmaterial', data)
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

// c2 修改物料
export function putModifyBasmaterial(data, success, fail) {
    Request.requestForm(Request.PUT, 'put-modify-basmaterial', data)
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

// c2 删除物料
export function deleteBasmaterial(data, success, fail) {
    Request.requestForm(Request.DELETE, 'delete-basmaterial', data)
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
export function postImportBasmaterial(data, success, fail) {
    Request.requestForm(Request.POST, 'post-import-basmaterial', data)
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
export function getExportBasmaterial(data, success, fail) {
    Request.requestForm(Request.GET, 'get-export-basmaterial', data)
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
