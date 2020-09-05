int trigPin = 12;
int echoPin = 11;
int buzzer = 10;
int LED1 = 9;
int LED2 = 8;
int LED3 = 7;
long duration;
int distance;
void setup() 
{
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);
digitalWrite(LED1,LOW);
digitalWrite(LED2,LOW);
digitalWrite(LED3,LOW);
Serial.begin(9600); 
}
void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
if(distance<=10){
  digitalWrite(LED1,HIGH);
  digitalWrite(LED2,HIGH);
  digitalWrite(LED3,HIGH);
  tone(buzzer, 2500); 
}
else if (distance<=25){
  
  digitalWrite(LED1,HIGH);
  digitalWrite(LED2,HIGH);
  digitalWrite(LED3,LOW);
  tone(buzzer, 2500); 
  delay(50);        
  noTone(buzzer);
  delay(50);
}
else if(distance<=50){
  digitalWrite(LED1,HIGH);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
  tone(buzzer, 2500); 
  delay(250);        
  noTone(buzzer);
  delay(250);
}
else{
  
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
  noTone(buzzer);
}
Serial.print("Distance from the object = ");
Serial.print(distance);
Serial.println(" cm");
delay(1000);
}
