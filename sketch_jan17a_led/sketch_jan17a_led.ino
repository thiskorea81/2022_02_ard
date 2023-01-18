int r=12;         // 빨강 12번
int g=11;         // 녹색 11번
int b=10;         // 파랑 10번

int sw1=8;        // 8번 스위치1
int sw2=9;        // 9번 스위치2

int randNum;
int randPin;

void led(int pinN, int onTime=1000, int offTime=1000);  // 핀번호, 켜져있는시간, 꺼져있는시간, 디폴트 값은 1000ms
void led_D(int pinN, int x=HIGH);

void setup(){
    Serial.begin(9600);
    pinMode(r, OUTPUT);
    pinMode(g, OUTPUT);
    pinMode(b, OUTPUT);
    pinMode(sw1, INPUT_PULLUP);
    randomSeed(analogRead(0));
}

void loop(){
  randNum=random(10, 100);    // 랜덤 켜저있는 시간(10~99)
  randPin=random(10, 13);     // 랜덤 핀 번호(10~12)
  Serial.println(randNum);
  led(randPin, randNum, 100);
  ledOff(randPin);
}

void led(int pinN, int onTime, int offTime){
  digitalWrite(pinN, HIGH);
  delay(onTime);
  digitalWrite(pinN, LOW);
  delay(offTime);
}

void led_D(int pinN, int x){
  digitalWrite(pinN, x);
  delay(1000);
}

void ledOff(int pinN){
  digitalWrite(pinN, LOW);
}
