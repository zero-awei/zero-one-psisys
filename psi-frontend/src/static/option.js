export const option1 = {
    
    yAxis: {},
    tooltip: {
        trigger: "axis"
    },
    xAxis: {
        data: [],   // 将数据保存到json中，使用axios读取数据。axios.get("json路径").then(res=>{})  
    },
    series: {
        type: "bar",
        // name: "销量",
        data: [],   
    }
}

// const option2 = {
    
//     yAxis: {},
//     tooltip: {
//         trigger: "axis"
//     },
//     xAxis: {
//         data: [],   // 将数据保存到json中，使用axios读取数据。axios.get("json路径").then(res=>{})  
//         boundaryGap: false
//     },
//     series: {
//         type: "line",
//         data: [],   //
//         smooth: true
//     }
// }

// const option3 = {
    
//     yAxis: {},
//     tooltip: {
//         trigger: "axis"
//     },
//     xAxis: {
//         data: [],   // 将数据保存到json中，使用axios读取数据。axios.get("json路径").then(res=>{})  
//     },
//     series: {
//         type: "bar",
//         // name: "销量",
//         data: [],   
//     }
// }

// const option4 = {
    
//     yAxis: {},
//     tooltip: {
//         trigger: "axis"
//     },
//     xAxis: {
//         data: [],   // 将数据保存到json中，使用axios读取数据。axios.get("json路径").then(res=>{})  
//         boundaryGap: false
//     },
//     series: {
//         type: "line",
//         data: [],   //
//         smooth: true
//     }
// }
// export default {option1,option2,option3,option4} 
