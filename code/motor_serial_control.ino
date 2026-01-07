/* -------- L298N + UNO SERIAL CONTROL --------
   Commands:
   F - Forward
   B - Backward
   L - Left
   R - Right
   S - Stop
   0–9 - Speed control (0 = stop, 9 = full speed)
--------------------------------------------- */

#define ENA 5
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11
#define ENB 6

int speedVal = 180;  // Default speed (0–255)

void setup() {
  Serial.begin(9600);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  stopMotors();
  Serial.println("READY: F B L R S | Speed 0-9");
}

void loop() {
  if (Serial.available()) {
    char cmd = Serial.read();

    switch (cmd) {

      case 'F':
        forward();
        break;

      case 'B':
        backward();
        break;

      case 'L':
        left();
        break;

      case 'R':
        right();
        break;

      case 'S':
        stopMotors();
        break;

      case '0'...'9':
        speedVal = map(cmd - '0', 0, 9, 0, 255);
        analogWrite(ENA, speedVal);
        analogWrite(ENB, speedVal);
        Serial.print("SPEED SET TO: ");
        Serial.println(speedVal);
        break;

      default:
        Serial.println("INVALID COMMAND");
        break;
    }
  }
}

/* -------- MOTOR FUNCTIONS -------- */

void forward() {
  analogWrite(ENA, speedVal);
  analogWrite(ENB, speedVal);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("FORWARD");
}

void backward() {
  analogWrite(ENA, speedVal);
  analogWrite(ENB, speedVal);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("BACKWARD");
}

void left() {
  analogWrite(ENA, speedVal);
  analogWrite(
