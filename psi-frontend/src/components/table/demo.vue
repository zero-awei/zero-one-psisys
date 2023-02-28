<!-- <template>
  <div class="main">
    <psi-table :items="items" :tableData="tableData" :attributes="attributes" :pagination="pagination" />

  </div>
</template>

<script setup>
import { reactive, toRefs } from 'vue'
const status = reactive({
  // table列配置
  items: [
    {
      label: 'Name',
      prop: 'name',
      width: '120',
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
      label: 'Date',
      prop: 'date',
      width: '120'
    },
    {
      type: 'text',
      label: 'City',
      prop: 'city',
      width: '120'
    },
    {
      type: 'text',
      label: 'Address',
      prop: 'address',
      width: '600'
    },
    {
      type: 'text',
      label: 'Zip',
      prop: 'zip',
      width: '120'
    },
    {
      type: 'text',
      label: 'Tag',
      prop: 'tag',
      width: '120'
    }
    // {
    //   type: 'slot',
    //   label: '操作',
    //   prop: 'operation',
    //   slotName: 'operation'
    // }
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
    height: '400',    //表格高度
    headOperation: ['add', 'importData', 'exportData', 'select']
  }
})

const { items, tableData, attributes } = toRefs(status)

// 分页相关配置
const pagination = reactive({
  currentPage: 2, // 当前页
  pageSize: 100, // 每页数据量
  pageSizes: [100, 200, 300, 400], // 可选择的每页展示量
  total: 400, //数据总量
  layout: 'total, sizes, prev, pager, next, jumper'
})
</script>

<style></style> -->

<template>
  <div>
    <el-table :data="tableData0" style="width: 100%; margin-bottom: 20px" row-key="id" border default-expand-all>
      <el-table-column fixed type="selection" width="50" />
      <el-table-column type="index" width="50" />
      <el-table-column prop="name" label="菜单名称" sortable />
      <el-table-column prop="href" label="菜单url" sortable />
    </el-table>

    <el-table :data="tableData1" style="width: 100%" row-key="id" border lazy :load="load"
      :tree-props="{ children: 'children', hasChildren: 'hasChildren' }">
      <el-table-column fixed type="selection" width="50" />
      <el-table-column type="index" width="50" />
      <el-table-column type="index" width="50" />
      <el-table-column prop="name" label="菜单名称" sortable />
      <el-table-column prop="href" label="菜单url" sortable />

    </el-table>
    <psi-table :items="tableItems" :tableData="tableData" :attributes="attributes" :pagination="pagination"></psi-table>
  </div>
</template>
<script lang="ts" setup>
import { ref, reactive, toRefs } from 'vue'
interface Menu {
  id: number
  href: string
  name: string
  icon: string
  hasChildren?: boolean
  children?: Menu[]
}

const load = (
  row: Menu,
  treeNode: unknown,
  resolve: (date: Menu[]) => void
) => {
  setTimeout(() => {
    resolve([
      {
        id: 2,
        name: '角色管理',
        href: '/sysmanagement/rolemanagement',
        icon: 'IconSetting',
      },
      {
        id: 3,
        name: '菜单管理',
        href: '/sysmanagement/menumanagement',
        icon: 'IconSetting',
      },
      {
        id: 4,
        name: '用户管理',
        href: '/sysmanagement/usermanagement',
        icon: 'IconSetting',
      },
      {
        id: 5,
        name: '部门管理',
        href: '/sysmanagement/sysposition',
        icon: 'IconSetting',
      },
      {
        id: 6,
        name: '组织结构管理',
        href: '/sysmanagement/orimanage',
        icon: 'IconSetting',
      },
      {
        id: 7,
        name: '分类字典',
        icon: 'IconTickets',
        href: '/sysmanagement/Category',
      },
      {
        id: 8,
        name: '通讯录',
        icon: 'IconTickets',
        href: '/sysmanagement/addressbook',
      }
    ])
  }, 1000)
}

const tableData0: Menu[] = [
  {
    id: 1,
    name: '系统管理',
    icon: 'IconSetting',
    href: '/',
    children: [
      {
        id: 2,
        name: '角色管理',
        href: '/sysmanagement/rolemanagement',
        icon: 'IconSetting',
      },
      {
        id: 3,
        name: '菜单管理',
        href: '/sysmanagement/menumanagement',
        icon: 'IconSetting',
      },
      {
        id: 4,
        name: '用户管理',
        href: '/sysmanagement/usermanagement',
        icon: 'IconSetting',
      },
      {
        id: 5,
        name: '部门管理',
        href: '/sysmanagement/sysposition',
        icon: 'IconSetting',
      },
      {
        id: 6,
        name: '组织结构管理',
        href: '/sysmanagement/orimanage',
        icon: 'IconSetting',
      },
      {
        id: 7,
        name: '分类字典',
        icon: 'IconTickets',
        href: '/sysmanagement/Category',
      },
      {
        id: 8,
        name: '通讯录',
        icon: 'IconTickets',
        href: '/sysmanagement/addressbook',
      }
    ]

  },
  {

    id: 2,
    name: '库存管理',
    icon: 'IconSetting',
    href: '/',
  }
]

const tableData1: Menu[] = [
  {
    id: 1,
    name: '系统管理',
    icon: 'IconSetting',
    href: '/',
    hasChildren: true
  },
  {
    id: 2,
    name: '库存管理',
    icon: 'IconSetting',
    href: '/',
  },

]

// 表格相关
const tableState = reactive({
  // 查询表单每一项的配置
  tableItems: [
    {
      type: 'text',
      label: '菜单名称',
      prop: 'name',
      width: '120'
    },
    {
      type: 'daterange',
      label: '菜单url',
      prop: 'href',
      width: '120'
    },
  ],

  // 配置数据绑定的字段
  tableData: [
    {
      id: 1,
      name: '系统管理',
      icon: 'IconSetting',
      href: '/',
      hasChildren: true
    },
    {
      id: 2,
      name: '库存管理',
      icon: 'IconSetting',
      href: '/',
    },
  ],
  attributes: {
    selection: true, //是否多选框
    index: true, // 索引
    border: true,
    maxHeight: '400',
    height: '400',
    rowKey: 'id',//当 row 中包含 children 字段时，被视为树形数据。 渲染嵌套数据需要 prop 的 row-key(比如id)
    defaultExpandAll: false,// 是否默认展开所有行，当 Table 包含展开行存在或者为树形表格时有效
    lazy: true,
    headOperation: ['add', 'select']
  }
})
const { tableItems, tableData, attributes } = toRefs(tableState)

const pagination = reactive({
  currentPage: 2, // 当前页
  pageSize: 100, // 每页数据量
  pageSizes: [100, 200, 300, 400], // 可选择的每页展示量
  total: 400, //数据总量
  layout: 'total, sizes, prev, pager, next, jumper'
})
</script>

<style scoped></style>