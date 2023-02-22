<template>
  <div>
    <NavHeadCom />
    <CenterCom1 />
    <CenterTabCom />
    <CenterPicCom />
  </div>
</template>

<style lang="css" scoped></style>

<script>
import CenterCom1 from "@/components/Home/CenterCom1.vue"
import CenterTabCom from "@/components/Home/CenterTabCom.vue"
import NavHeadCom from "@/components/Home/NavHeadCom.vue"
import CenterPicCom from "@/components/Home/CenterPicCom.vue"
export default {
  components: {
    CenterCom1,
    CenterTabCom,
    NavHeadCom,
    CenterPicCom
  },
  data() {
    return {

    }
  },

}
</script>
