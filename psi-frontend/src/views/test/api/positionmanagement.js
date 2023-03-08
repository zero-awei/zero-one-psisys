import { insert } from '@/views/sysmanage/api/positionmanagement.js'
import { delete } from '@/views/sysmanage/api/positionmanagement.js'
import { queryRank } from '@/views/sysmanage/api/positionmanagement.js'
import { queryAll } from '@/views/sysmanage/api/positionmanagement.js'
import { updatePosition } from '@/views/sysmanage/api/positionmanagement.js'
import { download} from '@/views/sysmanage/api/positionmanagement.js'
import { downloadUrl} from '@/views/sysmanage/api/positionmanagement.js'
import { upload} from '@/views/sysmanage/api/positionmanagement.js'


export function handleInsert() {
  // 自定义请求参数
  let params = {}
  params.code = 'devleader'
  params.name = '研发部经理'
  params.postRank = '2'
  params.id = '999'

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

export function handleDelete() {
  // 自定义请求参数
  let params = {}
  params.positionId = '999'

  delete(
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

export function handleRank() {
  // 自定义请求参数
  let params = {}

  queryRank(
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
  params.code = 'devleader'
  params.name = '研发部经理'
  params.postRank = '2'
  params.pageIndex = 1
  params.pageSize = 10

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


export function handleUpdatePosition() {
  // 自定义请求参数
  let params = {}
  params.code = 'devleader'
  params.name = '研发部经理'
  params.postRank = '2'
  params.id = '999'

  updatePosition(
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


export function handleDownload() {
  // 自定义请求参数
  let params = {}
  

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

export function handleDownloadUrl() {
  // 自定义请求参数
  let params = {}
  

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


export function handleUpload() {
  // 自定义请求参数
  let params = {}
  params.file = '999'
  

  upload(
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