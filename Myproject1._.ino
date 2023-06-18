
const int temperaturePin = A0;
bool ledBlinking = true;
bool tempSensorEnabled = true;

void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();

    if (command == '1') {
      ledBlinking = true;
      Serial.println("Turn on LED");
    } else if (command == '0') {
      ledBlinking = false;
      digitalWrite(9, 0);
      Serial.println("Turn off LED");
    } else if (command == '2') {
      tempSensorEnabled = false;
      Serial.println("Temperature sensor disabled");
    } else if (command == '3') {
      tempSensorEnabled = true;
      Serial.println("Temperature sensor enabled");
    }
  }

  if (tempSensorEnabled) {
    int sensorValue = analogRead(temperaturePin);
    float voltage = sensorValue * (5.0 / 1023.0);
    float temperatureC = (voltage - 0.5) * 100.0;

    Serial.print("Temperature: ");
    Serial.print(temperatureC);
    Serial.println(" degrees Celsius");
  }

  if (ledBlinking) {
    analogWrite(9, 64);
    Serial.println("LED Brightness 25%");
    delay(1000);
    analogWrite(9, 127);
    Serial.println("LED Brightness 50%");
    delay(1000);
    analogWrite(9, 255);
    Serial.println("LED Brightness 100%");
    delay(1000);
    analogWrite(9, 0);
    Serial.println("LED brightness 0%");
    delay(1000);
  }
}


