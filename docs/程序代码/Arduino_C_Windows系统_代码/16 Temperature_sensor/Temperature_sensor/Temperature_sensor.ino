//**********************************************************************************
/*  
 * Filename    : Temperature sensor
 * Description : Making a thermometer by thermistor.
 * Auther      : http//www.keyestudio.com
*/
#define PIN_ANALOG_IN   34
void setup() {
  Serial.begin(9600);
}

void loop() {
  int adcValue = analogRead(PIN_ANALOG_IN);    //read ADC pin
   float Rt=0;    //NTC thermistor
   float R=10000;    //10K resistance with a fixed resistance value
   float T2=273.15+25;    //Convert to Kelvin temperature
   float B=3950;    //B value is an important parameter of thermistor
   float K=273.15;    //Degree kelvin (K°)
   float VR=0;
   VR = (float)(adcValue / 4096.0 * 3.3);    //Convert to a voltage value
   Rt = (3.3 - VR) / VR * 4700;    //Calculate the NTC thermistor
   float temp = 1/(1/T2+log(Rt/R)/B)-K+0.5;    //Calculating temperature
  Serial.printf("ADC value : %d,\tVoltage : %.2fV, \tTemperature : %.2fC\n", adcValue, VR, temp);
  delay(1000);
}
//**********************************************************************************
