#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(13,12);
char c=' ';
int revleft4 = 11; // Motor Pins
int fwdleft5 = 10;
int revright6 = 9;
int fwdright7 = 8;
void setup() {
  pinMode(revleft4, OUTPUT); // Set Motor Pins As O/P
  pinMode(fwdleft5, OUTPUT);
  pinMode(revright6, OUTPUT);
  pinMode(fwdright7, OUTPUT);
Serial.begin(9600);
  Serial.println("ready");
  Bluetooth.begin(9600);
 
}
 
void loop() {
  if(Bluetooth.available())
  {
    c=Bluetooth.read();
    Serial.write(c);
  }
 
if(c == 'F'){            //move forward(all motors rotate in forward direction)
    digitalWrite(fwdright7, HIGH); // Move Forward
    digitalWrite(revright6, LOW);
    digitalWrite(fwdleft5, HIGH);                                
    digitalWrite(revleft4, LOW);   
delay(100);
}
 
else if(c == 'B'){      //move reverse (all motors rotate in reverse direction)
  digitalWrite(fwdright7, LOW); // Move Backward             
    digitalWrite(revright6, HIGH);
    digitalWrite(fwdleft5, LOW);                                
    digitalWrite(revleft4, HIGH);
  delay(100);
}
 
else if(c == 'R'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
    digitalWrite(fwdright7, HIGH); // Move Forward
    digitalWrite(revright6, LOW);
    digitalWrite(fwdleft5, HIGH);                                
    digitalWrite(revleft4, LOW);   
    delay(2000);
    digitalWrite(fwdright7, HIGH); // Move RIGHT      
    digitalWrite(revright6, LOW);   
    digitalWrite(revleft4, LOW);                                 
    digitalWrite(fwdleft5, LOW);  
    delay(100);
}
 
else if(c == 'L'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
    digitalWrite(fwdright7, HIGH); // Move Forward
    digitalWrite(revright6, LOW);
    digitalWrite(fwdleft5, HIGH);                                
    digitalWrite(revleft4, LOW);   
delay(2000);
    digitalWrite(fwdright7, LOW); // Move LEFT     
    digitalWrite(revright6, LOW);   
    digitalWrite(revleft4, HIGH);                                 
    digitalWrite(fwdleft5, LOW);  
    delay(100);
}
 
else if(c == 'S'){      //STOP (all motors stop)
    digitalWrite(fwdright7, LOW); //Stop                
    digitalWrite(revright6, LOW);
    digitalWrite(fwdleft5, LOW);                                
    digitalWrite(revleft4, LOW);
}
delay(100);
}
