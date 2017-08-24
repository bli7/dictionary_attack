#include <Servo.h>
Servo servoRight;
Servo servoLeft;

void setup() {
  
  
  servoRight.attach(13);
  servoLeft.attach(12);

  tone(4, 3000, 1000);                       // Play tone for 1 second
  delay(1000);                               // Delay to finish tone
  pinMode(7, INPUT);                         // Set right whisker pin to input
  pinMode(6, INPUT);                         // Set left whisker pin to input  

  Serial.begin(9600); 
}



void loop() {
  
  byte wLeft = digitalRead(6);               // Copy left result to wLeft  
  byte wRight = digitalRead(7);              // Copy right result to wRight

  Serial.print(wLeft);                       // Display left whisker state
  Serial.println(wRight);                    // Display right whisker state

  
    if (wRight == 0 and wLeft == 0)
    {
    backward();
    servoRight.writeMicroseconds(2000);
    servoLeft.writeMicroseconds(2000);
    delay(500);
    forward();
  }
  
  else if(wLeft == 0)              // If left whisker contact
  {
    servoRight.writeMicroseconds(2000);
    servoLeft.writeMicroseconds(2000);
    delay (500);
    forward();
  }
  
  else if (wRight == 0)             // If right whisker contact
  {
    servoRight.writeMicroseconds(1000);
    servoLeft.writeMicroseconds(1000);
    delay (500);
    forward();
  }
  
    
  else  {
   forward();    
  }
  
  delay(50);
 
}
  

void forward(void)
        { 
           servoRight.writeMicroseconds(2000);
           servoLeft.writeMicroseconds(1000);
           delay(3000);
        }

void backward(void)
        {        
          servoRight.writeMicroseconds(1000);
          servoLeft.writeMicroseconds(2000);       
          delay (3000);   
        }

