/*
 * Author: Manash Kumar Mandal
 * Example For sending data to SerialPort
 */

#define BAUD 9600
#define DELAY_TIME 20

const int up = 2;

void setup() {
  Serial.begin(BAUD);
  pinMode(up, INPUT);
}

//MouseX,MouseY,Click,Attack1,Attack2,Attack3,Attack4,Attack5
void loop() {
  if (digitalRead(up) == HIGH) {
    Serial.println("500,200,1,1,1,1,1,1");
  } else {
    Serial.println("500,200,0,1,1,1,1,1");
  }
  delay(DELAY_TIME);
}
