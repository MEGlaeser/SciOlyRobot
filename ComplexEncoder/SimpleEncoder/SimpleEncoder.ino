#define EncoderA 2
#define EncoderB 7


volatile long totalPulses=0;



void countPulses()
{
  if(digitalRead(EncoderB)>0)
  {
    totalPulses++;
  }
  else
  {
    totalPulses--;
  }
}

void setup() {
  pinMode(EncoderA, INPUT);
  pinMode(EncoderB, INPUT);
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(EncoderA),countPulses,RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(totalPulses);
}
