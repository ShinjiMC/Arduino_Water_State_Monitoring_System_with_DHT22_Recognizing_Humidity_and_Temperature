#include "DHT.h"
#include <SoftwareSerial.h>   // Incluimos la librería  SoftwareSerial
#define DHTPIN 2     // Pin donde está conectado el sensor
#define DHTTYPE DHT22   // Sensor DHT22

SoftwareSerial BT(10,11);
DHT dht(DHTPIN, DHTTYPE);

const int buttonPin = 3;
int ledPin[]={8,9,12};
int sensorPin = A0;
int sensorValue=0;
int buttonState = 0; 
int option=0;
int auxopt=0;

void setup() {
  Serial.begin(9600);
  BT.begin(9600);
  dht.begin();
  pinMode(3, INPUT);
  BT.println("Conexion exitosa");
  BT.println("SISTEMA DETECTOR DE HUMEDAD DE CUERPOS");
  BT.println("Puede escoger el estado deseado con ayuda del Potenciometro:");
  BT.println("  -Estado Solido");
  BT.println("  -Estado Liquido");
  BT.println("  -Estado Gaseoso");
  Serial.println("Iniciando...");
}

void loop() {
  if(BT.available()){
    Serial.write(BT.read());
  }
  if(Serial.available()){
    BT.write(Serial.read());
  }
  if(digitalRead(3)==HIGH){
    if(option==1){
      Solido();
      imprimirEstado(option);
    }
    else if(option==2){
      Liquido();
      imprimirEstado(option);
    }
    else if(option==3){
      Gaseoso();
      imprimirEstado(option);
    }
    delay(200);
  }
  if(digitalRead(3)==LOW){
    sensorValue = analogRead (sensorPin);
    cambio(sensorValue,option);
    if(option!=auxopt){
      imprimirEstado(option);
      auxopt=option;
    }
    delay(200);
  }
}
void imprimir(float h,float t,float f){
    float b=0;
    float ber=0;
    float hf=HF(h);
    float tf=TF(t);
    b=tf+hf;
    ber=1000/b;
    b=b+ber;
    BT.write("Humedad ");
    BT.print(h);
    BT.println(" %t ");
    BT.print("Temperatura: ");
    BT.print(t);
    BT.print(" *C ");
    BT.print(f);
    BT.println(" *F");
    BT.print("Natividad de Bacterias ");
    BT.print(b);
    BT.print("% - ");
    BT.print(b+10);
    BT.print("%");
    BT.println(" ");
    BT.println(" ");
}
float HF(float h){
  if(h < 50){
    return 50-h;
  }
  else if(60 < h){
    return h-60;
  }
  else{
    return 10;
  }
}
float TF(float t){
  float tf=0;
  if(t < 80 && -5 < t){
    tf=80-(t+5);
    
  }
  else{
    tf=10;
  }
  return tf;
}
void imprimirEstado(int option){
  if(option==1){
    Serial.println("Calculando en Solidos");
    BT.write("Calculando en Solidos");
    BT.println(" ");
    BT.println(" ");
  }
  else if(option==2){
    Serial.println("Calculando en Liquidos");
    BT.write("Calculando en Liquidos");
    BT.println(" ");
    BT.println(" ");
  }
  else if(option==3){
    Serial.println("Calculando en Gaseosos");
    BT.write("Calculando en Gaseosos");
    BT.println(" ");
    BT.println(" ");
  }
}
void cambio(int sensor,int& option){
  if(sensor>-1 && 342>sensor){
    digitalWrite(ledPin[0],HIGH);
    digitalWrite(ledPin[1],LOW);
    digitalWrite(ledPin[2],LOW);
    option=1;
  }
  if(sensor>341 && 683>sensor){
    digitalWrite(ledPin[1],HIGH);
    digitalWrite(ledPin[0],LOW);
    digitalWrite(ledPin[2],LOW);
    option=2;
  }
  if(sensor>682 && 1024>sensor){
    digitalWrite(ledPin[2],HIGH);
    digitalWrite(ledPin[1],LOW);
    digitalWrite(ledPin[0],LOW);
    option=3;
  }
}

void Solido(){
  float prodh=0;
  float prodt=0;
  float prodf=0;
  BT.write("Calculando...");
  BT.println(" ");
  BT.println(" ");
  for(int i=0;i<100;i++){
    float h = dht.readHumidity(); //Leemos la Humedad
    float t = dht.readTemperature(); //Leemos la temperatura en grados Celsius
    float f = dht.readTemperature(true); //Leemos la temperatura en grados Fahrenheit
    prodh=prodh+h;
    prodt=prodt+t;
    prodf=prodf+f;
    delay(200);
  }
  prodh=prodh/100;
  prodt=prodt/100;
  prodf=prodf/100;
  imprimir(prodh,prodt,prodf);
}
void Liquido(){
  float prodh=0;
  float prodt=0;
  float prodf=0;
  BT.write("Calculando...");
  BT.println(" ");
  BT.println(" ");
  for(int i=0;i<50;i++){
    float h = dht.readHumidity(); //Leemos la Humedad
    float t = dht.readTemperature(); //Leemos la temperatura en grados Celsius
    float f = dht.readTemperature(true); //Leemos la temperatura en grados Fahrenheit
    prodh=prodh+h;
    prodt=prodt+t;
    prodf=prodf+f;
    delay(200);
  }
  prodh=prodh/50;
  prodt=prodt/50;
  prodf=prodf/50;
  imprimir(prodh,prodt,prodf);
}
void Gaseoso(){
  float prodh=0;
  float prodt=0;
  float prodf=0;
  BT.write("Calculando...");
  BT.println(" ");
  BT.println(" ");
  for(int i=0;i<20;i++){
    float h = dht.readHumidity(); //Leemos la Humedad
    float t = dht.readTemperature(); //Leemos la temperatura en grados Celsius
    float f = dht.readTemperature(true); //Leemos la temperatura en grados Fahrenheit
    prodh=prodh+h;
    prodt=prodt+t;
    prodf=prodf+f;
    delay(200);
  }
  prodh=prodh/20;
  prodt=prodt/20;
  prodf=prodf/20;
  imprimir(prodh,prodt,prodf);
}
