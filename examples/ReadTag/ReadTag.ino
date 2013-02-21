#include <Wire.h>
#include <Adafruit_NFCShield_I2C.h>
#include <NfcAdapter.h>

NfcAdapter nfc = NfcAdapter();

void setup(void) {
  Serial.begin(115200);
  Serial.println("NDEF Reader");
  nfc.begin();
}

void loop(void) {
  Serial.println("\nScan a NFC tag");
  if (nfc.tagPresent())
  {
    NdefMessage message = nfc.read();
    message.print();
  }
  delay(5000);
}