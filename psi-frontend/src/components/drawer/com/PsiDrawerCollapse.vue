<template>
  <div class="demo-collapse">
    <!-- 折叠面板 -->
        <el-collapse>
        <el-collapse-item :title="title" name="1">
            <div>
            Consistent with real life: in line with the process and logic of real
            life, and comply with languages and habits that the users are used to;
            </div>
        </el-collapse-item>
        <el-collapse-item :title="title" name="2">
            <div style="margin: 20px">
                <!-- 通过v-for打印多个输入 -->
                <el-form 
                    :label-position="'right'"
                    label-width="100px"
                    style="max-width: 460px"
                >
                <!-- element表单 -->

                    <el-form-item :label=item v-for="item in items">
                        <!-- 输入 -->
                        <el-input/>
                    </el-form-item>
                </el-form>
            </div>
        </el-collapse-item>

        <div>
            <el-button type="primary" size="default" @click="">确定</el-button>
            <el-button type="default" size="default" @click="">取消</el-button>
        </div>

        </el-collapse>
    </div>
</template>

<script setup>
import { ref } from 'vue'


// 用一个props接收根组件传来的后台数据
const names = defineProps({
  items: Array,
  title: String
})




const activeName = ref('1')
</script>
