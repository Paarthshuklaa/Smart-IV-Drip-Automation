#include <HX711.h>

// Declare HX711 object
HX711 hx;

// Declare other variables
const int dout_pin = 0;  // GPIO 0 corresponds to D3 on some boards
const int sck_pin = 4;   // GPIO 4 corresponds to D2 on some boards
const int calibration_factor = -7050;  // Adjust as neededd
const int threshold = 100;  // Threshold for weight in grams

void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);

  // Initialize HX711
  hx.begin(dout_pin, sck_pin);
  hx.set_scale(calibration_factor);
  hx.tare();  // Reset the scale to 0

  Serial.println("HX711 scale initialized.");
}

void loop() {
  // Read weight
  float weight = hx.get_units(10);  // Average of 10 readings

  Serial.print("Weight: ");
  Serial.print(weight);
  Serial.println(" grams");

  delay(1000);  // 1-second delay between readings
}
