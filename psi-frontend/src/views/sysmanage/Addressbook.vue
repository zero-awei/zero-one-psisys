<!--
 * @Author: 160405103 1348313766@qq.com
 * @Date: 2023-02-23 13:15:02
 * @LastEditors: 160405103 1348313766@qq.com
 * @LastEditTime: 2023-02-23 15:13:58
 * @FilePath: \psi-frontend\src\views\sysmanage\SysPosition.vue
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
<template>
  <div>
    <!-- 通讯录 -->
    <!-- <el-row gutter="20">
      <el-col :span="6">
        <el-card>
          <el-row>
            <el-input v-model=""></el-input>
            <el-icon>
              <Search @click="query" />
            </el-icon>

          </el-row>
        </el-card>
      </el-col>
      <el-col :span="18">
        <el-card>
          查询
        </el-card>
      </el-col>
    </el-row> -->
    <psi-form :items="items" :formData="formData" @query="doQuery" @reset="doReset">
    </psi-form>

  </div>
</template>

<script scoped>
import { ref, reactive, toRefs, } from 'vue'
// 查询
const formState = reactive({
  // 查询表单每一项的配置
  items: [
    {
      type: 'input',
      label: '姓名',
      prop: 'name'
    },
     {
      type: 'input',
      label: '工号',
      prop: 'num'
    },
  ],

  // 配置数据绑定的字段
  formData: {
    name: '',
    num:''
  }
})

const { items, formData } = toRefs(formState)

// 表格相关
const tableState = reactive({
  // 查询表单每一项的配置
  tableItems: [
    {
      type: 'text',
      label: '姓名',
      prop: 'name',
      width: '120'
    },
    {
      type: 'slot',
      label: '工号',
      prop: 'type',
      width: '120',
      slotName: 'labelText',
    },
    {
      type: 'daterange',
      label: '部门',
      prop: 'path',
      width: '120'
    },
    // TODO 权限码感觉有问题
    {
      type: 'text',
      label: '职务',
      prop: 'permissionId',
      width: '300'
    },
    {
      type: 'slot',
      label: '',
      width: '400',
      slotName: 'basicOperation',
      fixed: 'right'
    }
  ],

  // 配置数据绑定的字段
  tableData: [],
  attributes: {
    selection: true, //是否多选框
    index: true, // 索引
    border: true,
    maxHeight: '400',
    height: '400',
    headOperation: ['add', 'select']
  }
})
const { tableItems, tableData, attributes } = toRefs(tableState)


function query() {

}
</script>

<style></style>