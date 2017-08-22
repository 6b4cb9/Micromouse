#include "L293D.h"
#define L293D_MAX_VOLTAGE 1024

/*
 * TODO:
 * 1. Dokumentacja pliku .h
 * 2. Pozbycie sie defina z t¹d
 * 3. Demo na lefta
 * 4. Demo na dwa silniki
 * 5. Ustawienie kierunków obrotów w set voltage
 *
 * */
bool L293D_init(l293d * myL293D){
	if(myL293D == 0 || myL293D->left_dc==0 || myL293D->right_dc == 0){
		return false;
	}
	HAL_TIM_PWM_Start(myL293D->left_dc->pwm_gen, myL293D->left_dc->channel);
	L293D_setVoltage(&(myL293D->left_dc), 0);
	HAL_TIM_PWM_Start(myL293D->right_dc->pwm_gen, myL293D->right_dc->channel);
	L293D_setVoltage(&(myL293D->right_dc), 0);
	return true;
}

bool L293D_stop(single_dc * dc){
	if(dc){
		HAL_GPIO_WritePin(dc->DC_A_Port, dc->DC_A_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(dc->DC_B_Port, dc->DC_B_Pin, GPIO_PIN_SET);
		return true;
	}
	return false;
}
;

bool L293D_setDir(single_dc * dc, int8_t dir){
	if(dir == 0){
		return false;
	}
	if(dir > 0){
		HAL_GPIO_WritePin(dc->DC_A_Port, dc->DC_A_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(dc->DC_B_Port, dc->DC_B_Pin, GPIO_PIN_RESET);
	}else{
		HAL_GPIO_WritePin(dc->DC_B_Port, dc->DC_B_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(dc->DC_A_Port, dc->DC_A_Pin, GPIO_PIN_RESET);
	}
	return true;
}

bool L293D_toggleDir(single_dc * dc){
	if(dc){
		HAL_GPIO_TogglePin(dc->DC_A_Port, dc->DC_A_Pin);
		HAL_GPIO_TogglePin(dc->DC_B_Port, dc->DC_B_Pin);
		return true;
	}
	return false;
}

bool L293D_setVoltage(single_dc * dc, uint16_t speed){
	if(dc){
		dc->pwm_gen->Instance->CCR1=speed;
		return true;
	}
	return false;
}

bool L293D_demo(l293d * demo){
	bool isOk = true;
	L293D_setDir(demo->left_dc, 1);
	L293D_setDir(demo->right_dc, 1);
	for (uint16_t i = 0; i< L293D_MAX_VOLTAGE; i++){
		L293D_setVoltage(demo->left_dc, i);
		L293D_setVoltage(demo->right_dc, i);
		HAL_Delay(5);
	}
	HAL_Delay(1000);
	L293D_setDir(demo->left_dc, -1);
	L293D_setDir(demo->right_dc, -1);
	HAL_Delay(2000);
	L293D_toggleDir(demo->left_dc);
	L293D_toggleDir(demo->right_dc);
	HAL_Delay(2000);
	L293D_stop(demo->left_dc);
	L293D_stop(demo->right_dc);
	return isOk;
}
