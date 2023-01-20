int red=11;
bool flag=true;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  
}
int touchN=0;


void loop() {
  //** put your main code here, to run repeatedly:
  //** read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  //** Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  // float voltage = sensorValue * (5.0 / 1023.0);
  //** print out the value you read:
  // Serial.println(voltage);
  //** Convert to the digital value(0 - 255)
  int digitalValue = (int)sensorValue * (255.0 / 1023.0);
  //Serial.println(sensorValue);
  Serial.println(flag);
  if (!flag && sensorValue>995){
    //Serial.print("touched ");
    //Serial.println(flag);
    //Serial.println(sensorValue);
    
    digitalWrite(red, HIGH);
    touchN++;
    Serial.print(touchN);
    Serial.print(", ");
    Serial.println(sensorValue);    
    
    flag=true;  
  }
  else{
    //Serial.print("untouched ");
    //Serial.println(flag);
    //Serial.println(sensorValue);
    
    //Serial.println("bright");
    digitalWrite(red, LOW);
    flag=false;
  }
  // analogWrite(red, digitalValue);
  
  delay(1000);
}
