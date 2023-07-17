#include <SoftwareSerial.h>

SoftwareSerial mySerial(2,3); // RX, TX
String arah;

#define motorKiri_1 4
#define motorKiri_2 5
#define motorKanan_2 6
#define motorKanan_1 7

#define motorKiri 11
#define motorKanan 10

int vnormal = 60;
int vbelok = 80;

void setup() {
 Serial.begin(9600);
 mySerial.begin(9600);
 
 pinMode(motorKiri_1, OUTPUT);
 pinMode(motorKiri_2, OUTPUT);
 
 pinMode(motorKanan_2, OUTPUT);
 pinMode(motorKanan_1, OUTPUT);

}

void loop() {
  while(mySerial.available()) {
  delay(10);
  char masukan = mySerial.read();
  arah += masukan;
}

if(arah.length() > 0){
  Serial.println(arah);
    if(arah == "forward")
    {
      digitalWrite(motorKiri_1, HIGH);
      digitalWrite(motorKiri_2, LOW);
      
      digitalWrite(motorKanan_1, HIGH);
      digitalWrite(motorKanan_2, LOW);
      
      analogWrite(motorKiri, vnormal);
      analogWrite(motorKanan, vnormal);
      
      Serial.println("maju");
      delay(300);
    }
    
    if(arah == "left")
    {
      digitalWrite(motorKiri_1, LOW);
      digitalWrite(motorKiri_2, LOW);
      
      digitalWrite(motorKanan_1, HIGH);
      digitalWrite(motorKanan_2, LOW);
      
      Serial.println("belok kiri");
      delay(300);
    }
     
    if(arah == "right")
    {
     digitalWrite(motorKiri_1, HIGH);
     digitalWrite(motorKiri_2, LOW);
        
     digitalWrite(motorKanan_1, LOW);
     digitalWrite(motorKanan_2, LOW);
        
     analogWrite(motorKiri, vbelok);
     analogWrite(motorKanan, vnormal);
        
     Serial.println("belok kanan");
     delay(300);
    }
      
    if(arah == "back")
    {
     digitalWrite(motorKiri_1, LOW);
     digitalWrite(motorKiri_2, HIGH);
     digitalWrite(motorKanan_1, LOW);
     digitalWrite(motorKanan_2, HIGH);
        
     analogWrite(motorKiri, vnormal);
     analogWrite(motorKanan, vnormal);
        
     Serial.println("mundur");
     delay(300);
    }
      
    if(arah == "stop")
    {
     digitalWrite(motorKiri_1, LOW);
     digitalWrite(motorKiri_2, LOW);
     digitalWrite(motorKanan_1, LOW);
     digitalWrite(motorKanan_2, LOW);
        
     analogWrite(motorKiri, 0);
     analogWrite(motorKanan, 0);
        
     Serial.println("berhenti");
     delay(300);
    }
      
      arah = "";
    }
}
