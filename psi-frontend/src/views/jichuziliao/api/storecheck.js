import Request from '@/apis/request.js'


// 仓库
// c2 普通查询
export function queryDepot(data, success, fail) {
    Request.requestForm(Request.GET, 'query-depot', data)
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

// c2 查询指定仓库子集列表
export function queryDepotKid(data, success, fail) {
    Request.requestForm(Request.GET, 'query-depot-kid', data)
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

// c2 查询指定仓库详细信息
export function queryDepotDetail(data, success, fail) {
    Request.requestForm(Request.GET, 'query-depot-detail', data)
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

// c2 查询指定仓库操作信息
export function queryDepotAction(data, success, fail) {
    Request.requestForm(Request.GET, 'query-depot-action', data)
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

// c2 新增仓库
export function addDepot(data, success, fail) {
    Request.requestForm(Request.POST, 'add-depot', data)
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

// c2 新增子集仓库
export function addDepotKid(data, success, fail) {
    Request.requestForm(Request.POST, 'add-depot-kid', data)
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

// c2 删除仓库
export function removeDepot(data, success, fail) {
    Request.requestForm(Request.DELETE, 'remove-depot', data)
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

// c2 修改仓库
export function modifyDepot(data, success, fail) {
    Request.requestForm(Request.PUT, 'modify-depot', data)
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

// c2 文件导出
export function exportDepots(data, success, fail) {
    Request.requestForm(Request.GET, 'export-depots', data)
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

// c2 文件导入
export function addDepots(data, success, fail) {
    Request.requestForm(Request.POST, 'add-depots', data)
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
