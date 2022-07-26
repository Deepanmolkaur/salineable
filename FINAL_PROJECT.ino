#include <HX711.h> 
 
 #include <Servo.h> 


int ledpin = 13;
Servo myservo;

HX711 scale(6, 5); //HX711 scale(6, 5);

float calibration_factor = -77;
float units;
float ounces;

void setup()
{
  Serial.begin(9600);
  scale.set_scale(calibration_factor);
  scale.tare();  Serial.println("HX711 weighing");

  Serial.println("Readings:");
   myservo.attach(3);
 myservo.write(0); 
   pinMode (ledpin,OUTPUT);
}

void loop()
{
 
  Serial.print("Reading:");
  units = scale.get_units(),10;
  if (units < 0)
  {
    units = 0.00;
  }
  ounces = units * 0.035274;
  Serial.print(units);
  Serial.println(" grams");
  delay(1000);
 if (units > 100 )
 {
 myservo.write(180);
 
   delay(1000);
   digitalWrite (ledpin,LOW);
   delay(1000);
   
 }
 if (units <60)
 {
  myservo.write(0);
    delay(1000);
 }
 if (units <60 )
 {
   digitalWrite (ledpin,HIGH);
    delay(1000);
  }
}
