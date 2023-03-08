package com.zeroone.star.login.controller;

import cn.hutool.captcha.CaptchaUtil;
import cn.hutool.captcha.LineCaptcha;
import cn.hutool.core.bean.BeanUtil;
import cn.hutool.core.util.StrUtil;
import com.anji.captcha.model.common.ResponseModel;
import com.anji.captcha.model.vo.CaptchaVO;
import com.anji.captcha.service.CaptchaService;
import com.zeroone.star.login.entity.SysRole;
import com.zeroone.star.login.entity.SysUser;
import com.zeroone.star.login.service.*;
import com.zeroone.star.login.utils.CommonUtils;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.components.easyexcel.constant.AuthConstant;
import com.zeroone.star.project.components.easyexcel.constant.RedisConstant;
import com.zeroone.star.project.dto.login.LoginDTO;
import com.zeroone.star.project.dto.login.Oauth2TokenDTO;
import com.zeroone.star.project.login.LoginApis;
import com.zeroone.star.project.utils.redis.RedisUtils;
import com.zeroone.star.project.utils.tree.NodeMapper;
import com.zeroone.star.project.utils.tree.TreeNode;
import com.zeroone.star.project.utils.tree.TreeUtils;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.TreeNodeVO;
import com.zeroone.star.project.vo.login.LoginVO;
import com.zeroone.star.project.vo.login.MenuTreeVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.concurrent.TimeUnit;

import static com.zeroone.star.project.vo.JsonVO.fail;

