import { createApp } from 'vue'
import { createPinia } from 'pinia'

import App from './App.vue'
import router from './router'
import 'element-plus/theme-chalk/src/message.scss'
import './assets/main.css'

const app = createApp(App)
app.use(createPinia())
app.use(router)
app.mount('#app')

// 安装HTTP中间件
import installHttp from './plugins/http'
installHttp(router)

// 安装ElIcon
import installElIcon from './plugins/el-icon'
installElIcon(app)

// 注册全局组件
import SearchComponent from './components/search/search.vue'
app.component('SearchComponent', SearchComponent)
