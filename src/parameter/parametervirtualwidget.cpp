#include "parametervirtualwidget.h"


ParameterVirtualWidget::ParameterVirtualWidget(QWidget *parent) : QWidget(parent)
{
    setupUi(this);
}

ParameterVirtualWidget::~ParameterVirtualWidget(){

}

void ParameterVirtualWidget::setPrecision(double number){

    decimalPrecision =0;
    int beforeDecimal=0;
    long double diff, rn; //rn stands for real number
    unsigned long long intNumber, multi = 1;
    number=abs(number);
    while(1){
        rn=number/multi;
        intNumber=rn;
        if(intNumber==0){
            break;
        }
        beforeDecimal++;
        multi=multi*10;
    }
    multi=1;
    while(1)
    {
        rn = (number * multi);
        intNumber = rn;  //the fractional part will be truncated here
        diff = rn - intNumber;
        if(diff == 0 || decimalPrecision>15-beforeDecimal)
            break;
       if(diff > 0.9 || decimalPrecision>15-beforeDecimal){
            break;
        }
        multi = multi * 10;
        decimalPrecision++;
    }

}
