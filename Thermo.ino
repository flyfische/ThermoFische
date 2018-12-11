#include "ThermoDisplay.h"
ThermoLogger logger;
ThermoDisplay display;
void setup()
{
  SerialUART *serial;
  logger.set_serial(&Serial1);
  display.set_logger(&logger);
  display.init();
  display.redraw();
  display.set_temp_1("156 F");
}
int32_t test_temp = 0;
void loop()
{
  delay(1000);
}
