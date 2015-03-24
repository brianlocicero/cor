#include <CapacitiveSensor.h>
CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2);
void setup() {
   cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF); 
   Serial.begin(9600);
   pinMode(7, OUTPUT);
}
void loop() {
    long total1 =  cs_4_2.capacitiveSensor(30);
    //value greater than 100 suggests hand is close to sensor
    if (total1 > 100) {
      Serial.print(total1);
      Serial.print("\n");
      digitalWrite(7, HIGH);
      delay(200);
      digitalWrite(7, LOW);
      delay(50);
      digitalWrite(7, HIGH);
      delay(100);
      digitalWrite(7, LOW);
      delay(800);
    } else {
      digitalWrite(7, LOW);
    }
}
