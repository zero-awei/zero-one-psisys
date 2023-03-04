<template>
  <div>
    <el-switch v-model="switchMode" class="mt-2" inline-prompt :active-icon="Sunny" :inactive-icon="MoonNight"
      style="--el-switch-on-color: #dcdfe6; --el-switch-off-color: #2c2c2c" />
    <el-button @click="dialogVisible = true">弹出对话框</el-button>

    <psi-dialog v-model="dialogVisible" :attrs="attrs" @determine="handleConfirm">

      <psi-form :items="items" :toggle-items="toggleItems" :formData="formData"></psi-form>

      <el-tabs v-model="activeName" class="demo-tabs" style="height:400px">

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
        <el-tab-pane label="明细" name="two">
          <!-- psi-table方式 -->
          <psi-table :items="tableItems" :tableData="tableData" :attributes="attributes" @add="add">
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


      <psi-form :buttonShow="false" :items="footItems" :formData="footFormData"></psi-form>

    </psi-dialog>
  </div>
</template>

<script setup>
import { ref, reactive, toRefs } from 'vue'
import { Sunny, MoonNight } from '@element-plus/icons-vue'

const switchMode = ref(true)
let dialogVisible = ref(false)
const state = reactive({
  attrs: {
    title: '单据',
    width: '80%',
    determine: true
  },
})
const { attrs, tabs, tabAttrs } = toRefs(state)

const searchState = reactive({
  items: [
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
  toggleItems: [
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
  formData: {
    id: '',
    date: '2023-02-02',
    do: 0,
    vaildate: 0,
    subject: '石化结款',
    supplier: 0,
    num: 200
  }
})
const { items, toggleItems, formData } = toRefs(searchState)
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
    outcome: ''
  }
})
const { footItems, footFormData } = toRefs(footState)


const value = ref('')

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

// 表格相关
const tableState = reactive({
  // 查询表单每一项的配置
  tableItems: [
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
  tableData: [
    {
      name: 'name1',
      age: 12,
      option: "Option1"
    }
  ],
  attributes: {
    selection: true, //是否多选框
    index: true, // 索引
    border: true,
    maxHeight: '300px',
    height: '300px',
    headOperation: ['add']
  }
})
const { tableItems, tableData, attributes } = toRefs(tableState)

// EL表格相关
const elTableData = reactive([
  {
    name: 'elname1',
    age: 12,
    option: "Option1"
  }
])

function add() {
  let param = {}
  param.name = ''
  param.age = ''
  param.option = ''
  // console.log(tableData)
  // console.log(tableData.value)
  tableData.value.push(param)

}
function addEl() {
  let param = {}
  param.name = ''
  param.age = ''
  param.option = ''
  // console.log(tableData)
  // console.log(tableData.value)
  elTableData.push(param)
}

function handleConfirm() {
  console.log('formData', formData.value)
  console.log('tableData', tableData.value)
  console.log('footFormData', footFormData.value)
  console.log('elTableData', elTableData)

}
</script>

<style lang="scss" scope>
// .demo-tabs>.el-tabs__content {
//   padding: 32px;
//   color: #6b778c;
//   font-size: 32px;
//   font-weight: 600;
// }


.footer {
  margin-top: 20px;
}
</style>
