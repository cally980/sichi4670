## 코드설명

pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
초음파 센서의 핀모드는 Trig핀에서 초음파를 내보내기 때문에 OUTPUT으로 설정 하고 Echo핀으로 반사되는 음파를 받아들여 전압으로 변환 시키기 때문에 INPUT으로 설정해 줍니다.

duration = pulseIn(echo,HIGH); 
pulsIn함수는 pulsIn(핀번호, 핀상태)의 형태로 이루어져 있으며 핀 상태가 바뀌면 그때까지 경과한 시간을 ms(마이크로 세컨드)단위로 반환시켜줍니다.

초음파 센서에서는 echo핀이 HIGH였다고 초음파를 받으면서 LOW로 바뀌기 때문에 pulsIn함수를 이용해서 초음파가 날아온 시간을 측정할 수 있습니다.

이를 바탕으로 위 코드를 해석해보면 아래와 같이 진행된다는 것을 알 수 있습니다.
trig(HIGH) - 초음파 발사 - trig(LOW) - 발사중지 - 물체에 맞고 돌아온 초음파를 echo(HIGH)핀으로 받음 - echo(LOW) - 거리계산 - 반복

distance = ((34000*duration)/1000000)/2;
거리를 cm단위로 측정하기 위해서 소리의 속도(340m/s)와 초음파가 돌아온 시간(마이크로세컨드)를 계산한 식 입니다. 그리고 초음파가 발사되서 돌아오는 시간에 나누기 2를 해주어서 편도 거리를 계산합니다.

아래는 초음파센서와 피에조부저, LED를 이용한 간단한 경보기를 만들어 보았습니다.


![회로도](http://blogfiles.naver.net/MjAxNzAxMjNfMjkz/MDAxNDg1MTQ0NDM3NzU3.PbGAf7tcHeMxpbo0b_NTkZcz3E_NClJQmM3o9MTnvRkg.1HIhMHggplwzHLcILH8v9qISjFowSDvGHhaGDYTColcg.JPEG.3demp/ultrasonic_alram.jpeg)
## 코드

--------------------------------------------------------------------------------
```
int trig = 2;
int echo = 3;
int buzzer = 8;
int LED = 9;
float duration;
float distance;

void setup() 
{
  Serial.begin(9600);
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  pinMode(buzzer,OUTPUT);
  //pinMode(LED, OUTPUT);
}

void loop() 
{
  digitalWrite(trig,HIGH);
  delay(10);
  digitalWrite(trig,LOW);
  duration = pulseIn(echo,HIGH);
  distance = ((34000*duration)/1000000)/2;
  Serial.print(distance);
  Serial.println("cm");

  if(distance < 20)
  {
  //  analogWrite(LED,255-(distance*12));
    
    tone(buzzer,1000,100);
    delay(100);
    tone(buzzer,1000,100);
    delay(100);
  
  else
  {
  //  digitalWrite(LED,LOW);
  }
  
  delay(100);
}
```
--------------------------------------------------------------------------------------

 거리감의 알람소리랑 케이스와 전선긴거사기