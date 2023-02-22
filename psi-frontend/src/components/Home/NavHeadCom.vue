<template>
    <el-breadcrumb separator="/home">
    <el-breadcrumb-item :to="{ path: '/home' }">homepage</el-breadcrumb-item>
    <el-breadcrumb-item
      ><a href="/home">promotion management</a></el-breadcrumb-item
    >
    <el-breadcrumb-item>promotion list</el-breadcrumb-item>
    <el-breadcrumb-item>promotion detail</el-breadcrumb-item>
  </el-breadcrumb>
</template>

<style lang="scss" scoped>
  .el-breadcrumb{
    margin-bottom:30px;
  }
</style>