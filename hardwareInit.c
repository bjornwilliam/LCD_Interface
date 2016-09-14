#include "sam4n_base/FreeRTOS/include/FreeRTOS.h"
#include "sam4n_base/FreeRTOS/include/semphr.h"

#include "hardwareInit.h"
#include "MCU_config.h"

#include "sam4n_base/Drivers/eefc.h"
#include "sam4n_base/Drivers/pmc.h"
#include "sam4n_base/Drivers/pio.h"
#include "sam4n_base/Drivers/spi.h"
#include "sam4n_base/Drivers/twi.h"



void hardwareInit() {
	WDT->WDT_MR |= 1<<15; // Disable Watch dog timer
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
		.bits_per_transfer = 8,
		.delay_between_two_consecutive_transfers = 0,
		.peripheral_clock_hz = CPU_CLOCK_FREQ_HZ,
		.spi_baudRate_hz = 12000000,
		.time_until_first_valid_SPCK = 0,
		.chip_select_active_after_transfer = true,
		.spi_mode = MODE_0
	};
	spi_handlerIsDoneSempahore	= xSemaphoreCreateBinary();
	spi_mutex					= xSemaphoreCreateMutex();
	spi_masterInit(SpiMasterSettings);
	spi_chipSelectInit(Spi_cs1);
	//SPI->SPI_MR |= 1 << 7; // LOCAL LOOPBACK
	//SPI->SPI_CR |= 1 << 24;
	
	// TWI INIT
	struct twi_options_t twi_options = {
		.master_clk = CPU_CLOCK_FREQ_HZ,
		.speed = 160000,
		.smbus = 0
		};
	twi_init(twi_options);
}