<!--
 * @Author: 160405103 1348313766@qq.com
 * @Date: 2023-03-04 19:07:02
 * @LastEditors: 160405103 1348313766@qq.com
 * @LastEditTime: 2023-03-05 16:17:11
 * @FilePath: \psi-frontend\src\views\jichuziliao\ClientCheck.vue
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
<template>
  <div>
    <!-- 客户 -->
    <psi-form :items="items" :formData="formData" :toggleItems="toggleItems" @query="doQuery" @reset="doReset"></psi-form>





    <!-- 表格数据 -->
    <!-- 修改点1 -->
    <div style="margin-top:10px">
      <psi-table :items="tableItems" :tableData="tableData" :attributes="attributes" :pagination="pagination"
        @add="addClient">


        <template v-slot:basicOperation="slot">
          <!-- 修改点2 -->
          <el-button link type="primary" @click="drawerVisible = true">编辑</el-button>

          <el-button link type="primary" @click="deleteRole(slot.data)">删除</el-button>
        </template>

      </psi-table>
    </div>

    <!-- 新增-抽屉 -->
    <psi-drawer v-model="drawerVisible" :title="drawerStatus.title" :basicItems="drawerStatus.basicItems"
      :toggleItems="drawerStatus.toggleItems" :formData="drawerStatus.formData" @confirm="confirm" />
  </div>
</template>
    
<script setup>
import { reactive, toRefs, ref, onMounted } from 'vue'
import { addCustomer, queryCondition } from './api/clientcheck.js'
// 抽屉
const drawerStatus = reactive({
  title: '抽屉标题',
  basicItems: [
    {
      type: 'input',
      prop: 'address',
      label: '客户地址'
    },
    {
      type: 'input',
      prop: 'area',
      label: '所属地区'
    },
    {
      type: 'input',
      prop: 'auxName',
      label: '助记名'
    },
    {
      type: 'input',
      prop: 'auxiliaryName',
      label: '辅助名称'
    },
    {
      type: 'input',
      prop: 'bizArea',
      label: '业务区域'
    },
    {
      type: 'input',
      prop: 'code',
      label: '客户编码'
    },
    {
      type: 'input',
      prop: 'name7',
      label: '启用'
    },
    {
      type: 'input',
      prop: 'name8',
      label: '备注'
    }
  ],
  toggleItems: [
    {
      title: '开票信息',
      name: '折叠唯一标识符号',
      items: [
        {
          type: 'input',
          prop: 'toggleName',
          label: '单位名称'
        },
        {
          type: 'input',
          prop: 'toggleGender',
          label: '税号'
        },
        {
          type: 'input',
          prop: 'toggleGender',
          label: '开户行'
        },
        {
          type: 'input',
          prop: 'toggleGender',
          label: '行号'
        },
        {
          type: 'input',
          prop: 'toggleGender',
          label: '账号'
        },
        {
          type: 'input',
          prop: 'toggleGender',
          label: '联系电话'
        },
        {
          type: 'input',
          prop: 'toggleGender',
          label: '开票地址'
        }
      ]
    },
    {
      title: '办款资料',
      name: '折叠2唯一标识符号',
      items: [
        {
          type: 'input',
          prop: 'toggle21',
          label: '单位名称'
        },
        {
          type: 'input',
          prop: 'toggle22',
          label: '开户行'
        },
        {
          type: 'input',
          prop: 'toggle23',
          label: '行号'
        },
        {
          type: 'input',
          prop: 'toggle24',
          label: '账号'
        }
      ]
    },
    {
      title: '收件信息',
      name: '折叠3唯一标识符号',
      items: [
        {
          type: 'input',
          prop: 'toggleName3',
          label: '收件人'
        },
        {
          type: 'input',
          prop: 'toggleGender3',
          label: '联系电话'
        },
        {
          type: 'input',
          prop: 'toggleGender3',
          label: '传真'
        },
        {
          type: 'input',
          prop: 'toggleGender3',
          label: 'Email'
        },
        {
          type: 'input',
          prop: 'toggleGender3',
          label: '地址'
        },
        {
          type: 'input',
          prop: 'toggleGender3',
          label: '邮编'
        }
      ]
    },
    {
      title: '财务信息',
      name: '折叠4唯一标识符号',
      items: [
        {
          type: 'input',
          prop: 'toggleName4',
          label: '财务信息联系人'
        },
        {
          type: 'input',
          prop: 'toggleGender4',
          label: '财务信息联系电话'
        }
      ]
    },
    {
      title: '其他信息',
      name: '折叠4唯一标识符号',
      items: [
        {
          type: 'input',
          prop: 'toggleName5',
          label: '财务信息联系人'
        },
        {
          type: 'input',
          prop: 'toggleGender5',
          label: '财务信息联系电话'
        }
      ]
    }
  ],
  formData: {
    address: '',
    area: '',
    auxName: '',
    auxiliaryName: '',
    bizArea: '',
    code: '',
    name1: '',
    name2: '',
    name3: '',
    toggleName: '',
    toggleGender: '',
    toggleName2: '',
    toggleGender2: '',
    toggleName3: '',
    toggleGender3: '',
    toggleName4: '',
    toggleGender4: '',
  }
})


