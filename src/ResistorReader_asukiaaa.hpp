#pragma once

#include <Arduino.h>

#ifndef ANALOG_ASUKIAAA_ADC_MAX
#ifdef ESP32
#define ANALOG_ASUKIAAA_ADC_MAX 4095
#else
#define ANALOG_ASUKIAAA_ADC_MAX 1023
#endif
#endif

namespace ResistorReader_asukiaaa {

enum class PinPosition {
  Downer,
  Upper,
};

double calcResistorFromAnalogRate(double rateAnalog, PinPosition pinPosition,
                                  float resistorFixedUpper,
                                  float resistorFixedDowner) {
  if (pinPosition == PinPosition::Downer) {
    return (double)resistorFixedDowner * (1 - rateAnalog) / rateAnalog -
           resistorFixedUpper;
  } else {
    return (double)resistorFixedUpper * rateAnalog / (1 - rateAnalog) -
           resistorFixedDowner;
  }
}

class Core {
 public:
  Core(int pinRead, PinPosition pinPosition, float resistorFixedUpper,
       float resistorFixedDowner, uint16_t adcMax = ANALOG_ASUKIAAA_ADC_MAX)
      : pinRead(pinRead),
        pinPosition(pinPosition),
        resistorFixedUpper(resistorFixedUpper),
        resistorFixedDowner(resistorFixedDowner),
        adcMax(adcMax) {}

  void update() {
    currentAdc = analogRead(pinRead);
    currentResistor =
        calcResistorFromAnalogRate((double)currentAdc / adcMax, pinPosition,
                                   resistorFixedUpper, resistorFixedDowner);
  }

  float getCurrentResistor() { return currentResistor; }
  uint16_t getCurrentAdc() { return currentAdc; }

 private:
  const int pinRead;
  const PinPosition pinPosition;
  const float resistorFixedUpper;
  const float resistorFixedDowner;
  const uint16_t adcMax;
  float currentResistor = 0;
  uint16_t currentAdc = 0;
};

}  // namespace ResistorReader_asukiaaa
