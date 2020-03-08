/************************
 * Ce programme permet d'afficher un chrono [0-15] sur un 7-segment.
 * Le contrôle se fait grâce à un BP. Les appuis successifs permettent de démarrer, arrêter et MAZ le chrono.
 * Ahmed TSOROEV et Nimesh TAHALOOA
 */

int val = 0;
int etat = B10;
const int buttonPin = 12;
const int ledPin = 13;
int ledState = HIGH;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;
unsigned long lastUpdate = 0;
int buttonState;
int lastButtonState = LOW;
int reading;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  digitalWrite(ledPin, ledState);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == HIGH) {
        ledState = !ledState;

        switch (etat) {
          case B10:
            etat = B01;
            break;
          case B01:
            etat = B00;
            break;
          case B00:
            etat = B10;
            break;
        }
      }
    }
  }
  digitalWrite(ledPin, ledState);
  displayValue();
  lastButtonState = reading;
  if (etat == B01) {
    if (millis() - lastUpdate >= 1000) {
      lastUpdate = millis();
      val++;
      if (val == 16) val = 0;
    }
  } //fin comptage
  else if (etat == B10) val = 0;
}

void displayValue() {
  switch (val) {
    //************ 0 *************
    case (0):
      digitalWrite(10, LOW);   // fixe la led comme allumée
      digitalWrite(11, HIGH);   // fixe la led comme allumée
      digitalWrite(2, HIGH);   // fixe la led comme allumée
      digitalWrite(3, HIGH);   // fixe la led comme éteinte
      digitalWrite(4, HIGH);   // fixe la led comme allumée
      digitalWrite(5, HIGH);   // fixe la led comme allumée
      digitalWrite(6, HIGH);   // fixe la led comme allumée
      digitalWrite(7, HIGH);   // fixe la led comme allumée
      // attendre 1 sec
      break;
    //************ 1 *************
    case (1):
      digitalWrite(10, LOW);   // fixe la led comme allumée
      digitalWrite(11, LOW);   // fixe la led comme allumée
      digitalWrite(2, LOW);   // fixe la led comme allumée
      digitalWrite(3, HIGH);   // fixe la led comme éteinte
      digitalWrite(4, LOW);   // fixe la led comme allumée
      digitalWrite(5, LOW);   // fixe la led comme allumée
      digitalWrite(6, HIGH);   // fixe la led comme allumée
      digitalWrite(7, HIGH);   // fixe la led comme allumée
      // attendre 1 sec
      break;
    //************ 2 *************
    case (2):
      digitalWrite(10, HIGH);   // fixe la led comme allumée
      digitalWrite(11, LOW);   // fixe la led comme allumée
      digitalWrite(2, HIGH);   // fixe la led comme allumée
      digitalWrite(3, HIGH);   // fixe la led comme éteinte
      digitalWrite(4, HIGH);   // fixe la led comme allumée
      digitalWrite(5, HIGH);   // fixe la led comme allumée
      digitalWrite(6, LOW);   // fixe la led comme allumée
      digitalWrite(7, HIGH);   // fixe la led comme allumée
      // attendre 1 sec
      break;
    //************ 3 *************
    case (3):
      digitalWrite(10, HIGH);   // fixe la led comme allumée
      digitalWrite(11, LOW);   // fixe la led comme allumée
      digitalWrite(2, HIGH);   // fixe la led comme allumée
      digitalWrite(3, HIGH);   // fixe la led comme éteinte
      digitalWrite(4, LOW);   // fixe la led comme allumée
      digitalWrite(5, HIGH);   // fixe la led comme allumée
      digitalWrite(6, HIGH);   // fixe la led comme allumée
      digitalWrite(7, HIGH);   // fixe la led comme allumée
      // attendre 1 sec
      break;
    //***** 4 *************
    case (4):
      digitalWrite(10, HIGH);   // fixe la led comme allumée
      digitalWrite(11, HIGH);   // fixe la led comme allumée
      digitalWrite(2, LOW);   // fixe la led comme allumée
      digitalWrite(3, HIGH);   // fixe la led comme éteinte
      digitalWrite(4, LOW);   // fixe la led comme allumée
      digitalWrite(5, LOW);   // fixe la led comme allumée
      digitalWrite(6, HIGH);   // fixe la led comme allumée
      digitalWrite(7, HIGH);   // fixe la led comme allumée
      // attendre 1 sec
      break;
    //************ 5 *************
    case (5):
      digitalWrite(10, HIGH);   // fixe la led comme allumée
      digitalWrite(11, HIGH);   // fixe la led comme allumée
      digitalWrite(2, HIGH);   // fixe la led comme allumée
      digitalWrite(3, LOW);   // fixe la led comme éteinte
      digitalWrite(4, LOW);   // fixe la led comme allumée
      digitalWrite(5, HIGH);   // fixe la led comme allumée
      digitalWrite(6, HIGH);   // fixe la led comme allumée
      digitalWrite(7, HIGH);   // fixe la led comme allumée
      // attendre 1 sec
      break;
    //************ 6 *************
    case (6):
      digitalWrite(10, HIGH);   // fixe la led comme allumée
      digitalWrite(11, HIGH);   // fixe la led comme allumée
      digitalWrite(2, HIGH);   // fixe la led comme allumée
      digitalWrite(3, LOW);   // fixe la led comme éteinte
      digitalWrite(4, HIGH);   // fixe la led comme allumée
      digitalWrite(5, HIGH);   // fixe la led comme allumée
      digitalWrite(6, HIGH);   // fixe la led comme allumée
      digitalWrite(7, HIGH);   // fixe la led comme allumée
      // attendre 1 sec
      break;
    //************ 7 *************
    case (7):
      digitalWrite(10, LOW);   // fixe la led comme allumée
      digitalWrite(11, LOW);   // fixe la led comme allumée
      digitalWrite(2, HIGH);   // fixe la led comme allumée
      digitalWrite(3, HIGH);   // fixe la led comme éteinte
      digitalWrite(4, LOW);   // fixe la led comme allumée
      digitalWrite(5, LOW);   // fixe la led comme allumée
      digitalWrite(6, HIGH);   // fixe la led comme allumée
      digitalWrite(7, HIGH);   // fixe la led comme allumée
      // attendre 1 sec
      break;
    //************ 8 *************
    case (8):
      digitalWrite(10, HIGH);   // fixe la led comme allumée
      digitalWrite(11, HIGH);   // fixe la led comme allumée
      digitalWrite(2, HIGH);   // fixe la led comme allumée
      digitalWrite(3, HIGH);   // fixe la led comme éteinte
      digitalWrite(4, HIGH);   // fixe la led comme allumée
      digitalWrite(5, HIGH);   // fixe la led comme allumée
      digitalWrite(6, HIGH);   // fixe la led comme allumée
      digitalWrite(7, HIGH);   // fixe la led comme allumée
      // attendre 1 sec
      break;
    //************ 9 **************
    case (9):
      digitalWrite(10, HIGH);   // fixe la led comme allumée
      digitalWrite(11, HIGH);   // fixe la led comme allumée
      digitalWrite(2, HIGH);   // fixe la led comme allumée
      digitalWrite(3, HIGH);   // fixe la led comme éteinte
      digitalWrite(4, LOW);   // fixe la led comme allumée
      digitalWrite(5, HIGH);   // fixe la led comme allumée
      digitalWrite(6, HIGH);   // fixe la led comme allumée
      digitalWrite(7, HIGH);   // fixe la led comme allumée
      // attendre 1 sec
      break;
    //************ A **************
    case (10):
      digitalWrite(10, HIGH);   // fixe la led comme allumée
      digitalWrite(11, HIGH);   // fixe la led comme allumée
      digitalWrite(2, HIGH);   // fixe la led comme allumée
      digitalWrite(3, HIGH);   // fixe la led comme éteinte
      digitalWrite(4, HIGH);   // fixe la led comme allumée
      digitalWrite(5, LOW);   // fixe la led comme allumée
      digitalWrite(6, HIGH);   // fixe la led comme allumée
      digitalWrite(7, HIGH);   // fixe la led comme allumée
      // attendre 1 sec
      break;
    //************ B *************
    case (11):
      digitalWrite(10, HIGH);   // fixe la led comme allumée
      digitalWrite(11, HIGH);   // fixe la led comme allumée
      digitalWrite(2, LOW);   // fixe la led comme allumée
      digitalWrite(3, LOW);   // fixe la led comme éteinte
      digitalWrite(4, HIGH);   // fixe la led comme allumée
      digitalWrite(5, HIGH);   // fixe la led comme allumée
      digitalWrite(6, HIGH);   // fixe la led comme allumée
      digitalWrite(7, HIGH);   // fixe la led comme allumée
      // attendre 1 sec
      break;
    //************ C *************
    case (12):
      digitalWrite(10, LOW);   // fixe la led comme allumée
      digitalWrite(11, HIGH);   // fixe la led comme allumée
      digitalWrite(2, HIGH);   // fixe la led comme allumée
      digitalWrite(3, LOW);   // fixe la led comme éteinte
      digitalWrite(4, HIGH);   // fixe la led comme allumée
      digitalWrite(5, HIGH);   // fixe la led comme allumée
      digitalWrite(6, LOW);   // fixe la led comme allumée
      digitalWrite(7, HIGH);   // fixe la led comme allumée
      // attendre 1 sec
      break;
    //************ D *************
    case (13):
      digitalWrite(10, HIGH);   // fixe la led comme allumée
      digitalWrite(11, LOW);   // fixe la led comme allumée
      digitalWrite(2, LOW);   // fixe la led comme allumée
      digitalWrite(3, HIGH);   // fixe la led comme éteinte
      digitalWrite(4, HIGH);   // fixe la led comme allumée
      digitalWrite(5, HIGH);   // fixe la led comme allumée
      digitalWrite(6, HIGH);   // fixe la led comme allumée
      digitalWrite(7, HIGH);   // fixe la led comme allumée
      // attendre 1 sec
      break;
    //************ E *************
    case (14):
      digitalWrite(10, HIGH);   // fixe la led comme allumée
      digitalWrite(11, HIGH);   // fixe la led comme allumée
      digitalWrite(2, HIGH);   // fixe la led comme allumée
      digitalWrite(3, LOW);   // fixe la led comme éteinte
      digitalWrite(4, HIGH);   // fixe la led comme allumée
      digitalWrite(5, HIGH);   // fixe la led comme allumée
      digitalWrite(6, LOW);   // fixe la led comme allumée
      digitalWrite(7, HIGH);   // fixe la led comme allumée
      // attendre 1 sec
      break;
    //************ F *************
    case (15):
      digitalWrite(10, HIGH);   // fixe la led comme allumée
      digitalWrite(11, HIGH);   // fixe la led comme allumée
      digitalWrite(2, HIGH);   // fixe la led comme allumée
      digitalWrite(3, LOW);   // fixe la led comme éteinte
      digitalWrite(4, HIGH);   // fixe la led comme allumée
      digitalWrite(5, LOW);   // fixe la led comme allumée
      digitalWrite(6, LOW);   // fixe la led comme allumée
      digitalWrite(7, HIGH);   // fixe la led comme allumée
      // attendre 1 sec
      break;
  }
}
