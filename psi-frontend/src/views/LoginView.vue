<!-- 登录页面 -->
<template>
  <!-- <div class="box-card">
        <div><el-card style="width: 480px;"> -->
  <!-- 表单验证 :rules="rules" -->
<!-- <span>系统登录</span>
        <el-form :model="formData" :rules="rules" status-icon label-width="60px">
          <el-form-item label="账号" prop="username">
            <el-input v-model="formData.username"></el-input>
          </el-form-item>
          <el-form-item label="密码" prop="password">
            <el-input v-model="formData.password" type="password" @keyup.native.enter="submitForm()"></el-input>
          </el-form-item>
          <el-form-item>
            <el-button type="primary" @click="submitForm()">登录</el-button>
          </el-form-item>
        </el-form>

            <Test /></el-card> -->
  <!-- 验证码组件 -->
<!-- <Verify mode="pop" :captchaType="captchaType" :imgSize="{ width: '400px', height: '200px' }" ref="verify"
            @success="handleSuccess"></Verify> -->
  <!-- </div></div> -->
  <div class="login-main">
    <div class="login-wraper">
      <div class="login-content">

        <div class="login-form">
          <h1>登录</h1>
          <el-form :model="formData" :rules="rules" status-icon label-width="60px" label-position="top" size="large"
            require-asterisk-position="right">
            <el-form-item label="账号" prop="username">
              <el-input v-model="formData.username"></el-input>
            </el-form-item>
            <br />
            <el-form-item label="密码" prop="password">
              <!-- TODO <el-input v-model="formData.password" type="password" @keyup.native.enter="submitForm()"></el-input> -->
              <el-input v-model="formData.password" type="password"></el-input>
            </el-form-item>

          </el-form>
          <button class="login-btn" @click="submitForm()">登录</button>
          <Verify mode="pop" :captchaType="captchaType" :imgSize="{ width: '400px', height: '200px' }" ref="verify"
            @success="handleSuccess" />
        </div>

      </div>

    </div>

  </div>
</template>

<script setup>
import Verify from '@/components/verifition/Verify.vue'
import Request from '@/apis/request'
import { ref, reactive, onMounted, onUnmounted } from 'vue'
import { login } from '@/apis/login'
import { ElMessage } from 'element-plus'
import { useRouter } from 'vue-router'
import { router } from '@/router/index.js'
import Test from '@/views/test/test.vue'
// 获取router对象
const $router = useRouter()

// 定义登录数据对象
const formData = reactive({
  username: '',
  password: ''
})
//校验规则
const rules = reactive({
  username: [
    { required: true, trigger: 'blur', message: '请输入用户名' }
  ],
  password: [
    { required: true, trigger: 'blur', message: '请输入密码' }
  ]

})

/**
 * 执行登录
 * @param code 验证码字符串
 */
function doLogin(code) {
  // console.log('777777777')
  // 发送登录请求
  login(
    {
      ...formData,
      clientId: import.meta.env.VITE_CLIENT_ID,
      code: code
    },
    () => {
      // console.log("99999999999")
      // 跳转到首页
      $router.push('/home')
      // 登录成功提示
      ElMessage.success('登录成功，前往首页')
    },
    () => {
      ElMessage.error('账号或密码错误')
    }
  )
}

// 点击回车键登录
function keyDown(e) {
  // 回车则执行登录方法 enter键的ASCII是13
  if (e.keyCode === 13) {
    doLogin(); // 定义的登录方法
  }
}
// onMounted(() => {
//   // 绑定监听事件
//   window.addEventListener("keydown", keyDown);
// })
// onUnmounted(() => {
//   // 销毁事件
//   window.removeEventListener("keydown", keyDown, false);
// })


// 定义登录提交函数
function submitForm() {
  //TODO[TEST_CODE]:测试直接进入主界面
  //$router.push('/home')

  // 弹出验证码框
  // useVerify('clickWord')
  // console.log('111111111')
  doLogin()
}

// 验证码组件引用
const verify = ref(null)
// 验证码类型
const captchaType = ref('')

/**
 * 弹出验证码框
 * @param type 验证码类型 blockPuzzle滑块验证 clickWord点击文字验证
 */
function useVerify(type) {
  captchaType.value = type
  verify.value.show()
}

/**
 * 验证码验证通过执行登录二次验证逻辑
 * @param res 验证通过信息
 */
function handleSuccess(res) {
  //TODO[TEST_CODE]:测试调用二次验证
  Request.requestForm(
    Request.POST,
    '/login',
    { captchaVerification: res.captchaVerification },
    { baseURL: import.meta.env.VITE_CAPTCHA_URL }
  )
    .then((res) => {
      // // console.log(res)
      if (res.data.repCode === '0000') {
        // 跳转到首页
        $router.push('/home')
        // 登录成功提示
        ElMessage.success('登录成功，前往首页')
        return
      }
      ElMessage.error('账号或密码错误')
    })
    .catch((res) => {
      // // console.log(res)
      ElMessage.error('账号或密码错误')
    })

  //doLogin(res.captchaVerification)
}
</script>

