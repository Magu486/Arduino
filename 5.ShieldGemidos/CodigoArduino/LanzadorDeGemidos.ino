/*********DFPlayer Mini*******/
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>
SoftwareSerial mySoftwareSerial(10,11);
DFRobotDFPlayerMini myDFPlayer;
/********Ultrasonido HC-SR04*******/
long distancia;
long tiempo;
int trig=8,echo=6;
void setup()
{
  /*DFPlayer Mini*/
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);
  myDFPlayer.begin(mySoftwareSerial);
  Serial.println("Modulo funcionando");
  myDFPlayer.volume(30);/*Volumen maximo*/
  /*Ultrasonido*/
  pinMode(trig,OUTPUT);/*trig.activación del pin 8 como salida: para el pulso ultrasónico*/
  pinMode(echo,INPUT);/*echo.activación del pin 6 como entrada: tiempo del rebote del ultrasonido*/
}
void loop()
{
  /*ultrasonido*/
  digitalWrite(trig,LOW); /* Por cuestión de estabilización del sensor*/
  delayMicroseconds(5);
  digitalWrite(trig, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  tiempo=pulseIn(echo, HIGH);
  distancia= int(0.017*tiempo);/*Distancia en cm*/
  if(distancia<50){ //Si la distancia es menor a 50cm
    myDFPlayer.play(1);//Reproduce 0001.mp3
    delay(15000);//Reproduce 0009.mp3 hasta los 15 segundos
  }else{ //Si la distancia es mayor a 50cm
    myDFPlayer.pause();
    delay(50);
  }
}
