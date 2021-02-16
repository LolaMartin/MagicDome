#include "sensores.h"

unsigned long retardo=250;
unsigned long retardo1=150;

Sensores::Sensores(){
  ConfigPines();
}

int FLAG=0;

void Sensores::CreativeMode(){
  
  for(int i=0;i<numEntradas;i++){
      r0 = digitalRead(y0);
      r1 = digitalRead(y1);
      r2 = digitalRead(y2);
      r3 = digitalRead(y3);
      r4 = digitalRead(y4);
      //Serial.println(millis() - tActLeds[i]);
      
      if(r0==1){
          antirrebote(retardo);
          //Serial.println("OK");
          //debug(i);
          l.OnLedn(i,colores[ArrayLeds[i]]);
          antirrebote(retardo1);
          ArrayLeds[i]++;
//          Serial.print("pos:");
//          Serial.print(i);
//          Serial.print("-color:");
//          Serial.print(ArrayLeds[i]);
//          Serial.print("\n");
          if(ArrayLeds[i]==10)
            ArrayLeds[i]=0;
      }
       
      if(r1==1){
          antirrebote(retardo);
          //debug(i+8);
          l.OnLedn(i+8,colores[ArrayLeds[i+8]]);
          antirrebote(retardo1);
          ArrayLeds[i+8]++;
//          Serial.print("pos:");
//          Serial.print(i+8);
//          Serial.print("-color:");
//          Serial.print(ArrayLeds[i+8]);
//          Serial.print("\n");
          if(ArrayLeds[i+8]==10)
            ArrayLeds[i+8]=0;
      }

      if(r2 == 1){
          antirrebote(retardo);
          //debug(i+16);
          l.OnLedn(i+16,colores[ArrayLeds[i+16]]);
          antirrebote(retardo1);
          ArrayLeds[i+16]++;
//          Serial.print("pos:");
//          Serial.print(i+16);
//          Serial.print("-color:");
//          Serial.print(ArrayLeds[i+16]);
//          Serial.print("\n");
          if(ArrayLeds[i+16]==10)
            ArrayLeds[i+16]=0;
      }


      if(r3 == 1){
          antirrebote(retardo);
          //debug(i+24);
          l.OnLedn(i+24,colores[ ArrayLeds[i+24]]);
          antirrebote(retardo1);
          ArrayLeds[i+24]++;
//          Serial.print("pos:");
//          Serial.print(i+24);
//          Serial.print("-color:");
//          Serial.print(ArrayLeds[i+24]);
//          Serial.print("\n");
          if(ArrayLeds[i+24]==10)
            ArrayLeds[i+24]=0;
        }

      if(r4 == 1){
          antirrebote(retardo);
          //debug(i+32);
          l.OnLedn(i+32,colores[ArrayLeds[i+32]]);
          antirrebote(retardo1);
          ArrayLeds[i+32]++;
//          Serial.print("pos:");
//          Serial.print(i+32);
//          Serial.print("-color:");
//          Serial.print(ArrayLeds[i+32]);
//          Serial.print("\n");
          if(ArrayLeds[i+32]==10)
            ArrayLeds[i+32]=0;
       }
    PORTB ++; 
  }//For
}

void Sensores::ArrayInitialization(){
  for(int i=0;i<nc;i++)
    ArrayLeds[i]=0;
}

void Sensores::antirrebote(unsigned long _retardo){
  unsigned long actual = millis();
  while( (millis() - actual) < _retardo );
}

//__________________SIMON DICE
void SimonDice::tono1(){
  tone(speaker,200);
  delay(200);
  noTone(speaker);
}
void SimonDice::tono2(){
  tone(speaker,300);
  delay(200);
  noTone(speaker);
}
void SimonDice::tono3(){
  tone(speaker, 400);
  delay(200);
  noTone(speaker);
}
void SimonDice::tono4(){
  tone(speaker, 500);
  delay(200);
  noTone(speaker);
}

void SimonDice::RandomColors(){
  for(int i=0;i<nc;i++){
    ColorLeds[i]=random(0,8);
  }
}

