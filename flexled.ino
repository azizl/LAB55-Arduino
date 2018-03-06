const int led = 7;
const int flex = A0;
int i;
void setup(){
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}
void loop(){
  i = analogRead(flex);
  Serial.println(i);
  i = map(i, 700, 900, 0, 255);
  analogWrite(led, i);
  delay(100);
}
