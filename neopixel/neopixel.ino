/**
 * Julie Jeannier - October 2016
 * This program is used to program Halloween glasses, made with Neopixel rings as described in this tutorial https://learn.adafruit.com/celebration-spectacles
 */

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// DEFINES
#define PINRIGHT  0
#define PINLEFT   2
#define NUMPIXELS 16  // 16 pixels Neopixel ring

// Neopixel
Adafruit_NeoPixel pixelsRight = Adafruit_NeoPixel(NUMPIXELS, PINRIGHT, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixelsLeft = Adafruit_NeoPixel(NUMPIXELS, PINLEFT, NEO_GRB + NEO_KHZ800);

// Colors used for effects
int R[] = {255,255,255,128,0,0,0,0,0,127,255,255};
int G[] = {0,128,255,255,255,255,255,128,0,0,0,0};
int B[] = {0,0,0,0,0,128,255,255,255,255,255,127};
int nbColor = 12;


// SETUP
void setup() 
{
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  // Configuration for right ring
  pixelsRight.begin();
  pixelsRight.setBrightness(64);
  // Cofniguration for left ring
  pixelsLeft.begin();
  pixelsLeft.setBrightness(64);
}


// LOOP
void loop() 
{
  //effect0();
  effect1();
  effect2();
  effect3();
  effect4();
  effect5();
  effect6();
}


// Used to know pixel number and order
void effect0()
{
      // Pixels right
    pixelsRight.setPixelColor(0, pixelsRight.Color(R[0],G[0],B[0]));
    pixelsRight.setPixelColor(2, pixelsRight.Color(R[0],G[0],B[0]));
    pixelsRight.setPixelColor(5, pixelsRight.Color(R[0],G[0],B[0]));
    pixelsRight.show();
    // Pixel left
    pixelsLeft.setPixelColor(0, pixelsLeft.Color(R[0],G[0],B[0]));
    pixelsLeft.setPixelColor(2, pixelsLeft.Color(R[0],G[0],B[0]));
    pixelsLeft.setPixelColor(5, pixelsLeft.Color(R[0],G[0],B[0]));
    pixelsLeft.show();
}


// Moving color gradient, one pixel displayed
void effect1() 
{
  int j = 0;
  int delayVal = 75;  // Delay in ms

  for(int i=0;i<NUMPIXELS;i++) {
    int color = j%nbColor;

    // Pixels right
    pixelsRight.setPixelColor(i, pixelsRight.Color(R[color],G[color],B[color]));
    pixelsRight.show();
    
    // Pixels left
    pixelsLeft.setPixelColor(i, pixelsLeft.Color(R[color],G[color],B[color]));
    pixelsLeft.show();
    
    delay(delayVal);
    
    // Pixels right
    pixelsRight.setPixelColor(i, pixelsRight.Color(0,0,0));
    pixelsRight.show();
    
    // Pixels right
    pixelsLeft.setPixelColor(i, pixelsLeft.Color(0,0,0));
    pixelsLeft.show();
    
    j++;
  }
}


// Moving color gradient, all pixels displayed
void effect2() 
{
  int delayVal = 20;

  for (int j=0; j<nbColor; j++) {
    for(int i=0;i<NUMPIXELS;i++) {  
      
      // Pixels right
      pixelsRight.setPixelColor(i, pixelsRight.Color(R[j],G[j],B[j]));
      pixelsRight.show();
      
      // Pixel left
      pixelsLeft.setPixelColor(i, pixelsLeft.Color(R[j],G[j],B[j]));
      pixelsLeft.show();
      
      delay(delayVal);
    }
  }
}

// Color change, all pixels displayed
void effect3() 
{
  int delayVal = 250;

  for (int j=0; j<nbColor; j++) {
    
    for(int i=0;i<NUMPIXELS;i++) {  
      
      // Pixels right
      pixelsRight.setPixelColor(i, pixelsRight.Color(R[j],G[j],B[j]));
      pixelsRight.show();
      
      // Pixel left
      pixelsLeft.setPixelColor(i, pixelsLeft.Color(R[j],G[j],B[j]));
      pixelsLeft.show();
    }
    
    delay(delayVal);
  }
}

// Blinking color change, all pixels displayed
void effect4() 
{
  int delayVal = 250;

  for (int j=0; j<nbColor; j++) {
    
    for(int i=0;i<NUMPIXELS;i++) { 
       
      // Pixels right
      pixelsRight.setPixelColor(i, pixelsRight.Color(R[j],G[j],B[j]));
      pixelsRight.show();
      
      // Pixel left
      pixelsLeft.setPixelColor(i, pixelsLeft.Color(R[j],G[j],B[j]));
      pixelsLeft.show();
    }
    
    delay(delayVal);
    
    for(int i=0;i<NUMPIXELS;i++) {  
      
      // Pixels right
      pixelsRight.setPixelColor(i, pixelsRight.Color(0,0,0));
      pixelsRight.show();
      
      // Pixel left
      pixelsLeft.setPixelColor(i, pixelsLeft.Color(0,0,0));
      pixelsLeft.show();
    }

    delay(delayVal);
  }
}

// Moving colors, joining at glasses center
void effect5() 
{
  int j = 0;
  int delayVal = 75;

  for(int i=0;i<NUMPIXELS;i++) {
    int color = j%nbColor;

    // Pixels right
    pixelsRight.setPixelColor(i, pixelsRight.Color(R[color],G[color],B[color]));
    pixelsRight.show();
    
    // Pixel left
    pixelsLeft.setPixelColor(NUMPIXELS-i, pixelsLeft.Color(R[color],G[color],B[color]));
    pixelsLeft.show();
    
    delay(delayVal);
    
    // Pixels right
    pixelsRight.setPixelColor(i, pixelsRight.Color(0,0,0));
    pixelsRight.show();
    
    // Pixels right
    pixelsLeft.setPixelColor(NUMPIXELS-i, pixelsLeft.Color(0,0,0));
    pixelsLeft.show();
    
    j++;
  }

  for(int i=0;i<NUMPIXELS;i++) {
    int color = j%nbColor;

    // Pixels right
    pixelsRight.setPixelColor(NUMPIXELS-i, pixelsRight.Color(R[color],G[color],B[color]));
    pixelsRight.show();
    
    // Pixel left
    pixelsLeft.setPixelColor(i, pixelsLeft.Color(R[color],G[color],B[color]));
    pixelsLeft.show();
    
    delay(delayVal);
    
    // Pixels right
    pixelsRight.setPixelColor(NUMPIXELS-i, pixelsRight.Color(0,0,0));
    pixelsRight.show();
    
    // Pixels right
    pixelsLeft.setPixelColor(i, pixelsLeft.Color(0,0,0));
    pixelsLeft.show();
    
    j++;
  }
}

// Blinking and moving color change, one on two pixels displayed
void effect6()
{
    int delayVal = 250;
    int color = 1;

    for(int j=0; j<nbColor; j++) {
      
        // Pixels right
        pixelsRight.setPixelColor(0, pixelsRight.Color(R[j],G[j],B[j]));
        pixelsRight.setPixelColor(2, pixelsRight.Color(R[j],G[j],B[j]));
        pixelsRight.setPixelColor(4, pixelsRight.Color(R[j],G[j],B[j]));
        pixelsRight.setPixelColor(6, pixelsRight.Color(R[j],G[j],B[j]));
        pixelsRight.setPixelColor(8, pixelsRight.Color(R[j],G[j],B[j]));
        pixelsRight.setPixelColor(10, pixelsRight.Color(R[j],G[j],B[j]));
        pixelsRight.setPixelColor(12, pixelsRight.Color(R[j],G[j],B[j]));
        pixelsRight.setPixelColor(14, pixelsRight.Color(R[j],G[j],B[j]));
    
        pixelsRight.setPixelColor(1, pixelsRight.Color(0,0,0));
        pixelsRight.setPixelColor(3, pixelsRight.Color(0,0,0));
        pixelsRight.setPixelColor(5, pixelsRight.Color(0,0,0));
        pixelsRight.setPixelColor(7, pixelsRight.Color(0,0,0));
        pixelsRight.setPixelColor(9, pixelsRight.Color(0,0,0));
        pixelsRight.setPixelColor(11, pixelsRight.Color(0,0,0));
        pixelsRight.setPixelColor(13, pixelsRight.Color(0,0,0));
        pixelsRight.setPixelColor(15, pixelsRight.Color(0,0,0));
    
        pixelsRight.show();
    
        // Pixels left
        pixelsLeft.setPixelColor(0, pixelsRight.Color(R[j],G[j],B[j]));
        pixelsLeft.setPixelColor(2, pixelsRight.Color(R[j],G[j],B[j]));
        pixelsLeft.setPixelColor(4, pixelsRight.Color(R[j],G[j],B[j]));
        pixelsLeft.setPixelColor(6, pixelsRight.Color(R[j],G[j],B[j]));
        pixelsLeft.setPixelColor(8, pixelsRight.Color(R[j],G[j],B[j]));
        pixelsLeft.setPixelColor(10, pixelsRight.Color(R[j],G[j],B[j]));
        pixelsLeft.setPixelColor(12, pixelsRight.Color(R[j],G[j],B[j]));
        pixelsLeft.setPixelColor(14, pixelsRight.Color(R[j],G[j],B[j]));
    
        pixelsLeft.setPixelColor(1, pixelsRight.Color(0,0,0));
        pixelsLeft.setPixelColor(3, pixelsRight.Color(0,0,0));
        pixelsLeft.setPixelColor(5, pixelsRight.Color(0,0,0));
        pixelsLeft.setPixelColor(7, pixelsRight.Color(0,0,0));
        pixelsLeft.setPixelColor(9, pixelsRight.Color(0,0,0));
        pixelsLeft.setPixelColor(11, pixelsRight.Color(0,0,0));
        pixelsLeft.setPixelColor(13, pixelsRight.Color(0,0,0));
        pixelsLeft.setPixelColor(15, pixelsRight.Color(0,0,0));
    
        pixelsLeft.show();
    
        delay(delayVal);
    
    // Pixels right
        pixelsRight.setPixelColor(0, pixelsRight.Color(0,0,0));
        pixelsRight.setPixelColor(2, pixelsRight.Color(0,0,0));
        pixelsRight.setPixelColor(4, pixelsRight.Color(0,0,0));
        pixelsRight.setPixelColor(6, pixelsRight.Color(0,0,0));
        pixelsRight.setPixelColor(8, pixelsRight.Color(0,0,0));
        pixelsRight.setPixelColor(10, pixelsRight.Color(0,0,0));
        pixelsRight.setPixelColor(12, pixelsRight.Color(0,0,0));
        pixelsRight.setPixelColor(14, pixelsRight.Color(0,0,0));
    
        pixelsRight.setPixelColor(1, pixelsRight.Color(R[j],G[j],B[j]));
        pixelsRight.setPixelColor(3, pixelsRight.Color(R[j],G[j],B[j]));
        pixelsRight.setPixelColor(5, pixelsRight.Color(R[j],G[j],B[j]));
        pixelsRight.setPixelColor(7, pixelsRight.Color(R[j],G[j],B[j]));
        pixelsRight.setPixelColor(9, pixelsRight.Color(R[j],G[j],B[j]));
        pixelsRight.setPixelColor(11, pixelsRight.Color(R[j],G[j],B[j]));
        pixelsRight.setPixelColor(13, pixelsRight.Color(R[j],G[j],B[j]));
        pixelsRight.setPixelColor(15, pixelsRight.Color(R[j],G[j],B[j]));
    
        pixelsRight.show();
    
        // Pixels left
        pixelsLeft.setPixelColor(0, pixelsRight.Color(0,0,0));
        pixelsLeft.setPixelColor(2, pixelsRight.Color(0,0,0));
        pixelsLeft.setPixelColor(4, pixelsRight.Color(0,0,0));
        pixelsLeft.setPixelColor(6, pixelsRight.Color(0,0,0));
        pixelsLeft.setPixelColor(8, pixelsRight.Color(0,0,0));
        pixelsLeft.setPixelColor(10, pixelsRight.Color(0,0,0));
        pixelsLeft.setPixelColor(12, pixelsRight.Color(0,0,0));
        pixelsLeft.setPixelColor(14, pixelsRight.Color(0,0,0));
    
        pixelsLeft.setPixelColor(1, pixelsRight.Color(R[j],G[j],B[j]));
        pixelsLeft.setPixelColor(3, pixelsRight.Color(R[j],G[j],B[j]));
        pixelsLeft.setPixelColor(5, pixelsRight.Color(R[j],G[j],B[j]));
        pixelsLeft.setPixelColor(7, pixelsRight.Color(R[j],G[j],B[j]));
        pixelsLeft.setPixelColor(9, pixelsRight.Color(R[j],G[j],B[j]));
        pixelsLeft.setPixelColor(11, pixelsRight.Color(R[j],G[j],B[j]));
        pixelsLeft.setPixelColor(13, pixelsRight.Color(R[j],G[j],B[j]));
        pixelsLeft.setPixelColor(15, pixelsRight.Color(R[j],G[j],B[j]));
    
        pixelsLeft.show();
    
        delay(delayVal);
  }
}

