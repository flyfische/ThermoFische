#ifndef _THERMO_LOGGER_H__
#define _THERMO_LOGGER_H__
#include "Arduino.h"
#include "HardwareTimer.h"
class ThermoLogger : public Print {
public:
	ThermoLogger();
	size_t write(uint8_t);
	size_t write(const uint8_t *buffer, size_t size);
	static uint32_t seconds;
	void set_serial(SerialUART *serial);
private:
	SerialUART *uart;

};

#endif
