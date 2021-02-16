#include "leds.h"

//Constructor 
Leds::Leds(){
}

int Leds::FindLed(int n){
    int pos;
    //Numero de fila y columna
    //n es el numero que tiene el led en la secuencia de la tira
    if(n<5){
      //Fila con 5 leds
      pos=3*100+n;
    }//Tercera fila
    else if(n>=5 && n<15){
      pos=2*100+n;
    }//Segunda Fila
    else{
      pos=100+n;
    }//Primera fila

    return pos;
}

//Enciende el led segun su posición en la tira
void Leds::OnLedn(int n,int color){
    int r,g,b;
    SetColor(color,r,g,b); 
    tira.setPixelColor(n,r,g,b); // Blanco
    tira.show(); 
}

//Apaga el led en la posicion dada n
void Leds::OffLedn(int n){
    tira.setPixelColor(n,0,0,0); // Apagados
    tira.show();
}

//Subalgoritmo para encender toda la cupula de color BLANCO
void Leds::OnCupula(){
    OnCupulaColor(BLANCO);
}

//Encender cupula entera de un color
void Leds::OnCupulaColor(int color){
    for(int i=0;i<nc;i++)
      OnLedn(i,color);
}

//Subalgoritmo para apagar por completo la cupula
void Leds::OffCupula(){
   for(int i=0;i<nc;i++)
      OffLedn(i);
}

//Subalgoritmo para encender una fila de un color determinado
void Leds::FxOn(int f,int color){
    //Numero de celdas de la fila
    int c=0,i=0;
    
    switch(f){
      case 3:
        i=0;
        c=5;//Piso 3
        break;
      case 2:
        i=5;
        c=20;//Piso 2
        break;
      case 1:
        i=20;
        c=40;//Piso 1
        break;
      }
    
    for(i;i<c;i++)
      OnLedn(i,color);
}

void Leds::FxOff(int f){
    //Numero de celdas de la fila
    int c=0,i=0;
    
    switch(f){
      case 3:
        i=0;
        c=5;//Piso 3
        break;
      case 2:
        i=5;
        c=20;//Piso 2
        break;
      case 1:
        i=20;
        c=40;//Piso 1
        break;
      }
    
    for(i;i<c;i++)
      OffLedn(i);
}

//Encender sector de la cupula
//La cupula tiene 5 sectores, cada uno compuesto por 8 leds (40/5=8)
void Leds::SectorOn(int i,int color){
    switch(i){
      //SECTOR 1
      case 1:
        OnLedn(i-1,color);
        for(int z=16;z<19;z++)
        OnLedn(z,color);
        for(int z=35;z<39;z++)
        OnLedn(z,color);

        break;
        
      case 2:
        OnLedn(i-1,color);
        for(int z=13;z<16;z++)
        OnLedn(z,color);
        for(int z=31;z<35;z++)
        OnLedn(z,color);

        break;

      case 3:
        OnLedn(i-1,color);
        for(int z=10;z<13;z++)
        OnLedn(z,color);
        for(int z=27;z<31;z++)
        OnLedn(z,color);

        break;

      case 4:
        OnLedn(i-1,color);
        for(int z=7;z<10;z++)
        OnLedn(z,color);
        for(int z=23;z<27;z++)
        OnLedn(z,color);

        break;  

      case 5:
        for(int z=i-1;z<7;z++)
        OnLedn(z,color);
        for(int z=19;z<23;z++)
        OnLedn(z,color);
        OnLedn(39,color);

        break;
      }
}

//Funcion de prueba para ver los sectores de distintos colores
void Leds::ColorSector(){
    SectorOn(0,AZUL);
    SectorOn(1,VERDE);
    SectorOn(2,FUCSIA);
    SectorOn(3,AMARILLO);
    SectorOn(4,AZUL);
}
  
void Leds::ColorTraduction(int &x){
    switch(x){
      case 0:
        x=0;
        break;
      case 1:
        x=51;
        break;
      case 2:
        x=102;
        break;
      case 3:
        x=204;
        break;
      case 4:
        x=204;
        break;
      case 5:
        x=255;
        break;
    }//switch
  }
  
//Escoger color
void Leds::SetColor(const int x,int &r,int &g, int &b){
    r=x/100;
    b=x%10;
    g=(x%100)/10;
    ColorTraduction(r);
    ColorTraduction(g);   
    ColorTraduction(b);
}

//Modo rave
void Leds::RandomColor(){
  int cont=0;
  for(int i=0;i<nc;i++){
    OnLedn(i,colores[cont]);
    cont++;
    delay(1000);
    if(cont>=10)
      cont=0;
  }
}

void Leds::RaveMood(){
  int cont=0;
  
  for(int i=0;i<nc;i++){
    OnLedn(i,colores[cont]);
    delay(10);
    cont++;
      for(int i=0;i<nc;i++){
        OnLedn(i,colores[cont]);
        delay(10);
        cont++;
          for(int i=0;i<nc;i++){
             OnLedn(i,colores[cont]);
             delay(10);
             cont++;
              for(int i=0;i<nc;i++){
                OnLedn(i,colores[cont]);
                delay(10);
                cont++;

                if(cont>9)
                  cont=0;
              }//last for
    
          }
      }
  }
}
//Example mode about how you can use color-sector function
void Leds::ColorSectors(){
  SectorOn(1,AZUL);
  SectorOn(2,VERDE);
  SectorOn(3,FUCSIA);
  SectorOn(4,AMARILLO);
  SectorOn(5,ROJO);
}
