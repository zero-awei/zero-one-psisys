import {ElMessage} from "element-plus";
import {
    currencyQuery,
    currencyDetail,
    currencyExecAddCurrency,
    currencyModify
} from "../../jichuziliao/api/currencycheck";

// export function handleQuery() {
//     // 自定义请求参数
//     let params = {}
//     params.code = ''
//     params.name = ''
//     params.pageIndex = '1'
//     params.pageSize = '10'
//     currencyQuery(
//         params,
//         (data) => {
//             console.log('全部请求data----', data)
//         },
//         (msg) => {
//             ElMessage.warning(msg)
//         }
//     )
// }

// export function handleQuery() {
//     // 自定义请求参数
//     let params = {}
//     params.name = '人民币'
//     currencyDetail(
//         params,
//         (data) => {
//             console.log('全部请求data----', data)
//         },
//         (msg) => {
//             ElMessage.warning(msg)
//         }
//     )
// }

// export function handleQuery() {
//     // 自定义请求参数
//     let params = {}
//     params.code = 'pp'
//     params.name = 'pp'
//     params.isFunctional = '0'
//     params.isEnabled = '1'
//     params.remarks= ''
//     currencyExecAddCurrency(
//         params,
//         (data) => {
//             console.log('全部请求data----', data)
//         },
//         (msg) => {
//             ElMessage.warning(msg)
//         }
//     )
// }

// export function handleQuery() {
//     // 自定义请求参数
//     let params = {}
//     params.id = '1223848226643051315'
//     params.code = 'USDa'
//     params.name = '美元dollar'
//     params.isFunctional = '0'
//     params.isEnabled = '1'
//     params.remarks = ''
//     currencyModify(
//         params,
//         (data) => {
//             console.log('全部请求data----', data)
//         },
//         (msg) => {
//             ElMessage.warning(msg)
//         }
//     )
// }
