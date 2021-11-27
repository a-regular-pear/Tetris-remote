#include <IRremote.h>

const int IR_RECV_PIN = 8;

unsigned long key_value = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("First");
  IrReceiver.begin(IR_RECV_PIN, ENABLE_LED_FEEDBACK); 

}

void loop() {
  // put IrReceiver main code here, to run repeatedly:
  if (IrReceiver.decode()){

    uint32_t results = IrReceiver.decodedIRData.decodedRawData;


    if (results == 0x0 && (key_value == 0xF807FB04 || key_value == 0xF906FB04 || key_value == 0xBE41FB04))
          results = key_value;
    
    switch(results){
      case 0xBF40FB04:
      Serial.println("up"); 
      break;

      case 0xBE41FB04:
      Serial.println("down"); 
      break;

      case 0xF807FB04:
      Serial.println("left");
      break;

      case 0xF906FB04:
      Serial.println("right");
      break;     
        
      case 0xBB44FB04:
      Serial.println("space");
      break;  
        
      case 0xDF20FB04:
      Serial.println("c");
      break;  
        

        
    }
    IrReceiver.resume(); 

    key_value = results;

  }



}
