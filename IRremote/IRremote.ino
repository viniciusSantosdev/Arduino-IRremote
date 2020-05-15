#include <IRremote.h>

int led = 7;

IRrecv receptor(8);
decode_results resultado;

void setup() {
  pinMode(led, OUTPUT);
  receptor.enableIRIn();
  Serial.begin(9600);
}

void loop() {
  if (receptor.decode(&resultado)){
    Serial.print("Codigo do botao: ");
    Serial.println(resultado.value, HEX);
    receptor.resume();

    if(resultado.value == 0xFDA857) {
      digitalWrite(led, 1);
    }
    else if(resultado.value == 0xFD6897){
      digitalWrite(led, 0);
    }

  }
  delay(100);

}
