int ldr = 36;
int bt = 17;
int ntp = 15;
int wifi = 2;
int iot = 12;
void setup() {
  Serial.begin(9600);
  pinMode(bt, OUTPUT);
  pinMode(ntp, OUTPUT);
  pinMode(wifi, OUTPUT);
  pinMode(iot, OUTPUT);
}

void loop() {
  int x = analogRead(ldr);
  Serial.print(x, 4);
  Serial.print("\t");
  int y =map(x , 400 , 950, 0 , 4);
  Serial.println(y);

  if (y == 1) {
    digitalWrite(bt, LOW);
    digitalWrite(ntp, HIGH);
    digitalWrite(wifi, HIGH);
    digitalWrite(iot, HIGH);
 } else if(y == 1) {
   digitalWrite(bt, LOW);
   digitalWrite(ntp, HIGH);
   digitalWrite(wifi, HIGH);
   digitalWrite(iot, HIGH);
 }else if(y == 2) {
   digitalWrite(bt, LOW);
   digitalWrite(ntp, LOW);
   digitalWrite(wifi, HIGH);
   digitalWrite(iot, HIGH);
 } else if(y == 3) {
  digitalWrite(bt, LOW);
   digitalWrite(ntp,LOW);
   digitalWrite(wifi, LOW);
   digitalWrite(iot, HIGH);
 } else if(y == 4) {
  digitalWrite(bt, HIGH);
   digitalWrite(ntp,HIGH);
   digitalWrite(wifi, HIGH);
   digitalWrite(iot, HIGH);
 }



  delay(500);
}
