//**********************************************************************************
/*  
 * Filename    : Avoiding alarm
 * Description : Obstacle avoidance sensor controls the buzzer
 * Auther      : http//www.keyes-robot.com
*/
int item = 0;
void setup() {
  pinMode(12, INPUT);  //Obstacle avoidance sensor is connected to GPIO12 and set to input mode
  pinMode(13, OUTPUT); //The buzzer is connected to GPIO13 and set to output mode
}

void loop() {
  item = digitalRead(12);//Read the level value output by the obstacle avoidance sensor
  if (item == 0) {//Obstruction detected
    digitalWrite(13, HIGH);//The buzzer sounded
  } else {//No obstacles detected
    digitalWrite(13, LOW);//The buzzer is off
  }
  delay(100);//Delay 100ms
}
//**********************************************************************************
