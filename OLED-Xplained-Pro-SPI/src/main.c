#include <asf.h>

#include "gfx_mono_ug_2832hsweg04.h"
#include "gfx_mono_text.h"
#include "sysfont.h"

int main (void)
{
	board_init();
	io_init();
	sysclk_init();
	delay_init();
	gfx_mono_ssd1306_init();
	WDT->WDT_MR = WDT_MR_WDDIS;

	// TC:
	LED_init(1);
	TC_init(TC0, ID_TC1, 1, 2);
	tc_start(TC0, 1);
	
	//RTC:
	LED_init(0);
	
	calendar rtc_initial = {2018, 3, 19, 12, 15, 45 ,1};
	RTC_init(RTC, ID_RTC, rtc_initial, RTC_IER_ALREN);
	
	uint32_t current_hour, current_min, current_sec;
	uint32_t current_year, current_month, current_day, current_week;
	rtc_get_time(RTC, &current_hour, &current_min, &current_sec);
	rtc_get_date(RTC, &current_year, &current_month, &current_day, &current_week);
	
	rtc_set_date_alarm(RTC, 1, current_month, 1, current_day);
	rtc_set_time_alarm(RTC, 1, current_hour, 1, current_min, 1, current_sec + 20);
	
	//RTT:
	RTT_init(4, 16, RTT_MR_ALMIEN);

	while(1) {
		pmc_sleep(SAM_PM_SMODE_SLEEP_WFI);
			
	}
}
