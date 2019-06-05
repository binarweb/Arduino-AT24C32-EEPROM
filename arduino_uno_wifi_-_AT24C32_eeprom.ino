#include "src/AT24Cx/AT24Cx.h"

AT24C32 eeprom;
bool done = false;
const unsigned long one_long = 4000000000; // 4 billions

#define SERIAL_BAUDRATE 115200

void setup() {
	Serial.begin(SERIAL_BAUDRATE);

	Serial.println("AT24C32 read/write test");
	Serial.println("----------------------");
}

void loop() {
	if (done) return;

	/*
	// WRITE TEST
	unsigned int address;

	// write char
	address = 20;
	byte data = 88; // max 8 bits = 255
	eeprom.write(address, data);

	byte c = eeprom.read(address);
	Serial.println(c);

	// write int
	address = 21;
	unsigned int data2 = 60001; // max 16 bits = 65535
	eeprom.writeInt(address, data2);

	unsigned int c2 = eeprom.readInt(address);
	Serial.println(c2);

	// write long
	address = 23;
	unsigned long data3 = 4000000001; // max 32 bits = 4294967295
	eeprom.writeLong(address, data3);

	unsigned long c3 = eeprom.readLong(address);
	Serial.println(c3);
	*/

	// ERASE THE EEPROM
	const int max_size = 32 * 256; // 32 bytes, 256 pages
	unsigned int index;
	// Serial.println("Erasing EEPROM...");
	// for (int i = 0; i < max_size; i++) {
		// index = i % 1000;
		// if (index == 0) {
			// Serial.print("i: ");
			// Serial.print(i);
			// Serial.println();
		// }
		// eeprom.write(i, 0);
	// }
	// Serial.println("done!");

	// READING THE WHOLE EEPROM
	Serial.println("Reading the whole EEPROM...");
	byte c;
	for (int i = 0; i < max_size; i++) {
		// index = i % 1000;
		// if (index == 0) {
			// Serial.print("i: ");
			// Serial.print(i);
			// Serial.println();
		// }
		c = eeprom.read(i);
		Serial.print("[");
		Serial.print(0 + i);
		Serial.print("] = ");
		Serial.println(c);
	}
	Serial.println("done!");

	done = true;
}