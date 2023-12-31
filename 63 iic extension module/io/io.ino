/*
 Blink led on PIN0
 by Mischianti Renzo <http://www.mischianti.org>

 https://www.mischianti.org/2019/01/02/pcf8574-i2c-digital-i-o-expander-fast-easy-usage/
*/

#include "Arduino.h"
#include "PCF8574.h"

// Set i2c address
PCF8574 pcf8574(0x3f);

void setup()
{
	Serial.begin(115200);
	delay(1000);

	// Set pinMode to OUTPUT
	pcf8574.pinMode(P0, OUTPUT);
	pcf8574.pinMode(P1, INPUT);
	pinMode(2, OUTPUT);
	Serial.print("Init pcf8574...");
	if (pcf8574.begin()){
		Serial.println("OK");
	}else{
		Serial.println("KO");
	}
}

void loop()
{
  if(pcf8574.digitalRead(P1)){
    digitalWrite(2,LOW);
  }
  else{
    digitalWrite(2,HIGH);
  }
	pcf8574.digitalWrite(P0, HIGH);
	delay(1000);
	pcf8574.digitalWrite(P0, LOW);
	delay(1000);
}
