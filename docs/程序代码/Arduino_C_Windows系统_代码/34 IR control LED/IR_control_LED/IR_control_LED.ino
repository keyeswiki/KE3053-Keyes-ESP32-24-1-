//**********************************************************************************
/*  
 * Filename    : IR Control LED
 * Description : Remote controls LED on and off
 * Auther      : http//www.keyes-robot.com
*/
#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

const uint16_t recvPin = 35;  // Infrared receiving GPIO35
IRrecv irrecv(recvPin);       // Create a class object used to receive class
decode_results results;       // Create a decoding results class object
int led = 5;//LED connect to GPIO5
boolean flag = true;  //LED flag bit

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();                  // Start the receiver
  pinMode(led, OUTPUT);
  ledcSetup(0, 1000, 8); //setup pwm channel
  ledcAttachPin(5, 0);  //attach the led pin to pwm channel
}

void loop() {
  if(irrecv.decode(&results)) {        // Waiting for decoding
    serialPrintUint64(results.value, HEX);// Print out the decoded results
    Serial.print("");
    handleControl(results.value);       // Handle the commands from remote control
    irrecv.resume();                    // Receive the next value
  }
}

void handleControl(unsigned long value){
  if (value == 0xFF02FD && flag == true){ // Receive the number 'OK'  
    ledcWrite(0, 170); //turn on LED
    delay(10);
    Serial.println("  led on");
    flag = false;
  } 
  else if (value == 0xFF02FD && flag == false){ // Receive the number 'OK'
    ledcWrite(0, 0); //turn on LED
    delay(10);
    Serial.println("  led off"); 
    flag = true;
  }
  else if(value == 0xFF6897){
    ledcWrite(0, 85);
    Serial.println("  weak light");
    delay(10);
  } 
  else if(value == 0xFF9867){
    ledcWrite(0, 170);
    delay(10);
    Serial.println("  normal light");
  } 
  else if(value == 0xFFB04F){
    ledcWrite(0, 255);
    delay(10);
    Serial.println("  strong light");
  }
}
//**********************************************************************************
