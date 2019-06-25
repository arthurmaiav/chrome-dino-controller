#include <Keyboard.h>

#define trigPin 9
#define echoPin 10
#define buzzer 5

char upArrow = KEY_UP_ARROW;
long duration, distance;
bool jumping = false;
int jumpCount = 0;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);    

  Keyboard.begin();
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
   distance = (duration / 2) / 29.1;
 
  if (distance < 50) {
    Keyboard.releaseAll();
    jumping = false;
  }

  else if(jumping == false){
    Keyboard.press(upArrow);
    jumping = true;
    jumpCount++;

    if(jumpCount%10 == 0){
        tone(buzzer, 261);
        Serial.println(jumpCount);
    }
  }

  delay(50);
  noTone(buzzer);
}