<style lang="scss" scoped>
span {
  display: block;
  font-size: 28px;
  top: -20px;
  left: 125px;
  /* margin:0 auto; */
}

.box-card {
  display: flex;
  /* width: 480px; */
  justify-content: center;
  /* 主轴居中 */
  align-items: center;
  /* 侧轴居中 */
  height: 100vh;
  /* margin: auto; */
  /* margin: 180px auto;
  padding: 20px; */
}

// .el-button {
//   left: 100px;
//   width: 80px;
//   font-size: 15px;
//   top: 20px;
// }

// login 样式
.login-main {
  width: 100vw;
  height: 100vh;
  // background-color: rgb(29, 67, 89);
  background-color: #d6dee48a;
  // background-color: #1c1c1d;
  display: flex;
  align-items: center;
  justify-content: center;

  .login-wraper {
    width: 85vw;
    height: 90vh;
    background-color: #fff;
    border-radius: 20px;
  }

  .login-content {
    width: 85vw;
    height: 90vh;
    background-color: #fff;
    border-radius: 20px;
    background: url("src/assets/login_two.jpg") no-repeat;
    background-size: 90% 100%;
    display: flex;
    justify-content: end;

    // position: absolute;
    // right: 15%;
    // top: 50%;
    // left: 50%;
    // transform: translate(-50%, -50%);
    .login-form {
      width: 43vw;
      padding: 50px 100px;

      :deep(.el-form-item__label) {
        font-size: 20px;
      }

      :deep(.el-input__wrapper) {
        border-radius: 40px;
        height: 60px;
        padding: 1px 30px;
        font-size: 20px;
      }
    }

    h1 {
      text-align: center;
      font-size: 45px;
      font-weight: bold;
      color: rgb(81, 100, 115);
      margin-bottom: 40px;
    }

    .login-btn {
      width: 100%;
      border-radius: 40px;
      color: #fff;
      border: 0;
      font-weight: 100;
      margin-top: 35px;
      cursor: pointer;
      height: 50px;
      background-color: rgb(59, 72, 89);
      font-size: 20px;
    }
  }
}



/* 新样式 */
* {
  margin: 0;
  padding: 0;
}

*::before,
*::after {
  position: static;
}

/*公共CSS*/
.box {
  background-color: rgb(29, 67, 89);

  .content {
    width: 85vw;
    height: 90vh;
    background: url("src/assets/login_two.jpg") no-repeat;
    background-size: 90% 100%;
    position: absolute;
    right: 15%;
    top: 50%;
    left: 50%;
    transform: translate(-50%, -50%);
    border-radius: 20px;
    background-color: #fff;

    .login-wrapper {
      width: 25vw;
      position: absolute;
      right: 15%;
      top: 50%;
      transform: translateY(-50%);

      h1 {
        text-align: center;
        font-size: 45px;
        color: rgb(81, 100, 115);
        margin-bottom: 40px;
      }

      .login-form {
        margin: 10px 0;

        .form-item {
          span {
            color: rgb(81, 100, 115);
          }

          .input-item {
            height: 60px;
            border: 1px solid rgb(214, 222, 228);
          }
        }

        .login-btn {
          height: 50px;
          background-color: rgb(59, 72, 89);
          font-size: 20px;
        }
      }

      .divider {
        .line {
          border-bottom: 1px solid rgb(214, 222, 228);
        }
      }

      .other-login-item {
        border-radius: 20px;

        img {
          width: 40px;
          height: 40px;
        }
      }
    }
  }
}

// .box {
//   width: 100vw;
//   height: 100vh;
//   background-color: rgb(29, 67, 89);
// }
// .box .content .login-wrapper h1 {
//   text-align: center;
// }
// .box .content .login-wrapper .login-form .form-item {
//   margin: 20px 0;
// }
// .box .content .login-wrapper .login-form .form-item span {
//   display: block;
//   margin: 5px 20px;
//   font-weight: 100;
// }
// .box .content .login-wrapper .login-form .form-item .input-item {
//   width: 100%;
//   border-radius: 40px;
//   padding: 20px;
//   box-sizing: border-box;
//   font-size: 20px;
//   font-weight: 200;
// }
// .box .content .login-wrapper .login-form .form-item .input-item:focus {
//   outline: none;
// }
// .box .content .login-wrapper .login-form .login-btn {
//   width: 100%;
//   border-radius: 40px;
//   color: #fff;
//   border: 0;
//   font-weight: 100;
//   margin-top: 10px;
//   cursor: pointer;
// }
</style>
