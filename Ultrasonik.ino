//================ Inisialisasi pin HC-RS04
//Pin Input
#define trigPin 8
#define echoPin 9
//Pin Output
#define relay1 2


void setup() {
  Serial.begin(9600); // digunakan untuk komunikasi Serial dengan komputer
  pinMode(trigPin, OUTPUT); // set pin trigger menjadi OUTPUT
  pinMode(echoPin, INPUT); // set pin echo menjadi INPUT
  pinMode(relay1, OUTPUT); // set pin relay1 menjadi OUTPUT
  digitalWrite(relay1, OUTPUT);
}
void loop() {
  // program di bawah ini agar trigger memancarakan sensor ultrasonic
  long durasi, jarak;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  durasi = pulseIn(echoPin, HIGH); // waktu pemantulan gelombang
  jarak = (durasi/2) / 29;

  if(jarak <= 30){
    Serial.println("Paket Disemprotkan");
    digitalWrite(relay1, HIGH); 
    delay(200);
  } 
  else {
    Serial.println("Tidak ada Paket");
    digitalWrite(relay1, LOW); 
    delay(200);
  }  
  Serial.print("Jarak : ");
  Serial.print( jarak );
  Serial.println(" cm"); // menampilkan jarak pada Serial Monitor
  delay(500);
}  
