//For the LCD I2C
#include <Wire.h> 
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); //I2C pins declaration

//For DHT11
#include <DHT.h>
#define DHTPIN A0 //where DHT middle pin is connected to
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

float humi;
float temp;
const int buzzerPin=9;
const int RELAY_PIN = 5;

void setup() {
  //Initializing LCD
  lcd.begin(16,2); //Defining 16 columns and 2 rows of lcd display
  lcd.backlight(); //To Power ON the back light
  lcd.setCursor(0,0); //Defining positon to write from first row, first column.
  lcd.clear();

  //Initializing buzzer
  pinMode(buzzerPin, OUTPUT);

  //Initializing LED
  pinMode(13, OUTPUT);

  //start sensor reading
  dht.begin();

  //Initializing digital pin A5 as an output
  pinMode(RELAY_PIN, OUTPUT);
}

void loop() {
  int tempValue = dht.readTemperature();
  int humiValue = dht.readHumidity();
  
  showTempHumi();
  delay(1000);

  if (tempValue > 27){
      digitalWrite(RELAY_PIN, LOW);
    }
   if( tempValue < 27){
      noTone(buzzerPin);
      digitalWrite(13, LOW);
      digitalWrite(RELAY_PIN, HIGH);
   }
   
   if (tempValue > 30) {
      tone(buzzerPin, 500);
      digitalWrite(13, HIGH);
      delay(100);
      digitalWrite(13, LOW);
      digitalWrite(RELAY_PIN, LOW);
   }
}

void showTempHumi(){
  humi = dht.readHumidity();
  temp = dht.readTemperature();
  
  lcd.clear();
  lcd.print("Temp: ");
  lcd.print(temp,2);
  lcd.print(char(223));
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Humi: ");
  lcd.print(humi,2);
  lcd.print("%");
}
