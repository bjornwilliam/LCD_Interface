#include "../sam4n_base/FreeRTOS/include/FreeRTOS.h"
#include "../sam4n_base/FreeRTOS/include/timers.h"

#include "Task_TestScreen.h"

#include "../sam4n_base/Drivers/spi.h"
#include "../sam4n_base/Drivers/ili9341/ili9341.h"

void Task_TestScreen() {
	xSemaphoreTake(spi_handlerIsDoneSempahore,0);
	ili9341_init();
	
	while(1) {		
		ili9341_enter_standby();
		
		vTaskDelay(1000);
		
	}
	
}

