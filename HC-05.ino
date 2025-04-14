#include <SoftwareSerial.h>

// Définition des broches pour les LEDs
int ledRouge = 6;
int ledBlue = 7;
int ledYello = 2;


// Définition des broches pour la communication Bluetooth
SoftwareSerial mySerial(11, 10); // RX (Arduino) ← TX (module), TX (Arduino) → RX (module)
void setup() {
  // Initialisation des broches des LEDs comme sortie
  pinMode(ledRouge, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  pinMode(ledYello, OUTPUT);

  // Initialisation de la communication série pour le Bluetooth
  mySerial.begin(9600);
  Serial.begin(9600);

  // Éteindre les LEDs au début
  digitalWrite(ledRouge, LOW);
  digitalWrite(ledBlue, LOW);
  digitalWrite(ledYello, LOW);

   mySerial.print("Message de Test A !");
   Serial.print("Message de Test B !");
}

void loop() {
  // Vérifier si un signal est reçu via Bluetooth
  while(mySerial.available()){
    
    char commande = mySerial.read();  // Lire la commande envoyée par le smartphone
    
    if (commande == '0') {
      // Si la commande est '0', allumer la LED rouge et éteindre la LED verte
      digitalWrite(ledRouge, HIGH);
      digitalWrite(ledBlue, LOW);

        mySerial.println("0");
        Serial.println("0");
    }
    else if (commande == '1') {
      // Si la commande est '1', allumer la LED verte et éteindre la LED rouge
      digitalWrite(ledRouge, LOW);
      digitalWrite(ledBlue, HIGH);

      mySerial.println("1");
      Serial.println("1");
    }
  }

  //  Lecture depuis le moniteur série (USB)
  while (Serial.available()) {
       char test = Serial.read(); // Lire la commande envoyée par l'Aarduino
       
    if (test == 'a') {
      digitalWrite(ledYello, LOW);
      mySerial.println("LED jaune OFF");
      Serial.println("LED jaune OFF");
    } 
    else if (test == 'b') {
      digitalWrite(ledYello, HIGH);
      mySerial.println("LED jaune ON");
      Serial.println("LED jaune ON");
    }
  }
}
