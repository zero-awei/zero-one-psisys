<template>
  <div class="contain">
    <!-- <div class="code">主面板</div>
    <div class="info">这是主面板</div> -->
  </div>
</template>

<style lang="css" scoped>
.contain {
  text-align: center;
  padding: 20%;
}
.code {
  font-size: xxx-large;
  font-weight: bold;
  color: #222222;
}
.info {
  font-weight: bold;
  color: dimgray;
}
</style>



getOption1(){
      var myEcharts = echarts.init(document.getElementById("div1"));
      myEcharts.setOption(option1);
      axios.get("/js/testData.json").then(res => {
        myEcharts.setOption(
          {
            xAxis: {
              data: res.data.month
            },
            series: {
              data: res.data.data,
              label: {
                  show: true
              }
            }
          }
        )
      })
    },