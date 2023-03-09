import { remove } from '@/views/sysmanage/api/organizationmanagement.js'
import { insert } from '@/views/sysmanage/api/organizationmanagement.js'
import { modify } from '@/views/sysmanage/api/organizationmanagement.js'
import { queryAll } from '@/views/sysmanage/api/organizationmanagement.js'
import { queryTree } from '@/views/sysmanage/api/organizationmanagement.js'


export function handleRemove() {
  // 自定义请求参数
  let params = {}
  params.id = '10'

  remove(
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
  params.address = '北京'
  params.creatBy = 'admin'
  params.creatTime = '2019-02-20 17:15:34'
  params.delFlag = '0'
  params.departName = '市场部'
  params.departNameAbbr = 'scb'
  params.departNameEn = 'marketing'
  params.departOrder = 1
  params.description = '很好'
  params.id = '4f1765520d6346f9bd9c79e2479e5b12'
  params.memo = '无'
  params.mobile = '12367677878'
  params.orgCategory = '1'
  params.orgCode = 'A01A103'
  params.orgType = '2'
  params.parentId = 'c6d7cb4deeac411cb3384b1b31278596'
  params.qywxIdentifier = 'wxid_1234567'
  params.status = '1'
  params.updateBy = 'admin'
  params.updateTime = '2019-02-26 16:36:18'
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

export function handleModify() {
  // 自定义请求参数
  let params = {}
  params.address = '北京'
  params.creatBy = 'admin'
  params.creatTime = '2019-02-20 17:15:34'
  params.delFlag = '0'
  params.departName = '市场部'
  params.departNameAbbr = 'scb'
  params.departNameEn = 'marketing'
  params.departOrder = 1
  params.description = '很好'
  params.id = '4f1765520d6346f9bd9c79e2479e5b12'
  params.memo = '无'
  params.mobile = '12367677878'
  params.orgCategory = '1'
  params.orgCode = 'A01A103'
  params.orgType = '2'
  params.parentId = 'c6d7cb4deeac411cb3384b1b31278596'
  params.qywxIdentifier = 'wxid_1234567'
  params.status = '1'
  params.updateBy = 'admin'
  params.updateTime = '2019-02-26 16:36:18'

  modify(
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

export function handleAll() {
  // 自定义请求参数
  let params = {}
  params.departName = '市场部'

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

export function handleTree() {
  // 自定义请求参数
  let params = {}
  params.departName = '市场部'

  queryTree(
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
