#include <IRremote.h>


// Connect the IR reciever to pin 8
const int IR_RECV_PIN = 8;

unsigned long key_value = 0;


void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECV_PIN, ENABLE_LED_FEEDBACK); 

}

void loop() {
  // put IrReceiver main code here, to run repeatedly:
  if (IrReceiver.decode()){

    // Stores the value that the sensor recieved
    uint32_t results = IrReceiver.decodedIRData.decodedRawData;

    // Allow the left/right/down key to being pressed continually (The other keys work in the fashion of Key.isDownPressed while this three work like Key.isBeingPressed)  
    if (results == 0x0 && (key_value == 0xF807FB04 || key_value == 0xF906FB04 || key_value == 0xBE41FB04))
          results = key_value;
    
    switch(results){

      // ▲ is pressed
      case 0xBF40FB04:
      Serial.println("up"); 
      break;

      // ▼ is pressed
      case 0xBE41FB04:
      Serial.println("down"); 
      break;

      // ◄ is pressed
      case 0xF807FB04:
      Serial.println("left");
      break;
      
      // ► is pressed
      case 0xF906FB04:
      Serial.println("right");
      break;     
      
      // OK is pressed
      case 0xBB44FB04:
      Serial.println("space");
      break;  

      // TEXT is pressed  
      case 0xDF20FB04:
      Serial.println("c");
      break;  
        

        
    }
    IrReceiver.resume(); 

    key_value = results;

  }



}
