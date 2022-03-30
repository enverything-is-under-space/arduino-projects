int buz=7;
int but=8;
int flag=0;

void setup() 
{
  pinMode(but,INPUT);
  pinMode(buz,OUTPUT);
}

void restStop()
{
              tone(buz,3000,1500);
              delay(500);
}
void restStart()
{
              tone(buz,1000,1500);
              delay(500);
}
void standAlarm()
{
        for(int i=1;i<=5;i++)
        {
              tone(buz,1,1000);
              delay(500);
              tone(buz,100,1000);
              delay(500);
              tone(buz,359,1000);
              delay(500);
        }
}
void loop()
{
  int butstatus= digitalRead(but);
  if(butstatus==LOW)
  {
        delay(3600);
        standAlarm();

                          delay(5000);
        
        restStart();
        delay(900);
        restStop();
  }
}
