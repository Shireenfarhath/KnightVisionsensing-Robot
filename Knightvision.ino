int trigpin=7;
int echopin=6;
volatile float dist;
volatile float time;
int a=4;
int b=3;
int ldr;
int buzzer=5;

void setup()
{
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(buzzer,OUTPUT);
}
void loop()
{
    ldr=analogRead(A0);
  
  while(ldr==1)
  { 
    
    
    digitalWrite(trigpin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigpin,HIGH);
    delayMicroseconds(2);
    digitalWrite(trigpin,LOW);
    time=pulseIn(echopin,HIGH);
    dist=time*(0.034/2);
    Serial.println(dist);
    
    if(dist<40)
    {
      digitalWrite(a,LOW);
      digitalWrite(buzzer,HIGH);
    }
    else
    {
      digitalWrite(a,HIGH);
      
      digitalWrite(buzzer,LOW);
    }
  }
}