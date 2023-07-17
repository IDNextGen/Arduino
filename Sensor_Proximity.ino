#define pinpro1 7
#define pinpro2 8
#define pinpro3 9
#define pinpro4 10

void setup() {
  Serial.begin(9600); //Memulai serial communication boud rate di 9600
  pinMode(pinpro1, INPUT); // set pin proximity1 menjadi INPUT
  pinMode(pinpro2, INPUT); // set pin proximity2 menjadi INPUT
  pinMode(pinpro3, INPUT); // set pin proximity3 menjadi INPUT
  pinMode(pinpro4, INPUT); // set pin proximity4 menjadi INPUT
}
void loop() {
  int pro  = digitalRead(pinpro1);
  int pro2 = digitalRead(pinpro2);
  int pro3 = digitalRead(pinpro3);
  int pro4 = digitalRead(pinpro4);
  Serial.println(pro);
  Serial.println(pro2);
  Serial.println(pro3); 
  Serial.println(pro4);

   if (pro == 1)
    {
      // Kirim notifikasi Telegram
      Serial.println("Ada Objek 1");
    }
   if (pro2 == 1)
    {
      // Kirim notifikasi Telegram
      Serial.println("Ada Objek 2");
    }
   if (pro3 == 1)
    {
      // Kirim notifikasi Telegram
      Serial.println("Ada Objek 3");
    }
   if (pro4 == 1)
    {
      // Kirim notifikasi Telegram
      Serial.println("Ada Objek 4");
    }        
  delay(500);
}
