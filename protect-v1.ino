#include <IRremote.h>

int pirpin = 13;
int iscoming = 0;
int touchpin = 8;
int istouched = 0;
IRsend irsend;
void setup() 
{
  Serial.begin(9600);
  pinMode(pirpin, INPUT);
  pinMode(touchpin, INPUT);
  Serial.println("lets go");
}

void loop() 
{
  changeViaTouch();
  delay(1000);
  iscoming = digitalRead(pirpin);
  if(iscoming == 1) 
  {
    iscoming = 0;
    Serial.println("semeone is coming.");
    irsend.sendNEC(0xF7B04F, 32);
    changeViaTouch();
  }
  changeViaTouch();
}

void changeViaTouch()
{
  iscoming = 0;
  istouched = digitalRead(touchpin);
  if(istouched == 1)
  {
    istouched = 0;
    Serial.println("touched");
    irsend.sendNEC(0xF7E01F, 32);   
  }
}
