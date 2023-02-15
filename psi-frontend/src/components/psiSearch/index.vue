<template>
  <div class="search-main">
    <el-card>
      <psi-search :items="items1" :formData="formData1" />
    </el-card>
    <br />
    <el-card>
      <psi-search
        :items="items"
        :toggle-items="toggleItems"
        :formData="formData"
      />
    </el-card>
    <br />
    <el-card>
      <psi-search
        :items="items2"
        :toggle-items="toggleItems2"
        :formData="formData2"
        @search="search"
      />
    </el-card>
  </div>
</template>

<script setup>
import { reactive, toRefs } from 'vue'

const state = reactive({
  // 查询表单每一项的配置
  items: [
    {
      type: 'input',
      label: '用户名',
      prop: 'name',
      placeholder: '请输入用户名'
    },
    {
      type: 'input',
      label: '账号',
      prop: 'account',
      placeholder: '请输入账号'
    },
    {
      type: 'select',
      label: '性别',
      prop: 'gender',
      placeholder: '请选择性别',
      options: [
        {
          label: '男',
          value: 0
        },
        {
          label: '女',
          value: 1
        }
      ]
    },
    {
      type: 'datePicker',
      label: '日期',
      prop: 'date',
      placeholder: '请选择日期'
    },
    {
      type: 'daterange',
      label: '日期',
      prop: 'daterange',
      startPlaceholder: '开始日期',
      endPlaceholder: '结束日期'
    }
  ],
  toggleItems: [
    {
      type: 'input',
      label: '折叠用户名',
      prop: 'toggleName',
      placeholder: '请输入用户名'
    },
    {
      type: 'select',
      label: '折叠性别',
      prop: 'toggleGender',
      placeholder: '请选择性别',
      options: [
        {
          label: '男',
          value: 0
        },
        {
          label: '女',
          value: 1
        }
      ]
    },
    {
      type: 'datePicker',
      label: '折叠日期',
      prop: 'toggleDate',
      placeholder: '请选择日期'
    }
  ],

  // 配置数据绑定的字段
  formData: {
    name: '',
    gender: '',
    date: '',
    daterange: '',
    account: '',
    toggleName: '',
    toggleGender: '',
    toggleDate: ''
  }
})

const { items, toggleItems, formData } = toRefs(state)
// console.log("-----",formData.name) 这句话没起作用
const state1 = reactive({
  items1: [
    {
      type: 'input',
      label: '用户名',
      prop: 'name1',
      placeholder: '请输入用户名'
    },
    {
      type: 'input',
      label: '账号',
      prop: 'account1',
      placeholder: '请输入账号'
    }
  ],
  formData1: {
    name1: '',
    account1: ''
  }
})

const { items1, formData1 } = toRefs(state1)
const state2 = reactive({
  // 查询表单每一项的配置
  items2: [
    {
      type: 'input',
      label: '单据编号',
      prop: 'billNo',
      placeholder: '请输入'
    },
    {
      type: 'daterange',
      label: '单据日期',
      prop: 'daterange',
      startPlaceholder: '开始日期',
      endPlaceholder: '结束日期'
    }
  ],
  toggleItems2: [
    {
      type: 'input',
      label: '单据主题',
      prop: 'subject',
      placeholder: '请输入'
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
        },
        {
          label: '供应商3',
          value: 2
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
        },
        {
          label: '阶段3',
          value: 2
        }
      ]
    },
    {
      type: 'select',
      label: '已生效',
      prop: 'isEffective',
      placeholder: '请选择',
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
      placeholder: '请选择',
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
      placeholder: '请选择',
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

  // 配置数据绑定的字段
  formData2: {
    billNo: '',
    daterange: [],
    subject: '',
    supplierId: '',
    billStage: '',
    isEffective: '',
    isClosed: '',
    isVoided: ''
  }
})
const { items2, toggleItems2, formData2 } = toRefs(state2)

function search(res) {
  // res 就是 formdata
  console.log('----父组件', res)
}
</script>

<style></style>
