/*초음파 센서를 이용해서 거리를 측정해서
10센티미터 이내에 사물이 들어오면 
LED를 깜빡이게 하는 장치
*/

#define TRIG 7 //TRIG 핀 설정 (초음파 보내는 핀)
#define ECHO 6 //ECHO 핀 설정 (초음파 받는 핀)
#define LED 11 // led  핀 설정 (LED를 켜는 핀)

void led(int pinN, int onTime=1000, int offTime=1000);  // 핀번호, 켜져있는시간, 꺼져있는시간, 디폴트 값은 1000ms

void setup() {

  Serial.begin(9600); //PC모니터로 센서값을 확인하기위해서 시리얼 통신을 정의해줍니다. 
  pinMode(LED, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop(){

  long duration, distance;

  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn (ECHO, HIGH); //물체에 반사되어돌아온 초음파의 시간을 변수에 저장합니다.

  //34000*초음파가 물체로 부터 반사되어 돌아오는시간 /1000000 / 2(왕복값이아니라 편도값이기때문에 나누기2를 해줍니다.)

  //초음파센서의 거리값이 위 계산값과 동일하게 Cm로 환산되는 계산공식 입니다. 수식이 간단해지도록 적용했습니다.

  distance = duration * 17 / 1000; 

  //PC모니터로 초음파 거리값을 확인 하는 코드 입니다.

  Serial.println(duration ); //초음파가 반사되어 돌아오는 시간을 보여줍니다.
  Serial.print("\nDIstance : ");
  Serial.print(distance); //측정된 물체로부터 거리값(cm값)을 보여줍니다.
  Serial.println(" Cm");

  if (distance<10)
    led(LED, 50, 50);

  delay(1000); //1초마다 측정값을 보여줍니다.
}

void led(int pinN, int onTime, int offTime){
  digitalWrite(pinN, HIGH);
  delay(onTime);
  digitalWrite(pinN, LOW);
  delay(offTime);
}