void SimonDice::ShowSequence(){   
   
   for(int i = 0; i < nivelActual; i++){
      if (( secuencia[i] == 0 ) || ( secuencia[i] == 4 ) || ( secuencia[i] == 8 ) || ( secuencia[i] == 12 ) || ( secuencia[i] == 16 ) || ( secuencia[i] == 20 ) || ( secuencia[i] == 24 ) || ( secuencia[i] == 28 ) || ( secuencia[i] == 32 ) || ( secuencia[i] == 36 )) {
         tono1();
      }
      
      if (( secuencia[i] == 1 ) || ( secuencia[i] == 5 ) || ( secuencia[i] == 9 ) || ( secuencia[i] == 13 ) || ( secuencia[i] == 17 ) || ( secuencia[i] == 21 ) || ( secuencia[i] == 25 ) || ( secuencia[i] == 29 ) || ( secuencia[i] == 33 ) || ( secuencia[i] == 37 )) {
         tono2();
      }
      
      if (( secuencia[i] == 2 ) || ( secuencia[i] == 6 ) || ( secuencia[i] == 10 ) || ( secuencia[i] == 14 ) || ( secuencia[i] == 18 ) || ( secuencia[i] == 22 ) || ( secuencia[i] == 26 ) || ( secuencia[i] == 30 ) || ( secuencia[i] == 34 ) || ( secuencia[i] == 38 )) {
         tono3();
      }
      
      if (( secuencia[i] == 3 ) || ( secuencia[i] == 7 ) || ( secuencia[i] == 11) || ( secuencia[i] == 15 ) || ( secuencia[i] == 19 ) || ( secuencia[i] == 23 ) || ( secuencia[i] == 27 ) || ( secuencia[i] == 31 ) || ( secuencia[i] == 35 ) || ( secuencia[i] == 39 )) {
         tono4();
      }

      l.OnLedn(secuencia[i],colores[ColorLeds[secuencia[i]]]); 
      delay(velocidad);
//      l.OnCupula();   
//      delay(200);
   }
}


void SimonDice::ReadSequence(int &flag,int i,bool &gover){
        gover=false;
        PORTB = B00000000;
        // for para leer cada una de las entradas del mux
        for(int j = 0; j < numEntradas; j++){
          
            r0 = digitalRead(y0);
            r1 = digitalRead(y1);
            r2 = digitalRead(y2);
            r3 = digitalRead(y3);
            r4 = digitalRead(y4);
            
            if(r0 == 1){
                l.OnLedn(j,colores[ColorLeds[j]]);
                tono1();
                secuenciaUsuario[i] = j;
                flag = 1;
                delay(200);
                l.OnCupula();
                if(secuenciaUsuario[i] != secuencia[i]){
                   ErrorSequence();
                   gover=true;
                }   
            } 
             if(r1 == 1){
                l.OnLedn(j+8,colores[ColorLeds[j+8]]);
                tono2();
                secuenciaUsuario[i] = j+8;
                flag = 1;
                delay(200);
                l.OnCupula();
                if(secuenciaUsuario[i] != secuencia[i]){
                   ErrorSequence();
                   gover=true;
                }
             }
             if(r2 == 1){
                l.OnLedn(j+16,colores[ColorLeds[j+16]]);
                tono3();
                secuenciaUsuario[i] = j+16;
                flag = 1;
                delay(200);
                l.OnCupula();
                if(secuenciaUsuario[i] != secuencia[i]){
                   ErrorSequence();
                   gover=true;
                }  
             }
              if(r3 == 1){
                l.OnLedn(j+24,colores[ColorLeds[j+2]]);
                tono4();
                secuenciaUsuario[i] = j+24;
                flag = 1;
                delay(200);
                l.OnCupula();
                if(secuenciaUsuario[i] != secuencia[i]){
                  ErrorSequence();
                  gover=true;
                }
                
              }
            if(r4 == 1){        
                l.OnLedn(j+32,colores[ColorLeds[j+32]]);
                tono1();
                secuenciaUsuario[i] = j+32;
                flag = 1;
                delay(200);
                l.OnCupula();
                if(secuenciaUsuario[i] != secuencia[i]){
                   ErrorSequence();
                   gover=true;
                }
            }
            PORTB ++; 
        }
}

