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


    if (results == 0x0)
          results = key_value;
    
    switch(results){
      case 0xB946FF00:
      Serial.println("CH"); 
      break;

      case 0xEA15FF00:
      Serial.println("+"); 
      break;

      case 0xBB44FF00:
      Serial.println("|<<");
      break;

      case 0xBC43FF00:
      Serial.println("|>||");
      break;     
        
      case 0xBF40FF00:
      Serial.println(">>|");
      break;  
        
      case 0xF807FF00:
      Serial.println("-");
      break;  
        

        
    }
    IrReceiver.resume(); 

    key_value = results;

  }



}
