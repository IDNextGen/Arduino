const int pin2 = 2;     // membuat konstanta data pin 2

void setup() {
  pinMode(pin2, OUTPUT);    // set pin 2 menjadi OUTPUT
  Serial.begin(9600);       // digunakan untuk komunikasi Serial dengan komputer
}

void loop() {

  // program di bawah ini untuk mensimulasikan relay
  digitalWrite(pin2, HIGH);   //ketika pin 2 HIGH relay NO
  delay(1000);       //delay 1000 m/s = 1 detik
  digitalWrite(pin2, LOW);   //ketika pin 2 LOW relay NC
  delay(1000);      //de;ay 1000 m/s = 1 detik
}
