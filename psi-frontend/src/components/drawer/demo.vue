<!--
 * @Author: li.ziwei
 * @Date: 2023-02-11 13:36:36
 * @LastEditTime: 2023-02-23 00:17:40
 * @LastEditors: 160405103 1348313766@qq.com
 * @Description: 
 * @FilePath: \psi-frontend\src\components\drawer\index.vue
 * 可以输入预定的版权声明、个性签名、空行等
-->
<template>
  <div>
    <el-button 
    type="primary" 
    @click="drawerVisible = true">打开</el-button>
    
    <psi-drawer 
    v-model="drawerVisible" 
    :title="drawerStatus.title" 
    :basicItems="drawerStatus.basicItems"
    :toggleItems="drawerStatus.toggleItems" 
    :formData="drawerStatus.formData" 
    @confirm="confirm" />
  </div>
</template>

<!-- 这里我使用组合式api进行编写 -->
<script setup>
import { ref, reactive, toRefs } from '@vue/reactivity'
const drawerStatus = reactive({
  title: '抽屉标题',
  basicItems: [
    {
      type: 'input',
      prop: 'name1',
      label: '姓名1'
    },
    {
      type: 'input',
      prop: 'name2',
      label: '姓名2'
    },
    {
      type: 'input',
      prop: 'name3',
      label: '姓名3'
    }
  ],
  toggleItems: [
    {
      title: '折叠标题1',
      name: '折叠唯一标识符号',
      items: [
        {
          type: 'input',
          prop: 'toggleName',
          label: '折叠姓名'
        },
        {
          type: 'input',
          prop: 'toggleGender',
          label: '折叠性别'
        }
      ]
    },
    {
      title: '折叠标题2',
      name: '折叠2唯一标识符号',
      items: [
        {
          type: 'input',
          prop: 'toggleName2',
          label: '折叠姓名2'
        },
        {
          type: 'input',
          prop: 'toggleGender2',
          label: '折叠性别2'
        }
      ]
    },
    {
      title: '折叠标题3',
      name: '折叠3唯一标识符号',
      items: [
        {
          type: 'input',
          prop: 'toggleName3',
          label: '折叠姓名3'
        },
        {
          type: 'input',
          prop: 'toggleGender3',
          label: '折叠性别3'
        }
      ]
    },
    {
      title: '折叠标题4',
      name: '折叠4唯一标识符号',
      items: [
        {
          type: 'input',
          prop: 'toggleName4',
          label: '折叠姓名4'
        },
        {
          type: 'input',
          prop: 'toggleGender4',
          label: '折叠性别4'
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

// const items = reactive({
//   // 后台接收的数据放到这里，就可以传值了
//   arr: ["开票信息", "办款资料", "收件信息"]
// })

let drawerVisible = ref(false)
// const { items } = toRefs(status)
function confirm(data) {
  // 子组件传过来的formData数据
}
</script>

<style></style>
