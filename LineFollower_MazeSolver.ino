
const byte numSensors = 8;
const byte maxPWM = 255;

const byte testCase = 0;

struct SensorReadings {
  int values[8];
};

void fakeSensorReading(SensorReadings &s, int testcase) {
  switch (testcase) {
    case 0:
      s.values[0] = 100;
      s.values[1] = 100;
      s.values[2] = 100;
      s.values[3] = 900;
      s.values[4] = 900;
      s.values[5] = 100;
      s.values[6] = 100;
      s.values[7] = 100;
      break;
    case 1:
      s.values[0] = 100;
      s.values[1] = 100;
      s.values[2] = 900;
      s.values[3] = 900;
      s.values[4] = 100;
      s.values[5] = 100;
      s.values[6] = 100;
      s.values[7] = 100;
      break;
    case 2:
      s.values[0] = 100;
      s.values[1] = 100;
      s.values[2] = 100;
      s.values[3] = 100;
      s.values[4] = 900;
      s.values[5] = 900;
      s.values[6] = 100;
      s.values[7] = 100;
      break;
    case 3:
      s.values[0] = 100;
      s.values[1] = 100;
      s.values[2] = 100;
      s.values[3] = 100;
      s.values[4] = 100;
      s.values[5] = 100;
      s.values[6] = 100;
      s.values[7] = 100;
      break;
    case 4:
      for (int i = 0; i < 8; i++) {
      s.values[i] = 900;
      }
    default:
      for (int i = 0; i < 8; i++) {
      s.values[i] = 100;
      }
  break;
  }
}

SensorReadings sensors;

void setup() {
  Serial.begin(9600);
  
}

void loop() {
  for(int i = 0; i < 4; i++) {
    fakeSensorReading(sensors, i);
    for (int j = 0; j < numSensors; j++) {
      if (j == 7) {
        Serial.println(sensors.values[j]);
      } else {
        Serial.print(sensors.values[j]);
        Serial.print(" ");
      }
      delay(100);
    }
    delay(2000);
  }
}
