/*
  Arduino Starter Kit example
  Project 5 - Servo Mood Indicator

  This sketch is written to accompany Project 5 in the Arduino Starter Kit

  Parts required:
  - servo motor
  - 10 kilohm potentiometer
  - two 100 uF electrolytic capacitors

  created 13 Sep 2012
  by Scott Fitzgerald

  http://www.arduino.cc/starterKit

  This example code is part of the public domain.
*/

// include the Servo library
#include <TimerOne.h> 
#include <Servo.h>
#include <NewPing.h>
#define trigPin 12                                   // Pin 12 trigger output
#define echoPin 2                                 // Pin 2 Echo input
                                 // Pin 13 onboard LED
#define echo_int 0                                    // Interrupt id for echo pulse

//#define TIMER_US 50                                   // 50 uS timer duration 
//#define TICK_COUNTS 4000   

//volatile long echo_start = 0;                         // Records start of echo pulse 
//volatile long echo_end = 0;                           // Records end of echo pulse
//volatile long echo_duration = 0;                      // Duration - difference between end and start
//volatile int trigger_time_count = 0;                  // Count down counter to trigger pulse time
//volatile long range_flasher_counter = 0;              // Count down counter for flashing distance LED
//volatile long distance = 0;


 
#define TRIGGER_PIN 12
#define ECHO_PIN 2
#define MAX_DISTANCE 200

Servo base;  // create a servo object
Servo left;
Servo right;
Servo claw;
char receivedChar;
int baseAngle = 63;
int leftAngle = 90;
int rightAngle = 80;
int clawAngle = 140;
int pos1;
int pos2;
int Vx,Vy,p0,pf,tf,ti;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 
void setup() {
 

//  pinMode(trigPin, OUTPUT);                           // Trigger pin set to output
//  pinMode(echoPin, INPUT);


  base.attach(11); // attaches the servo on pin 9 to the servo object
  left.attach(10);
  right.attach(9);
  claw.attach(6);
  claw.write(clawAngle);
  base.write(baseAngle);
  left.write(leftAngle);
  right.write(rightAngle);
  Serial.begin(9600); // open a serial connection to your computer
}

void loop() {
  
  // set the servo position
//  delay(50);
//  unsigned int distance = sonar.ping_cm();
//  Serial.print(distance);
//  Serial.println("cm");
//  if(distance<10){
//    claw.write(100);
//  }
  if (Serial.available() > 0) {
    receivedChar = Serial.read();
    Serial.print("Recieved: ");
    Serial.println(receivedChar);
  
    
    if(receivedChar == 'c')
    {
      claw.write(120);
    }
    if(receivedChar == 'm'){
      base.write(63);
    }
    else if(receivedChar == '0'){
      
      claw.write(140);
    }
    else if(receivedChar == 'r'){
      base.write(71);
    }
    else if(receivedChar == 'l'){
      base.write(55);
    }
    else if(receivedChar == 'o'){
      claw.write(140);
    }

 
  }
    
  
  
  
  //base.write(90);

  // wait for the servo to get there

}
//int Vx,Vy,p0,pf,tf,ti;
void timerIsr()
{
    Vx = (Vy-p0)/(pf-p0)*(tf/ti);
    // Flash the onboard LED distance indicator
}

//void trigger_pulse()
//{
//      static volatile int state = 0;                 // State machine variable
//
//      if (!(--trigger_time_count))                   // Count to 200mS
//      {                                              // Time out - Initiate trigger pulse
//         trigger_time_count = TICK_COUNTS;           // Reload
//         state = 1;                                  // Changing to state 1 initiates a pulse
//      }
//    
//      switch(state)                                  // State machine handles delivery of trigger pulse
//      {
//        case 0:                                      // Normal state does nothing
//            break;
//        
//        case 1:                                      // Initiate pulse
//           digitalWrite(trigPin, HIGH);              // Set the trigger output high
//           state = 2;                                // and set state to 2
//           break;
//        
//        case 2:                                      // Complete the pulse
//        default:      
//           digitalWrite(trigPin, LOW);               // Set the trigger output low
//           state = 0;                                // and return state to normal 0
//           break;
//     }
//}

//void echo_interrupt()
//{ 
//  switch (digitalRead(echoPin))                     // Test to see if the signal is high or low
//  {
//    case HIGH:                                      // High so must be the start of the echo pulse
//      echo_end = 0;                                 // Clear the end time
//      echo_start = micros();                        // Save the start time
//      break;
//      
//    case LOW:                                       // Low so must be the end of hte echo pulse
//      echo_end = micros();                          // Save the end time
//      echo_duration = echo_end - echo_start;        // Calculate the pulse duration
//      break;
//  }
//}
//
//
//void distance_flasher()
//{
////      if (--range_flasher_counter <= 0)                // Decrement and test the flash timer
////      {                                                // Flash timer time out
////         if (echo_duration < 25000)                    // If the echo duration is within limits
////         {
////           range_flasher_counter = echo_duration * 2;  // Reload the timer with the current echo duration
////         }
////         else
////         {
////           range_flasher_counter = 25000;              // If out of range use a default
////         }
////         
////         digitalWrite( onBoardLED, digitalRead( onBoardLED ) ^ 1 );   // Toggle the onboard LED
////      }
////  if((echo_duration / 58)<3){
////    Serial.println("Close!");
////  }
//  //Serial.println(distance);
//  
//}



