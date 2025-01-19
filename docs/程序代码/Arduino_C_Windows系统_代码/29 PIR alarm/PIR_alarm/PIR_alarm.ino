//**********************************************************************************
/*  
 * Filename    : PIR alarm
 * Description : PIR control buzzer
 * Auther      : http//www.keyes-robot.com
*/
int item = 0;
void setup() {
  pinMode(12, INPUT);  //PIR motion sensor is connected to GPIO12 and set as the input mode
  pinMode(13, OUTPUT);//The active buzzer is connected to GPIO13 and set to output mode
  pinMode(5, OUTPUT);//LED is connected to GPIO5 and set to output mode
}

void loop() {
  item = digitalRead(12);//Read digital level signal output by infrared pyrorelease sensor
  if (item == 1) {  //Movement detected
    digitalWrite(13, HIGH); //Turn on the buzzer
    digitalWrite(5, HIGH); //Turn on the LED
    delay(200);//Delay 200ms
    digitalWrite(13, LOW); //Turn off the buzzer
    digitalWrite(5, LOW); //Turn off the LED
    delay(200);//Delay 200ms
  } else {  //No detection
    digitalWrite(13, LOW); //Turn off the buzzer
    digitalWrite(5, LOW); //Turn off the LED
  }
}
//**********************************************************************************