let drawerVisible = ref(false)

// 编辑删除
// 修改点3~5
function addClient() {
  drawerVisible.value = true
}
// 修改
function reviseClient() {
  drawerVisible.value = true
}

let clientEditDialogVisible = ref(false)

// const { clientEditDialogAttrs } = toRefs(clientEditDialogState)


const formState = reactive({
  // 查询表单每一项的配置
  // 修改点6
  items: [
    {
      type: 'input',
      label: '编码',
      prop: 'code',
      placeholder: '请输入编码'
    },
    {
      type: 'input',
      label: '名称',
      prop: 'name',
      placeholder: '请输入名称'
    }
  ],
  // 传给后台的查询数据，由输入框传来
  // 修改点7
  formData: {
    code: '',
    name: '',
  }
})

const { items, toggleItems, formData } = toRefs(formState)
const status = reactive({
  // table列配置
  tableItems: [
    {
      label: '#',
      prop: 'name',
      width: '120',
      align: 'center',
      type: 'function',
      // ES6 的 Template Strings 模版字符串
      callback: (data) => {
        return `<span style="color:#409eff"> ${data.name}</span>`
      }
    },
    {
      type: 'text',
      prop: 'address',
      label: '客户地址',
      width: '120'
    },
    {
      type: 'text',
      prop: 'area',
      label: '所属地区',
      width: '120'
    },
    {
      type: 'text',
      prop: 'auxName',
      label: '助记名',
      width: '120'
    },
    {
      type: 'text',
      prop: 'auxiliaryName',
      label: '辅助名称',
      width: '120'
    },
    {
      type: 'text',
      prop: 'bizArea',
      label: '业务区域',
      width: '120'
    },
    {
      type: 'text',
      label: '编码',
      prop: '客户编码',
      width: '120'
    },
    {
      type: 'text',
      label: '名称',
      prop: 'city',
      width: '120'
    },
    {
      type: 'text',
      label: '助记名',
      prop: 'address',
      width: '600'
    },
    {
      type: 'text',
      label: '分类',
      prop: 'zip',
      width: '120'
    },
    {
      type: 'text',
      label: '等级',
      prop: 'tag',
      width: '120'
    },
    // 表格右侧固定的编辑和删除
    {
      type: 'slot',
      label: '纳税规模',
      width: '120',
      prop: 'tag'
    },
    {
      type: 'text',
      label: '欠款额度',
      prop: 'tag',
      width: '120'
    },
    {
      type: 'text',
      label: '所属总公司',
      prop: 'tag',
      width: '120'
    },
    {
      type: 'text',
      label: '所属地区',
      prop: 'tag',
      width: '120'
    },
    {
      type: 'text',
      label: '业务区域',
      prop: 'tag',
      width: '120'
    },
    {
      type: 'text',
      label: '客户网站',
      prop: 'tag',
      width: '120'
    },
    {
      type: 'text',
      label: '启用',
      prop: 'tag',
      width: '120'
    },
    {
      type: 'text',
      label: '备注',
      prop: 'tag',
      width: '120'
    },
    {
      type: 'text',
      label: '创建人',
      prop: 'tag',
      width: '120'
    },
    {
      type: 'text',
      label: '修改时间',
      prop: 'tag',
      width: '120'
    },
    {
      type: 'text',
      label: '修改人',
      prop: 'tag',
      width: '120'
    },
    {
      type: 'slot',
      label: '操作',
      width: '120',
      slotName: 'basicOperation',
      fixed: 'right'
    }
  ],
  // table 数据
  tableData: [
  ],
  // table 总体配置
  attributes: {
    selection: true, //是否多选框
    index: true, // 索引
    border: true,
    maxHeight: '400',
    height: '400',
    // 待后续修改1
    headOperation: ['add', 'select'],
    // rightOperation: true
  },
  props: {
    address: String,
    city: String,
    date: String
  }
})

const { tableItems, tableData, attributes } = toRefs(status)

// 分页相关配置
// 待后续修改2
const pagination = reactive({
  currentPage: 2, // 当前页
  pageSize: 100, // 每页数据量
  pageSizes: [100, 200, 300, 400], // 可选择的每页展示量
  total: 400, //数据总量
  layout: 'total, sizes, prev, pager, next, jumper'
})


onMounted(() => {
  doQueryCondition()
})

// ---- 方法
// 抽屉自定义事件
function confirm(data) {
  let params = {}
  params.address = data.address
  params.area = data.area
  params.auxName = data.auxName
  params.auxiliaryName = data.auxiliaryName
  params.bizArea = data.bizArea
  params.code = data.code



  addCustomer(
    {
      ...params
    },
    (data) => {
      // 新增以后刷新用户表格
      doQueryCondition()

    },
    (msg) => {
      ElMessage.warning(msg)
    }
  )
}
//普通分页查询
function doQueryCondition() {
  queryCondition(
    {},
    (data) => {
      tableData = [...data.rows]
    },
    (msg) => {
      ElMessage.warning(msg)
    }
  )
}
</script>
    
<style lang='stylus' scoped></style>
    