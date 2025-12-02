int BT = 17;
int WIFI = 2;
int NTP = 15;
int IOT = 12;
void setup() {
  pinMode(BT, OUTPUT);
  pinMode(WIFI, OUTPUT);
  pinMode(NTP, OUTPUT);
  pinMode(IOT, OUTPUT);

}

void loop() {
    // digitalWrite(BT, HIGH);
    // delay(800); 
    // digitalWrite(unit8_t pin, unit8_t val) -> void
    digitalWrite(BT,LOW );
    delay(1000);
    digitalWrite(BT,HIGH );
    delay(1000);
    digitalWrite(WIFI, LOW);
    delay(900); 
    digitalWrite(WIFI, HIGH );
    delay(700);
    digitalWrite(NTP, LOW);
    delay(600); 
    digitalWrite(NTP, HIGH);
    delay(400); 
    digitalWrite(IOT, LOW);
    delay(400); 
    digitalWrite(IOT, HIGH);
    delay(200); 
    

    

}

