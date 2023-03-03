<template>
  <div class="top">
    <!--ToDo 2.5系统收支概况 -->
    <!-- 
    <el-row>
        <el-col class="head" :span="12">
            <el-card class="box-card">
              <template #header>
                <div class="card-header">
                      <span>概况</span>
                    <el-icon class="icon1"><Refresh /></el-icon>
                </div>
              </template>  
                  <div class="card-bottom1">
                    <el-row>
                        <el-col :span="8">
                          <span>即时库存</span>
                          <p>0</p>
                        </el-col>
                    <el-col :span="8">
                          <span>客户欠款（元）</span>
                          <p>math</p>
                        </el-col>
                        <el-col :span="8">
                          <span>欠供应商（元）</span>
                          <p>math</p>
                        </el-col>   
                     </el-row>
                  </div >  
            </el-card>
          </el-col>
   -->

    <el-row>
      <el-col class="head" :span="12">
        <el-card class="box-card">
          <template #header>
            <div class="card-header">
              <!-- {{Card name}} -->
              <span>概况</span>
              <!-- 更新图标 加事件 -->
              <el-icon class="icon1">
                <Refresh />
              </el-icon>
            </div>
          </template>
          <div class="card-bottom1">
            <el-row>
              <el-col :span="8">
                <span>即时库存</span>
                <p>0</p>
              </el-col>
              <el-col :span="8">
                <span>客户欠款（元）</span>
                <p>math</p>
              </el-col>
              <el-col :span="8">
                <span>欠供应商（元）</span>
                <p>math</p>
              </el-col>
            </el-row>
          </div>
        </el-card>
      </el-col>

      <el-col class="head" :span="6">
        <el-card class="box-card">
          <template #header>
            <div class="card-header">
              <!-- {{Card name}} -->
              <span>客户</span>
              <!-- 更新图标 加事件 -->
              <el-icon class="icon2">
                <Refresh />
              </el-icon>
            </div>
          </template>
          <div class="card-bottom2">
            <div class="body">
              <div class="head-info.center">
                <span>本日+</span>
                <p>0</p>
              </div>
              <div class="head-info.center">
                <span>本周+</span>
                <p>0</p>
              </div>
              <div class="head-info.center">
                <span>本月+</span>
                <p>0</p>
              </div>
              <div class="head-info.center">
                <span>客户数</span>
                <p>0</p>
              </div>
            </div>
          </div>
        </el-card>
      </el-col>

      <el-col class="head" :span="6">
        <el-card class="box-card">
          <template #header>
            <div class="card-header">
              <!-- {{Card name}} -->
              <span>供应商</span>
              <!-- 更新图标 加事件 -->
              <el-icon class="icon3">
                <Refresh />
              </el-icon>
            </div>
          </template>
          <div class="card-bottom2">
            <div class="body">
              <div class="head-info.center">
                <span>本日+</span>
                <p>0</p>
              </div>
              <div class="head-info.center">
                <span>本周+</span>
                <p>0</p>
              </div>
              <div class="head-info.center">
                <span>本月+</span>
                <p>0</p>
              </div>
              <div class="head-info.center">
                <span>供应商数</span>
                <p>0</p>
              </div>
            </div>
          </div>
        </el-card>
      </el-col>
    </el-row>
  </div>
</template>

<style scoped>
.top {
  left: -14px;
  min-width: 1052px;
  width: 1192px;
}

.head {
  height: 160px;
  padding: 4px;
}

.el-icon {
  color: blue;
}

.icon2 {
  left: 200px;
}

.icon1 {
  left: 480px;
}

.icon3 {
  left: 185px;
}

.card-header span {
  color: black;
  font-size: 16px;
}

.card-bottom1 {
  height: 67px;
}

.card-bottom1 span {
  color: rgba(0, 0, 0, .45);
  display: inline-block;
  font-size: 14px;
  line-height: 22px;
  margin-bottom: 4px;
}

.card-bottom1 p {
  color: rgba(0, 0, 0, .85);
  font-size: 30px;
  line-height: 32px;
}


.body {
  display: flex;
}

.body div {
  padding: 4px;
}

.card-bottom2 .head-info.center {
  padding: 4px;
}

.card-bottom2 span {
  color: rgba(0, 0, 0, .45);
  display: inline-block;
  font-size: 14px;
  line-height: 22px;
  margin-bottom: 4px;
}

.card-bottom2 p {
  color: rgba(0, 0, 0, .85);
  font-size: 30px;
  line-height: 32px;
}
</style>

<script setup>

</script>

 