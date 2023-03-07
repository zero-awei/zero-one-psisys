<template>
  <!-- 采购入库 -->
  <div>
    <!-- 查询 （高级查询？？？？）-->
    <psi-form
      label="from1"
      :items="items"
      :formData="formData"
      :toggleItems="toggleItems"
      @query="handleQuery"
      @reset="handleReset"
    ></psi-form>
  </div>
  <div style="margin-top: 10px">
    <!-- 表格数据 -->
    <!-- 导入导出 采购入库详情？？？？？？ -->
    <psi-table
       label="tab1"
      :items="tableItems"
      :tableData="tableData"
      :attributes="attributes"
      :pagination="pagination"
      @add="handleAdd"
    >
    <template v-slot:basicOperation="slot">
          <el-button link type="primary" @click="drawerVisible = true">编辑</el-button>

          <el-button link type="primary" @click="deleteRole(slot.data)">删除</el-button>
      </template>
    </psi-table>




<!-- 弹出框 -->
<psi-dialog v-model="dialogVisible" :attrs="attrs">
      <template #default>

        <el-switch v-model="switchMode" class="mt-2" inline-prompt :active-icon="Sunny" :inactive-icon="MoonNight"
      style="--el-switch-on-color: #dcdfe6; --el-switch-off-color: #2c2c2c" />

        <div class="search">
          <!-- 弹出框上面的表单 -->
          <psi-form :items="itemsDia" :toggle-items="toggleItemsDia" :formData="formDataDia"></psi-form>
        </div>

        <div class="tabs">
          <!-- 明细 -->
          <el-tabs v-model="activeName" class="demo-tabs" style="height:300px">

            <!-- 采购明细 -->
          <el-tab-pane label="采购明细" name="first">
          <!-- el-table方式 -->
          <el-button @click="addEl">新增</el-button>
          <el-table :data="elTableData" height="300px" max-height="300px" border>
            <el-table-column prop="name" label="el姓名" width="180">
              <el-input v-model="elTableData.name"></el-input>
            </el-table-column>
            <el-table-column prop="age" label="el年龄" width="180">
              <el-input v-model="elTableData.age"></el-input>
            </el-table-column>
            <el-table-column prop="option" label="选项" width="180">
              <el-select v-model="elTableData.option" class="m-2" placeholder="Select" size="large">
                <el-option v-for="item in options" :key="item.value" :label="item.label" :value="item.value" />
              </el-select>
            </el-table-column>
          </el-table>
        </el-tab-pane>

        <!-- 明细 -->
        <el-tab-pane label="明细" name="two">
          <!-- psi-table方式 -->
          <psi-table :items="tableItemsP" :tableData="tableDataP" :attributes="attributesP" @add="add">
            <template v-slot:inputName="slot">
              <el-input v-model="slot.data.name"></el-input>
            </template>
            <template v-slot:inputAge="slot">
              <el-input v-model="slot.data.age"></el-input>
            </template>
            <template v-slot:selectOption="slot">
              <el-select v-model="slot.data.option" class="m-2" placeholder="Select" size="large">
                <el-option v-for="item in options" :key="item.value" :label="item.label" :value="item.value" />
              </el-select>
            </template>
          </psi-table>
        </el-tab-pane>
          </el-tabs>
        </div>

        <div class="footer">
          <psi-form :buttonShow="false" :items="footItems" :formData="footFormData"></psi-form>
        </div>
      </template>
    </psi-dialog>

  </div>
</template>

<script setup>
import { ref, reactive, toRefs, onMounted ,isRef} from 'vue'
// 引入方法
import {} from './api/caigouruku.js'
// 引入日期格式化方法
import { format } from '@/apis/date/index.js'
import { Sunny, MoonNight } from '@element-plus/icons-vue'
const switchMode = ref(true)
const value = ref('')
let dialogVisible = ref(false)


const state = reactive({
  attrs: {
    title: '采购入库-新增',
    width: '80%',
    determine: true
  },
})
const { attrs, tabs, tabAttrs } = toRefs(state)



// 采购明细下面表格
// EL表格相关
const elTableData = reactive([
  {
    name: 'elname1',
    age: 12,
    option: "Option1"
  }
])
//明细中的option
const options = [
  {
    value: 'Option1',
    label: 'Option1',
  },
  {
    value: 'Option2',
    label: 'Option2',
  },
  {
    value: 'Option3',
    label: 'Option3',
  },
  {
    value: 'Option4',
    label: 'Option4',
  },
  {
    value: 'Option5',
    label: 'Option5',
  },
]

