<template>
  <div>
    <div class="top">
      <CenterCom1 />
    </div>
    <div class="bottom">
      <el-row :gutter="20">
        <el-col :span="12">
          <CenterDivCom />
        </el-col>
        <el-col :span="6">
          <CenterPicCom />
        </el-col>
        <el-col :span="6">
          <CenterTabCom />
        </el-col>
      </el-row>
    </div>
    <SearchCom />
  </div>
</template>

<style lang="css" scoped>
.top {
  margin-bottom: 4px;
}

.bottom {
  display: flex;
  margin: 4px 4px 0px 6px;
  height: 100%;
}
</style>

<script>
import SearchCom from '@/components/Home/SearchCom.vue'
import CenterCom1 from "@/components/Home/CenterCom1.vue"
import CenterTabCom from "@/components/Home/CenterTabCom.vue"
import CenterDivCom from "@/components/Home/CenterDivCom.vue"
import CenterPicCom from "@/components/Home/CenterPicCom.vue"
export default {
  components: {
    CenterCom1,
    CenterTabCom,
    // NavHeadCom,
    CenterPicCom,
    CenterDivCom,
    SearchCom
  },
  data() {
    return {

    }
  },

}
</script>
