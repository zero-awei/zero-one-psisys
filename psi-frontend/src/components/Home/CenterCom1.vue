<template>
 <div class="top">
    <div class="head">
      <el-row>
        <el-col :span="12">
            <el-card class="box-card">
              <template #header>
                <div class="card-header">
                      <!-- {{Card name}} -->
                      <span>概况</span>
                      <!-- 更新图标 加事件 -->
                    <el-icon><Refresh /></el-icon>
                </div>
              </template>  
                  <div class="card-bottom1">
                    <el-row>
                        <el-col :span="8">
                          <span>即时库存（元）</span>
                          <p>math</p>
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

          <el-col :span="5">
             <el-card class="box-card">
              <template #header>
                <div class="card-header">
                      <!-- {{Card name}} -->
                      <span>客户</span>
                      <!-- 更新图标 加事件 -->
                    <el-icon><Refresh /></el-icon>
                </div>
              </template>  
                  <div class="card-bottom2">
                    <div class="body">
                      <div class="head-info.center">
                        <span>今日+</span>
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
                  </div >  
            </el-card>
          </el-col>

          <el-col :span="7">
            <el-card class="box-card">
              <template #header>
                <div class="card-header">
                      <!-- {{Card name}} -->
                      <span>供应商</span>
                      <!-- 更新图标 加事件 -->
                    <el-icon><Refresh /></el-icon>
                </div>
              </template>  
                  <div class="card-bottom2">
                    <div class="body">
                      <div class="head-info.center">
                        <span>今日+</span>
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
                  </div >  
            </el-card>
          </el-col>
        </el-row>
      </div>
    </div >
</template>

<style lang="scss" scoped>
.card-header {
  display: flex;
  justify-content: space-between;
  align-items: center;
span{
  color: black;
  font-size: 16px;
  white-space: nowrap;
  text-overflow: ellipsis;
}
}

.card-bottom1{ 
.head-info.center{
span{
    color: rgba(70, 67, 67, 0.45);
    display: inline-block;
    font-size: 14px;
    line-height: 22px;
    margin-bottom: 4px;
}
 p{
    color: rgba(0,0,0,.85);
    font-size: 24px;
    line-height: 32px;
    margin: 0;
}
} 
}

.card-bottom2{
 .body{
  display:flex;
  .head-info.center {
    text-align: center;
    padding: 0 40px;
    span{
    color: rgba(0,0,0,.45);
    display: inline-block;
    font-size: 14px;
    line-height: 22px;
    margin-bottom: 4px;
       }
     .head-info.center p {
    color: rgba(0,0,0,.85);
    font-size: 24px;
    line-height: 32px;
    margin: 0;
     }
   }
 }
}
</style>

<script>
export default{
     name:"CenterCom1"
}

</script>