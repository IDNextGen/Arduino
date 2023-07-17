const int pin2 = 2; 
const int pin4 = 4;
const int pin7 = 7; 
const int pin8 = 8;

void setup() {
  pinMode(pin2, OUTPUT);
  pinMode(pin4, OUTPUT);   
  pinMode(pin7, OUTPUT);   
  pinMode(pin8, OUTPUT);      
  Serial.begin(9600);     
  
}

void loop() {

  // program di bawah ini untuk mensimulasikan relay
if (
  digitalWrite(pin2, HIGH);
  delay(1000);       
  digitalWrite(pin2, LOW);   
  delay(1000);      
}
