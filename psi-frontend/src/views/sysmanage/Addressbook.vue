<!--
 * @Author: 160405103 1348313766@qq.com
 * @Date: 2023-02-23 13:15:02
 * @LastEditors: 160405103 1348313766@qq.com
 * @LastEditTime: 2023-02-27 19:59:46
 * @FilePath: \psi-frontend\src\views\sysmanage\SysPosition.vue
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
<template>
  <div>
    <!-- 通讯录 -->
    <el-row gutter="20">
      <el-col :span="6">
        <el-card style="height:100vh">
          <el-input placeholder="输入机构名称查询" v-modle="name">
            <template #append>
            <el-icon @click="handleQueryAddress">
              <Search />
              </el-icon>
          </template>
        </el-input>
        <br/>
        <el-tree :data="data" :props="defaultProps" @node-click="handleNodeClick" />
      </el-card>
     
      </el-col>
      <el-col :span="18">
        <el-card style="height:100vh">
        <!-- 查询 -->
        <psi-form :items="formItems" :formData="formData" @query="handleQuery" @reset="handleReset"></psi-form>

        <div style="margin-top:10px">
          <psi-table :items="tableItems" :tableData="tableData" :attributes="attributes" :pagination="pagination">
            <template v-slot:basicOperation="slot">
            <!-- 修改点2 -->
            <el-button link type="primary" @click="clientEditDialogVisible = true">编辑</el-button>

            <el-button link type="primary" @click="deleteRole(slot.data)">删除</el-button>
          </template>
          
          </psi-table>
        </div>
        </el-card>
      </el-col>
    </el-row>

  </div>
</template>

<script setup>
import { ref, reactive, toRefs, onMounted } from 'vue'
import { query, queryAll } from './api/addressbook.js'


const name = ref('')
// 查询表单相关数据及方法
const formState = reactive({
  // 查询表单每一项的配置
  formItems: [
    {
      type: 'input',
      label: '姓名',  // 标签名
      prop: 'realname', // 对应字段
      placeholder: '请输入'
    },
    {
      type: 'input',
      label: '工号',
      prop: 'workNo',
      placeholder: '请输入'
    },
    {
      type: 'slot',
      label: '操作',
      width: '120',
      slotName: 'basicOperation',
      fixed: 'right'
    }
  ],

  // 配置数据绑定的字段
  formData: {
    realname: '',
    workNo: '',
  }
})
const { formItems, formData } = toRefs(formState)

// 表格相关
const tableState = reactive({
  // 查询表单每一项的配置
  tableItems: [
    {
      type: 'text',
      label: '姓名',
      prop: 'nealname',
      width: '120'
    },
    {
      type: 'text',
      label: '工号',
      prop: 'workNo',
      width: '120'
    },
    {
      type: 'text',
      label: '部门',
      prop: 'departName',
      width: '120'
    },
    {
      type: 'text',
      label: '职务',
      prop: 'post',
      width: '120'
    },

    {
      type: 'text',
      label: '手机',
      prop: 'phone',
      width: '120'
    },
    {
      type: 'text',
      label: '公司邮箱',
      prop: 'email',
      width: '120'
    }
  ],

  // 配置表格数据绑定的字段
  tableData: [],
  attributes: {
    index: true, // 索引
    border: true,
    maxHeight: '400',
    height: '400',
    headOperation: []
  }
})
const { tableItems, tableData, attributes } = toRefs(tableState)

// 分页相关配置
const pagination = reactive({
  currentPage: 2, // 当前页
  pageSize: 100, // 每页数据量
  pageSizes: [100, 200, 300, 400], // 可选择的每页展示量
  total: 400, //数据总量
  layout: 'total, sizes, prev, pager, next, jumper'
})



const handleNodeClick = (data) => {
  console.log(data)
}

const data = [
  {
    label: '北京F公司',
    children: [
      {
        label: '市场部',
       
      },
       {
        label: '研发部',

      },
       {
        label: '财务部',

      },
    ],
  },
]

const defaultProps = {
  children: 'children',
  label: 'label',
}
// --------------- 方法--------------
// 点击查询按钮 
function handleQuery() {
  // 处理请求参数
  let params = {}
  params.realname = formData.value.realname
  params.workNo = formData.value.workNo
  query(
    params,
    (data) => {
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

// 点击重置按钮
function handleReset() {
  handleQueryAll()
}

function handleQueryAll() {
  queryAll(
    {

    },
    // 成功回调函数

    (data) => {
      // 查询全部返回的是表格数据
      // 分页
      pagination.value.currentPage = data.pageIndex
      pagination.value.pageSize = data.pageSize
      pagination.value.total = data.total

      // 表格数据
      tableData.value = data.rows

    },
    // 失败回调函数
    (msg) => {
      ElMessage.warning(msg)
    }
  )
}

function handleQueryAddress() {

}

onMounted(() => {
  handleQueryAll()
})
</script>

<style scoped></style>