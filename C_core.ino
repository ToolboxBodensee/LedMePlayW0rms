// Toolbox Bodensee e.V. Worm0r
// for the LEDmePlay
//
// by Thomas Kekeisen
//

#include <stdlib.h>

// Include libraries for adafruit matrix
#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library
#include <avr/pgmspace.h>   // Necessary in order to maintain the maze data in program memory

// Setup adafruit matrix
#define CLK 50
#define OE  51
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3
RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false);



void setup()
{
  // Initialize serial connection
  Serial.begin(9600);

  // Initialize random number generator
  randomSeed(analogRead(40));

  initButtons();
  initMatrix();

  // Enter the game loop
  loop();
}

void initMatrix ()
{
    // Initialize matrix and define text mode
    matrix.begin();
    matrix.setTextSize(1);
    matrix.setTextWrap(false); 
}

void _C ()
{
    clearMatrix();    
}

void _L (int startX, int startY, int endX, int endY, unsigned int color)
{
    drawLine(startX, startY, endX, endY, color);
}

void _L_BLUE (int startX, int startY, int endX, int endY)
{
    drawLine(startX, startY, endX, endY, COLOR_BLUE);
}

void _L_GREEN (int startX, int startY, int endX, int endY)
{
    drawLine(startX, startY, endX, endY, COLOR_GREEN);
}

void _L_RED (int startX, int startY, int endX, int endY)
{
    drawLine(startX, startY, endX, endY, COLOR_RED);
}

void _OFF (int x, int y)
{
    drawPixel(x, y, COLOR_BLACK);
}

void _P (int x, int y, unsigned int color)
{
    drawPixel(x, y, color);
}

void _P_BLUE (int x, int y)
{
    drawPixel(x, y, COLOR_BLUE);
}

void _P_GREEN (int x, int y)
{
    drawPixel(x, y, COLOR_GREEN);
}

void _P_RED (int x, int y)
{
    drawPixel(x, y, COLOR_RED);
}

void clearMatrix ()
{
     matrix.fillScreen(COLOR_BLACK);  
}

void drawLine (int startX, int startY, int endX, int endY, unsigned int color)
{
    matrix.drawLine(startX, startY, endX, endY, color);
}

void drawPixel (int x, int y, unsigned int color)
{
    matrix.drawPixel(x, y, color);
}

unsigned int randomColor ()
{
    int index = rand() % 3;
    
    if (index == 0)
    {
        return COLOR_RED;
    }
    else if (index == 1)
    {
        return COLOR_BLUE;
    }
     
    return COLOR_GREEN;   
}

// Main loop
void loop()
{
    do
    {

        //gameLoop();
        menuLoop();
    }
    while (true);
}

void synchronizeFrames (unsigned long engineLoopStartPoint)
{
  do
  {
  }
  while (abs(millis() - engineLoopStartPoint) < 20);
}
