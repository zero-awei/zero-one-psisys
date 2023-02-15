<template>
  <div class="demo-collapse">
    <!-- 折叠面板 -->
        <el-collapse>
        <el-collapse-item title="Consistency" name="1">
            <div>
            Consistent with real life: in line with the process and logic of real
            life, and comply with languages and habits that the users are used to;
            </div>
        </el-collapse-item>
        <el-collapse-item title="Feedback" name="2">
            <div style="margin: 20px">
                <!-- 通过v-for打印多个输入 -->
                <el-form 
                    :label-position="'right'"
                    label-width="100px"
                    style="max-width: 460px"
                >
                <!-- element表单 -->

                    <el-form-item :label=n.message v-for="n in names">
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


// 这里用于渲染文字，不知道是从后台传过来还是前台自己做
const names = ref([{message: "开票信息"}, {message: "办款资料"}, {message: "收件信息"}]) 




const activeName = ref('1')
</script>
