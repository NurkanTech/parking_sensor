#define echoPin 5
#define trigPin 6
#define buzzerPin 8

int maxRange=100;  //'maxRange-minRange'--> measurement range (max:400cm for HCSR04)
int minRange =0;

void setup() {
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(buzzerPin,OUTPUT);
}

void loop() {
  int measurement=dist(maxRange,minRange);
  melody(measurement*10);

}
int dist(int maxrange, int minrange)
{
  long duration,distance;

  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=duration/58.2;   // transformation for duration to distance 
  delay(50);

  if(distance==maxrange || distance==minrange)
    return 0;
    return distance;
    }

  int melody(int dly)
  {
    tone(buzzerPin,3);
    delay(dly);
    noTone(buzzerPin);
    delay(dly);  // dly=measurement*10

    
  }