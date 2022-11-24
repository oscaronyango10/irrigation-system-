#include <DHT.h>
#define Type DHT11
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


int mSensor = A0; // Soil Sensor input at Analog PIN A0
int msValue ;
int dt = 1000;

int sensePin = 2;
DHT HT(sensePin,Type);
float humidity;
float tempC;
float tempF;
int setTime = 500;

LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  // put your setup code here, to run once:
    pinMode(4, OUTPUT);
    Serial.begin(9600);
    delay(2000);
    
    HT.begin();
    delay(setTime);    
	 lcd.begin();    

	 lcd.backlight();      
}

void loop() {
  
lcd.clear();
lcd.setCursor (0,0);
  
  humidity = HT.readHumidity();
  tempC = HT.readTemperature();
  tempF = HT.readTemperature(true); 
 lcd.print("Humidity = ");
lcd.print(humidity); 
lcd.setCursor (0,1);
lcd.print(" Temp C =");
lcd.print(tempC ); 
lcd.print("C ");  
lcd.print( tempF);
lcd.println(" F");   

// Serial.print("Humidity = ");
// Serial.print(humidity); 
// Serial.print(" Temp C =");
// Serial.print(tempC ); 
// Serial.print("C ");  
//  Serial.print( tempF);
//  Serial.println(" F");
 
  delay(dt);

  
   msValue= analogRead(mSensor);
   Serial.print(" Moisture: ");
   Serial.println(msValue);
   
    if(msValue>=500){
      digitalWrite(4,HIGH);
     }
     else{
      digitalWrite(4,LOW);
     }
   delay(dt);
}
