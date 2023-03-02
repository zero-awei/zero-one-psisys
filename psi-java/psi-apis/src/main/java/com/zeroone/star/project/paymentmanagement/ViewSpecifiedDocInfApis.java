package com.zeroone.star.project.paymentmanagement;

import com.zeroone.star.project.query.paymentmanagement.ViewSpecifiedDocInfQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.paymentmanagement.ViewSpecifiedDocInfVO;

public interface ViewSpecifiedDocInfApis {
    JsonVO<PageVO<ViewSpecifiedDocInfVO>> viewspecifieddocinf_true(ViewSpecifiedDocInfQuery condition);
    JsonVO<PageVO<ViewSpecifiedDocInfVO>> viewspecifieddocinf_false(ViewSpecifiedDocInfQuery condition);
    JsonVO<PageVO<ViewSpecifiedDocInfVO>> viewspecifieddocinf_red(ViewSpecifiedDocInfQuery condition);

}
