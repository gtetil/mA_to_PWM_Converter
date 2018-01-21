
int aiPin = A0;
int pwmPin = 3;
int maxOnTime = 128; //microseconds
int onTime = 0;
int aiRead = 0;

void setup() {

  ADCSRA &= ~(bit (ADPS0) | bit (ADPS1) | bit (ADPS2)); // clear prescaler bits
  ADCSRA |= bit (ADPS2); 
  pinMode(pwmPin, OUTPUT);

}

void loop() {
  
  if (aiRead > 10) {
    digitalWrite(pwmPin, HIGH);
    delayMicroseconds(aiRead);
  }
  aiRead = analogRead(aiPin) >> 3;
  digitalWrite(pwmPin, LOW);
  delayMicroseconds(maxOnTime - aiRead);

}
