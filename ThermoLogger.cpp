#include "ThermoLogger.h"
uint32_t ThermoLogger::seconds = 0;

ThermoLogger::ThermoLogger(void) {

}

void ThermoLogger::set_serial(SerialUART *serial) {
	this->uart = serial;
	serial->begin(115200);
	serial->println("Initialized.");
}

size_t ThermoLogger::write(uint8_t buff) {
	uart->printf("[%d]ThermoLogger> ", ThermoLogger::seconds);
	uart->write(buff);
}
size_t ThermoLogger::write(const uint8_t *buffer, size_t size) {
	if (size > 1 && buffer[1] != '\n') {
		uart->printf("[%d]ThermoLogger> ", ThermoLogger::seconds);
	}
	uart->print((char*)buffer);
}