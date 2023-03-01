<!--
 * @Author: li.ziwei
 * @Date: 2023-02-15 15:14:03
 * @LastEditTime: 2023-03-01 11:48:33
 * @LastEditors: 160405103 1348313766@qq.com
 * @Description: 
 * @FilePath: \psi-frontend\src\components\Home\HeadSideCom.vue
 * 可以输入预定的版权声明、个性签名、空行等
-->
<template>
  <div class="header-nav" style="display:flex">
    <div style="height:59px;line-height:59px;width:180px">
      <SearchCom />
    </div>
  <!-- <div> -->
  <!-- 改造的下拉菜单 -->
  <el-dropdown style="height:59px;line-height:59px;color:white;cursor:pointer">
    <!-- <span class="el-dropdown-link" style="height:59px;"> -->
    <span class="el-dropdown-link">{{ userInfo }}</span>
      <!-- </span> -->
      <template #dropdown>
        <el-dropdown-menu class="newDrop">
          <!-- <el-dropdown-item>
                                      <el-icon>
                                       <component :is="item.icon"></component>
                                         切换部门
                                      </el-icon>
                                    </el-dropdown-item> -->
          <el-dropdown-item @click="modifyPassword">
            <el-icon style="left: 0px;color:black;margin-right:12px">
              <!-- <Fold /> -->
              <Edit />
            </el-icon>
            密码修改
          </el-dropdown-item>
          <el-dropdown-item>
            <el-icon style=" left: 0px;color:black;margin-right:12px">
              <IconSetting />
            </el-icon>
            系统设置
          </el-dropdown-item>
          <el-dropdown-item @click="handleClick">
            <el-icon style="left: 0px;color:black;margin-right:12px">
              <House />
            </el-icon>
            退出登录
          </el-dropdown-item>
        </el-dropdown-menu>
      </template>
    </el-dropdown>

    <!-- </div> -->
    <div style="height:59px;line-height:59px;color:white;margin-left:10px;">当前月度：{{ currentDate }}</div>

    <el-dialog v-model="modifyPasswordVisible" title="修改密码" width="30%" center>
      <el-form :label-position="right" label-width="80px" :model="modifyPasswordData" style="max-width: 460px"
        :rules="rules">
        <el-form-item label="旧密码" prop="oldPassword">
          <el-input type="password" show-password v-model="modifyPasswordData.oldPassword" />
        </el-form-item>
        <el-form-item label="新密码" prop="newPassword">
          <el-input type="password" show-password v-model="modifyPasswordData.newPassword" />
        </el-form-item>
        <el-form-item label="确认密码" prop="newPasswordVerify">
          <el-input type="password" show-password v-model="modifyPasswordData.newPasswordVerify" />
        </el-form-item>
      </el-form>
      <template #footer>
        <span class="dialog-footer">
          <el-button type="primary" @click="handleModifyPassword">确定</el-button>
          <el-button @click="centerDialogVisible = false">
            取消
          </el-button>
        </span>
      </template>
    </el-dialog>
  </div>
</template>


<script setup>
import { reactive, ref, watch } from 'vue'
import { userStore } from '@/stores/user'
import SearchCom from '@/components/Home/SearchCom.vue'
import { ArrowDown } from '@element-plus/icons-vue'
import { useRouter } from 'vue-router'
import { format } from '@/apis/date/index.js'
// 获取router对象
const $router = useRouter()
const store = userStore()
// 用户信息提示
const userInfo = ref(
  '欢迎用户：' + (store.getUser === null ? '游客' : store.getUser.username)
)
/* let panelShow=ref(false)
function handleSearch() {
  panelShow.value=true
  }*/

function handleClick() {
  /* if(command === 'cancel'){
     //清除token
  // Cookie.remove('token')
  //跳到登录页面
  $router.push(/login)
  } */
  $router.push('/')
}

// 菜单数据
const menus = store.getMenus

//获取当前时间
const date = new Date()
const currentDate = ref('')
currentDate.value = format(date, 'yyyy-MM-dd')

const modifyPasswordVisible = ref(false)

const modifyPasswordData = reactive({
  oldPassword: '',
  newPassword: '',
  newPasswordVerify: '',
})

// 校验规则
const checkOldPassword = (rule, value, callback) => {
  if (!value) {
    return callback(new Error('旧密码不能为空'))
  }
}
const checkNewPassword = (rule, value, callback) => {
  if (!value) {
    return callback(new Error('新密码不能为空'))
  }
  if (value === modifyPasswordData.newPassword) {
    return callback(new Error('新密码不能和旧密码相同'))
  }
}
const checkNewPasswordVerify = (rule, value, callback) => {
  if (!value) {
    return callback(new Error('新密码不能为空'))
  }
  if (value !== modifyPasswordData.newPasswordVerify) {
    return callback(new Error('两次密码输入不一致'))
  }
}
const rules = reactive({
  oldPassword: [{ validator: checkOldPassword, trigger: 'blur', required: true }],
  newPassword: [{ validator: checkNewPassword, trigger: 'blur', required: true }],
  newPasswordVerify: [{ validator: checkNewPasswordVerify, trigger: 'blur', required: true }],
})

function modifyPassword() {
  modifyPasswordData.oldPassword = ''
  modifyPasswordData.newPassword = ''
  modifyPasswordData.newPasswordVerify = ''
  modifyPasswordVisible.value = true

}

function handleModifyPassword() {

}
</script>

<style lang="scss" scoped>
.header-nav {
  // padding: 20px;
  background-color: #1890ff;
  height: 59px;
  font-size: 15px;
  display: inline;
}

.el-icon {
  color: white;
  top: px;
  left: -50px;
}

span {
  z-index: 2;
  color: #fff;
  height: 59px;
  font-size: 15px;
  // display:flex;
}

.el-dropdown-link {
  cursor: pointer;
  // display: block;
  // top: -23px;
  height: 40px;
  margin-left: 10px;
  // align-items: center;
}

.newDrop {
  width: 150px;
  text-align: center;
  // left: 30px;
  font-size: 14px;
}

.el-icon {
  left: 0px;
}
</style>
