
const byte numSensors = 8;
const byte maxPWM = 255;

const byte testCase = 0;

struct SensorReadings {
  int values[8];
};

enum State { NORMAL, LOST, JUNCTION, MARKER };

const char* stateName(State s) {
  switch (s) {
    case NORMAL:   return "NORMAL";
    case LOST:     return "LOST";
    case JUNCTION: return "JUNCTION";
    case MARKER:   return "MARKER";
    default:       return "UNKNOWN";
  }

}

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

int classify(const SensorReadings &s) {
  byte numBlackSensors = 0;
  byte leftSensors= 0;
  byte centerSensors= 0;
  byte rightSensors= 0;

  bool L = false;
  bool C = false;
  bool R = false;

  bool edgeL = 0;
  bool edgeR = 0;

  for (int i = 0; i < numSensors; i++) {
    if (s.values[i] > 500){
      numBlackSensors++;
    }

    if(i <= 2 && s.values[i] > 500) {
      leftSensors++;
    }

    if(i >= 3 && i <= 4 && s.values[i] > 500) {
      centerSensors++;
    }

    if(i >= 5 && i <= 7 && s.values[i] > 500) {
      rightSensors++;
    }
  }

  L = leftSensors > 0;
  C = centerSensors > 0;
  R = rightSensors > 0;
}

SensorReadings sensors;

void setup() {
  Serial.begin(9600);
  
}

void loop() {
  Serial.println();
  delay(500);
}
