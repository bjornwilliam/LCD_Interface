#include "../sam4n_base/FreeRTOS/include/FreeRTOS.h"
#include "../sam4n_base/FreeRTOS/include/timers.h"

#include "Task_TestScreen.h"

#include "../sam4n_base/Drivers/spi.h"
#include "../sam4n_base/Drivers/ili9341/ili9341.h"
#include "../Bitmaps/seven.h"
#include "../Bitmaps/searching.h"
void Task_TestScreen() {
	ili9341_init();
	vTaskDelay(150/portTICK_RATE_MS);
	setLandscapeRotation();
	//ili9341_readManufactorID();
	//ili9341_readManufactorID();
	//ili9341_adjust_brightness(0);
	//ili9341_draw_vertical_line(100,20,100,0);
	//ili9341_draw_horizontal_line(100,20,100,0);
	
	ili9341_draw_image(seven,200,150,68,75);
	//TEST_drawImage(Searching,10,10,229,25);
	while(1) {		
// 		ili9341_enter_standby();		
// 		vTaskDelay(1000/portTICK_RATE_MS);
// 		ili9341_exit_standby();
 		vTaskDelay(1000/portTICK_RATE_MS);		
	}	
}

