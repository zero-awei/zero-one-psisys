package com.zeroone.star.project.jurisdiction;

import com.zeroone.star.project.query.jurisdiction.JurisdictionQuery;

import java.util.List;

public interface JurisdictionApis {
    /**
     * 根据角色id查询角色所有权限
     *
     * @param RId 角色id
     * @return 角色权限列表
     */
    List<JurisdictionQuery> showJurisdiction(int RId);

    /**
     * 根据用户选择的权限增加该用户的权限
     * @param listJurisdiction
     * @return 是否添加成功
     */
    Boolean addJurisdiction(List<String> listJurisdiction);

    /**
     * 根据用户的角色id和要删除的权限id，删除权限
     * @param RId
     * @param JId
     * @return 是否删除成功
     */
    Boolean deleteJurisdiction (int RId,int JId);
}
