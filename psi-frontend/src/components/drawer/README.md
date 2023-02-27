# psi-drawer 抽屉组件

## 第一版

### 示例 (演示路径 /component/drawer)

```vue
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
    @confirm="handleConfirm" />
  </div>
</template>

<script setup>
import { ref,reactive, toRefs } from 'vue'
let dialogVisible = ref(false)

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

let drawerVisible = ref(false)
function handleConfirm(data){
  // 点击 确定 按钮触发该事件
}
</script>

<style></style>
```

组件需要 v-model 绑定一个 Boolean 值
## psi-drawer 属性

| 属性名       | 说明                                                   | 类型                              | 默认 |
| ---------- | ------------------------------------------------------------- | --------------------------------- | ------- |
| title     | 抽屉标题| String                        | ——       |
| basicItems     | 抽屉中不折叠部分的表单选项| Array                        | ——       |
| toggleItems     | 抽屉中折叠部分的表单选项(注意示例的数组结构)| Array                        | ——       |
| formData     | 抽屉绑定的一个表单对象| Object                        | ——       |

basicItems,toggleItems 的属性配置和 psi-form 组件的item配置相同

## 事件

| 事件名       | 说明                                                   | 类型                              | 默认 |
| ---------- | ------------------------------------------------------------- | --------------------------------- | ------- |
| confirm     |  点击抽屉的确定按钮触发该事件          |——       |——
