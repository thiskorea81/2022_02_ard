int r=12;         // 빨강 12번
int g=11;         // 녹색 11번
int b=10;         // 파랑 10번

int fin=5;        // 입력 5번

void led(int pinN, int onTime=1000, int offTime=1000);  // 핀번호, 켜져있는시간, 꺼져있는시간, 디폴트 값은 1000ms
void led_D(int pinN, int x=HIGH);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(fin, INPUT);
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
}

void loop(){
  led(b, 100, 100);
}

void led(int pinN, int onTime, int offTime){
  digitalWrite(pinN, HIGH);
  int a=digitalRead(fin);
  Serial.println(a);
  delay(onTime);
  digitalWrite(pinN, LOW);
  a=digitalRead(fin);
  Serial.println(a);
  delay(offTime);
}

void led_D(int pinN, int x){
  analogWrite(pinN, x);
  delay(1000);
}

void ledOff(int pinN){
  digitalWrite(pinN, LOW);
}