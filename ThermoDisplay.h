#ifndef _THERMO_DISPLAY_H__
#define _THERMO_DISPLAY_H__
#include "LTDC_F746_Discovery.h" // TFT
#include "TouchScreen_F7_Discovery.h" // TOUCH
#include "FreeMono9pt7b.h" // FreeMono9pt7bBitmaps
#include "ThermoLogger.h"

class ThermoDisplay {
public:
	ThermoDisplay(void);

	void init(void);
	void set_header(char *header);
	void set_status(char *status);
	void set_temp_1(int32_t tmp);
	void set_temp_2(int32_t tmp);
	void set_temp_3(int32_t tmp);
	void set_temp_4(int32_t tmp);
	void set_temp_1(char *tmp = NULL);
	void set_temp_2(char *tmp = NULL);
	void set_temp_3(char *tmp = NULL);
	void set_temp_4(char *tmp = NULL);
	void set_logger(ThermoLogger *logger);
	void redraw(void);
private:
	void draw_v_line(int16_t x, int16_t y, int16_t height, int16_t thickness, uint16_t color);
	void draw_h_line(int16_t x, int16_t y, int16_t height, int16_t thickness, uint16_t color);
	LTDC_F746_Discovery tft;
	uint16_t *buffer;
	uint16_t display_width;
	uint16_t display_height;
	ThermoLogger *logger;
};

#endif