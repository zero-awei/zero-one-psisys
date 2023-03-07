<!--
 * @Author: 160405103 1348313766@qq.com
 * @Date: 2023-02-24 13:55:48
 * @LastEditors: 160405103 1348313766@qq.com
 * @LastEditTime: 2023-03-07 17:19:13
 * @FilePath: \psi-frontend\src\views\dashboard\Dashboard.vue
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
<template>
  <div class="total">
    <!-- <div class="top"> -->
    <div>
      <!-- <el-row> -->
      <CenterCom1 />
      <!-- </el-row> -->
    </div>
    <div class="bottom">
      <el-row :gutter="10">
        <el-col :span="10">
          <CenterDivCom />
        </el-col>
        <el-col :span="8">
          <CenterPicCom />
        </el-col>
        <el-col :span="6">
          <CenterTabCom />
        </el-col>
      </el-row>
    </div>
  </div>
</template>

<style lang="css" scoped>
.top {
  min-width: 180px;
  /* margin-bottom:4px; */
  /* top: -10px; */
}

.bottom {
  display: flex;
  /* height: 100%; */
  /* margin-top: 25px; */
  /* min-width: 1052px; */
  /* width: 1192px; */
  /* left: -14px; */
}
</style>

<script>
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
  },
  data() {
    return {
      ratio: 100
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
      // console.log(this.ratio);
      //得到的额百分比
      return this.ratio;
    },
  }
}
</script>
