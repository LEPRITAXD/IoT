#define LED1 13
#define LED2 12
#define LED3 11

bool option = false;

void main_menu() {
  Serial.println(":::: MAIN MENU ::::");
  Serial.println("[1]. Turn on led1");
  Serial.println("[2]. Turn off led1");
  Serial.println("[3]. Turn on led2");
  Serial.println("[4]. Turn off led2");
  Serial.println("[5]. Turn on led3");
  Serial.println("[6]. Turn off led3");
  Serial.println("[7]. Turn on all leds");
  Serial.println("[8]. Turn off all leds");
  Serial.println("[9]. Leds flashing on");
  Serial.println("[10]. Leds flashing off");
}

void setup() {
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  main_menu();
}

void loop() {
  if (Serial.available() > 0) {
    char opt = Serial.read();
    
    if (opt == '1') {
      flashing = false;
      digitalWrite(LED1, HIGH);
    } else if (opt == '2') {
      flashing = false;
      digitalWrite(LED1, LOW);
    } else if (opt == '3') {
      flashing = false;
      digitalWrite(LED2, HIGH);
    } else if (opt == '4') {
      flashing = false;
      digitalWrite(LED2, LOW);
    } else if (opt == '5') {
      flashing = false;
      digitalWrite(LED3, HIGH);
    } else if (opt == '6') {
      flashing = false;
      digitalWrite(LED3, LOW);
    } else if (opt == '7') {
      flashing = false;
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
    } else if (opt == '8') {
      flashing = false;
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
    } else if (opt == '9') {
      option = true;
    }
  }
  
  if (option == true) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    delay(1000);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    delay(1000);
  }
}
