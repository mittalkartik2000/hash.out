#include <SoftwareSerial.h>
SoftwareSerial BTserial(10,11);
int sensorPin = A0;
int sensorValue = 0;
int butpower = 9;
int s;
int che=A0;
int che0=A4; 
int r;          
int level=100;    
int fadeAmount=5;  
int button;
int butch[10];
int i=0;
int count;
int help;
int sent=0;


void setup()
{
  pinMode(butpower,OUTPUT);
  pinMode(che, INPUT);// button read
  pinMode(che0, INPUT);// button 2 read
  Serial.begin(9600);
  BTserial.begin(9600);
}


void loop()
{
analogWrite(butpower,level);
button = analogRead(che);
/*if(button==level)
{
  button=1;
}
else
{
  button=0;
}*/
butch[i]=button;
i++;
if(i==9)
i=0;
if(i==9)
{
  for(int j=1;j<9;j++)
  {
    if(butch==0)
    count++;
    if(count>5)
    help=0;
    else
    help=1;
    
  }
  count=0;
}
if(button>5)
{button=1;
count++;
if(count>5 && sent ==0)
{BTserial.print("HELP");
Serial.print("HELP");
sent=1;
}
}
else
{button=0;
count=0;}
Serial.println(button);


delay(200);


}
