<template>
    <div>
        <el-drawer 
            v-model="drawer"
            title="I am the title"
            size="40%"
        >
            <Collapse></Collapse>
        </el-drawer>

         <el-button type="primary" style="margin-left: 16px" @click="drawer = true" link>
            open
        </el-button>
    </div>
</template>


<script setup>
import Collapse from './Drawer-Collapse.vue'
import { ref } from 'vue'

const drawer = ref(false)


</script>