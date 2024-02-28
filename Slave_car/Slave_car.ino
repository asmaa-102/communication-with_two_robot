
#define IN1 7
#define IN2 6
#define IN3 5
#define IN4 4
#define ENA 9
#define ENB 10
int distance = 0;


void setup() {
  // put your setup code here, to run once:
pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(IN4,OUTPUT);
pinMode(ENA,OUTPUT);
pinMode(ENB,OUTPUT);

Serial.begin(9600);

}

void loop() {
  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);
 
 while(Serial.available()>0)
  {
    
    char v = Serial.read();
    
    if(v == 'R')
    {
      Serial.println(v);
      
       backward();
       delay(100);
      TurnRight();
      delay(150);
      forward();
      
      
      
    }
      else if (v =='L')
      {
        Serial.println(v);
      
       backward();
       delay(150);
      TurnLeft();
      delay(150);
      forward();
      
      
      }
           
    else 
   {
      delay(150);
      forward(); 
   }


}
}


void backward()
{
 
  analogWrite(ENA, 60);
  analogWrite(ENB, 60);
  
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  
}
void forward()
{

  
  
  analogWrite(ENA, 60);
  analogWrite(ENB, 60);
  
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  
}

void TurnLeft()
{
  analogWrite(ENA,60);
  analogWrite(ENB,60);
  
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);

  delay(300);

  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  
}

void TurnRight()
{
  analogWrite(ENA, 60);
  analogWrite(ENB, 60);
  
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);

  delay(300);

  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  
}
void movestop()
{ 
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}
