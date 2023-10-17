const int LED_ADELANTE = 0;
const int LED_ATRAS = 15;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_ADELANTE, OUTPUT);
  pinMode(LED_ATRAS, OUTPUT);
  digitalWrite(LED_ADELANTE, HIGH);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(LED_ATRAS, LOW);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(LED_ATRAS, HIGH);
  delay(1000);
}
