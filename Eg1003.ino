#include <Servo.h>
Servo servol;

void setup(){
  //initialize serial communication at 9600 bits per second
  Serial.begin(9600);
  
  servol.attach(9,900,2100);//Connect the servo to PIN 9 on Micro Controller
                            //with a minimum pulse width of
                            //900 and a maximum pulse width of
                            //2100
  
}
//loop script allows for continuous run
void loop(){
  //read the input on analog pin 0;
  int sensorValue=analogRead(A0);
  //print out the muscle sensor value;
  Serial.println(sensorValue);
  delay(1000);//delay in between reads for stability
  int position;

  //change popsition at full speed;
  if(sensorValue>600){
    Serial.println(sensorValue);
    servol.write(180);//tekk servo to move 180 degrees
    delay(1000);
  }

//stop  Servo if sensor value is not >600
  else{
    Serial.println(sensorValue);
   servol.write(0);
 }
}
