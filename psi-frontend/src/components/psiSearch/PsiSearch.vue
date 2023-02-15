<template>
  <div class="psi-search">
    <!-- 查询区域 -->
    <div class="table-page-search-wrapper">
      <el-form
        ref="searchRef"
        :model="formData"
        class="demo-form-inline"
        label-position="right"
        label-width="auto"
      >
        <el-row :gutter="20">
          <template v-for="item in items">
            <el-col :xl="6" :lg="7" :md="8" :sm="24">
              <el-form-item
                v-if="item.type === 'input'"
                :key="item.prop"
                :label="item.label"
                :prop="item.prop"
              >
                <el-input
                  :placeholder="item.placeholder"
                  v-model="formData[item.prop]"
                />
              </el-form-item>
              <el-form-item
                v-if="item.type === 'select'"
                :key="item.prop"
                :label="item.label"
                :prop="item.prop"
              >
                <el-select
                  v-model="formData[item.prop]"
                  :placeholder="item.placeholder"
                >
                  <el-option
                    v-for="option in item.options"
                    :key="option.value"
                    :label="option.label"
                    :value="option.value"
                  />
                </el-select>
              </el-form-item>
              <el-form-item
                v-if="item.type === 'datePicker'"
                :key="item.prop"
                :label="item.label"
                :prop="item.prop"
              >
                <el-date-picker
                  v-model="formData[item.prop]"
                  :type="item.prop"
                  :placeholder="item.placeholder"
                />
              </el-form-item>
              <el-form-item
                v-if="item.type === 'daterange'"
                :key="item.prop"
                :label="item.label"
                :prop="item.prop"
              >
                <el-date-picker
                  v-model="formData[item.prop]"
                  :type="item.prop"
                  :start-placeholder="item.startPlaceholder"
                  :end-placeholder="item.endPlaceholder"
                  :default-value="[new Date(2023, 1, 1), new Date(2023, 2, 1)]"
                />
              </el-form-item>
            </el-col>
          </template>
        </el-row>
        <template v-if="toggleSearchStatus">
          <el-row :gutter="20">
            <template v-for="item in toggleItems">
              <el-col :xl="6" :lg="7" :md="8" :sm="24">
                <el-form-item
                  v-if="item.type === 'input'"
                  :key="item.prop"
                  :label="item.label"
                  :prop="item.prop"
                >
                  <el-input
                    :placeholder="item.placeholder"
                    v-model="formData[item.prop]"
                  />
                </el-form-item>
                <el-form-item
                  v-if="item.type === 'select'"
                  :key="item.prop"
                  :label="item.label"
                  :prop="item.prop"
                >
                  <el-select
                    v-model="formData[item.prop]"
                    :placeholder="item.placeholder"
                  >
                    <el-option
                      v-for="option in item.options"
                      :key="option.value"
                      :label="option.label"
                      :value="option.value"
                    />
                  </el-select>
                </el-form-item>
                <el-form-item
                  v-if="item.type === 'datePicker'"
                  :key="item.prop"
                  :label="item.label"
                  :prop="item.prop"
                >
                  <el-date-picker
                    v-model="formData[item.prop]"
                    type="date"
                    :placeholder="item.placeholder"
                  />
                </el-form-item>
              </el-col>
            </template>
          </el-row>
        </template>

        <el-row>
          <el-button type="primary" @click="onSubmit">查询</el-button>

          <el-button @click="searchReset" icon="RefreshRight">重置</el-button>

          <template v-if="props.toggleItems.length > 0">
            <!-- 如果 v-if 放在el-button中，感觉上有些许卡顿-->
            <el-button @click="toggleSearchStatus = !toggleSearchStatus">
              {{ toggleSearchStatus ? '收起' : '展开' }}
              <el-icon>
                <ArrowDown v-if="toggleSearchStatus" />
                <ArrowUp v-else />
              </el-icon>
            </el-button>
          </template>
        </el-row>
      </el-form>
    </div>
  </div>
</template>

<script setup>
import { ref } from 'vue'
const props = defineProps({
  items: {
    type: Array,
    default: () => []
  },
  toggleItems: {
    type: Array,
    default: () => []
  },
  formData: {
    type: Object,
    default: () => {
      return {}
    }
  }
})

let toggleSearchStatus = ref(false)

const emit = defineEmits(['search'])
function onSubmit() {
  console.log('子组件emit')
  emit('search', props.formData)
}

const searchRef = ref(null)
const searchReset = () => {
  searchRef.value.resetFields()
}
</script>

<style></style>
