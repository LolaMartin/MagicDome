#include "colors.h"
#include "leds.h"
#include "sensores.h"

#define c 261
#define d 294
#define e 329
#define f 349
#define g 391
#define gS 415
#define a 440
#define aS 466
#define b 494
#define cH 523
#define cSH 554
#define dH 587
#define dSH 622
#define eH 659
#define fH 698
#define fSH 740
#define gH 784
#define gSH 830
#define aH 880
       
void beep (int speaker, int frequencyInHertz, long timeInMilliseconds) { 
    l.OnCupulaColor(AZUL);
    // use led to visualize the notes being played
     
    long delayAmount = (long)(1000000/frequencyInHertz);
    // the lesser delay the higher the note
  
    long timeInSeconds = timeInMilliseconds*1000;
  
    long beepDuration = (long)(timeInSeconds / (delayAmount*2));

    tone(speaker,50);
    noTone(speaker);
    for (int i=0; i < beepDuration; i++) {
        digitalWrite(speaker,HIGH);
        delayMicroseconds(delayAmount);
        digitalWrite(speaker,LOW);
        delayMicroseconds(delayAmount);
    }    
    
    l.OffCupula();
    // set led back to low
    
    delay(20);
    // a little delay to make all notes sound separate
}    
     
void startImperialMarch() {
    // for the sheet music see:
    // http://www.musicnotes.com/sheetmusic/mtd.asp?ppn=MN0016254
    // this is just a translation of said sheet music to frequencies / time in ms
    // used 500 ms for a quart note
    
    beep(speaker, a, 500);
    beep(speaker, a, 500);     
    beep(speaker, a, 500); 
    beep(speaker, f, 350); 
    beep(speaker, cH, 150);
    
    beep(speaker, a, 500);
    beep(speaker, f, 350);
    beep(speaker, cH, 150);
    beep(speaker, a, 1000);
    // first bit
    
    beep(speaker, eH, 500);
    beep(speaker, eH, 500);
    beep(speaker, eH, 500);    
    beep(speaker, fH, 350); 
    beep(speaker, cH, 150);
    
    beep(speaker, gS, 500);
    beep(speaker, f, 350);
    beep(speaker, cH, 150);
    beep(speaker, a, 1000);
    //second bit...
    
//    beep(speaker, aH, 500);
//    beep(speaker, a, 350); 
//    beep(speaker, a, 150);
//    beep(speaker, aH, 500);
//    beep(speaker, gSH, 350); 
//    beep(speaker, gH, 125);
    
//    beep(speaker, fSH, 125);
//    beep(speaker, fH, 125);    
//    beep(speaker, fSH, 250);
//    delay(250);
//    beep(speaker, aS, 250);    
//    beep(speaker, dSH, 500);  
//    beep(speaker, dH, 350);  
//    beep(speaker, cSH, 125);  
//    // start of the interesting bit
    
//    beep(speaker, cH, 125);  
//    beep(speaker, b, 125);  
//    beep(speaker, cH, 250);      
//    delay(250);
//    beep(speaker, f, 250);  
//    beep(speaker, gS, 500);  
//    beep(speaker, f, 375);  
//    beep(speaker, a, 125); 
//    
//    beep(speaker, cH, 500); 
//    beep(speaker, a, 375);  
//    beep(speaker, cH, 125); 
//    beep(speaker, eH, 1000); 
//    // more interesting stuff
//    
//    beep(speaker, aH, 500);
//    beep(speaker, a, 350); 
//    beep(speaker, a, 150);
//    beep(speaker, aH, 500);
//    beep(speaker, gSH, 350); 
//    beep(speaker, gH, 125);
//    
//    beep(speaker, fSH, 125);
//    beep(speaker, fH, 125);    
//    beep(speaker, fSH, 250);
//    delay(250);
//    beep(speaker, aS, 250);    
//    beep(speaker, dSH, 500);  
//    beep(speaker, dH, 350);  
//    beep(speaker, cSH, 125);  
//    // repeat... repeat
//    
//    beep(speaker, cH, 125);  
//    beep(speaker, b, 125);  
//    beep(speaker, cH, 250);      
//    delay(250);
//    beep(speaker, f, 250);  
//    beep(speaker, gS, 500);  
//    beep(speaker, f, 375);  
//    beep(speaker, cH, 125); 
//           
//    beep(speaker, a, 500);            
//    beep(speaker, f, 375);            
//    beep(speaker, cH, 125);            
//    beep(speaker, a, 1000);       
//    // and we're done \ó/    
}

 
