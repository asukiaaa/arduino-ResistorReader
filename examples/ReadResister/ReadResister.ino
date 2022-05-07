#include <ResistorReader_asukiaaa.hpp>

#define PIN_RESISTOR 15
#define PIN_RESISTOR_POSITION ResistorReader_asukiaaa::PinPosition::Downer
#define RESISTOR_FIXED_UPPER 0
#define RESISTOR_FIXED_DOWNER 10

//                      PIN_RESISTOR on Upper
//                      |
// VCC - Upper resistor - Adjustable resistor - Downer resistor - GND

//                                            PIN_RESISTOR on Downer
//                                            |
// VCC - Upper resistor - Adjustable resistor - Downer resistor - GND

ResistorReader_asukiaaa::Core resistorReader(PIN_RESISTOR,
                                             PIN_RESISTOR_POSITION,
                                             RESISTOR_FIXED_UPPER,
                                             RESISTOR_FIXED_DOWNER);

void setup() { Serial.begin(115200); }

void loop() {
  resistorReader.update();
  Serial.println("adc: " + String(resistorReader.getCurrentAdc()));
  Serial.println("resistor: " + String(resistorReader.getCurrentResistor()));
  Serial.println("at " + String(millis()));
  Serial.println();
  delay(1000);
}
