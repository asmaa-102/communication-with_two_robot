// Define pins for motor driver module
#define IN1 7
#define IN2 6
#define IN3 5
#define IN4 4
#define ENA 9
#define ENB 10
// Define pins for ultrasonic sensors
#define trigPinLeft 8
#define echoPinLeft 11
#define trigPinRight 12
#define echoPinRight 13
// Define variables for distance readings
long durationLeft, distanceLeft;
long durationRight, distanceRight;
int v ;


void setup() {
  // put your setup code here, to run once:
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  
  // Set ultrasonic sensor pins as input/output
  pinMode(trigPinLeft, OUTPUT);
  pinMode(echoPinLeft, INPUT);
  pinMode(trigPinRight, OUTPUT);
  pinMode(echoPinRight, INPUT);
  
  // Initialize serial communication
  Serial.begin(9600);

}
void loop() 
{
  // Read distance from left sensor
  digitalWrite(trigPinLeft, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinLeft, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinLeft, LOW);
  durationLeft = pulseIn(echoPinLeft, HIGH);
  distanceLeft = durationLeft * 0.034 / 2;

  // Read distance from right sensor
  digitalWrite(trigPinRight, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinRight, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinRight, LOW);
  durationRight = pulseIn(echoPinRight, HIGH);
  distanceRight = durationRight * 0.034 / 2;

  // Print distance readings to serial monitor
  Serial.print("Distance left: ");
  Serial.print(distanceLeft);
  Serial.print("cm");
  Serial.print("\t");
  Serial.print("Distance right: ");
  Serial.print(distanceRight);
  Serial.println("cm");
  // Check for obstacles and adjust motor speed accordingly
  if (distanceLeft < 25  ) 
  {
     
       backward();
       delay(200);
      TurnRight();
      delay(150);
      forward();
      Serial.println('R');
  }
 else if(distanceRight < 25 )
  {
   
    
      
       backward();
       delay(200);
       
      TurnLeft();
      delay(150);
      forward();
     
      Serial.println('L');
    
  }
  else
  {
    forward();
  }
}

void forward()
{
  analogWrite(ENA,120);
  analogWrite(ENB,120);
  
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  
}
void backward()
{
  
  analogWrite(ENA,100);
  analogWrite(ENB,100);
  
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}


void TurnRight()
{
  analogWrite(ENA,120);
  analogWrite(ENB,120);
  
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

void TurnLeft()
{
  analogWrite(ENA,120);
  analogWrite(ENB,120);
  
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
