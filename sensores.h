#ifndef SENSORES_H
#define SENSORES_H

#include "colors.h"
#include "leds.h"

//Libreria para el manejo del neopixel
#include <Adafruit_NeoPixel.h>

#define numEntradas 8
#define max 10

//Buzzer Pin
static int speaker=12;
#define NIVEL_MAX 100

// salidas, señales control del mux
static int A = 8;
static int B = 9;
static int C = 10;
// entradas
static int y0 = 3; // salida del mux0
static int y1 = 4; // salida del mux1
static int y2 = 5; // salida del mux2
static int y3 = 6; // salida del mux3
static int y4 = 7; // salida del mux4

// variable para guardar lecturas
static int r0; // lectura del mux0
static int r1; // lectura del mux1
static int r2; // lectura del mux2
static int r3; // lectura del mux3
static int r4; // lectura del mux4

//SONIDO
static int melodia[8] = {262, 196, 196, 220, 196, 0, 247, 262};
static long unsigned duracionNotas[8] = {4, 8, 8, 4, 4, 4, 4, 4};
   
class Sensores{
  private:
    Leds l;
    void ConfigPines(){
      pinMode(A, OUTPUT);
      pinMode(B, OUTPUT);
      pinMode(C, OUTPUT); 
      pinMode(y0, INPUT);
      pinMode(y1, INPUT);
      pinMode(y2, INPUT);
      pinMode(y3, INPUT);
      pinMode(y4, INPUT);
    }

   public:
    //Constructor
    Sensores();

    //Funciones sensores y colores
    //MODO CREATIVA 
    void CreativeMode();
    int ArrayLeds[nc];

    void espero(int tiempo);
    void antirrebote(unsigned long retardo);
    void ArrayInitialization();
    
};//clase

class SimonDice{
  public:
    Leds l;
    // SIMON DICE
    // ----------------------
    int nivelActual = 1;
    int velocidad = 500;
    int secuencia[NIVEL_MAX];
    int secuenciaUsuario[NIVEL_MAX];

    int ColorLeds[nc];
    
    void RandomColors();
    // ---------------------------
      
     void tono1();
     void tono2();
     void tono3();
     void tono4();

     void ShowSequence();
     void ReadSequence(int &flag, int i,bool &gover);
     void GAMEOVER();
     void ErrorSequence();
     void RightSequence();
     void SequenceGenerator();

} ;//Fin de la clase

class Piano{
  private:
    Leds l;
    int flag = 0;
    int frec_mux0[max-2] = {
      267, // C4
      294, // D4
      330, // E4
      392, // G4
      440, // A4
      131, // C3
      147, // D3
      165 // E3
    };
    
    int frec_mux1[max-2] = {
      175, // F3
      196, // G3
      220, // A3
      247, // B3
      267, // C4
      294, // D4
      330, // E4
      349 // F4
    };
    
    int frec_mux2[max-2] = {
      392, // G4
      440, // A4
      494, // B4
      523, // C5
      33,  // C1
      41,  // E1
      49,  // G1
      62  // B1
    };
    
    int frec_mux3[max-2] = {
      73,  // D2
      87,  // F2
      110, // A2
      131, // C3
      165, // E3
      196, // G3
      247, // B3
      294 // D4
    };
    
    int frec_mux4[max-2] = {
      349, // F4
      440, // A4
      523, // C5
      659, // E5
      784, // G5
      988, // B5
      1175, // D6
      1397 // F6
    };

    unsigned long duracion_nota = 300;
    unsigned long tiempo = 0;
    size_t i = 0;
    size_t tamanio = sizeof(frec_mux4) / sizeof(int);
    unsigned long actual = 0;
  
  public:
    
    void tocaMux0(int indice);
    void tocaMux1(int indice);
    void tocaMux2(int indice);
    void tocaMux3(int indice);
    void tocaMux4(int indice);
    void piano();
    void espero(int tiempo);
};


#endif
