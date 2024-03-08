#define speed 255
#define MoveTime 800
#define TurnTime 800
#define StopTime 1500
#define PWMR 6           // Right Wheel PWM pin to the motor driver ENA pin
#define RightForward 8   // Right Motor direction pin 1 to the motor driver IN1 pin
#define RightBackward 7   // Right Motor direction pin 2 to the motor driver IN2 pin
#define LeftForward 10   // Left Motor direction pin 1 to the motor driver IN3 pin
#define LeftBackward 11   // Left Motor direction pin 2 to motor driver IN4 pin
#define PWML 12          // Left Wheel PWM pin to the motor driver ENB pin

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void RightWheelsForward()
{
  digitalWrite(RightForward, HIGH);
  digitalWrite(RightBackward, LOW);
  analogWrite(PWMR, speed);
}
void RightWheelsBackward()
{
  digitalWrite(RightForward, LOW);
  digitalWrite(RightBackward, HIGH);
  analogWrite(PWMR, speed);
}
void LeftWheelsForward()
{
  digitalWrite(LeftForward, HIGH);
  digitalWrite(LeftBackward, LOW);
  analogWrite(PWML, speed);
}
void LeftWheelsBackward()
{
  digitalWrite(LeftForward, LOW);
  digitalWrite(LeftBackward, HIGH);
  analogWrite(PWML, speed);
}
void stop()
{
  analogWrite(PWML, 0);
  analogWrite(PWMR, 0);
}
void init_GPIO() {
  pinMode(RightForward, OUTPUT);
  pinMode(RightBackward, OUTPUT);
  pinMode(PWML, OUTPUT);
  pinMode(LeftForward, OUTPUT);
  pinMode(LeftBackward, OUTPUT);
  pinMode(PWMR, OUTPUT);
  stop();
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------

void forward(int step) {
  for (int i = 0; i < step; i++) {
    RightWheelsForward();
    LeftWheelsForward();
    delay(MoveTime);
    stop();
    delay(StopTime);

  }
}
void backward(int step) {
  for (int i = 0; i < step; i++) {
    RightWheelsBackward();
    LeftWheelsBackward();
    delay(MoveTime);
    stop();
    delay(StopTime);

  }
}
void right(int step) {
  for (int i = 0; i < step; i++) {
    LeftWheelsForward();
    RightWheelsBackward();
    delay(TurnTime);
    stop();
    delay(StopTime);

  }
}
void left(int step) {
  for (int i = 0; i < step; i++) {
    RightWheelsForward();
    LeftWheelsBackward();
    delay(TurnTime);
    stop();
    delay(StopTime);

  }
}


void setup() {
  init_GPIO();
  forward(1);
  backward(1);

}

void loop() {
  // put your main code here, to run repeatedly:

}
