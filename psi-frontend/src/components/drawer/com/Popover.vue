<template>
    <div>
        <el-popover
        placement="left-start"
        title="Title"
        :width="300"
        trigger="click"
        content="this is content, this is content, this is content"
        >
        <!-- content是没有内容的时候填充的 -->

        <template #reference>
            <el-button class="m-2">Hover to activate</el-button>
        </template>
        


                <el-checkbox v-model="checked3" label="Option 1" />
                <el-checkbox v-model="checked4" label="Option 2" />
                <el-checkbox v-model="checked3" label="Option 1" />
                <el-checkbox v-model="checked4" label="Option 2" />


                <el-checkbox v-model="checked3" label="Option 1" />
                <el-checkbox v-model="checked4" label="Option 2" />
                <el-checkbox v-model="checked3" label="Option 1" />
                <el-checkbox v-model="checked4" label="Option 2" />
        

        </el-popover>
    </div>
</template>

<script setup>
import { ref } from 'vue'

const visible = ref(false)
</script>

