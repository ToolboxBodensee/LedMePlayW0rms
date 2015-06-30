// Toolbox Bodensee e.V. Worm0r
// for the LEDmePlay
//
// by Thomas Kekeisen
//

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




// Main loop
void loop()
{
 // matrix.drawLine(5, 20, 8, 17, matrix.Color333(1, 1, 4));

  
  do
  {

    gameLoop();

  }
  while (true);
}

void gameLoop()
{
  unsigned long engineLoopStartPoint;
 int x = 0;
  do
  {
    engineLoopStartPoint = millis();
    {

     

      if (buttonPlayer1Fire1Pressed())
      {
        matrix.drawPixel(x, x, matrix.Color333(0, 0, 0));
        x++;
    if (x > 32) x = 0;        
        matrix.drawPixel(x, x, matrix.Color333(0, 255, 0));

      };


    }
    synchronizeFrames(engineLoopStartPoint);
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
