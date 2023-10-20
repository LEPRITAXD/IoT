int pinLed = 13;            // Pin del LED 
int pinMotor = 10;          // Pin del motor

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  pinMode(pinLed, OUTPUT);
  pinMode(pinMotor, OUTPUT);
  //FRANK ESTEBAN FERNANDEZ
  // Inicialización del sensor de temperatura
  lcd.begin(16, 2);
  lcd.print("Temperatura de: ");
  Serial.begin(9600); // Velocidad de comunicación en baudios
}

void loop()
{  
  valorSensor = analogRead(A0); // Leer el valor analógico de A0 (pin analógico)
  temperatura = (valorSensor * (500.0 / 1024.0)) - 50.0;
  // Serial.print("Temperatura_°C: ");
  Serial.println(temperatura);
  
  lcd.setCursor(0, 1);
  lcd.print(temperatura);
  delay(1000);  
  
  if(temperatura <= 10){
    digitalWrite(pinLed, HIGH);
    delay(500);
    digitalWrite(pinLed, LOW);
    // digitalWrite(pinMotor, HIGH);
  }
  else if(temperatura >= 11 && temperatura <= 25){
    digitalWrite(pinLed, LOW);
    digitalWrite(pinMotor, LOW);
  }
  else if(temperatura >= 26){
    digitalWrite(pinLed, HIGH);
    delay(500);
    digitalWrite(pinMotor, HIGH);
  }
}
