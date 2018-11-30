#include "Button.h"

#define led_button1 13
#define led_button2 12
#define led_button3 11
#define led_button4 10

Button S1(A0);
Button S2(A1);
Button S3(A2);
Button S4(A3);

unsigned long previousMillis=0;
int interval = 1000;
int ledState=LOW;
int level_number_new=1;
int level_number_old=-1;

int sequence[120]={13,13,11,10,10,13,10,12,10,11,11,12,10,12,11,10,13,13,11,
10,12,12,11,13,11,12,11,10,13,12,11,10,13,12,11,10,10,13,10,12,10,11,11,12,10,
12,11,10,13,13,11,10,12,12,10,13,11,12,13,11,13,12,12,11,13,11,13,10,10,12,11,12,
10,12,11,10,13,13,11,10,12,12,11,13,11,12,11,10,13,12,11,10,13,12,11,10,10,13,10,12,
10,11,11,12,10,12,11,10,13,13,11,10,12,12,11,13,11};

void setup() {
  
Serial.begin(9600);
pinMode(13, OUTPUT);
pinMode(12, OUTPUT);
pinMode(11, OUTPUT);
pinMode(10, OUTPUT);
}

void one_pressed(){
  
if(digitalRead(led_button1)==HIGH){
  
  if(level_number_new==level_number_old){
    Serial.println("you fail");
    }
    
    if(level_number_new!=level_number_old){
      
      if(S1.pressed()){
        level_number_new++;
        Serial.println(level_number_new);
        digitalWrite(13, LOW);
        digitalWrite(12, LOW);
        digitalWrite(11, LOW);
        digitalWrite(10, LOW);
        }
       }
      }
     }

void two_pressed(){
  
if(digitalRead(led_button2)==HIGH){
  
  if(level_number_new==level_number_old){
    Serial.println("you fail");
    }
    
    if(level_number_new!=level_number_old){
      
      if(S2.pressed()){
        level_number_new++;
        Serial.println(level_number_new);
        digitalWrite(13, LOW);
        digitalWrite(12, LOW);
        digitalWrite(11, LOW);
        digitalWrite(10, LOW);
        }
       }
      }
     }

void three_pressed(){
  
  if(digitalRead(led_button3)==HIGH){
    
    if(level_number_new==level_number_old){
      Serial.println("you fail");
      }
      
      if(level_number_new!=level_number_old){
        
        if(S3.pressed()){
          level_number_new++;
          Serial.println(level_number_new);
          digitalWrite(13, LOW);
          digitalWrite(12, LOW);
          digitalWrite(11, LOW);
          digitalWrite(10, LOW);
          }
         }
        }
       }

void four_pressed(){
  
  if(digitalRead(led_button4)==HIGH){
    
    if(level_number_new==level_number_old){
      Serial.println("you fail");
      }
      
      if(level_number_new!=level_number_old){
        if(S4.pressed()){
          level_number_new++;
          Serial.println(level_number_new);
          digitalWrite(13, LOW);
          digitalWrite(12, LOW);
          digitalWrite(11, LOW);
          digitalWrite(10, LOW);
          }
         }
        }
       }

void level_climb(){
  
  if(level_number_new<=5){
    interval=1000;
    }
    
    if(level_number_new>5 && level_number_new<=10){
    interval=970;
    }

    if(level_number_new>10 && level_number_new<=15){
    interval=940;
    }

    if(level_number_new>15 && level_number_new<=20){
    interval=910;
    }

    if(level_number_new>20 && level_number_new<=25){
    interval=910;
    }

    if(level_number_new>25 && level_number_new<=30){
    interval=910;
    }

    if(level_number_new>30 && level_number_new<=35){
    interval=910;
    }

    if(level_number_new>35 && level_number_new<=40){
    interval=910;
    }

    if(level_number_new>40 && level_number_new<=45){
    interval=910;
    }

    if(level_number_new>45 && level_number_new<=50){
    interval=910;
    }

    if(level_number_new>50 && level_number_new<=55){
    interval=910;
    }

    if(level_number_new>55 && level_number_new<=60){
    interval=910;
    }

    if(level_number_new>60 && level_number_new<=65){
    interval=910;
    }

    if(level_number_new>65 && level_number_new<=70){
    interval=910;
    }

    if(level_number_new>70 && level_number_new<=75){
    interval=910;
    }

    if(level_number_new>75 && level_number_new<=80){
    interval=910;
    }

    if(level_number_new>80 && level_number_new<=85){
    interval=910;
    }

    if(level_number_new>85 && level_number_new<=90){
    interval=910;
    }

    if(level_number_new>90 && level_number_new<=95){
    interval=910;
    }

    if(level_number_new>95 && level_number_new<=100){
    interval=910;
    }
   }
  
void loop() {

one_pressed();
two_pressed();
three_pressed();
four_pressed();

level_climb();
  


 unsigned long currentMillis = millis();


  if (currentMillis - previousMillis >= interval) {


    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
      level_number_old++;
      Serial.println(level_number_old);
      
    } else {
      ledState = LOW;
      
    }

    // set the LED with the ledState of the variable:
    digitalWrite(sequence[level_number_new], ledState);
 }
}
    
