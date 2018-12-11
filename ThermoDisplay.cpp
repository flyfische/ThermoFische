#include "ThermoDisplay.h"

ThermoDisplay::ThermoDisplay(void) {

}
void ThermoDisplay::set_logger(ThermoLogger *logger) {
	this->logger = logger;
}
void ThermoDisplay::draw_v_line(int16_t x, int16_t y, int16_t height, int16_t thickness, uint16_t color) {
	int16_t i = 0;
	for (i = 0; i < thickness; i++) {
		this->tft.drawFastVLine(x+i,y,height,color);
	}
}
void ThermoDisplay::draw_h_line(int16_t x, int16_t y, int16_t height, int16_t thickness, uint16_t color) {
	int16_t i = 0;
	for (i = 0; i < thickness; i++) {
		this->tft.drawFastHLine(x,y+i,height,color);
	}
}
void ThermoDisplay::set_header(char *header) {
	tft.setCursor(5, 20);
	tft.setTextSize(1);
	tft.println(header);
}
void ThermoDisplay::set_status(char *header) {
	uint16_t x_pos = display_width - (12 * strlen(header));
	tft.setCursor(x_pos, 20);
	tft.setTextSize(1);
	tft.println(header);
}

void ThermoDisplay::set_temp_1(int32_t tmp) {
	logger->println("Setting temp 1");
	tft.setTextSize(4);
  	tft.setCursor(0,115);
	tft.print(tmp);
	tft.println(" F");
  	//tft.println("%d F", tmp);
}
void ThermoDisplay::set_temp_2(int32_t tmp) {
	logger->println("Setting temp 2");
	tft.setTextSize(4);
	tft.setCursor((display_width / 2) + 5,115);

	tft.print(tmp);
	tft.println(" F");
}
void ThermoDisplay::set_temp_3(int32_t tmp) {
	logger->println("Setting temp 3");
	tft.setTextSize(4);
	tft.setCursor(0,((display_height + 30) / 2) + 85);
  	tft.print(tmp);
	tft.println(" F");
}
void ThermoDisplay::set_temp_4(int32_t tmp) {
	logger->println("Setting temp 4");
	tft.setTextSize(4);
	tft.setCursor((display_width / 2) + 5,((display_height + 30) / 2) + 85);
  	tft.print(tmp);
	tft.println(" F");
}
void ThermoDisplay::set_temp_1(char *tmp) {
	tft.setTextSize(4);
  	tft.setCursor(0,115);
  	if (tmp == NULL) {
  		logger->println("No probe detected on temp 1");
  		tft.setTextSize(2);
  		tft.print("NO PROBE");
  	}
  	else {
		logger->println("Setting temp 1");
		tft.print(tmp);
	}
}
void ThermoDisplay::set_temp_2(char *tmp) {
	tft.setTextSize(4);
	tft.setCursor((display_width / 2) + 5,115);
	if (tmp == NULL) {
		logger->println("No probe detected on temp 2");
  		tft.setTextSize(2);
  		tft.print("NO PROBE");
  	}
  	else {
  		logger->println("Setting temp 2\n");
		tft.print(tmp);
	}
}
void ThermoDisplay::set_temp_3(char *tmp) {
	tft.setTextSize(4);
	tft.setCursor(0,((display_height + 30) / 2) + 85);
  	if (tmp == NULL) {
  		logger->println("No probe detected on temp 3");
  		tft.setTextSize(2);
  		tft.print("NO PROBE");
  	}
  	else {
    	logger->println("Setting temp 3");
		tft.print(tmp);
	}}
void ThermoDisplay::set_temp_4(char *tmp) {
	tft.setTextSize(4);
	tft.setCursor((display_width / 2) + 5,((display_height + 30) / 2) + 85);
  	if (tmp == NULL) {
  		logger->println("No probe detected on temp 4");
  		tft.setTextSize(2);
  		tft.print("NO PROBE");
  	}
  	else {
  		logger->println("Setting temp 4");
		tft.print(tmp);
	}
}
void ThermoDisplay::redraw(void) {
  	tft.fillScreen(LTDC_WHITE);
  	tft.setTextColor(LTDC_PURPLE);
  	tft.setFont(&FreeMono9pt7b);
  	set_header("Thermo v0.2");
  	set_status("Connected");

  	// Draw frames
  	this->draw_h_line(0,30,display_width,3, LTDC_PURPLE);
  	this->draw_v_line(display_width / 2,30,display_height,3,LTDC_PURPLE);
  	this->draw_h_line(0, (display_height + 30) / 2, display_width, 3, LTDC_PURPLE);
  	
  	// Setup temperature labels
  	tft.setCursor(5, 50);
  	tft.setTextSize(1);
  	tft.println("Tmp 1");
  	tft.setCursor(5, ((display_height + 30) / 2) + 20);
  	tft.println("Tmp 3");
  	tft.setCursor((display_width / 2) + 5, 50);
  	tft.println("Tmp 2");
  	tft.setCursor((display_width / 2) + 5, ((display_height + 30) / 2) + 20);
  	tft.println("Tmp 4");

}
void ThermoDisplay::init(void) {
	logger->println("Initializing display...");
	display_width = LTDC_F746_ROKOTECH.width;
	display_height = LTDC_F746_ROKOTECH.height;
	this->buffer = (uint16_t *)malloc(LTDC_F746_ROKOTECH.width * LTDC_F746_ROKOTECH.height);
	tft.begin((uint16_t *)buffer);
	redraw();
  	// Set sane defaults
  	set_temp_1();
  	set_temp_2();
  	set_temp_3();
  	set_temp_4();
  	logger->println("Initialized display.");
}