//ARDUINO IDE code for Obstacle detecting Robot

const int trig = 12;

const int echo = 11;

long duration, inches, cm;

void setup()

{

Serial.begin(115200);

pinMode(trig,OUTPUT);

pinMode(echo,INPUT);

pinMode(3, OUTPUT);

pinMode(4, OUTPUT);

pinMode(5, OUTPUT);

pinMode(6, OUTPUT);

}

void loop()

{

digitalWrite(trig, LOW);

delayMicroseconds(2);

digitalWrite(trig, HIGH);

delayMicroseconds(5);

digitalWrite(trig, LOW);

duration = pulseIn(echo, HIGH);

//this returns the time duration taken

//for the ultrasonics to hit an obstacle and return

inches = duration / 74 / 2;//converts the time duration into inches

cm = duration / 29 / 2;//converts the time duration to cm
Serial.println(cm);
if(cm>15)//checks for the distance is greater than 4cm

//the bot forward if the condition is true
{
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  Serial.print("No obstacle detected");
}

else if(cm<=15)
{
//the robot turns right when an obstacle is detected
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  delay(500);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  Serial.print("Obstacle detected");

delay(250);//this delays the process by 250millisec
}
Serial.println();

delay(250);//this delays the code by 0.1 second and repeats the loop again

}
