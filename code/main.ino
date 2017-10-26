const int trig = 2;
const int echo = 3;
const int buzzer = 9;
const int LED = 8;

float duration;
float distance;
int timeThreshHold = 1000;

void setup()
{
  Serial.begin(9600);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop()
{
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = ((34000 * duration) / 1000000) / 2;
  Serial.print(distance);
  Serial.println("cm");

  if (distance < 30)
  {
    for (int timeIndex = 0; timeIndex < timeThreshHold; timeIndex += 100) {
      tone(buzzer, 1000, timeIndex);
      delay(timeIndex*2);
    }
  }
  else if (distance < 50 )
  {
    for (int timeIndex = 0; timeIndex < timeThreshHold; timeIndex += 200) {
      tone(buzzer, 900, timeIndex);
      delay(timeIndex*2);
    }
  }
  else if (distance < 70 )
  {
    for (int timeIndex = 0; timeIndex < timeThreshHold; timeIndex += 300) {
      tone(buzzer, 800, timeIndex); 
      delay(timeIndex*2);
    }
  }
  else if (distance < 90 )
  {
    for (int timeIndex = 0; timeIndex < timeThreshHold; timeIndex += 400) {
      tone(buzzer, 700, timeIndex);
      delay(timeIndex*2);
    }
  }
  else if (distance < 120 )
  {
    for (int timeIndex = 0; timeIndex < timeThreshHold; timeIndex += 500) {
      tone(buzzer, 600, timeIndex); 
      delay(timeIndex*2);
    }
  }
  delay(500);
}
