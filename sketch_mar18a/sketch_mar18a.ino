int sensorValue;
int inByte;
int i;
float voltage;

void setup() {
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  pinMode(14, INPUT);
  Serial.println("Hello, World!");
}

void loop() {

  if (Serial.available() > 0)
    inByte = Serial.read();
  switch (inByte) {
    case'1':
      digitalWrite(12, HIGH);
      Serial.println("1");
      delay(500);
      break;
    case'0':
      digitalWrite(12, LOW);
      Serial.println("0");
      delay(500);
      break;
  }


  sensorValue = analogRead(14);
  Serial.println(sensorValue);
  voltage = sensorValue * 2.5 / 4095;
  Serial.println(voltage);
  delay(500);
  if (voltage > 2)
    digitalWrite(12, HIGH);
  else
    digitalWrite(12, LOW);
}
