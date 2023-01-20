int red=11;
bool eventT=false;
int touchN=0;
int aa[]={1,1,1,0,0,1,0,1};
int n=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(red, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(eventT);
  Serial.print(" : ");
  if(eventT && n<8){
    Serial.println(aa[n]);
    n++;
  }
  else{
    Serial.println();
  }
  delay(1000);
  eventT=!eventT;
}
