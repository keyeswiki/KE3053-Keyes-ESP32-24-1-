//**********************************************************************************
/*  
 * Filename    : adjust the light
 * Description : Controlling the brightness of LED by potentiometer.
 * Auther      : http//www.keyestudio.com
*/
#define PIN_ANALOG_IN    34  // The pin of the potentiometer
#define PIN_LED           5  // The pin of the LED
#define CHANNEL           0  // Use ledc channel 0

void setup() {
  ledcSetup(CHANNEL, 1000, 12);     // The PWM value ranges from 0 to 4096
  ledcAttachPin(PIN_LED, CHANNEL);  // The PIN_LED pin is defined as the output pin of channel 0
}

void loop() {
  ledcWrite(CHANNEL, analogRead(PIN_ANALOG_IN));   // set the pulse width.
  delay(10);
}
//**********************************************************************************
