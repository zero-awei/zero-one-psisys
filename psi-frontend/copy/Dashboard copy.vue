<template>

  <div class="HomeCenter">
    <div class="head">概况，客户，供应商</div>
    <div class="contain">
      <div class="left">销售,采购</div>
      <div class="center">四个图表</div>
      <div class="right">处理中主要单据</div>
    </div >
  </div>
</template>

<style lang="scss" scoped>
.HomeCenter{
  .head{
    height:12.25rem;
    width:100%;
    background: red;
    padding:.2rem;
  }
  .contain{
    display:flex;
    flex-wrap: wrap;
    justify-content: space-between;
  .left{
    width:23rem;
    background-color: aqua;
     padding:.2rem;
  }
  .center{
    width:11.5rem;
    background-color: rgb(220, 45, 156);
     padding:.2rem;
  }
  .right{
    width:11.5rem;
    background-color: rgb(21, 211, 97);
     padding:.2rem;
  }
  }
}
</style>
