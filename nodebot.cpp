int ePin1 = 10; // Enable pin 1 on digital 10
int ePin2 = 9; // Enable pin 2 on digital 9
int m1Pin1 = 6; // Signal Pin 1 motor 1  (I1 on L293D motor driver)
int m1Pin2 = 5; // Signal Pin 2 motor 1  (I1 on L293D motor driver)
int m2Pin1 = 4; // Signal Pin 1 motor 2  (I1 on L293D motor driver)
int m2Pin2 = 3; // Signal Pin 2 motor 2  (I1 on L293D motor driver)


void setup() {
    Serial.begin(9600);
    pinMode(ePin1, OUTPUT);
    pinMode(ePin2, OUTPUT);
    pinMode(m1Pin1, OUTPUT);
    pinMode(m1Pin2, OUTPUT);
    pinMode(m2Pin1, OUTPUT);
    pinMode(m2Pin2, OUTPUT);
    digitalWrite(ePin1, HIGH);
    digitalWrite(ePin2, HIGH);
    digitalWrite(m1Pin1, LOW);
    digitalWrite(m1Pin2, LOW);
    digitalWrite(m2Pin1, LOW);
    digitalWrite(m2Pin2, LOW);
}
void loop() {
    char ch;
    while (Serial.available() > 0) {

        ch = Serial.read();

        while (ch == 'D') {  // Rotate clockwise - check motor connections to swap with custom value
            digitalWrite(m1Pin1, HIGH);
            digitalWrite(m1Pin2, LOW);
            digitalWrite(m2Pin1, LOW);
            digitalWrite(m2Pin2, HIGH);
            Serial.flush();
            break;
        }
        while (ch == 'A') { // Rotate counter-clockwise - check motor connections to swap with custom value
            digitalWrite(m1Pin1, LOW);
            digitalWrite(m1Pin2, HIGH);
            digitalWrite(m2Pin1, HIGH);
            digitalWrite(m2Pin2, LOW);
            Serial.flush();
            break;
        }
        while (ch == 'W') { // Move forward - check motor connections to swap with custom value
            digitalWrite(m1Pin1, HIGH);
            digitalWrite(m1Pin2, LOW);
            digitalWrite(m2Pin1, HIGH);
            digitalWrite(m2Pin2, LOW);
            Serial.flush();
            break;
        }
        while (ch == 'X') { // Move back - check motor connections to swap with custom value
            digitalWrite(m1Pin1, LOW);
            digitalWrite(m1Pin2, HIGH);
            digitalWrite(m2Pin1, LOW);
            digitalWrite(m2Pin2, HIGH);
            Serial.flush();
            break;
        }
        while (ch == 'S') { // Stop 
            digitalWrite(m1Pin1, LOW);
            digitalWrite(m1Pin2, LOW);
            digitalWrite(m2Pin1, LOW);
            digitalWrite(m2Pin2, LOW);
            Serial.flush();
            break;
        }
    }
}