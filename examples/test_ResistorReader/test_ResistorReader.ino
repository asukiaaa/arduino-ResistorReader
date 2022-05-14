#include <unity.h>

#include <ResistorReader_asukiaaa.hpp>

void test_calcResistorFromADC_downer() {
  double resistorAlowwDiff = 0.01;
  float resistorUpper = 0;
  float resistorDowner = 10;
  auto pinPosition = ResistorReader_asukiaaa::PinPosition::Downer;
  float rateAnalog;
  double resistorResult;
  double resistorExpected;

  rateAnalog = 0.5;
  resistorExpected = 10;
  resistorResult = ResistorReader_asukiaaa::calcResistorFromAnalogRate(
      rateAnalog, pinPosition, resistorUpper, resistorDowner);
  TEST_ASSERT_FLOAT_WITHIN(resistorAlowwDiff, resistorExpected,
                            resistorResult);

  rateAnalog = 0.5555;
  resistorExpected = 8;
  resistorResult = ResistorReader_asukiaaa::calcResistorFromAnalogRate(
      rateAnalog, pinPosition, resistorUpper, resistorDowner);
  TEST_ASSERT_FLOAT_WITHIN(resistorAlowwDiff, resistorExpected, resistorResult);

  rateAnalog = 0.6666;
  resistorExpected = 5;
  resistorResult = ResistorReader_asukiaaa::calcResistorFromAnalogRate(
      rateAnalog, pinPosition, resistorUpper, resistorDowner);
  TEST_ASSERT_FLOAT_WITHIN(resistorAlowwDiff, resistorExpected, resistorResult);

  rateAnalog = 0.8333;
  resistorExpected = 2;
  resistorResult = ResistorReader_asukiaaa::calcResistorFromAnalogRate(
      rateAnalog, pinPosition, resistorUpper, resistorDowner);
  TEST_ASSERT_FLOAT_WITHIN(resistorAlowwDiff, resistorExpected, resistorResult);

  rateAnalog = 1;
  resistorExpected = 0;
  resistorResult = ResistorReader_asukiaaa::calcResistorFromAnalogRate(
      rateAnalog, pinPosition, resistorUpper, resistorDowner);
  TEST_ASSERT_FLOAT_WITHIN(resistorAlowwDiff, resistorExpected, resistorResult);
}

void test_calcResistorFromADC_upper() {
  double resistorAlowwDiff = 0.01;
  float resistorUpper = 10;
  float resistorDowner = 0;
  auto pinPosition = ResistorReader_asukiaaa::PinPosition::Upper;
  float rateAnalog;
  double resistorResult;
  double resistorExpected;

  rateAnalog = 0.5;
  resistorExpected = 10;
  resistorResult = ResistorReader_asukiaaa::calcResistorFromAnalogRate(
      rateAnalog, pinPosition, resistorUpper, resistorDowner);
  TEST_ASSERT_FLOAT_WITHIN(resistorAlowwDiff, resistorExpected, resistorResult);

  rateAnalog = 0.4444;
  resistorExpected = 8;
  resistorResult = ResistorReader_asukiaaa::calcResistorFromAnalogRate(
      rateAnalog, pinPosition, resistorUpper, resistorDowner);
  TEST_ASSERT_FLOAT_WITHIN(resistorAlowwDiff, resistorExpected, resistorResult);

  rateAnalog = 0.3333;
  resistorExpected = 5;
  resistorResult = ResistorReader_asukiaaa::calcResistorFromAnalogRate(
      rateAnalog, pinPosition, resistorUpper, resistorDowner);
  TEST_ASSERT_FLOAT_WITHIN(resistorAlowwDiff, resistorExpected, resistorResult);

  rateAnalog = 0.1666;
  resistorExpected = 2;
  resistorResult = ResistorReader_asukiaaa::calcResistorFromAnalogRate(
      rateAnalog, pinPosition, resistorUpper, resistorDowner);
  TEST_ASSERT_FLOAT_WITHIN(resistorAlowwDiff, resistorExpected, resistorResult);

  rateAnalog = 0;
  resistorExpected = 0;
  resistorResult = ResistorReader_asukiaaa::calcResistorFromAnalogRate(
      rateAnalog, pinPosition, resistorUpper, resistorDowner);
  TEST_ASSERT_FLOAT_WITHIN(resistorAlowwDiff, resistorExpected, resistorResult);
}

