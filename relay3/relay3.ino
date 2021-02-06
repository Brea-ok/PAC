
#define relay  2
#define echoPin 8 
#define trigPin 9 

int distance;
int unos;
int ceros;
long duration;

void setup() {
  pinMode(relay, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  Serial.begin(9600);
}

void lecturaSensor(){
  distance = 0;
  duration = 0;
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  Serial.println(distance);
   if(distance <= 150){ // distancia para modificar
    unos++;
    }
   else{
    ceros++;
    }
  delay(200);
  }

void imprimirUno(){
    Serial.println(1);
    digitalWrite(relay, HIGH);
    Serial.println("Esta sonando gato, yeah bebu");
  }

void imprimirCero(){
      Serial.println(0);
      digitalWrite(relay, LOW);
      Serial.println("Ahora no more bb");
  
  }

void loop() {
  unos = 0;
  ceros = 0;
  for(int i=0;i<4;i++){ //i es la cantidad de lecturas que quiero tomar. i< [numero par]
   lecturaSensor();
  } 
  Serial.println(unos);
  Serial.println(ceros);
  if(unos>ceros){
  imprimirUno();
  }
  else{
  imprimirCero();
  }
 }
 
  
