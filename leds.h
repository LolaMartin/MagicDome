#ifndef LEDS_H
#define LEDS_H
//Libreria para el manejo del neopixel
#include <Adafruit_NeoPixel.h>
#include "colors.h"

  //Numero de filas
  #define nc 40
  //Numero de celdas
    //Del 0 al 4 ->3 fila
    //del 5 al 14 -> 2 fila
    //del 15 al 39 -> 1 fila
  #define nf 3
  //NUMERO DE SECTORES  
  #define ns 5 
     
  //Brillo de los led
  //Valor por defecto, podemos variarlo de 0 a 250
  #define brillo 30
  
  static Adafruit_NeoPixel tira = Adafruit_NeoPixel(nc,11, NEO_GRB + NEO_KHZ800);
  
  //Array de colores
  static int colores[]= {
     ROJO, VERDE, AZUL, ROSA,AMARILLO, FUCSIA, CIAN, AGUAMARINA, NARANJA, BLANCO,
  };
  
  class Leds{ 
    private:

    public:
    
      //Constructor  
      Leds();
  
      //Recibe el numero que representa al led de la tira y lo convierte a piso y numero
      int FindLed(int n);
      //Enciende el led segun su orden dentro de la tira en el color 
      //que se recibe como parametro
      void OnLedn(int n,int color);
      //Apaga el led de la posicion n
      void OffLedn(int n);
      //Subalgoritmo para encender toda la cupula de color BLANCO
      void OnCupula();
      //Encender cupula entera de un color
      void OnCupulaColor(int color);
      //Subalgoritmo para apagar por completo la cupula
      void OffCupula();
      //Subalgoritmo para encender filas completas de un color determinado
      void FxOn(int f,int color);
      //Funcion que permite apagar una fila escogida
      void FxOff(int f);
      //Funcion que permite iluminar un sector de los 5, dada su posicion
      //en el color que se escoja
      void SectorOn(int i,int color);
      //Funcion de prueba para ver la cupula iluminada en 5 sectores de 
      //Colores ya preestablecidos
      void ColorSector();
      //Traduce el codigo de los colores
      //Mas informacion sobre su codificacion en la libreria de colores
      void ColorTraduction(int &x);  
      //Escoger color
      void SetColor(const int x,int &r,int &g, int &b);  
      //Enciende uno a uno los leds cada uno de un color distinto
      void RandomColor();
      //RAVE
      void RaveMood();
      //Color Sectors
      void ColorSectors();
  } ;

#endif
