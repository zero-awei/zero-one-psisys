package com.zeroone.star.login.config;

import com.zeroone.star.project.utils.tree.NodeMapper;
import com.zeroone.star.project.utils.tree.TreeNode;
import com.zeroone.star.project.vo.login.MenuTreeVO;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

/**
 * <p>
 * 描述：实现数据转换为树形节点数据匹配接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Configuration
public class TreeConfig {
    @Bean
    public NodeMapper<MenuTreeVO> createMenuNodeMapper() {
        return menu -> {
            TreeNode<MenuTreeVO> treeNode = new TreeNode<>();
            treeNode.setId(menu.getId());
            treeNode.setText(menu.getName());
            if (menu.getParentMenuId() == null) {
                treeNode.setPid(null);
            } else {
                treeNode.setPid(menu.getParentMenuId());
            }
            treeNode.setRaw(menu);
            treeNode.setHref(menu.getPath());
            treeNode.setIcon(menu.getIcon());
            return treeNode;
        };
    }
}
