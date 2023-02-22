<template>
      <el-card class="box-card">

        <template #header>
          <div class="card-header">
            <span>销售</span>
            <el-icon><Refresh /></el-icon>
         </div>
        </template>
        <!-- <div v-for="o in 4" :key="o" class="text item">{{ 'List item ' + o }}</div> -->
        <div>
            <div class="div1">
             <el-row :gutter="20">
                <el-col :span="12">
                     <el-card shadow="hover">
                    <div>订单</div>

                    <div class="body">
                        <div class="left">
                            <div>
                                <span>今日笔数</span>
                                 <p>0</p>
                            </div>
                            <div>本周:8</div>
                            <div>本月:8</div>
                        </div>
                        <div class="right">
                            <div>
                                <span>今日金额</span>
                                <p>12222</p>
                            </div>
                            <div>本周:8</div>
                            <div>本月:8</div>
                        </div>
                    </div>
                    </el-card>
                </el-col>

                <el-col :span="12">
                     <el-card shadow="hover">
                    <div>出库</div>

                    <div class="body">
                        <div class="left">
                            <div>
                                <span>今日笔数</span>
                                 <p>0</p>
                            </div>
                            <div>本周:8</div>
                            <div>本月:8</div>
                        </div>
                        <div class="right">
                            <div>
                                <span>今日金额</span>
                                <p>12222</p>
                            </div>
                            <div>本周:8</div>
                            <div>本月:8</div>
                        </div>
                    </div>
                    </el-card>
                </el-col>
            </el-row>
            </div>

            <div class="div2">
            <el-row :gutter="20">
                <el-col :span="12">
                     <el-card shadow="hover">
                    <div>订单</div>

                    <div class="body">
                        <div class="left">
                            <div>
                                <span>今日笔数</span>
                                 <p>0</p>
                            </div>
                            <div>本周:8</div>
                            <div>本月:8</div>
                        </div>
                        <div class="right">
                            <div>
                                <span>今日金额</span>
                                <p>12222</p>
                            </div>
                            <div>本周:8</div>
                            <div>本月:8</div>
                        </div>
                    </div>
                    </el-card>
                </el-col>

                <el-col :span="12">
                     <el-card shadow="hover">
                    <div>出库</div>

                    <div class="body">
                        <div class="left">
                            <div>
                                <span>今日笔数</span>
                                 <p>0</p>
                            </div>
                            <div>本周:8</div>
                            <div>本月:8</div>
                        </div>
                        <div class="right">
                            <div>
                                <span>今日金额</span>
                                <p>12222</p>
                            </div>
                            <div>本周:8</div>
                            <div>本月:8</div>
                        </div>
                    </div>
                    </el-card>
                </el-col>
            </el-row>
            </div>


            <el-row :gutter="12">
                <el-col :span="6">
                <el-card shadow="hover">
                    <div>订单</div>

                    <div class="body">
                        <div class="left">
                            <div>
                                <span>今日笔数</span>
                                 <p>0</p>
                            </div>
                            <div>本周:8</div>
                            <div>本月:8</div>
                        </div>
                        <div class="right">
                            <div>
                                <span>今日金额</span>
                                <p>12222</p>
                            </div>
                            <div>本周:8</div>
                            <div>本月:8</div>
                        </div>
                    </div>
                    </el-card>
                    </el-col>

                    <el-col :span="6">
                    <el-card shadow="hover">
                         <div>出库</div>
                        <div class="body">
                        <div class="left">
                            <div>
                                <span>今日笔数</span>
                                <p>0</p>
                            </div>
                            <div>本周:8</div>
                            <div>本月:8</div>
                        </div>
                        <div class="right">
                            <div>
                                <span>今日金额</span>
                                <p>12222</p>
                            </div>
                            <div>本周:8</div>
                            <div>本月:8</div>
                        </div>
                    </div>
                    </el-card>
                    </el-col>

                    <el-col :span="6">
                    <el-card shadow="hover">
                         <div>应收</div>
                        <div class="left">
                            <div>
                                <span>今日笔数</span>
                                <p>0</p>
                            </div>
                            <div>本周:8</div>
                            <div>本月:8</div>
                        </div>
                        <div class="right">
                            <div>
                                <span>今日金额</span>
                                <p>12222</p>
                            </div>
                            <div>本周:8</div>
                            <div>本月:8</div>
                        </div>
                    </el-card>
                    </el-col>

                <el-col :span="6">
                <el-card shadow="hover">
                     <div>付款</div>
                    <div class="left">
                        <div>
                            <span>今日笔数</span>
                            <p>0</p>
                        </div>
                        <div>本周:8</div>
                        <div>本月:8</div>
                    </div>
                    <div class="right">
                        <div>
                            <span>今日金额</span>
                            <p>12222</p>
                        </div>
                        <div>本周:8</div>
                        <div>本月:8</div>
                    </div>
                </el-card>
                </el-col>

            </el-row>
        </div>
      </el-card>



        <el-card class="box-card">
        <template #header>
          <div class="card-header">
            <span>销售</span>
            <el-icon><Refresh /></el-icon>
         </div>
        </template>
        <!-- <div v-for="o in 4" :key="o" class="text item">{{ 'List item ' + o }}</div> -->
        <div>
            <el-row :gutter="12">
                <el-col :span="6">
                <el-card shadow="hover">
                    <div>订单</div>
                    <div class="body">
                        <div class="left">
                            <div>
                                <span>今日笔数</span>
                                 <p>0</p>
                            </div>
                            <div>本周:8</div>
                            <div>本月:8</div>
                        </div>
                        <div class="right">
                            <div>
                                <span>今日金额</span>
                                <p>12222</p>
                            </div>
                            <div>本周:8</div>
                            <div>本月:8</div>
                        </div>
                    </div>
                    </el-card>
                    </el-col>

                    <el-col :span="6">
                    <el-card shadow="hover">
                         <div>订单</div>
                        <div class="body">
                        <div class="left">
                            <div>
                                <span>今日笔数</span>
                                <p>0</p>
                            </div>
                            <div>本周:8</div>
                            <div>本月:8</div>
                        </div>
                        <div class="right">
                            <div>
                                <span>今日金额</span>
                                <p>12222</p>
                            </div>
                            <div>本周:8</div>
                            <div>本月:8</div>
                        </div>
                    </div>
                    </el-card>
                    </el-col>

                    <el-col :span="6">
                    <el-card shadow="hover">
                         <div>订单</div>
                        <div class="left">
                            <div>
                                <span>今日笔数</span>
                                <p>0</p>
                            </div>
                            <div>本周:8</div>
                            <div>本月:8</div>
                        </div>
                        <div class="right">
                            <div>
                                <span>今日金额</span>
                                <p>12222</p>
                            </div>
                            <div>本周:8</div>
                            <div>本月:8</div>
                        </div>
                    </el-card>
                    </el-col>

                <el-col :span="6">
                <el-card shadow="hover">
                     <div>订单</div>
                    <div class="left">
                        <div>
                            <span>今日笔数</span>
                            <p>0</p>
                        </div>
                        <div>本周:8</div>
                        <div>本月:8</div>
                    </div>
                    <div class="right">
                        <div>
                            <span>今日金额</span>
                            <p>12222</p>
                        </div>
                        <div>本周:8</div>
                        <div>本月:8</div>
                    </div>
                </el-card>
                </el-col>

            </el-row>
        </div>
      </el-card>
</template>

<style scoped>
.card-header {
  display: flex;
  justify-content: space-between;
  align-items: center;
}
.div1{
    width:261px;
    height:234px;
}

.text {
  font-size: 14px;
}

.item {
  margin-bottom: 18px;
}

.box-card {
  width: 587px;
  height:480px;
  padding:4px;

}
.body{
    display: flex;
}
</style>