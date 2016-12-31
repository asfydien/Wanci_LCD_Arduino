#include <Wire.h> 
#include <Time.h>
#include <DS1307RTC.h>
#include <LiquidCrystal_I2C.h>

#if defined(ARDUINO) && ARDUINO >= 100
#define printByte(args)  write(args);
#else
#define printByte(args)  print(args,BYTE);
#endif

/*
 * Libraries anu diperyogikeun:
 *   https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library
 *   https://github.com/PaulStoffregen/DS1307RT
 *   https://github.com/PaulStoffregen/Time
 * 
 * Parantos dicobi ngangge Arduino 1.8.0
 */

LiquidCrystal_I2C lcd(0x27, 16, 2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

String bulan[] = {"Januari", "Pebruari", "Maret", "April", 
                  "Mei", "Juni", "Juli", "Agustus",
                  "Semptember", "Oktober", "Nopember", "Desember"}; 

String hari[] = {"Senen", "Salasa", "Rebo", "Kemis", "Juma'ah", "Saptu", "Ahad"};

uint8_t colon[8] = {0x0,0x0,0x4,0x0,0x0,0x4,0x0, 0x0};
uint8_t ge[8]     = {0x0,0x0,0xf,0x11,0x11,0xf,0x1,0xe};
//uint8_t koma[8]   = {0x0,0x0,0x0,0x0,0x0,0xc,0x4,0x8};

tmElements_t tm;

void setup()
{
  //lcd.begin(16, 2);
  lcd.backlight();
  //lcd.home();
  lcd.print("LCD Ready ...");
  lcd.createChar(0, colon);
  lcd.createChar(1, ge);
  //lcd.createChar(2, koma);
  delay(1500);
}


void loop()
{
  
  if (RTC.read(tm)){
    //lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(hari[tm.Wday]);
    //lcd.printByte(1);
    lcd.print(", ");
    lcd.print(tm.Day);
    lcd.print(" ");
    lcd.print(bulan[tm.Month-1]);
    lcd.print(" ");
    lcd.print(tmYearToCalendar(tm.Year));
    lcd.setCursor(0, 1);
    lcd.print("Tabuh");
    lcd.setCursor(6, 1);
    lcd.print(digit2(tm.Hour));
    lcd.setCursor(8, 1);
    lcd.printByte(0);
    lcd.print(digit2(tm.Minute));
    lcd.printByte(0);
    lcd.setCursor(12, 1);
    lcd.print(digit2(tm.Second));
  }else{
      lcd.clear();
      lcd.print("DS1307 not Ready");
  }

  delay(1000);
}

String digit2(int number) {
  if (number >= 0 && number < 10) {
    return '0' + (String)number;
  }
  return (String)number;
}
