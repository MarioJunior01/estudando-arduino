int LED1 =8;
int LED2=7;
int LED3=2;
void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
 

  
}

void loop()
{
  digitalWrite(LED3, HIGH);
  delay(5000);
  digitalWrite(LED3, LOW);
  digitalWrite(LED2, HIGH);
  delay(3000);
  digitalWrite(LED2, LOW);
  digitalWrite(LED1, HIGH);
  delay(5000);
  digitalWrite(LED1, LOW);
  
  
}
 