// 明细的表格
// 表格相关
const tableStateP = reactive({
  // 查询表单每一项的配置
  tableItemsP: [
    {
      type: 'slot',
      label: '姓名',
      width: '200',
      slotName: 'inputName',
      prop: 'name'
    },
    {
      type: 'slot',
      label: '年龄',
      width: '200',
      slotName: 'inputAge',
      prop: 'age'
    },
    {
      type: 'slot',
      label: '选项',
      width: '200',
      slotName: 'selectOption',
      prop: 'option'
    },
  ],

  // 配置数据绑定的字段
  tableDataP: [
    {
      name: 'name1',
      age: 12,
      option: "Option1"
    }
  ],
  attributesP: {
    selection: true, //是否多选框
    index: true, // 索引
    border: true,
    maxHeight: '300px',
    height: '300px',
    headOperation: ['add']
  }
})
const { tableItemsP, tableDataP, attributesP } = toRefs(tableStateP)

// 弹出框最下面表单
const footState = reactive({
  footItems: [
    {
      type: 'input',
      label: '备注',
      prop: 'note',
      placeholder: '请输入备注'
    },
    {
      type: 'input',
      label: '核批意见',
      prop: 'advice',
      placeholder: '请输入核批意见'
    },
    {
      type: 'input',
      label: '核批结果',
      prop: 'outcome',
      placeholder: '请输入核批结果'
    }
  ],
  footFormData: {
    note: '',
    advice: '',
    outcome: ''
  }
})
const { footItems, footFormData } = toRefs(footState)


//弹出框上面 表单
const formStateDia = reactive({
  // 查询表单每一项的配置
  // 修改点6
  itemsDia: [
    {
      type: 'input',
      label: '单据编号',
      prop: 'id',
      placeholder: '请输入单据编号'
    },
    {
      type: 'datePicker',
      label: '单据日期',
      prop: 'date',
      placeholder: ''
    },
    {
      type: 'select',
      prop: 'do',
      options: [
        {
          label: '执行完',
          value: 0
        },
        {
          label: '执行中',
          value: 1
        }
      ]
    },
    {
      type: 'select',
      prop: 'vaildate',
      label: '已生效',
      options: [
        {
          label: '是',
          value: 0
        },
        {
          label: '否',
          value: 1
        }
      ]
    }
  ],
  toggleItemsDia: [
    {
      type: 'input',
      label: '单据主题',
      prop: 'subject',
      placeholder: '请输入单据主题'
    },
    {
      type: 'select',
      label: '供应商',
      prop: 'supplier',
      placeholder: '请选择',
      options: [
        {
          label: '供应商1',
          value: 0
        },
        {
          label: '供应商2',
          value: 1
        },
        {
          label: '供应商3',
          value: 2
        }
      ]
    },
    {
      type: 'input',
      label: '已核销金额',
      prop: 'num',
      placeholder: '已核销金额'
    }
  ],
  formDataDia: {
    id: '',
    date: '2023-02-02',
    do: 0,
    vaildate: 0,
    subject: '石化结款',
    supplier: 0,
    num: 200
  }
})

const { itemsDia, toggleItemsDia, formDataDia } = toRefs(formStateDia)












// 查询表单相关数据及方法
const formState = reactive({
  // 查询表单每一项的配置
  items: [
    {
      type: 'input',
      label: '单据编号',
      prop: 'billNo'
    },
    {
      type: 'daterange',
      label: '单据日期',
      prop: 'daterange',
      startPlaceholder: '开始日期',
      endPlaceholder: '结束日期'
    }
  ],
  // 查询表单折叠项的配置
  toggleItems: [
    {
      type: 'input',
      label: '单据主题',
      prop: 'subject'
    },
    {
      type: 'select',
      label: '供应商',
      prop: 'supplierId',
      placeholder: '请选择',
      options: [
        {
          label: '供应商1',
          value: 0
        },
        {
          label: '供应商2',
          value: 1
        }
      ]
    },
    {
      type: 'select',
      label: '单据阶段',
      prop: 'billStage',
      placeholder: '请选择',
      options: [
        {
          label: '阶段1',
          value: 0
        },
        {
          label: '阶段2',
          value: 1
        }
      ]
    },
    {
      type: 'select',
      label: '已生效',
      prop: 'isEffective',
      options: [
        {
          label: '是',
          value: 0
        },
        {
          label: '否',
          value: 1
        }
      ]
    },
    {
      type: 'select',
      label: '已关闭',
      prop: 'isClosed',
      options: [
        {
          label: '是',
          value: 0
        },
        {
          label: '否',
          value: 1
        }
      ]
    },
    {
      type: 'select',
      label: '已作废',
      prop: 'isVoided',
      options: [
        {
          label: '否',
          value: 1
        },
        {
          label: '是',
          value: 0
        }
      ]
    }
  ],
  // 配置数据绑定的字段
  formData: {
    billNo: '',
    billStage: '',
    daterange: [],
    isClosed: 0,
    isEffective: 0,
    isVoided: 1,
    subject: '',
    supplierId: ''
  }
})

