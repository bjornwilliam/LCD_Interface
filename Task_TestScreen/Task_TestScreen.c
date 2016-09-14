#include "../sam4n_base/FreeRTOS/include/FreeRTOS.h"
#include "../sam4n_base/FreeRTOS/include/timers.h"

#include "Task_TestScreen.h"

#include "../sam4n_base/Drivers/spi.h"
#include "../sam4n_base/Drivers/ili9341/ili9341.h"

void Task_TestScreen() {
	xSemaphoreTake(spi_handlerIsDoneSempahore,0);
	ili9341_init();
	vTaskDelay(10/portTICK_RATE_MS);
	//ili9341_drawPixel(50,50,500);
	ili9341_drawVLine(50,50,60,0x40A9A6);
	
	while(1) {		
// 		ili9341_enter_standby();		
// 		vTaskDelay(1000/portTICK_RATE_MS);
// 		ili9341_exit_standby();
 		vTaskDelay(1000/portTICK_RATE_MS);
		
	}
	
}

