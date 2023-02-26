import { query } from '@/views/sysmanage/api/addressbook.js'

export function handleQuery() {
  // 自定义请求参数
  let params = {}
  params.realname = 'name1'
  params.workNo = '1'
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
