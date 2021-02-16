#include "sensores.h"
#include "leds.h"

//Declaracion de objetos
Leds l;
Sensores sens;
SimonDice s;
Piano pi;

//Adafruit_NeoPixel tira = Adafruit_NeoPixel(nc,11, NEO_GRB + NEO_KHZ800);

//Botones
const int buttonPin = 2;     // the number of the pushbutton pin//black
const int SubModePin = 13;     // the number of the pushbutton pin//GREY

//#define ESTADO_INICIAL  0
#define ESTADO_INICIAL  0
#define ESTADO_LAMPARA  1
#define ESTADO_PIANO    2
#define ESTADO_SENSOR   3
#define ESTADO_SIMON    4

#define SUBMODO_SECTORES 0
#define SUBMODO_COLOR 1
#define SUBMODO_ESPIRAL 2

volatile int modo = 0;
int pAnt = 0;
int subModo = 0;
static int estadoAnt = 0;
static int estadoSig = 1;
static int estadoAct = ESTADO_INICIAL;
bool firstTime = true;
bool firstT = true;
bool gover=false;
int cont = 0;
//Variables para contar el tiempo con millis() dentro de la interrupción
const int Banda = 400;
long bg;

//Variable volatil para la interrupción
volatile int ISR_Cont = 0;
long Time = 0;
int flag=0;


void setup() {
  //Configura las entradas y salidas
  // inicializacion de la tira de leds
  tira.begin();
  tira.show();
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);//BLACK BUTTON
  pinMode(SubModePin, INPUT);  // GREY BUTTON
  //Configura la interrupción en el PIN del pulsador en modo FALLING
  attachInterrupt(digitalPinToInterrupt(buttonPin), InterContador, RISING);
}

void loop() {
  //Esta etapa  incrementa el contador cuando ISR_Cont
  //es modificado dentro de la interrupción
  if (cont != ISR_Cont) {
    cont = ISR_Cont;
  }

  PORTB = B00000000;
  // Control modos
  controlModos();
  // Control submodos
  controlSubModos();

  switch (estadoAct) {
    case ESTADO_INICIAL:
      if (firstTime){
        firstTime = false;
        //startImperialMarch();
        l.OnCupulaColor(AZUL);
      }else{
        l.OnCupulaColor(AZUL);
      }

    break;

    case ESTADO_LAMPARA:
      switch(subModo){
        case SUBMODO_SECTORES:
          firstT=true;
          l.ColorSectors();
          break;
        case SUBMODO_COLOR:
          l.FxOn(1, ROSA);
          l.FxOn(2, AZUL);
          l.FxOn(3, NARANJA);
          break;   
        case SUBMODO_ESPIRAL:
          if(firstT){
            l.OnCupula();
            firstT=false;
            for(int i=0;i<nc;i++){
              l.OnLedn(i,colores[random(0, 9)]);
              delay(100);
            }
          }else{
            l.OnLedn(random(0, 39), colores[random(0, 9)]);
            delay(100);
          }
        break;
      }
      break;

    case ESTADO_PIANO:
      pi.piano();
    break;

    case ESTADO_SENSOR:
      if (!firstTime) {
        l.OnCupula();
        firstTime = true;
        sens.ArrayInitialization();
      }else{
        sens.CreativeMode();
      }

    break;

    case ESTADO_SIMON:
      if(firstTime){
        l.OnCupula();
        firstTime=false;
        gover=false;
        s.nivelActual=1;
        s.RandomColors();
        s.SequenceGenerator();
        delay(500);
      }
      s.ShowSequence();
      Serial.print("nivelActual:");
      Serial.print(s.nivelActual);
      Serial.print("\n");
      int flag;
      for(int i=0;i< s.nivelActual; i++){
        flag = 0;
        do{
          s.ReadSequence(flag,i,gover);
        }while(flag == 0 && estadoAnt!=estadoAct);
      }
      if(!gover)
        s.RightSequence();
      break;
  }

}//loop

//Función que se ejecuta cuando se ACTIVA la INTERRUPCIÓN
void InterContador() {
  //Incrementa el contador

   if (millis() - Time > Banda){
      ISR_Cont++;
      estadoAnt = estadoAct;
      Time = millis();
      noTone(speaker);
   }
}

void controlSubModos(){
  bg = digitalRead(SubModePin);
  if((millis() - Time > Banda) && (bg == 1)){
      //if( {
        subModo++;
        //Serial.println(subModo);
      //}
      Time = millis();
   }
  
  if(subModo == 3){
    subModo = 0;
  }
}

void controlModos(){
  if (pAnt != ISR_Cont) {
    pAnt = ISR_Cont;
    //estadoAnt = estadoAct;
    estadoAct++;
    subModo = 0;

    if (estadoAct == 5) {
      estadoAct = 0;
    }
    flag = 1;
  }
}
