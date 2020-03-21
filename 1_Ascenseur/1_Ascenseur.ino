/*
 * Ce programme permet de simuler la commande d'un ascenseur avec 4 niveaux: 0,1,2 et 3.
 * Le contrôle se fait grâce à 4 BP, un par niveaux.
 * Lorsqu'un bouton est appuyé, l'ascenseur monte ou descend à l'étage corréspondant au bouton.
 * L'étage actuel de l'ascenseur est constamment affiché sur le 7 Segment.
 * Nimesh TAHALOOA et Ahmed TSOROEV
*/
#define STOP 0
#define UP 1
#define DOWN 2
int liftState = STOP;
int liftFloor = 0;
int userChoice = 0;
int lastUpdate = 0;
const int buttonPin_0 = 8;
const int buttonPin_1 = 9;
const int buttonPin_2 = 12;
const int buttonPin_3 = 13;
int PinsArray[4] = {8, 9, 12, 13};

void setup() {
  displayValue();
  pinMode(buttonPin_0, INPUT);
  pinMode(buttonPin_1, INPUT);
  pinMode(buttonPin_2, INPUT);
  pinMode(buttonPin_3, INPUT);
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
  
  if (liftState == STOP) {
    for (int i = 0; i <= 3; i++) {
      int pushed = digitalRead(PinsArray[i]);
      if (pushed == HIGH) {
        userChoice = i;
        break;
      }
    }
  }
    if (liftFloor < userChoice) {
      liftState = UP;
    }
    else if (liftFloor > userChoice) {
      liftState = DOWN;
    }
    else {
      liftState = STOP;
    }

    switch (liftState) {
      case(UP):
        liftFloor++;
        delay(1000);
        displayValue();
        break;
      case(DOWN):
        liftFloor--;
        delay(1000);
        displayValue();
        break;
    }
  }

  void displayValue() {
    switch (liftFloor) {
      //************ 0 *************
      case (0):
        digitalWrite(10, LOW);
        digitalWrite(11, HIGH);
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(7, HIGH);
        // attendre 1 sec
        break;
      //************ 1 *************
      case (1):
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, HIGH);
        digitalWrite(7, HIGH);
        // attendre 1 sec
        break;
      //************ 2 *************
      case (2):
        digitalWrite(10, HIGH);
        digitalWrite(11, LOW);
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(6, LOW);
        digitalWrite(7, HIGH);
        // attendre 1 sec
        break;
      //************ 3 *************
      case (3):
        digitalWrite(10, HIGH);
        digitalWrite(11, LOW);
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(7, HIGH);
        // attendre 1 sec
        break;
    }
  }
