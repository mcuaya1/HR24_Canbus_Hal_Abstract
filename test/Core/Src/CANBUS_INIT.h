#ifndef CANBUS_INIT_H
#define CANBUS_H

#include "stm32f7xx_hal_def.h"

class CANBUS(){

	private:
		CAN_HandleTypeDef canbus;

	public:
		CANBUS(){
			this.canbus.Instance = CAN1;
			// filters
			// Don't know if we need all these
			CAN_FilterTypeDef canfilterconfig;
			canfilterconfig.FilterActivation = CAN_FILTER_ENABLE;
			canfilterconfig.FilterBank = 18;  // which filter bank to use from the assigned ones
			canfilterconfig.FilterFIFOAssignment = CAN_FILTER_FIFO0;
			canfilterconfig.FilterIdHigh = 0x446<<5;
			canfilterconfig.FilterIdLow = 0;
			canfilterconfig.FilterMaskIdHigh = 0x446<<5;
			canfilterconfig.FilterMaskIdLow = 0x0000;
			canfilterconfig.FilterMode = CAN_FILTERMODE_IDMASK;
			canfilterconfig.FilterScale = CAN_FILTERSCALE_32BIT;
			canfilterconfig.SlaveStartFilterBank = 20;  // how many filters to assign to the CAN1 (master can)
			HAL_CAN_ConfigFilter(&canbus1, &canfilterconfig);
		};
		//Starts the Can
		bool StartCan(){
			 if (HAL_CAN_ConfigFilter(&canbus, &canfilterconfig) != HAL_OK) {
			    Error_Handler();
			  }

			  if (HAL_CAN_RegisterCallback(&canbus, HAL_CAN_RX_FIFO0_MSG_PENDING_CB_ID, can_irq)) {
			    Error_Handler();
			  }

			  if (HAL_CAN_Start(&canbus) != HAL_OK) {
			    Error_Handler();
			  }

			  if (HAL_CAN_ActivateNotification(&canbus, CAN_IT_RX_FIFO0_MSG_PENDING) != HAL_OK) {
			    Error_Handler();
			  }
			return true;
		}

}

#endif
