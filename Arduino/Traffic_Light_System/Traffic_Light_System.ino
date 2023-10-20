// FRANK ESTEBAN FERNANDEZ
int led_verd=10;
int led_amar=9;
int led_rojo=8;
void setup() {
  // put your setup code here, to run once:
  pinMode(led_verd,OUTPUT);//No Pin y Mode (OUTPUT/INPUT)
  pinMode(led_amar,OUTPUT);
  pinMode(led_rojo,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led_verd,HIGH);
  delay(1000); //1000=1 SEG
  digitalWrite(led_verd,LOW);
  digitalWrite(led_amar,HIGH);
  delay(1000); //1000=1 SEG
  digitalWrite(led_amar,LOW);
  digitalWrite(led_rojo,HIGH);
  delay(1000); //1000=1 SEG
  digitalWrite(led_rojo,LOW);
  digitalWrite(led_amar,HIGH);
  delay(1000); //1000=1 SEG
  digitalWrite(led_amar,LOW); 
  

}
