int button=8;
int buz=7;
int flag=0;
int runHours=0;
unsigned long allSeconds=0;

void setup() 
{
//  Serial.begin(9600);
  pinMode(button,INPUT);
  pinMode(buz,OUTPUT);
}
  

void loop() 
{

            allSeconds=millis()/1000;
            runHours= allSeconds/3600;
            
  if(runHours>=1 && flag==1)
  {
        tone(buz,1,5000);
        delay(500);
        tone(buz,100,5000);
        delay(500);
        tone(buz,359,5000);
        delay(1800);
//        flag=0;
  }
  else
  {
      if(digitalRead(button)==LOW)
      {
          if(flag==0)
          {
            flag=1;//means start calculation time 
            tone(buz,1500,500);
//            Serial.println("button pressed flag=1 START.");
          }
      }
  }
//  Serial.println(millis());
}


/*void printTime()
    {
            unsigned long runMillis= millis();
            unsigned long allSeconds=millis()/1000;
            runHours= allSeconds/3600;
            int secsRemaining=allSeconds%3600;
            int runSeconds=secsRemaining%60;
            char buf[21];
            sprintf(buf,"Runtime%02d:%02d:%02d",runHours,runMinutes,runSeconds);
            Serial.println(buf);
            delay(1000);
          }*/
