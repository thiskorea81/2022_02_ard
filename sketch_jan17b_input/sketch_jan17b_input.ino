void led(int pinN, int onTime=1000, int offTime=1000);  // 핀번호, 켜져있는시간, 꺼져있는시간, 디폴트 값은 1000ms
void ledD(int pinN, int x=1);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(11, INPUT);
  pinMode(10, OUTPUT);
  pinMode(12, OUTPUT);
}

void morseN(int n){ 
  ledD(10, n);
  int a = digitalRead(11);
  Serial.println(a);
  ledD(12, a);
}

void numberMo(int k){
  if(k<6){
    Serial.println("under 6");
    for(int i=0; i<k; i++)
      morseN(0);
    for(int i=0; i<5-k; i++)
      morseN(1);
    Serial.println("end");
  }
  else{
    k=k-5;
    Serial.println("over 5");
    for(int i=0; i<k; i++)
      morseN(1);
    for(int i=0; i<5-k; i++)
      morseN(0);

    Serial.println("end");
  }
}

void loop(){
  
  if(Serial.available()>0){
    int a = Serial.parseInt();   // read();
    Serial.println(a);
    numberMo(a);
  }  
}

void ledD(int pinN, int x){
  digitalWrite(pinN, x);
  delay(1000);
}

void ledOff(int pinN){
  digitalWrite(pinN, LOW);
}
