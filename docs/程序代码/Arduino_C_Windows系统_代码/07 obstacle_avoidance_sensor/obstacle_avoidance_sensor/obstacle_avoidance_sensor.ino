//*************************************************************************************
/*
 * Filename    : obstacle avoidance sensor
 * Description : Reading the obstacle avoidance value
 * Auther      : http://www.keyes-robot.com
*/
int val = 0;
void setup() {
  Serial.begin(9600);//Set baud rate to 9600
  pinMode(5, INPUT);//Set pin GP5 to input mode
}

void loop() {
  val = digitalRead(5);//Read digital level
  Serial.print(val);//Print the level signal read
  if (val == 0) {//Obstruction detected
    Serial.print("        ");
    Serial.println("There are obstacles");
    delay(100);
  }
  else {//No obstructions detected
    Serial.print("        ");
    Serial.println("All going well");
    delay(100);
  }
}
//*************************************************************************************
