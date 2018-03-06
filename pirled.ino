int led = 13;
int inputPin = 7;
int i = 0;
int pirState = LOW;
void setup() {
  pinMode(inputPin, INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  i = digitalRead(inputPin);
  if(i = HIGH){
    digitalWrite(led, HIGH);
   if(pirState = LOW){
     Serial.println("Motion alert");
     pirState = HIGH;
   }
  }else{
    digitalWrite(led, LOW);
  if(pirState = HIGH){
    Serial.println("No motion");
    pirState = LOW;
  }
  }
   
}
