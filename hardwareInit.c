#include "sam4n_base/FreeRTOS/include/FreeRTOS.h"
#include "sam4n_base/FreeRTOS/include/semphr.h"

#include "hardwareInit.h"

#include "sam4n_base/Drivers/eefc.h"
#include "sam4n_base/Drivers/pmc.h"
#include "sam4n_base/Drivers/pio.h"
#include "sam4n_base/Drivers/spi.h"



void hardwareInit() {
	// PMC 
	init_flash();
	struct PmcInit pmcInit = {
		.freq = EXTERNAL,
		.css = PLLA_CLOCK,
		.pres = CLK_1,
		.divide = 3,
		.multiply = 25
	};
	pmc_init(pmcInit);
	
	pio_init();
	
	// SPI INIT
	struct SpiMaster SpiMasterSettings = {
		.NVIC_spi_interrupt_priority = 11,
		.cs_0 = none0,
		.cs_1 = PC4,
		.cs_2 = none2,
		.cs_3 = none3
	};
	struct SpiSlaveSettings Spi_cs1 = {
		.chip_select = NPCS1,
		.bits_per_transfer = 9,
		.delay_between_two_consecutive_transfers = 0,
		.peripheral_clock_hz = 100000000,
		.spi_baudRate_hz = 10000000,
		.time_until_first_valid_SPCK = 0,
		.spi_mode = MODE_0
	};
	spi_handlerIsDoneSempahore	= xSemaphoreCreateBinary();
	spi_mutex					= xSemaphoreCreateMutex();
	spi_masterInit(SpiMasterSettings);
	spi_chipSelectInit(Spi_cs1);
	//SPI->SPI_MR |= 1 << 7;
	//SPI->SPI_CR |= 1 << 24;
	
	
}