void test_calcResistorFromADC_pin_downer_resistor_both() {
  double resistorAlowwDiff = 0.01;
  float resistorUpper = 10;
  float resistorDowner = 5;
  auto pinPosition = ResistorReader_asukiaaa::PinPosition::Downer;
  float rateAnalog;
  double resistorResult;
  double resistorExpected;

  rateAnalog = 0.2;
  resistorExpected = 10;
  resistorResult = ResistorReader_asukiaaa::calcResistorFromAnalogRate(
      rateAnalog, pinPosition, resistorUpper, resistorDowner);
  TEST_ASSERT_FLOAT_WITHIN(resistorAlowwDiff, resistorExpected, resistorResult);

  rateAnalog = 0.2174;
  resistorExpected = 8;
  resistorResult = ResistorReader_asukiaaa::calcResistorFromAnalogRate(
      rateAnalog, pinPosition, resistorUpper, resistorDowner);
  TEST_ASSERT_FLOAT_WITHIN(resistorAlowwDiff, resistorExpected, resistorResult);

  rateAnalog = 0.25;
  resistorExpected = 5;
  resistorResult = ResistorReader_asukiaaa::calcResistorFromAnalogRate(
      rateAnalog, pinPosition, resistorUpper, resistorDowner);
  TEST_ASSERT_FLOAT_WITHIN(resistorAlowwDiff, resistorExpected, resistorResult);

  rateAnalog = 0.294;
  resistorExpected = 2;
  resistorResult = ResistorReader_asukiaaa::calcResistorFromAnalogRate(
      rateAnalog, pinPosition, resistorUpper, resistorDowner);
  TEST_ASSERT_FLOAT_WITHIN(resistorAlowwDiff, resistorExpected, resistorResult);

  rateAnalog = 0.3333;
  resistorExpected = 0;
  resistorResult = ResistorReader_asukiaaa::calcResistorFromAnalogRate(
      rateAnalog, pinPosition, resistorUpper, resistorDowner);
  TEST_ASSERT_FLOAT_WITHIN(resistorAlowwDiff, resistorExpected, resistorResult);
}

void test_calcResistorFromADC_pin_upper_resistor_both() {
  double resistorAlowwDiff = 0.01;
  float resistorUpper = 10;
  float resistorDowner = 5;
  auto pinPosition = ResistorReader_asukiaaa::PinPosition::Upper;
  float rateAnalog;
  double resistorResult;
  double resistorExpected;

  rateAnalog = 0.6;
  resistorExpected = 10;
  resistorResult = ResistorReader_asukiaaa::calcResistorFromAnalogRate(
      rateAnalog, pinPosition, resistorUpper, resistorDowner);
  TEST_ASSERT_FLOAT_WITHIN(resistorAlowwDiff, resistorExpected, resistorResult);

  rateAnalog = 0.5652;
  resistorExpected = 8;
  resistorResult = ResistorReader_asukiaaa::calcResistorFromAnalogRate(
      rateAnalog, pinPosition, resistorUpper, resistorDowner);
  TEST_ASSERT_FLOAT_WITHIN(resistorAlowwDiff, resistorExpected, resistorResult);

  rateAnalog = 0.5;
  resistorExpected = 5;
  resistorResult = ResistorReader_asukiaaa::calcResistorFromAnalogRate(
      rateAnalog, pinPosition, resistorUpper, resistorDowner);
  TEST_ASSERT_FLOAT_WITHIN(resistorAlowwDiff, resistorExpected, resistorResult);

  rateAnalog = 0.4118;
  resistorExpected = 2;
  resistorResult = ResistorReader_asukiaaa::calcResistorFromAnalogRate(
      rateAnalog, pinPosition, resistorUpper, resistorDowner);
  TEST_ASSERT_FLOAT_WITHIN(resistorAlowwDiff, resistorExpected, resistorResult);

  rateAnalog = 0.3333;
  resistorExpected = 0;
  resistorResult = ResistorReader_asukiaaa::calcResistorFromAnalogRate(
      rateAnalog, pinPosition, resistorUpper, resistorDowner);
  TEST_ASSERT_FLOAT_WITHIN(resistorAlowwDiff, resistorExpected, resistorResult);
}

void setup() {
  delay(2000);  // for board that does not support software reset
  UNITY_BEGIN();
}

void loop() {
  static int testCount = 0;
  RUN_TEST(test_calcResistorFromADC_downer);
  RUN_TEST(test_calcResistorFromADC_upper);
  RUN_TEST(test_calcResistorFromADC_pin_downer_resistor_both);
  RUN_TEST(test_calcResistorFromADC_pin_upper_resistor_both);
  if (++testCount >= 3) {
    UNITY_END();
  }
}
