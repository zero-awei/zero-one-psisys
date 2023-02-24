<template>
  <div>
    <el-button @click="dialogVisible = true">弹出对话框</el-button>
    <psi-dialog v-model="dialogVisible" :attrs="attrs">
      <template #default>
        <div class="search">
          <psi-form
            :items="items"
            :toggle-items="toggleItems"
            :formData="formData"
          ></psi-form>
        </div>

        <div class="tabs">
          <el-tabs v-model="activeName" class="demo-tabs">
            <el-tab-pane label="明细" name="first"> 明细表格</el-tab-pane>
          </el-tabs>
        </div>

        <div class="footer">
          <psi-form
            :buttonShow="false"
            :items="footItems"
            :formData="footFormData"
          ></psi-form>
        </div>
      </template>
    </psi-dialog>
  </div>
</template>

<script setup>
import { ref, reactive, toRefs } from 'vue'

let dialogVisible = ref(false)
const state = reactive({
  attrs: {
    title: '单据',
    width: '80%'
  }
})
const { attrs } = toRefs(state)

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
    id: 'QTFY-2022',
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
</script>

<style lang="scss" scope>
.demo-tabs > .el-tabs__content {
  padding: 32px;
  color: #6b778c;
  font-size: 32px;
  font-weight: 600;
}
.footer {
  margin-top: 20px;
}
</style>
