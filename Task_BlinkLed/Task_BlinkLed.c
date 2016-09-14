#include "../sam4n_base/FreeRTOS/include/FreeRTOS.h"
#include "../sam4n_base/FreeRTOS/include/timers.h"

#include "../sam4n_base/Drivers/pio.h"

void Task_BlinkLed() {
	
	while (1) {
		pio_enableOutput(PIOB,14);
		vTaskDelay(2000);
		pio_disableOutput(PIOB,14);
		vTaskDelay(2000);
	}
}

