package com.zeroone.star.project.dto.paymentManager;

public class UpdateBillStageDto {
    private Long id;
    private String billStage;


    @Override
    public String toString() {
        return "UpdateBillStageDto{" +
                "id=" + id +
                ", billStage='" + billStage + '\'' +
                '}';
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getBillStage() {
        return billStage;
    }

    public void setBillStage(String billStage) {
        this.billStage = billStage;
    }
}
