<script>
import { userStore } from '../stores/user'
const store = userStore()
// 菜单数据
const menus = store.getMenus
</script>

<template>
    <el-menu default-active="2" class="el-menu-vertical-demo">

        <!-- <el-menu-item>首页</el-menu-item> -->
        <el-sub-menu index="1">
            <template #title>
                <el-icon>
                    <Discount />
                </el-icon>
                <span>首页</span>
            </template>
        </el-sub-menu>

        <el-sub-menu index="2">
            <template #title>
                <el-icon>
                    <MessageBox />
                </el-icon>
                <span>采购管理</span>
            </template>
            <el-menu-item>采购申请</el-menu-item>
            <el-menu-item>采购询价</el-menu-item>
            <el-menu-item>供应报价</el-menu-item>
            <el-menu-item>采购报价</el-menu-item>
        </el-sub-menu>

        <el-sub-menu index="3">
            <template #title>
                <el-icon>
                    <MessageBox />
                </el-icon>
                <span>库存管理</span>
            </template>
            <el-menu-item>入库库存</el-menu-item>
            <el-menu-item>及时库存</el-menu-item>
            <el-menu-item>出入库统计</el-menu-item>
        </el-sub-menu>

        <el-sub-menu index="4">
            <template #title>
                <el-icon>
                    <MessageBox />
                </el-icon>
                <span>应付与付款</span>
            </template>
            <el-menu-item></el-menu-item>
        </el-sub-menu>

        <el-sub-menu index="5">
            <template #title>
                <el-icon>
                    <MessageBox />
                </el-icon>
                <span>基础资料</span>
            </template>
            <el-menu-item></el-menu-item>
        </el-sub-menu>

        <el-sub-menu index="6">
            <template #title>
                <el-icon>
                    <MessageBox />
                </el-icon>
                <span>系统管理</span>
            </template>
            <el-menu-item></el-menu-item>
        </el-sub-menu>

    </el-menu>
</template>
