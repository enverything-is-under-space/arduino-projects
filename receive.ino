//this code from https://x4bx54.medium.com/control-your-homes-infrared-enabled-devices-using-your-smart-phone-30df054a69c2

#include <IRremote.h>
int RECV_PIN = 7; // the pin where you connect the output pin of IR sensor
IRrecv irrecv(RECV_PIN);
decode_results results;
void setup()
{
Serial.begin(9600);
irrecv.enableIRIn();
}
void loop()
{
  if (irrecv.decode(&results))// Returns 0 if no data ready, 1 if data ready.
  {
    int value = results.value;// Results of decoding are stored in result.value
    Serial.print("Code: ");
    Serial.println(results.value, HEX);
    switch (results.decode_type)
    {
      case NEC: Serial.println("NEC"); 
        break ;
      case SONY: Serial.println("SONY"); 
        break;
      case RC5: Serial.println("RC5");
        break;
      case RC6: Serial.println("RC6");
//         break;
//      case DISH: Serial.println("DISH"); break;
//      case SHARP: Serial.println("SHARP"); break ;
//      case JVC: Serial.println("JVC"); break ;
//      case SANYO: Serial.println("SANYO"); break ;
//      case MITSUBISHI: Serial.println("MITSUBISHI"); 
//        break;

//      case SAMSUNG: Serial.println("SAMSUNG"); 
//        break;
//      case LG: Serial.println("LG"); break ;
//      case WHYNTER: Serial.println("WHYNTER"); break ;
//      case AIWA_RC_T501: Serial.println("AIWA_RC_T501"); break ;
//      case PANASONIC: Serial.println("PANASONIC"); break ;
//      case DENON: Serial.println("DENON"); break ;
      default:
        case UNKNOWN: Serial.println("UNKNOWN"); break ;
    }
      Serial.println("");
      irrecv.resume(); // Restart the ISR state machine and Receive the next value
  
    
  }
}
