#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define SS_PIN 10       
#define RST_PIN 9       
#define BUZZER_PIN 7    

#define BEEP_FREQUENCY 1500  
#define BEEP_DURATION 50     
#define BEEP_GAP 50          


MFRC522 mfrc522(SS_PIN, RST_PIN);

String rfid_tags[] = {
  "7560562c", "55171553", "5dd37cc3", "ad1169c3", "61113f43", "6160a2a", "4d67ec3","7176c6b "//put your rfid card numbers here 
};
String messages[] = {
  "BOURBON - RS 10",
  "PEPSI BLACK - RS 20",
  "LAYS - RS 20",
  "GEMS - RS 40",
  "MAGGIE - RS 10",
  "LAYS RED - RS 20",
  "KURKURE - RS 25",
  "Access Denied, Unknown User!"
};

void setup() {
  Serial.begin(9600);  // Start serial communication for debugging


  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);  
  }
  
   display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("SCAN YOUR"));
  display.setCursor(0, 10);
  display.println(F("PRODUCT"));
  display.display();
  delay(2000);

  
  SPI.begin();
  mfrc522.PCD_Init();
  
  
  pinMode(BUZZER_PIN, OUTPUT);

  
  if (mfrc522.PCD_PerformSelfTest()) {
    Serial.println(F("RFID Reader is successfully initialized"));
  } else {
    Serial.println(F("RFID Reader initialization failed"));
    while (true);
  }
}

void loop() {
  
  if (mfrc522.PICC_IsNewCardPresent()) {
    if (mfrc522.PICC_ReadCardSerial()) {
  
      String rfid_uid = "";
      for (byte i = 0; i < mfrc522.uid.size; i++) {
        rfid_uid += String(mfrc522.uid.uidByte[i], HEX);
      }

      Serial.print(F("UID of the card: "));
      Serial.println(rfid_uid);

  
      String message = "Unknown Card";
      for (int i = 0; i < 7; i++) {   
        if (rfid_uid == rfid_tags[i]) {
          message = messages[i];  
          break;  
        }
      }

      
      display.clearDisplay();
      display.setTextSize(1);
      display.setCursor(0, 20);
      display.println(F("PRODUCT Scanned "));
      display.setCursor(0, 0);
      display.println(message);
      display.display();

      
      scanningBeep();

      
      delay(1000);

      
      display.clearDisplay();
      display.setCursor(0, 0);
      display.println(F("SCAN YOUR"));
      display.setCursor(0, 10);
      display.println(F("PRODUCT"));
      display.display();

      
      delay(500);
    }
  }
}


void scanningBeep() {
  for (int i = 0; i < 3; i++) {
    tone(BUZZER_PIN, BEEP_FREQUENCY);
    delay(BEEP_DURATION);            
    noTone(BUZZER_PIN);              
    delay(BEEP_GAP);                 
  }
}
