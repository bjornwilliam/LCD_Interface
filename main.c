#include "sam4n_base/FreeRTOS/include/FreeRTOS.h"
#include "sam4n_base/FreeRTOS/include/task.h"
#include "FreeRTOSConfig.h"

#include <sam.h>


int main(void)
{
    /* Initialize the SAM system */
    SystemInit();

    /* Replace with your application code */
    while (1) 
    {
    }
}



void vAssertCalled( uint32_t ulLine, const char *pcFile )
{
/* The following two variables are just to ensure the parameters are not
optimised away and therefore unavailable when viewed in the debugger. */
volatile uint32_t ulLineNumber = ulLine, ulSetNonZeroInDebuggerToReturn = 0;
volatile const char * const pcFileName = pcFile;

	taskENTER_CRITICAL();
	while( ulSetNonZeroInDebuggerToReturn == 0 )
	{
		/* If you want to set out of this function in the debugger to see the
		assert() location then set ulSetNonZeroInDebuggerToReturn to a non-zero
		value. */
	}
	taskEXIT_CRITICAL();

	( void ) pcFileName;
	( void ) ulLineNumber;
}
/*-----------------------------------------------------------*/


void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
	( void ) pcTaskName;
	( void ) pxTask;

	/* Run time stack overflow checking is performed if
	configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook	function is
	called if a stack overflow is detected. */
	vAssertCalled( __LINE__, __FILE__ );
}