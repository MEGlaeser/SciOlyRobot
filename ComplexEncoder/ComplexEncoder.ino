#define EncoderA 2
#define EncoderB 7


volatile long totalPulses=0;



void countPulses()
{
  if(digitalRead(EncoderB) != digitalRead(EncoderA))
  {
    totalPulses--;
  }
  else
  {
    totalPulses++;
  }
}

void setup() {
  pinMode(EncoderA, INPUT);
  pinMode(EncoderB, INPUT);
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(EncoderA),countPulses,CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(totalPulses);
}
