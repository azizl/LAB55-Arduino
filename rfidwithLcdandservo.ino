#include <SoftwareSerial.h>
#include <Servo.h>
#include <LiquidCrystal.h>
Servo myS;
int led = 7;
int led2 = 8;
int i;
LiquidCrystal lcd(8,9,4,5,6,7);
SoftwareSerial mySerial(16, 17); //RX TX
void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
  Serial.println("RFID is trying to be triggered....");
  mySerial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  lcd.setCursor(2,0);
  lcd.print("Door");
  lcd.setCursor(5,1);
  lcd.print("Locker");
  delay(4000);
  lcd.clear();
  lcd.setCursor(0, 0); 
      lcd.print("Processing Data.");
      delay(3000);
      lcd.clear(); 
      lcd.setCursor(3, 0);
      lcd.print("Waiting For");
      lcd.setCursor(3, 1);
      lcd.print("RFID....");    
   myS.attach(6);
}
void loop(){
  myS.write(1);
  digitalWrite(led,HIGH);
  digitalWrite(led2, LOW);
   lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("RFID scanning");
  if (mySerial.available()){
    Serial.write(mySerial.read());
    myS.write(170);
    digitalWrite(led, LOW);
    digitalWrite(led2, HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("RFID detected");
  }
  delay(475);
}
