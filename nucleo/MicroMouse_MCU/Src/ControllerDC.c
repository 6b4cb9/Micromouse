#include"ControllerDC.h"


bool ControllerDC_init(l293d * demo){
	if(L293D_init(demo))
		return true;
	else
		return false;

}

void ControllerDC_break(l293d * demo,int8_t dcIndicator){
	if(dcIndicator < 0)
		L293D_stop(demo->left_dc);
	else if(dcIndicator > 0)
		L293D_stop(demo->right_dc);
	else{
		L293D_stop(demo->right_dc);
		L293D_stop(demo->left_dc);
	}

}

bool ControllerDC_setSpeed(uint16_t speed, single_dc *dc){
	if(speed<0){
		L293D_setDir(dc,-1);
		L293D_setVoltage(dc,speed);
		return true;
	}
	else if(speed>0){
		L293D_setDir(dc,1);
		L293D_setVoltage(dc,speed);
		return true;
	}
	else
		return false;
}

bool ControllerDC_demo(l293d * demo){
	bool isOk = true;
	ControllerDC_init(demo);
	for(uint16_t i = 50; i< 1000; i++){
		ControllerDC_setSpeed(i,demo->left_dc);
		HAL_Delay(20);
	}
	ControllerDC_break(demo,0);
	return isOk;
}
