// inclure la librerie du servomoteur
#include <Servo.h> 
// Definir les broches de Trig et Echo de l'ultrason
const int trigPin = 8;
const int echoPin = 9;
// Declaration de la durée et de la distance
long duration;
int distance;
Servo myServo; // Creer un objet pour controler le servomoteur 
void setup() {
  pinMode(trigPin, OUTPUT); // Mettre la broche Trig en sortie
  pinMode(echoPin, INPUT); // Mettre la broche Echo en entree
  Serial.begin(9600);
  myServo.attach(10); // Definir la broche oú il faut brancher le signal du servomoteur
}
void loop() {
  // Tourner le moteur de 15 á 165 degré
  for(int i=15;i<=165;i++){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();// Appel de la fonction de calcul de la distance mesurée par le capteur á ultrason pour chaque degré   
  Serial.print(i); // Envoyer les valeurs en degré dans le port série   
  Serial.print(","); // Envoyer le caractere additionnel á coté de la valeur precedente qu'on aura besoin plutard dans l'espace de developpement integré de Processing 
  Serial.print(distance); // Envoyer la valeur de la distance dans le port série
  Serial.print("."); // Envoyer le caractere additionnel á coté de la valeur precedente qu'on aura besoin plutard dans l'espace de developpement integré de Processing
  }
  // Repeter l'action maintenant de 165 á 15 degré
  for(int i=165;i>15;i--){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  }
}
// Fonction pour calculer la distance mesurée par le capteur á ultrason
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Mettre la broche Trig á l'etat haut pour 10 microsecondes 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Lire la broche Echo , Calculer le temps et retourner ce dernier
  distance= duration*0.034/2;
  return distance;
}
