
import cn.hutool.core.bean.BeanUtil;
import com.zeroone.star.prepayment.entity.FinPayment;
import com.zeroone.star.prepayment.mapper.FinPaymentMapper;
import com.zeroone.star.prepayment.service.IFinPaymentService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.dto.prepayment.AuditDTO;
import com.zeroone.star.project.dto.prepayment.ModifyDTO;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.stereotype.Service;

import javax.jws.soap.SOAPBinding;
import java.time.LocalDateTime;
import java.util.Date;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.prepayment.entity.FinPayment;
import com.zeroone.star.prepayment.entity.FinPaymentEntry;
import com.zeroone.star.prepayment.mapper.FinPaymentMapper;
import com.zeroone.star.prepayment.service.IFinPaymentEntryService;
import com.zeroone.star.prepayment.service.IFinPaymentService;
import com.zeroone.star.project.dto.prepayment.FinPaymentEntryDTO;
import com.zeroone.star.project.dto.prepayment.PrepaymentDTO;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.Random;

/**
 * <p>
 * 付款单 服务实现类
 * </p>
 *
 * @author zhd
 * @since 2023-02-18
 */
@Service
public class FinPaymentServiceImpl extends ServiceImpl<FinPaymentMapper, FinPayment> implements IFinPaymentService {

    @Autowired
    FinPaymentMapper finPaymentMapper;
    @Autowired
    IFinPaymentEntryService finPaymentEntryService;

    /**
     * 修改付款单
     * author forever爱
     */
    @Override
    public boolean updateById(ModifyDTO modifyDTO, UserDTO userDTO) {
        FinPayment finPayment = new FinPayment();
        BeanUtil.copyProperties(modifyDTO, finPayment);
        //时间
        finPayment.setUpdateTime(LocalDateTime.now());
        //用户信息
        finPayment.setUpdateBy(userDTO.getUsername());
        return updateById(finPayment);
    }

    /**
     * 审核采购预付单功能
     * param auditDTO 审核DTO
     * return 查询结果
     * author forever爱
     */
    @Override
    public JsonVO<String> auditById(AuditDTO auditDTO, UserDTO userDTO) {
        FinPayment finPayment = new FinPayment();
        BeanUtil.copyProperties(auditDTO, finPayment);
        //审核生效时间、修改时间
        finPayment.setUpdateTime(LocalDateTime.now());
        finPayment.setEffectiveTime(LocalDateTime.now());
        //审核人、修改人信息
        finPayment.setApprover(userDTO.getUsername());
        finPayment.setUpdateBy(userDTO.getUsername());
        boolean flag = updateById(finPayment);
        if (flag) {
            return JsonVO.success("修改成功");
        }
        return JsonVO.fail("修改失败");
    }
    /**
     * 添加采购预付单
     * Author: Kong
     */
    @Override
    @Transactional
    public int prepay(PrepaymentDTO prepaymentDTO){
        //生成19位id
        long timestamp1 = System.currentTimeMillis(); // 毫秒级时间戳
        int randNum1 = new Random().nextInt(1000000000); // 生成9位随机数
        String uniqueId1 = timestamp1 + String.format("%09d", randNum1); // 将时间戳和随机数拼接起来
        String id1 = uniqueId1.substring(0, 19);// 截取前19位作为最终的唯一ID
        FinPayment finPayment = new FinPayment();
        BeanUtils.copyProperties(prepaymentDTO,finPayment);
        finPayment.setId(id1);
        System.out.println(finPayment.getAmt());
        System.out.println(finPayment.getBillDate());
        int res = finPaymentMapper.insert(finPayment);
        int count=0;
        for (FinPaymentEntryDTO finPaymentEntryDTO:prepaymentDTO.getFinPaymentEntryList()){
            //生成19位id
            long timestamp2 = System.currentTimeMillis(); // 毫秒级时间戳
            int randNum2 = new Random().nextInt(1000000000); // 生成9位随机数
            String uniqueId2 = timestamp2 + String.format("%09d", randNum2); // 将时间戳和随机数拼接起来
            String id2 = uniqueId2.substring(0, 19);// 截取前19位作为最终的唯一ID
            FinPaymentEntry finPaymentEntry = new FinPaymentEntry();
            BeanUtils.copyProperties(finPaymentEntryDTO,finPaymentEntry);
            finPaymentEntry.setId(id2);
            finPaymentEntry.setMid(id1);
            finPaymentEntry.setBillNo(prepaymentDTO.getBillNo());//获取单号
            int i = finPaymentEntryService.insert(finPaymentEntry);
            if(i==1) count++;
        }
        if (res!=1 || count!=prepaymentDTO.getFinPaymentEntryList().size()) return 0;
        return 1;
    }
}
