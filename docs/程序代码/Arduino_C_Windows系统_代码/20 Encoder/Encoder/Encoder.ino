//**********************************************************************************
/*  
 * Filename    : Encoder
 * Description : Rotary encoder module counting.
 * Auther      : http//www.keyestudio.com
*/
//Interfacing Rotary Encoder with Arduino
//Encoder Switch -> pin 16
//Encoder DT -> pin 27
//Encoder CLK -> pin 14

int Encoder_DT  = 27;
int Encoder_CLK  = 14;
int Encoder_Switch = 16;
 
int Encoder_Count;
 
void setup() {
  Serial.begin(9600);
  pinMode (Encoder_DT, INPUT);
  pinMode (Encoder_CLK, INPUT);
  pinMode (Encoder_Switch, INPUT);
}
 
 
int lastClk = HIGH;
 
 
void loop() {
  int newClk = digitalRead(Encoder_CLK);
  if (newClk != lastClk) {
    // There was a change on the CLK pin
    lastClk = newClk;
    int dtValue = digitalRead(Encoder_DT);
    if (newClk == LOW && dtValue == HIGH) {
      Encoder_Count ++;
      Serial.println(Encoder_Count);
    }
    if (newClk == LOW && dtValue == LOW) {
      Encoder_Count--;
      Serial.println(Encoder_Count);
    }
  }

  if (digitalRead(Encoder_Switch) == 0)
  {
    delay(5);
    if (digitalRead(Encoder_Switch) == 0) {
      Serial.println("Switch pressed");
      while (digitalRead(Encoder_Switch) == 0);
    }
  }
}
//**********************************************************************************