/**
 * <p>
 * 描述：登录接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Slf4j
@RestController
@RequestMapping("login")
@Api(tags = "login")
public class LoginController implements LoginApis {
    @Resource
    OauthService oAuthService;
    @Resource
    UserHolder userHolder;
    @Resource
    ISysUserService userService;
    @Resource
    ISysRoleService roleService;
    @Resource
    private RedisUtils redisUtils;
    @Resource
    private CaptchaService captchaService;

    @ApiOperation(value = "授权登录")
    @PostMapping("auth-login")
    @Override
    public JsonVO<Oauth2TokenDTO> authLogin(LoginDTO loginDTO) {
        CaptchaVO captchaVO = new CaptchaVO();
        captchaVO.setCaptchaVerification(loginDTO.getCode());
        ResponseModel response = captchaService.verification(captchaVO);
        if (!response.isSuccess()) {
            JsonVO<Oauth2TokenDTO> fail = fail(null);
            fail.setMessage(response.getRepCode() + response.getRepMsg());
            //验证码校验失败，返回信息告诉前端
            //repCode  0000  无异常，代表成功
            //repCode  9999  服务器内部异常
            //repCode  0011  参数不能为空
            //repCode  6110  验证码已失效，请重新获取
            //repCode  6111  验证失败
            //repCode  6112  获取验证码失败,请联系管理员
            return fail;
        }

        // 2、账号密码认证
        Map<String, String> params = new HashMap<>(5);
        params.put("grant_type", "password");
        params.put("client_id", loginDTO.getClientId());
        params.put("client_secret", AuthConstant.CLIENT_PASSWORD);
        params.put("username", loginDTO.getUsername());
        params.put("password", loginDTO.getPassword());

        // 3. 调用远程接口，获取Token
        JsonVO<Oauth2TokenDTO> oauth2Token = oAuthService.postAccessToken(params);

        // 4. 将授权token存储到Redis中，记录登录状态
        String userTokenKey = CommonUtils.generateRedisTokenKey(oauth2Token.getData().getToken());
        if (redisUtils.add(userTokenKey, 1, 1L, TimeUnit.HOURS) < 0) {
            return fail(oauth2Token.getData(), ResultStatus.SERVER_ERROR);
        }

        // 5. 返回结果token
        return oauth2Token;
    }

    /**
     * @author Gerins
     * @param oauth2TokenDTO Token数据对象
     * @return
     */
    @ApiOperation(value = "刷新登录")
    @PostMapping("refresh-token")
    @Override
    public JsonVO<Oauth2TokenDTO> refreshToken(Oauth2TokenDTO oauth2TokenDTO) {
        // 1. 判断Redis服务器是否存在token
        String oldTokenKey = CommonUtils.generateRedisTokenKey(oauth2TokenDTO.getToken());
        if (!redisUtils.isExist(oldTokenKey)) {
            return fail(null, ResultStatus.UNAUTHORIZED);
        }

        // 2. 封装参数
        Map<String, String> params = new HashMap<>(4);
        params.put("grant_type", "refresh_token");
        params.put("client_id", oauth2TokenDTO.getClientId());
        params.put("client_secret", "123456");
        params.put("refresh_token", oauth2TokenDTO.getRefreshToken());

        // 3. 调用远程接口
        JsonVO<Oauth2TokenDTO> refreshedTokenDTO = oAuthService.postAccessToken(params);
        // 检查将要使用的参数是不是对的
        log.info("oAuthService.postAccessToken required data: {}", refreshedTokenDTO.getData().getToken());

        // 4. 用刷新后的Token更新Redis数据
        String refreshedTokenKey = CommonUtils.generateRedisTokenKey(refreshedTokenDTO.getData().getToken());
        if (redisUtils.add(refreshedTokenKey, 1, 1L, TimeUnit.HOURS) < 0) {
            return fail(null, ResultStatus.SERVER_BUSY);
        }
        // 当添加新token之后才删除，这样避免删除成功，但是添加失败后，导致token被误删除
        if (redisUtils.del(oldTokenKey) < 0) {
            return fail(null, ResultStatus.SERVER_BUSY);
        }
        // TODO:未实现注销凭证验证
        // 5. 返回结果
        return refreshedTokenDTO;

    }

    @ApiOperation(value = "获取当前用户")
    @GetMapping("current-user")
    @Override
    public JsonVO<LoginVO> getCurrUser() {
        UserDTO currentUser;
        try {
            currentUser = userHolder.getCurrentUser();
        } catch (Exception e) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), e.getMessage());
        }
        if (currentUser == null) {
            return fail(null);
        } else {

            SysUser user = userService.getById(currentUser.getId());
            currentUser.setId(user.getId());
            currentUser.setUsername(user.getUsername());
            // 1正常 2冻结
            currentUser.setIsEnabled(user.getStatus());

            /*
            查询用户拥有的角色列表
             */
            List<SysRole> sysRoles = roleService.listRoleByUserId(currentUser.getId());
            List<String> roleNameList = new ArrayList<>();
            for (SysRole sysRole : sysRoles) {
                roleNameList.add(sysRole.getRoleName());
            }

            currentUser.setRoles(roleNameList);

            /*
            通过用户名查询机构编码
             */

            String orgCode = roleService.getOrgCodeByUsername(currentUser.getUsername());
            currentUser.setOrgCode(orgCode);

            //TODO:这里需要根据业务逻辑接口，重新实现
            LoginVO vo = new LoginVO();
            BeanUtil.copyProperties(currentUser, vo);
            return JsonVO.success(vo);
        }
    }

    @ApiOperation(value = "修改密码")
    @GetMapping("change-password")
    @Override
    public JsonVO<String> changePassword(LoginDTO loginDTO) {

        // 当前用户名
        String username = loginDTO.getUsername();
        // 要修改的密码
        String loginDTOPassword = loginDTO.getPassword();

        // 查询数据库，查看当前密码
        String currentPassword = userService.getCurrentPassword(username);

        BCryptPasswordEncoder passwordEncoder = new BCryptPasswordEncoder();

        if (passwordEncoder.matches(loginDTOPassword, currentPassword)) {
            return fail("修改的密码不能与原密码相同！");
        }

        String password = passwordEncoder.encode(loginDTOPassword);
        Boolean isUpdate = userService.updatePassword(username, password);
        if (isUpdate == true) {
            return JsonVO.success("修改成功！");
        }
        return fail("修改失败！");
    }

    @ApiOperation(value = "退出登录")
    @GetMapping("logout")
    @Override
    public JsonVO<String> logout() {
        // 1. 获取当前用户Token
        String userToken;
        try {
            userToken = userHolder.getCurrentUserToken();
        } catch (Exception e) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), e.getMessage());
        }
        if (StrUtil.isBlank(userToken)) {
            return fail(ResultStatus.UNAUTHORIZED.getMessage(), ResultStatus.UNAUTHORIZED);
        }

        // 2. 移除当前用户Token
        String userTokenKey = CommonUtils.generateRedisTokenKey(userToken);
        if (redisUtils.del(userTokenKey) < 0) {
            return fail(ResultStatus.SERVER_ERROR.getMessage(), ResultStatus.SERVER_ERROR);
        }

        return JsonVO.success("退出操作成功" + ResultStatus.SUCCESS.getMessage());

    }

    @Resource
    ISysMenuService menuService;

    @Resource
    NodeMapper<MenuTreeVO> nodeMapper;

    @ApiOperation(value = "获取菜单")
    @GetMapping("get-menus")
    @Override
    public JsonVO<List<TreeNodeVO<MenuTreeVO>>> getMenus() throws Exception {
        //1 获取当前用户
        UserDTO currentUser = userHolder.getCurrentUser();
        //2 获取当前用户拥有的菜单
        List<MenuTreeVO> menus = menuService.listMenuByRoleCode(currentUser.getRoles());
        //3 转换树形结构
        List<TreeNode<MenuTreeVO>> treeNodes = TreeUtils.listToTree(menus, nodeMapper);
        //4 转换成VO数据
        List<TreeNodeVO<MenuTreeVO>> tree = new ArrayList<>();
        for (TreeNode<MenuTreeVO> sub : treeNodes) {
            TreeNodeVO<MenuTreeVO> one = new TreeNodeVO<>();
            BeanUtil.copyProperties(sub, one);
            tree.add(one);
        }
        return JsonVO.success(tree);
    }


    @Value("${captcha.width}")
    private int captchaWidth;

    @Value("${captcha.height}")
    private int captchaHeight;

    @Value("${captcha.codeCount}")
    private int codeCount;

    @Value("${captcha.lineCount}")
    private int lineCount;

}
