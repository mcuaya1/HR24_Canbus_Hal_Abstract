#ifndef CANBUS_INIT_H
#define CANBUS_H

#include "stm32f7xx_hal_def.h"

class CANBUS(){

	private:
		CAN_HandleTypeDef canbus;

	public:
		CANBUS(){
			this.canbus.Instance = CAN1;
		};
		//Starts the Can
		bool StartCan(){
			HAL_CAN_START(&canbus);
			return true;
		}

}

#endif
