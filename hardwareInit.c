#include "hardwareInit.h"

#include "sam4n_base/Drivers/eefc.h"
#include "sam4n_base/Drivers/pmc.h"
#include "sam4n_base/Drivers/pio.h"


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
	
	
}