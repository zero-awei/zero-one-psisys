import { createApp } from 'vue'
import { createPinia } from 'pinia'

import App from './App.vue'
import router from './router'
import 'element-plus/theme-chalk/src/message.scss'
// import * as ElementPlusIconsVue from '@element-plus/icons-vue'
import './assets/main.css'
import * as echarts from "echarts"


const app = createApp(App)
app.use(createPinia())
app.use(router)
app.mount('#app')
// for (const [key, component] of Object.entries(ElementPlusIconsVue)) {
//   app.component(key, component)
// }

// 安装HTTP中间件
import installHttp from './plugins/http'
installHttp(router)

// 安装ElIcon
import installElIcon from './plugins/el-icon'
installElIcon(app)

// 解决Chrome 增加了新的事件捕获机制－Passive Event Listeners 导致页面加载变慢
import 'default-passive-events'

// 注册全局组件
import PsiForm from './components/form/PsiForm.vue'
import PsiTable from './components/table/PsiTable.vue'
import PsiDialog from './components/dialog/PsiDialog.vue'
import PsiDrawer from './components/drawer/com/PsiDrawer.vue'
import PsiPopover from './components/drawer/com/PsiPopover.vue'
app.component('PsiForm', PsiForm)
app.component('PsiTable', PsiTable)
app.component('PsiDialog', PsiDialog)
app.component('PsiDrawer', PsiDrawer)
app.component('PsiPopover', PsiPopover)
