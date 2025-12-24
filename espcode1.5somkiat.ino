int ldr = 36;

void setup() {
  serial.begin(9600);

}

void loop() 
  int x = analogread(idr);
  serial.println(x);
  delay(1000);

}
// lab5