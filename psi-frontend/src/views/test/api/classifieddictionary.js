import { deleteDict } from '@/views/sysmanage/api/classifieddictionary.js'
import { insert } from '@/views/sysmanage/api/classifieddictionary.js'
import { queryAll } from '@/views/sysmanage/api/classifieddictionary.js'
import { queryOne } from '@/views/sysmanage/api/classifieddictionary.js'
import { updateOne } from '@/views/sysmanage/api/classifieddictionary.js'

export function handleDelete() {
  // 自定义请求参数
  let params = {}
  params.id = '9999'

  deleteDict(
    params,
    (data) => {
      console.log('全部请求data----', data)
      // 查询返回的是表格数据
      // 分页
      pagination.value.currentPage = data.pageIndex
      pagination.value.pageSize = data.pageSize
      pagination.value.total = data.total

      // 表格数据
      tableData.value = data.rows
    },
    (msg) => {
      ElMessage.warning(msg)
    }
  )
}

export function handleInsert() {
  // 自定义请求参数
  let params = {}
  params.name = '张三1'
  params.pid = '9999'

  insert(
    params,
    (data) => {
      console.log('全部请求data----', data)
      // 查询返回的是表格数据
      // 分页
      pagination.value.currentPage = data.pageIndex
      pagination.value.pageSize = data.pageSize
      pagination.value.total = data.total

      // 表格数据
      tableData.value = data.rows
    },
    (msg) => {
      ElMessage.warning(msg)
    }
  )
}

export function handleQueryAll() {
  // 自定义请求参数
  let params = {}
  params.pageIndex = 1
  params.ppageSizeid = 10

  queryAll(
    params,
    (data) => {
      console.log('全部请求data----', data)
      // 查询返回的是表格数据
      // 分页
      pagination.value.currentPage = data.pageIndex
      pagination.value.pageSize = data.pageSize
      pagination.value.total = data.total

      // 表格数据
      tableData.value = data.rows
    },
    (msg) => {
      ElMessage.warning(msg)
    }
  )
}

export function handleUpdateOne() {
  // 自定义请求参数
  let params = {}
  params.id = '144'
  params.name = '嘻嘻哈哈'

  updateOne(
    params,
    (data) => {
      console.log('全部请求data----', data)
      // 查询返回的是表格数据
      // 分页
      pagination.value.currentPage = data.pageIndex
      pagination.value.pageSize = data.pageSize
      pagination.value.total = data.total

      // 表格数据
      tableData.value = data.rows
    },
    (msg) => {
      ElMessage.warning(msg)
    }
  )
}

export function handleQueryOne() {
  // 自定义请求参数
  let params = {}
  params.pid = '1'

  queryOne(
    params,
    (data) => {
      console.log('全部请求data----', data)
      // 查询返回的是表格数据
      // 分页
      pagination.value.currentPage = data.pageIndex
      pagination.value.pageSize = data.pageSize
      pagination.value.total = data.total

      // 表格数据
      tableData.value = data.rows
    },
    (msg) => {
      ElMessage.warning(msg)
    }
  )
}
