<template>
  <!-- 银行账户 -->
  <div>
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
import { reactive, toRefs, ref } from 'vue'
import { } from './api/accountcheck.js'
// 抽屉
const drawerStatus = reactive({
  title: '抽屉标题',
  basicItems: [
    {
      type: 'input',
      prop: 'name1',
      label: '编码'
    },
    {
      type: 'input',
      prop: 'name2',
      label: '名称'
    },
    {
      type: 'input',
      prop: 'name3',
      label: '客户分类'
    },
    {
      type: 'input',
      prop: 'name4',
      label: '客户等级'
    },
    {
      type: 'input',
      prop: 'name5',
      label: '纳税规模'
    },
    {
      type: 'input',
      prop: 'name6',
      label: '欠款额度'
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

// 抽屉自定义事件
function confirm(data) {
  emit('confirm', props.formData)
}

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
      label: '账号',
      prop: 'date',
      width: '120',
      fixed: 'left'
    },
    {
      type: 'text',
      label: '账户名',
      prop: 'city',
      width: '120',
      fixed: 'left'
    },
    {
      type: 'text',
      label: '币种',
      prop: 'address',
      width: '600'
    },
    {
      type: 'text',
      label: '行号',
      prop: 'zip',
      width: '120'
    },
    {
      type: 'text',
      label: '账户管理员',
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
      type: 'slot',
      label: '创建时间',
      width: '120',
      prop: 'tag'
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
    // 表格右侧固定的编辑和删除
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
    {
      date: '2016-05-03',
      name: 'Tom1',
      state: 'California',
      city: 'Los Angeles',
      address: 'No. 189, Grove St, Los Angeles',
      zip: 'CA 90036',
      tag: 'Home'
    },
    {
      date: '2016-05-03',
      name: 'Tom1',
      state: 'California',
      city: 'Los Angeles',
      address: 'No. 189, Grove St, Los Angeles',
      zip: 'CA 90036',
      tag: 'Home'
    },
    {
      date: '2016-05-03',
      name: 'Tom1',
      state: 'California',
      city: 'Los Angeles',
      address: 'No. 189, Grove St, Los Angeles',
      zip: 'CA 90036',
      tag: 'Home'
    },
    {
      date: '2016-05-03',
      name: 'Tom1',
      state: 'California',
      city: 'Los Angeles',
      address: 'No. 189, Grove St, Los Angeles',
      zip: 'CA 90036',
      tag: 'Home'
    }
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
</script>
    
<style lang='stylus' scoped></style>
    