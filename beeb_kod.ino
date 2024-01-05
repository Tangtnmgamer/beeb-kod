#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <Servo.h>

Servo ServoR;
int pos = 0;
int IRread = 0;
int IRsensor = 3;
int POXread = 0;
int POXsensor = 4;
int Motor =  13; 
int checkSW =10;
int SW =1;
int LIMIT;

void setup() {
    ServoR.attach(9);
    pinMode(IRsensor, INPUT);
    pinMode(POXsensor, INPUT);
    pinMode(checkSW, INPUT);
    pinMode(Motor, OUTPUT);
    digitalWrite(Motor,LOW); 
    Serial.begin(9600);
    lcd.begin();
    lcd.noBacklight();   
    lcd.backlight();
    lcd.home();
    lcd.setCursor(5,0);
    lcd.print("Ready");
      
}

void loop() 
{

  POXread = digitalRead(POXsensor);  
  IRread = digitalRead(IRsensor);
  lcd.home();
  lcd.setCursor(5,0);
  lcd.print("Ready");
  SW = digitalRead(checkSW);
  Serial.print("IRread =");
  Serial.println(IRread);
  Serial.print("POXread =");
  Serial.println(POXread);
  Serial.print("SW = ");
  Serial.println(SW);
  delay(20);

  if(POXread == 1){
    Servor();
  }
  if(IRread == 0)
  { 
  Serial.print("POXread =");
  Serial.println(POXread);
   lcd.home();
   lcd.setCursor(3,0);
   lcd.print("IN process");
   MotorDrive();
  }
   else(IRread == 1);
    {    
    

    }
}





void Servor()
 {
  ServoR.write(0);
  delay(200); 
  ServoR.write(0);  
 }

void MotorDrive()
 {
  delay(1000);
  SW = digitalRead(checkSW);
  while (SW == 1)  
  {

    while (SW == 1)   
  {
    Serial.println(SW);
    Serial.println("Motor spin");
    SW = digitalRead(checkSW);
    digitalWrite(Motor,HIGH);     
  }
   ServoR.write(90);
   digitalWrite(Motor,LOW);
   delay(1000);
   lcd.clear();
   lcd.setCursor(3,0);
   lcd.print("complete");
   delay(1000);
   lcd.clear();
   }
}