const { items, toggleItems, formData } = toRefs(formState)
const tableStatus = reactive({
  // table列配置
  tableItems: [
    {
      label: '单据编号',
      prop: 'name',
      width: '160',
      align: 'center',
      type: 'function',
      fixed: true,
      // ES6 的 Template Strings 模版字符串
      callback: (data) => {
        return `<span style="color:#409eff"> ${data.name}</span>`
      }
    },
    {
      type: 'text',
      label: '单据日期',
      prop: 'date',
      width: '100'
    },
    {
      type: 'text',
      label: '单据主题',
      prop: 'city',
      width: '184'
    },
    {
      type: 'text',
      label: '源单号',
      prop: 'address',
      width: '160'
    },
    {
      type: 'text',
      label: '供应商',
      prop: 'zip',
      width: '184'
    },
    {
      type: 'text',
      label: '操作',
      prop: 'tag',
      width: '120'
    } ,
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
      date: '2016-05-02',
      name: 'Tom2',
      state: 'California',
      city: 'Los Angeles',
      address: 'No. 189, Grove St, Los Angeles',
      zip: 'CA 90036',
      tag: 'Office'
    },
    {
      date: '2016-05-04',
      name: 'Tom3',
      state: 'California',
      city: 'Los Angeles',
      address: 'No. 189, Grove St, Los Angeles',
      zip: 'CA 90036',
      tag: 'Home'
    },
    {
      date: '2016-05-01',
      name: 'Tom4',
      state: 'California',
      city: 'Los Angeles',
      address: 'No. 189, Grove St, Los Angeles',
      zip: 'CA 90036',
      tag: 'Office'
    }
  ],
  // table 总体配置
  attributes: {
    selection: true, //是否多选框
    index: true, // 索引
    border: true, //表格边框
    maxHeight: '400', // 表格最大高度
    height: '400', //表格高度
    headOperation: ['add', 'importData', 'exportData', 'select']
  }
})
const { tableItems, tableData, attributes } = toRefs(tableStatus)
// 分页相关配置
const pagination = reactive({
  currentPage: 2, // 当前页
  pageSize: 100, // 每页数据量
  pageSizes: [100, 200, 300, 400], // 可选择的每页展示量
  total: 400, //数据总量
  layout: 'total, sizes, prev, pager, next, jumper'
})



// ------------ 方法 ------------
// 7.5 普通查询
function handleQuery(data) {
  // // // console.log('父组件接收')
  // // // console.log('params--', params.daterange)
  // // console.log('data.daterange[0]', data.daterange[0])
  // // console.log('data.daterange[1]', data.daterange[1])
  // // console.log('typeof', typeof data.daterange[1])
  // 处理表单数据 主要是开始日期和结束日期
  let params = {}
  params.billNo = data.billNo
  params.billStage = data.billStage
  params.billStage = data.billStage
  params.isClosed = data.isClosed
  params.isEffective = data.isEffective
  params.isVoided = data.isVoided
  params.subject = data.subject
  params.supplierId = data.supplierId
  params.billDateBegin = format(data.daterange[0], 'yyyy-MM-dd hh:mm:ss')
  params.billDateEnd = format(data.daterange[1], 'yyyy-MM-dd hh:mm:ss')
  // // console.log('params', params)
  // 后端调用接口
  // query(
  //   {
  //     params
  //   },
  //   (data) => {
  //     tableData = data.rows
  //     pagination.currentPage = data.pageIndex
  //     pagination.pageSize = data.pageSize
  //     pagination.pages = data.pages
  //   }
  // )
}
// 表单重置
function handleReset(){
  //查询表单重置，表格也要刷新
  // doGetTableList()
}
//新增
function handleAdd() {
  //弹出采购入库新增组件
  // dialogVisible = true
  dialogVisible.value = true
}
//点击页面初始化数据
onMounted(() => {
  // handleQueryAll()
})

</script>


<style scoped>
/* .psi-table {
  padding: 0 15px;
  margin-top: 24px;
} */

</style>