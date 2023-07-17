#include <SoftwareSerial.h>
#include <AFMotor.h>

SoftwareSerial mySerial(2, 13);

AF_DCMotor motorKanan(1);
AF_DCMotor motorKiri(2);

String arah;

void setup() {
Serial.begin(9600);
mySerial.begin(9600);

motorKanan.run(RELEASE);
motorKiri.run(RELEASE);

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
    motorKanan.run(FORWARD);
    motorKanan.setSpeed(150);
    motorKiri.run(FORWARD);
    motorKiri.setSpeed(100);
    Serial.println("maju");
    delay(300); 
  }
  
  if(arah == "left")
  {
    motorKanan.run(FORWARD);
    motorKanan.setSpeed(100);
    motorKiri.run(RELEASE);
    Serial.println("belok kiri");
    delay(300);
  }
  
  if(arah == "right")
  {
    motorKiri.run(FORWARD);
    motorKiri.setSpeed(100);
    motorKanan.run(RELEASE);
    Serial.println("belok kanan");
    delay(300);
  }

  if(arah == "back")
  {
    motorKanan.run(BACKWARD);
    motorKanan.setSpeed(150);
    motorKiri.run(BACKWARD);
    motorKiri.setSpeed(150);
    Serial.println("mundur");
    delay(300);
  }

  if(arah == "stop")
  {
    motorKanan.run(RELEASE);
    motorKiri.run(RELEASE);
    Serial.println("berhenti");
    delay(300);
  }

  arah = "";
  }
}
