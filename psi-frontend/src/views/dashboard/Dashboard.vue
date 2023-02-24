<template>
  <div class="total">
    <div class="top"><CenterCom1 /></div >
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
    </div >
    <SearchCom />
  </div>
</template>

<style lang="css" scoped>
  .total{
    background-color:rgba(0,0,0,.03);
  }
  .top{
    min-width:180px;
    /* margin-bottom:4px; */
    top:-10px;
  }
  .bottom{
    display:flex; 
    margin:4px 4px 0px 6px;
    height:100%;
  }
</style>

<script>
import SearchCom from '@/components/Home/SearchCom.vue'
import CenterCom1 from "@/components/Home/CenterCom1.vue"
import CenterTabCom from "@/components/Home/CenterTabCom.vue"
import CenterDivCom from "@/components/Home/CenterDivCom.vue"
import CenterPicCom from "@/components/Home/CenterPicCom.vue"
export default {
  components :{
    CenterCom1,
    CenterTabCom,
    // NavHeadCom,
    CenterPicCom,
    CenterDivCom,
    SearchCom
  },
  data () {
    return {
      ratio:100
    }
  },
  mounted() {
    this.$nextTick(() => {
      window.addEventListener("resize", () => {
        // 监听浏览器窗口大小改变
        // 浏览器变化执行动作
        this.detectZoom();
      });
    });
  },
  methods: {
    detectZoom() {
      // let ratio = 0
      const screen = window.screen;
      const ua = navigator.userAgent.toLowerCase();
      if (window.devicePixelRatio !== undefined) {
        this.ratio = window.devicePixelRatio;
      } else if (~ua.indexOf("msie")) {
        if (screen.deviceXDPI && screen.logicalXDPI) {
          this.ratio = screen.deviceXDPI / screen.logicalXDPI;
        }
      } else if (
        window.outerWidth !== undefined &&
        window.innerWidth !== undefined
      ) {
        this.ratio = window.outerWidth / window.innerWidth;
      }
 
      if (this.ratio) {
        this.ratio = Math.round(this.ratio * 100);
      }
      console.log(this.ratio);
        //得到的额百分比
      return this.ratio;
    },
  } 
}
</script>
