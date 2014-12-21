int ANALOG_NUM =6;
int DIGITAL_NUM = 14;
void setup()
{
  Serial.begin(9600);
  for(int pin = 0; pin < ANALOG_NUM; ++pin) {
    analogWrite(pin, 0);
  }
  for(int pin = 0; pin < DIGITAL_NUM; ++pin) {
    digitalWrite(pin, LOW);
  }
}

void loop()
{
  int index = 0;
  for(int pin = 0; pin < ANALOG_NUM; ++pin, ++index) {
    unsigned char data[] = {index, map(analogRead(pin), 0, 1023, 0, 255)};
    Serial.write(data, 2);
  }
  for(int pin = 0; pin < DIGITAL_NUM; ++pin, ++index) {
    unsigned char data[] = {index, digitalRead(pin)==HIGH?255:0};
    Serial.write(data, 2);
  }
  delay(30);
}
