long distancia,tiempo;
int trig=2,echo=5,buzzer=12;
void setup(){
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
  pinMode(trig, OUTPUT); /*trig.activación del pin 2 como salida: para el pulso ultrasónico*/
  pinMode(echo, INPUT); /*echo.activación del pin 5 como entrada: tiempo del rebote del ultrasonido*/
}
void loop(){
  digitalWrite(trig,LOW); /* Por cuestión de estabilización del sensor*/
  delayMicroseconds(5);
  digitalWrite(trig, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  tiempo=pulseIn(echo, HIGH);
  distancia= int(0.017*tiempo); /*fórmula para calcular la distancia obteniendo un valor entero*/
  /*Monitorización en centímetros por el monitor serial*/
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");
  if(distancia<50){
    digitalWrite(buzzer,HIGH);/*El buzzer emite sonido*/
    delay(3000);
  }else{
    digitalWrite(buzzer,LOW);/*El buzzer no suena*/
    delay(200);
  }
}


