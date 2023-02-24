## 目录结构说明

下面目录或文件为有效资源，其他目录或文件不要提交到服务端：

- public：存放开放资源，比如比较大的图片文件或站点图标
- `src`：存放资源和源码的目录，注意`.vue`文件文件名大写字母开头
  - `src/apis`：存放网络对接`api`接口实现
  - `src/assets`：小资源文件可以放图标文件或全局样式表
  - `src/components`：存放公用组件
  - `src/plugins`：存放自定义插件封装
  - `src/router`：路由配置文件目录
  - `src/stores`：状态管理文件目录
  - `src/views`：存放页面目录
  - `src/App.vue`：程序入口`vue`文件
  - `src/main.js`：程序入口挂载以及插件装配文件
- .`env.XXX`：为环境变量文件
- `.eslintrc.cjs`：为`eslint`配置文件
- `.gitignore`：忽略配置文件
- `.prettierrc.json`: 代码美化配置文件
- `index.html`：程序入口页面
- `package.json`：第三方`JS`库管理配置文件
- `README.md`：项目自述文件
- `vite.config.js`：`Vite`构建工具配置文件
- `start.sh`：`Linux`下面的启动脚本


## .vue文件及操作说明

