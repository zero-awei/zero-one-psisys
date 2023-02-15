import { createApp }  from 'vue'
import { createPinia } from 'pinia'

import App from './App.vue'
import router from './router'
import 'element-plus/theme-chalk/src/message.scss'
import * as ElementPlusIconsVue from '@element-plus/icons-vue'
import './assets/main.css'
// import Vue from 'vue'


const app = createApp(App)
app.use(createPinia())
app.use(router)
app.mount('#app')
for (const [key, component] of Object.entries(ElementPlusIconsVue)) {
  app.component(key, component)
}

// 安装HTTP中间件
import installHttp from './plugins/http'
installHttp(router)

// 安装ElIcon
import installElIcon from './plugins/el-icon'
installElIcon(app)

// 注册全局组件
import PsiSearch from './components/search/PsiSearch.vue'
import PsiTable from './components/table/PsiTable.vue'
import PsiDialog from './components/dialog/PsiDialog.vue'
app.component('PsiSearch', PsiSearch)
app.component('PsiTable', PsiTable)
app.component('PsiDialog', PsiDialog)
