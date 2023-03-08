/*
 * @Author: 160405103 1348313766@qq.com
 * @Date: 2023-02-28 20:49:18
 * @LastEditors: 160405103 1348313766@qq.com
 * @LastEditTime: 2023-03-08 19:45:27
 * @FilePath: \psi-frontend\vite.config.js
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
import { fileURLToPath, URL } from 'node:url'
import { defineConfig, loadEnv } from 'vite'
import vue from '@vitejs/plugin-vue'
import AutoImport from 'unplugin-auto-import/vite'
import Components from 'unplugin-vue-components/vite'
import { ElementPlusResolver } from 'unplugin-vue-components/resolvers'
import { createHtmlPlugin } from 'vite-plugin-html'

const getViteEnv = (mode, target) => {
  return loadEnv(mode, process.cwd())[target]
}

// https://vitejs.dev/config/
export default ({ mode }) =>
  defineConfig({
    server: {
      host: '0.0.0.0',
      port: 3000,
      https: false,
      proxy: {
        '/api': {
          changeOrigin: true,
          // target: 'http://localhost:10100',
          // rewrite: (path) => path.replace(/^\/api/, '')

          //TODO[TEST_CODE]:使用ApiPost云MOCK
          target:
            'https://console-mock.apipost.cn/mock/99738a62-8857-4bb2-8010-c92424b03584',
          rewrite: (path) => path.replace(/^\/api/, '')
        },
        '/captcha': {
          changeOrigin: true,
          // target: 'http://localhost:10680',
          target: 'http://101.132.238.119:10200/',
          // target: 'http://8.130.23.223:10001/',
          rewrite: (path) => path.replace(/^\/captcha/, '')
        },
        '/C1': {
          changeOrigin: true,
          // target: 'http://39.101.122.174:8090/',
          target: 'http://8.130.23.223:10001/',
          rewrite: (path) => path.replace(/^\/C1/, '')
        },
        '/C3': {
          // changeOrigin: true,
          // target: 'http://47.113.148.133:8090/',
          target: 'http://8.130.23.223:10001/',
          rewrite: (path) => path.replace(/^\/C3/, '')
        },
        '/J1oauth': {
          changeOrigin: true,
          // target: 'http://101.132.238.119:10400/',
          target: 'http://8.130.23.223:10001/',
          rewrite: (path) => path.replace(/^\/J1oauth/, '')
        },
        '/J1login': {
          changeOrigin: true,
          // target: 'http://101.132.238.119:10200/',
          target: 'http://8.130.23.223:10001/',
          rewrite: (path) => path.replace(/^\/J1login/, '')
        },
        '/J1sys': {
          changeOrigin: true,
          // target: 'http://47.113.200.198:15555/',
          target: 'http://8.130.23.223:10001/',
          rewrite: (path) => path.replace(/^\/J1sys/, '')
        },
        // 不是虚拟前缀
        '/J2sys': {
          changeOrigin: true,
          // target: 'http://8.130.30.128:10101/',
          target: 'http://8.130.23.223:10001/',
          rewrite: (path) => path.replace(/^\/J2sys/, '')
        },
        // 基本信息
        '/J2basedetail': {
          changeOrigin: true,
          // target: 'http://8.130.30.128:10110/',
          target: 'http://8.130.23.223:10001/',
          rewrite: (path) => path.replace(/^\/J2basedetail/, '')
        },
        // 首页模块
        '/J2titlepage': {
          changeOrigin: true,
          // target: 'http://8.130.24.117:10102/',
          target: 'http://8.130.23.223:10001/',
          rewrite: (path) => path.replace(/^\/J2titlepage/, '')
        },
        '/J4': {
          changeOrigin: true,
          target: 'http://8.130.20.243:10690/'
        },
        '/C5': {
          changeOrigin: true,
          target: 'http://47.115.231.132:8090/'
        }
      }
    },
    build: {
      assetsDir: 'static',
      chunkSizeWarningLimit: 1500,
      rollupOptions: {
        output: {
          manualChunks(id) {
            if (id.includes('node_modules')) {
              return id
                .toString()
                .split('node_modules/')[1]
                .split('/')[0]
                .toString()
            }
          }
        }
      }
    },
    plugins: [
      vue(),
      AutoImport({
        resolvers: [ElementPlusResolver()]
      }),
      Components({
        resolvers: [ElementPlusResolver()]
      }),
      createHtmlPlugin({
        inject: {
          data: {
            title: getViteEnv(mode, 'VITE_APP_TITLE')
          }
        }
      })
    ],
    resolve: {
      alias: {
        '@': fileURLToPath(new URL('./src', import.meta.url))
      }
    }
  })
