#include <Arduino.h>
#include "bitset.h"
// #include "SSD1306Wire.h"

const int out_pin = D1; 
const int pulse_burst = 562; //640; 
const int ms_zero = 1687; //1591;
const int ms_one = 562; //525;

// SSD1306Wire  display(0x3c, D2, D1);

struct Packet
{
   using BS8 = Bitset<8>;
   BS8 address {0b00000000};
   BS8 address_inverse {0b00000000};
   BS8 command {0b00000000};
   BS8 command_inverse {0b00000000};

   void signal(int ms, int mode){
      digitalWrite(out_pin, mode);
      delayMicroseconds(ms);
   }
   

   void send_byte(BS8& byte){
      for(auto b : byte){
         signal(pulse_burst, LOW);
         signal(b ? ms_zero : ms_one, HIGH);

         digitalWrite(out_pin, HIGH);
         Serial.println(b);
      }
      Serial.println("------");
   }

   void send(){
      signal(9000, HIGH);
      signal(4500, LOW);

      send_byte(address);
      send_byte(address_inverse);
      send_byte(command);
      send_byte(command_inverse);

      signal(pulse_burst, HIGH);

      digitalWrite(out_pin, LOW);
      Serial.println("DONE");
  }

};



void setup() {
  Serial.begin(115200);
  pinMode(out_pin, OUTPUT);
//   digitalWrite(out_pin, LOW); // Always low

   // display.init();
   // display.setContrast(255);
     pinMode(LED_BUILTIN, OUTPUT); 
}


void loop() {

  
  digitalWrite(out_pin, HIGH); 
  digitalWrite(LED_BUILTIN, LOW);
  delay(1500);
   

   digitalWrite(out_pin, LOW);
   digitalWrite(LED_BUILTIN, HIGH);
   delay(3000);
}

void lp() {
   // ------------------------------------------------- IMPLEMENT LAST PULSE WIDTH (YELLOW IN IMAGES)
   //    display.clear();
   // display.drawString(1, display.getHeight()/2, "Sending");
   // display.display();

  Serial.println("Hello World...");
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(out_pin, HIGH); 
  delay(300);
   
  Packet p;
  p.address = 0b00000000;
  p.address_inverse = 0b11111001;
  p.command = 0b01110000;
  p.command_inverse = 0b10001111; 

//   p.send();




      // display.clear();
   // display.display();
   digitalWrite(out_pin, LOW);
   digitalWrite(LED_BUILTIN, HIGH);
   delay(3000); // wait for a second
  


   
}

