<template>
  <div>
    <!-- 采购申请 -->
    <psi-form :items="items" :formData="formData" :toggleItems="toggleItems" @query="doQuery" @reset="doReset"></psi-form>

    <!-- 表格数据 -->
    <!-- 修改点1 -->
    <div style="margin-top:10px">
      <psi-table :items="tableItems" :tableData="tableData" :attributes="attributes" :pagination="pagination"
        @add="addClient">
        <template v-slot:basicOperation="slot">
          <!-- 修改点2 -->
          <el-button link type="primary" @click="dialogVisible = true">编辑</el-button>

          <el-button link type="primary" @click="deleteRole(slot.data)">删除</el-button>
        </template>

      </psi-table>
    </div>

    <psi-dialog v-model="dialogVisible" :attrs="attrs">
      <!-- <template #default> -->
      <div class="search">
        <psi-form :items="items" :toggle-items="toggleItems" :formData="formData"></psi-form>
      </div>

      <div class="tabs">
        <el-tabs v-model="activeName" class="demo-tabs" style="height:400px">
          <el-tab-pane label="明细" name="first"> 明细表格</el-tab-pane>
        </el-tabs>
      </div>

      <div class="footer">
        <psi-form :buttonShow="false" :items="footItems" :formData="footFormData"></psi-form>
      </div>
      <!-- </template> -->
    </psi-dialog>

    <psi-dialog v-model="dialogVisible" :attrs="attrs">
      <template #default>
        <div class="search">
          <psi-form :items="items" :toggle-items="toggleItems" :formData="formData"></psi-form>
        </div>

        <div class="tabs">
          <el-tabs v-model="activeName" class="demo-tabs" style="height:300px">
              <el-tab-pane label="明细" name="two">
              <!-- psi-table方式 -->
              <psi-table 
              :items="dialogTableItems" 
              :tableData="dialogTableData" 
              :attributes="dialogattributes" 
              @add="add">
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
import { reactive, toRefs, ref } from 'vue'

//弹出下
const tableState = reactive({
  // 查询表单每一项的配置
  dialogTableItems: [
    {
      type: 'slot',
      label: '源单分录号',
      width: '200',
      slotName: 'inputName',
      prop: 'name'
    },
    {
      type: 'slot',
      label: '物料',
      width: '200',
      slotName: 'inputAge',
      prop: 'age'
    },
    {
      type: 'slot',
      label: '规格型号',
      width: '200',
      slotName: 'inputName',
      prop: 'option'
    },
    {
      type: 'slot',
      label: '单位',
      width: '200',
      slotName: 'selectOption',
      prop: 'option'
    },
    {
      type: 'slot',
      label: '数量',
      width: '200',
      slotName: 'selectOption',
      prop: 'option'
    },
    {
      type: 'slot',
      label: '税率%',
      width: '200',
      slotName: 'selectOption',
      prop: 'option'
    },
    {
      type: 'slot',
      label: '参考含税单价',
      width: '200',
      slotName: 'selectOption',
      prop: 'option'
    },
    {
      type: 'slot',
      label: '参考含税金额',
      width: '200',
      slotName: 'selectOption',
      prop: 'option'
    },
    {
      type: 'slot',
      label: '建议供应商',
      width: '200',
      slotName: 'selectOption',
      prop: 'option'
    },
    {
      type: 'slot',
      label: '备注',
      width: '200',
      slotName: 'selectOption',
      prop: 'option'
    },
  ],

  // 配置数据绑定的字段
  dialogTableData: [
    {
      name: 'name1',
      age: 12,
      option: "Option1"
    }
  ],
  dialogattributes: {
    selection: true, //是否多选框
    index: true, // 索引
    border: true,
    maxHeight: '500px',
    height: '500px',
    headOperation: ['add']
  }
})

const { dialogTableItems, dialogTableData, dialogattributes } = toRefs(tableState)

// 弹出框
//弹出上
let dialogVisible = ref(false)
const state = reactive({
  attrs: {
    title: '单据',
    width: '80%',
    determine: true  //对话框的确定按钮生效
  }
})

const { attrs } = toRefs(state)

const searchState = reactive({
  dialogItems: [
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
  dialogToggleItems: [
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
  dialogFormData: {
    id: 'QTFY-2022',
    date: '2023-02-02',
    do: 0,
    vaildate: 0,
    subject: '石化结款',
    supplier: 0,
    num: 200,
  }
})
// const dialogref = ref()
// // // console.log('----', dialogref)

let activeName = ref('first')

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
    outcome: '',
  }
})
const { dialogItems, dialogToggleItems, dialogFormData } = toRefs(searchState)
const { footItems, footFormData } = toRefs(footState)



// 编辑删除
// 修改点3~5
function addClient() {
  dialogVisible.value = true
}
let clientEditDialogVisible = ref(false)

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
      type: 'daterange',
      label: '日期',
      prop: 'daterange',
      startPlaceholder: '开始日期',
      endPlaceholder: '结束日期'
    }
  ],
  // 传给后台的查询数据，由输入框传来
  // 修改点7
  formData: {
    code: '',
    daterange: [],
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
      label: '单据编号',
      prop: 'date',
      width: '120'
    },
    {
      type: 'text',
      label: '单据日期',
      prop: 'city',
      width: '120'
    },
    {
      type: 'text',
      label: '单据主题',
      prop: 'address',
      width: '600'
    },
    {
      type: 'text',
      label: '源单号',
      prop: 'zip',
      width: '120'
    },
    {
      type: 'text',
      label: '采购类型',
      prop: 'tag',
      width: '120'
    },
    {
      type: 'text',
      label: '需求部门',
      prop: 'tag',
      width: '120'
    },
    {
      type: 'text',
      label: '需求人',
      prop: 'tag',
      width: '120'
    },
    {
      type: 'text',
      label: '需求日期',
      prop: 'tag',
      width: '120'
    },
    {
      type: 'text',
      label: '数量',
      prop: 'tag',
      width: '120'
    },
    {
      type: 'text',
      label: '已订数量',
      prop: 'tag',
      width: '120'
    },
    {
      type: 'text',
      label: '参考金额',
      prop: 'tag',
      width: '120'
    },
    {
      type: 'text',
      label: '单据阶段',
      prop: 'tag',
      width: '120'
    },
    {
      type: 'text',
      label: '已生效',
      prop: 'tag',
      width: '120'
    },
    {
      type: 'text',
      label: '已关闭',
      prop: 'tag',
      width: '120'
    },
    {
      type: 'text',
      label: '已作废',
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
      label: '自动单据',
      prop: 'tag',
      width: '120'
    },
    {
      type: 'text',
      label: '红字单据',
      prop: 'tag',
      width: '120'
    },
    {
      type: 'text',
      label: '生效时间',
      prop: 'tag',
      width: '120'
    },
    {
      type: 'text',
      label: '核批人',
      prop: 'tag',
      width: '120'
    },
    {
      type: 'text',
      label: '制单时间',
      prop: 'tag',
      width: '120'
    },
    {
      type: 'text',
      label: '制单人',
      prop: 'tag',
      width: '120'
    },
    {
      type: 'text',
      label: '制单部门',
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
    