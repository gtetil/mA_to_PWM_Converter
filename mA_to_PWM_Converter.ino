
int aiPin = A1;
int pwmPin = 3;
int maxOnTime = 128; //microseconds
int onTime = 0;
int aiRead = 0;

void setup() {

  ADCSRA &= ~(bit (ADPS0) | bit (ADPS1) | bit (ADPS2)); // clear prescaler bits
  ADCSRA |= bit (ADPS2); 
  pinMode(pwmPin, OUTPUT);

  //soft start
  delay(5000);
  aiRead = analogRead(aiPin) >> 3;
  if (aiRead > 10) {
    for (int i = 0; i < 15000; i++) {
      digitalWrite(pwmPin, HIGH);
      delayMicroseconds(20);
      digitalWrite(pwmPin, LOW);
      delayMicroseconds(108);
    }
    for (int i = 0; i < 15000; i++) {
      digitalWrite(pwmPin, HIGH);
      delayMicroseconds(64);
      digitalWrite(pwmPin, LOW);
      delayMicroseconds(64);
    }
    for (int i = 0; i < 15000; i++) {
      digitalWrite(pwmPin, HIGH);
      delayMicroseconds(110);
      digitalWrite(pwmPin, LOW);
      delayMicroseconds(18);
    }
  }

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
