<template>
  <div>
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
<!-- <template>
  <el-dialog class="uiot-dialog" width="900px" :visible.sync="isShow" :before-close="beforeClose"
    :close-on-click-modal="false" :title="$t('basicData.device.propDlg.dlgTitle')" @open="open">
    <el-table
      :data="propTableData.col.filter(data => handleAdd || data.name.toLowerCase().includes(handleAdd.toLowerCase()))"
      highlight-current-row border>
      <el-table-column label="No." type="index" align="center" width="50"></el-table-column>
      <el-table-column :label="$t('basicData.device.propDlg.code')">
        <template slot-scope="scope">
          <span v-if="scope.row.isSet">
            <el-input size="mini" v-model="scope.row.code"></el-input>
          </span>
          <span v-else>{{ scope.row.code }}</span>
        </template>
      </el-table-column>
      <el-table-column :label="$t('basicData.device.propDlg.name')">
        <template slot-scope="scope">
          <span v-if="scope.row.isSet">
            <el-input size="mini" v-model="scope.row.name"></el-input>
          </span>
          <span v-else>{{ scope.row.name }}</span>
        </template>
      </el-table-column>
      <el-table-column :label="$t('basicData.device.propDlg.minValue')">
        <template slot-scope="scope">
          <span v-if="scope.row.isSet">
            <el-input size="mini" v-model="scope.row.minValue"></el-input>
          </span>
          <span v-else>{{ scope.row.minValue }}</span>
        </template>
      </el-table-column>
      <el-table-column :label="$t('basicData.device.propDlg.maxValue')">
        <template slot-scope="scope">
          <span v-if="scope.row.isSet">
            <el-input size="mini" v-model="scope.row.maxValue"></el-input>
          </span>
          <span v-else>{{ scope.row.maxValue }}</span>
        </template>
      </el-table-column>
      <el-table-column :label="$t('basicData.device.propDlg.valueType')">
        <template slot-scope="scope">
          <span v-if="scope.row.isSet">
            <el-select size="mini" v-model="scope.row.valueType" :placeholder="$t('common.pleSelect')">
              <el-option v-for="item in valTypeOptions" :key="item.value" :label="item.label"
                :value="item.value"></el-option>
            </el-select>
          </span>
          <span v-else>{{ scope.row.valueType }}</span>
        </template>
      </el-table-column>
      <el-table-column :label="$t('basicData.device.propDlg.warning')">
        <template slot-scope="scope">
          <span v-if="scope.row.isSet">
            <el-select v-model="scope.row.warning" size="mini">
              <el-option v-for="item in warnOptions" :key="item.value" :label="item.label"
                :value="item.value"></el-option>
            </el-select>
          </span>
          <span v-else>{{ scope.row.warning === true ? '是' : '否' }}</span>
        </template>
      </el-table-column>
      <el-table-column align="center" width="170px">
        <template slot="header" slot-scope="scope">
          <el-button v-model="handleAdd" size="mini" type="success" round plain
            @click="handleAdd(scope.$index, scope.row)">{{ $t('common.add') }}</el-button>
        </template>
        <template slot-scope="scope">
          <el-button size="mini" type="primary" round plain v-if="!scope.row.isSet"
            @click="valChange(scope.row, scope.$index, true)">{{ $t('common.edit') }}</el-button>
          <el-button size="mini" type="primary" round plain v-else @click="valChange(scope.row, scope.$index, true)">{{
            $t('common.save') }}</el-button>
          <el-button size="mini" type="danger" round plain v-if="!scope.row.isSet"
            @click="handleDelete(scope.$index, scope.row)">{{ $t('common.delete') }}</el-button>
          <el-button size="mini" type="danger" round plain v-else @click="valChange(scope.row, scope.$index, false)">{{
            $t('common.cancel') }}</el-button>
        </template>
      </el-table-column>
    </el-table>
  </el-dialog>
</template>

<script>
import { open } from 'fs'

const defaultProp = {
  code: '',
  maxValue: '',
  minValue: '',
  name: '',
  valueType: 'String',
  id: '',
  typeId: '',
  warning: false
}

export default {
  props: {
    isShow: Boolean,
    oneRow: {
      type: Array,
      default: function () {
        return defaultProp
      }
    }
  },
  data() {
    return {
      propTableData: {
        sel: null, // 选中行
        col: []
      },
      warnOptions: [
        {
          value: true,
          label: '是'
        },
        {
          value: false,
          label: '否'
        }
      ],
      valTypeOptions: [
        {
          value: 'String',
          label: 'String'
        },
        {
          value: 'Int',
          label: 'Int'
        },
        {
          value: 'Double',
          label: 'Double'
        },
        {
          value: 'Boolean',
          label: 'Boolean'
        },
        {
          value: 'Date',
          label: 'Date'
        }
      ]
    }
  },
  created() { },
  methods: {
    open() {
      this.propTableData.col = this.oneRow
      this.propTableData.col.map(i => {
        i.isSet = false
      })
      console.log('open', this.propTableData.col)
    },
    // 添加
    handleAdd() {
      for (let i of this.propTableData.col) {
        if (i.isSet) {
          return this.Message(
            this.$t('basicData.device.propDlg.pleSave'),
            'warning'
          )
        }
      }
      let row = {
        code: '',
        maxValue: '',
        minValue: '',
        name: '',
        valueType: 'String',
        id: '',
        typeId: '',
        warning: false,
        isSet: true
      }
      this.propTableData.col.push(row)
      this.propTableData.sel = row
    },
    //修改
    valChange(row, index, qx) {
      console.log('edit', this.propTableData)
      //点击修改，判断是否已经保存所有操作
      for (let i of this.propTableData.col) {
        console.log('i.isSet', i.isSet, i.id, row.id)
        if (i.isSet && i.id != row.id) {
          this.Message(this.$t('basicData.device.propDlg.pleSave'), 'warning')
          return false
        }
      }
      //是否是取消操作
      if (!qx) {
        console.log('qx', this.propTableData.sel.id)
        if (!this.propTableData.sel.id) {
          this.propTableData.col.splice(index, 1)
        }
        return (row.isSet = !row.isSet)
      }
      //提交数据
      if (row.isSet) {
        console.log('this.propTableData.sel', this.propTableData.sel)
        const v = this.propTableData.sel
        // 必填项判断
        if (v.code == '' || v.name == '') {
          this.Message(this.$t('common.pleEnter'), 'warning')
        } else {
          this.$emit('confirm', this.propTableData.sel)
          row.isSet = false
        }
      } else {
        this.propTableData.sel = row
        row.isSet = true
      }
    },
    // 删除
    handleDelete(index, row) {
      this.$emit('delete', row.id)
    },
    beforeClose() {
      this.$emit('cancel')
    },
    Message(msg, type) {
      this.$message({ type: type ? type : 'info', message: msg })
    }
  }
}
</script>

<style lang="scss"></style>
 -->
