#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include "NTPClient.h" // https://github.com/arduino-libraries/NTPClient/issues/36#issuecomment-334312492

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "RTClib.h" // https://www.elecrow.com/wiki/index.php?title=Tiny_RTC
#include "Wanci.h"

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

RTC_DS1307 RTC;

const char *ssid     = "ssid";
const char *password = "pass";

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, 3600*7); // +7j Indonesia (WIB)};

void setup(){
  // initialize the LCD
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  
  lcd.setCursor(0,0);
  lcd.print("Ngonekkeun ... ");
  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }

  Serial.println(WiFi.localIP());

  lcd.clear();
  lcd.print("Sync");
  
  timeClient.begin();

  if (timeClient.update()){
    // DateTime (y, m, d, hh, mm, ss)
    RTC.adjust(DateTime (timeClient.getYear(), timeClient.getMonth(), timeClient.getDate(),
                         timeClient.getHours(), timeClient.getMinutes(), timeClient.getSeconds()));
  } 
  
}

void loop() {

  DateTime now = RTC.now();
    
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(get_poe(now.dayOfWeek())+", "+String(now.day())+"/"+String(now.month())+"/"+String(now.year()));
  lcd.setCursor(0,1);
  lcd.print(String(now.hour())+":"+String(now.minute())+":"+String(now.second()));

  Serial.println(timeClient.getFullFormattedTime());

  Serial.println(get_peperenian_waktu(now.hour(), now.minute()));
    
  delay(1000);
}
