int red=11;
bool flag=false;
int touchN=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  
}

void loop() {
  int sensorValue = analogRead(A0);
  int digitalValue = (int)sensorValue * (255.0 / 1023.0);
  

  if (sensorValue>995){    
    digitalWrite(red, HIGH);
    if(!flag)
      touchN++;
    Serial.print(touchN);
    Serial.print(", ");
    Serial.println(sensorValue);    
    
    flag=true;  
  }
  else {    
    Serial.println(flag);
    digitalWrite(red, LOW);
    flag=false;
  }
  // analogWrite(red, digitalValue);
  
  delay(1000);
}
