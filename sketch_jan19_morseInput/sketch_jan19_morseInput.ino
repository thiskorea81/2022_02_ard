void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(9, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    //int x = Serial.read();
    int x = Serial.parseInt();
    // String xs = Serial.readString();

    Serial.print("x = ");
    Serial.println(x);
  }

}
