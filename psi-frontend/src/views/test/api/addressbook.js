import { query } from '@/views/sysmanage/api/addressbook.js'
import { queryOrganizationName } from '@/views/sysmanage/api/addressbook.js'
import { queryOrganizationTreeName } from '@/views/sysmanage/api/addressbook.js'
import { download } from '@/views/sysmanage/api/addressbook.js'
import { downloadUrl } from '@/views/sysmanage/api/addressbook.js'

export function handleQuery() {
  // 自定义请求参数
  let params = {}
  params.realname = '张三'
  params.workNo = '10'
  params.pageIndex = 1
  params.pageSize = 10

  query(
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

export function handleQueryOrganizationName() {
  // 自定义请求参数
  let params = {}
  params.departName = '市场部'
  params.pageIndex = 1
  params.pageSize = 10

  queryOrganizationName(
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

export function handleQueryOrganizationTreeName() {
  // 自定义请求参数
  let params = {}
  params.departName = '市场部'
  params.pageIndex = 1
  params.pageSize = 10

  queryOrganizationTreeName(
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

export function handleExcel() {
  // 自定义请求参数
  let params = {}
  params.realname = '张三'
  params.workNo = '10'
  params.pageIndex = 1
  params.pageSize = 10

  download(
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

export function handleExcelUrl() {
  // 自定义请求参数
  let params = {}
  params.realname = '张三'
  params.workNo = '10'
  params.pageIndex = 1
  params.pageSize = 10

  downloadUrl(
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