void SimonDice::GAMEOVER(){
   for(int i=0;i<8;i++){
      int duracionNota = 1000/duracionNotas[i];
      tone(speaker, melodia[i],duracionNota);
      int pausaEntreNotas = duracionNota * 1.30;
      delay(pausaEntreNotas);
      noTone(speaker);
   }  
}

void SimonDice::ErrorSequence(){
  //ALL DOME DISPLAY RED
  l.OnCupulaColor(ROJO);
  GAMEOVER();
  for(int i=0;i<5;i++){
    l.OnCupulaColor(ROJO);
    delay(100);
    l.OnCupula();
  }
  nivelActual=1;
  velocidad=500;
  SequenceGenerator();
  
}

void SimonDice::RightSequence(){
  if(nivelActual < NIVEL_MAX);
      nivelActual++;
   velocidad -= 50;
   delay(200);
}

void SimonDice::SequenceGenerator(){
   for(int i = 1; i < NIVEL_MAX; i++){
    secuencia[i]=random(0,39);
   }
}

//----------------------PIANO
void Piano::piano(){
  flag = 0;
  l.OnCupula();

    //while(!fin){
      for(int i = 0; i < numEntradas; i++){
    
          r0 = digitalRead(y0);
          r1 = digitalRead(y1);
          r2 = digitalRead(y2);
          r3 = digitalRead(y3);
          r4 = digitalRead(y4);
    
          // Comprobamos
          if(r0 == 1){
                l.OnLedn(i,CIAN);
                tocaMux0(i);
          }
          if(r1 == 1){
                l.OnLedn(i+8,CIAN);
                tocaMux1(i);
          }
          if(r2 == 1){
                l.OnLedn(i+16,CIAN);
                tocaMux2(i);
          }
    
          if(r3 == 1){
                l.OnLedn(i+24,CIAN);
                tocaMux3(i);
          }
          
          if(r4 == 1){
                l.OnLedn(i+32,CIAN);
                tocaMux4(i);
          }
          
          PORTB ++; 
          noTone(speaker);
   
      }
      
    //}
}

void Piano::tocaMux0(int indice){
  while( (millis() - tiempo) < 1.5*duracion_nota );
  tiempo = millis();
  //Serial.println("entro");
  tone(speaker, frec_mux0[indice]); 
              
  espero(300);
  noTone(speaker);
            
  flag = 1;
  espero(200);
}

void Piano::tocaMux1(int indice){
  while( (millis() - tiempo) < 1.5*duracion_nota );
  tiempo = millis();
  //Serial.println("entro");
  tone(speaker, frec_mux1[indice]); 
              
  espero(300);
  noTone(speaker);
            
  flag = 1;
  espero(200);
}

void Piano::tocaMux2(int indice){
  while( (millis() - tiempo) < 1.5*duracion_nota );
  tiempo = millis();
  //Serial.println("entro");
  tone(speaker, frec_mux2[indice]); 
              
  espero(300);
  noTone(speaker);
            
  flag = 1;
  espero(200);
}

void Piano::tocaMux3(int indice){
  while( (millis() - tiempo) < 1.5*duracion_nota );
  tiempo = millis();
  //Serial.println("entro");
  tone(speaker, frec_mux3[indice]); 
              
  espero(300);
  noTone(speaker);
            
  flag = 1;
  espero(200);
}

void Piano::tocaMux4(int indice){
  while( (millis() - tiempo) < 1.5*duracion_nota );
  tiempo = millis();
  //Serial.println("entro");
  tone(speaker, frec_mux4[indice]); 
              
  espero(300);
  noTone(speaker);

  flag = 1;
  espero(200);
}

void Piano::espero(int tiempo){
  actual = millis();
  while( (millis() - actual) < tiempo );
}
