#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10  //slave select pin for RFID reader
#define RST_PIN 9  //reset pin for RFID reader
#define LOCK_PIN 8  //pin connected to the lock

MFRC522 mfrc522(SS_PIN, RST_PIN); //MFRC522 instance

void setup() 
{
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  pinMode(LOCK_PIN, OUTPUT); //set lock pin as output
  digitalWrite(LOCK_PIN, HIGH);  //ensure lock is initially locked
  Serial.println("Scan a card");
}

void loop() 
{
  //check for new cards
  if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()) 
  {
    delay(50);
    return;
  }

  if (!mfrc522.PICC_ReadCardSerial()) 
  {
    Serial.println("Error reading card"); //error feedback
    delay(50); //short delay after error
    return;
  }

  // Show UID on serial monitor
  Serial.print("Card UID:");
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  }
  Serial.println();
  const byte authorizedUID[4] = {0xDE, 0xAD, 0xBE, 0xEF};
  bool accessGranted = true;
  for (byte i = 0; i < 4; i++)
  {
    if (mfrc522.uid.uidByte[i] != authorizedUID[i])
    {
      accessGranted = false;
      break;
    }
  }

  if (accessGranted) 
  {
    Serial.println("Access Granted");
    digitalWrite(LOCK_PIN, LOW); //unlock door
    delay(5000);                 //keep door unlocked for 5 seconds
    digitalWrite(LOCK_PIN, HIGH); //lock door again
  } 
  else 
  {
    Serial.println("Access Denied");
  }

 
  mfrc522.PICC_HaltA();  //halt PICC
  mfrc522.PCD_StopCrypto1();  //stop PCD encryption
}
