//this is from https://x4bx54.medium.com/control-your-homes-infrared-enabled-devices-using-your-smart-phone-30df054a69c2
#include <IRremote.h>
// Referring to the IRRemote function library, the header file defined PIN 3 as the signal output, so it can only connect to PIN 3. Do check if it out if you’re not using the UNO or wish to change the PIN out.
IRsend irsend;
void setup()
{
    Serial.println("ready");
}
void loop()
{
  delay(1000);
  //irsend.sendNEC(0xFFE01F, 32);
  delay(1000);
  irsend.sendNEC(0xF720DF, 32);
  delay(1000);
  irsend.sendNEC(0xF720DF, 32);
}
