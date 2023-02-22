<!--
 * @Author: li.ziwei
 * @Date: 2023-02-15 15:14:57
 * @LastEditTime: 2023-02-23 00:27:06
 * @LastEditors: 160405103 1348313766@qq.com
 * @Description: 
 * @FilePath: \psi-frontend\src\components\drawer\com\PsiDrawer.vue
 * 可以输入预定的版权声明、个性签名、空行等
-->
<!--
 * @Author: li.ziwei
 * @Date: 2023-02-15 15:14:57
 * @LastEditTime: 2023-02-15 15:47:04
 * @LastEditors: li.ziwei
 * @Description: 
 * @FilePath: \psi-frontend\src\components\drawer\com\Drawer.vue
 * 可以输入预定的版权声明、个性签名、空行等
-->
<template>
  <div class="psi-drawer">
    <el-drawer v-model="visible" :title="title" size="50%" class="drawer-class">
      <div class="drawer-form-class">
        <el-collapse v-model="activeNames" @change="handleChange">
          <el-form :model="formData" class="demo-form-inline" label-position="right" label-width="auto"
            style="margin-top:25px">
            <div class="items-class">
              <template v-for="item in basicItems">
                <el-form-item v-if="item.type === 'input'" :key="item.prop" :label="item.label" :prop="item.prop">
                  <el-input :placeholder="item.placeholder ?? '请输入'" v-model="formData[item.prop]" />
                </el-form-item>
                <el-form-item v-if="item.type === 'select'" :key="item.prop" :label="item.label" :prop="item.prop">
                  <el-select v-model="formData[item.prop]" :placeholder="item.placeholder ?? '请选择'">
                    <el-option v-for="option in item.options" :key="option.value" :label="option.label"
                      :value="option.value" />
                  </el-select>
                </el-form-item>
                <el-form-item v-if="item.type === 'datePicker'" :key="item.prop" :label="item.label" :prop="item.prop">
                  <el-date-picker v-model="formData[item.prop]" type="date" :placeholder="item.placeholder ?? '请选择'" />
                </el-form-item>
              </template>
            </div>

            <template v-for="toggleItem in toggleItems">
              <el-collapse-item :title="toggleItem.title" :name="toggleItem.name">
                <template v-for="item in toggleItem.items">
                  <div class="items-class">
                    <el-form-item v-if="item.type === 'input'" :key="item.prop" :label="item.label" :prop="item.prop">
                      <el-input :placeholder="item.placeholder ?? '请输入'" v-model="formData[item.prop]" />
                    </el-form-item>
                    <el-form-item v-if="item.type === 'select'" :key="item.prop" :label="item.label" :prop="item.prop">
                      <el-select v-model="formData[item.prop]" :placeholder="item.placeholder ?? '请选择'">
                        <el-option v-for="option in item.options" :key="option.value" :label="option.label"
                          :value="option.value" />
                      </el-select>
                    </el-form-item>
                    <el-form-item v-if="item.type === 'datePicker'" :key="item.prop" :label="item.label"
                      :prop="item.prop">
                      <el-date-picker v-model="formData[item.prop]" type="date"
                        :placeholder="item.placeholder ?? '请选择'" />
                    </el-form-item>
                  </div>
                </template>
              </el-collapse-item>
            </template>





          </el-form>
        </el-collapse>
      </div>
      <footer>
        <el-button @click="visible = false"> 取消</el-button>
        <el-button @click="confirm"> 确定</el-button>
      </footer>
    </el-drawer>
  </div>
</template>

<script setup>
import PsiDrawerCollapse from './PsiDrawerCollapse.vue'
import { ref, computed } from 'vue'

const props = defineProps({
  modelValue: null,
  title: {
    type: String,
    default: () => {
      return ''
    }
  },
  basicItems: {
    type: Array,
    default: () => []
  },
  toggleItems: {
    type: Array,
    default: () => []
  },
  formData: {
    type: Object,
    default: () => { return {} }
  }
})
// const drawer = ref(false)

// 当前激活的折叠面板
const activeNames = ref('')
const emit = defineEmits(['update:modelValue', 'confirm'])
const visible = computed({
  get() {
    return props.modelValue
  },
  set(visible) {
    emit('update:modelValue', visible)
  }
})

function confirm() {
  emit('confirm', props.formData)
}
</script>

<style scoped>
/* .drawer-form-class {
  position: relative;
  height: 100vh;
} */
/* .psi-drawer {
  position: relative;
  height: 100vh;
} */

/* .drawer-class {
  position: relative;
  height: 100vh;

}*/

/* footer {
  height: 60px;
  line-height: 60px;
  position: absolute;
  bottom: 0;
  left: 0;
} */

.items-class {
  margin: 0 40px
}

:deep(.el-drawer__header) {
  margin-bottom: -4px
}
</style>
