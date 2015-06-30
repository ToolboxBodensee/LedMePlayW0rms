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
 int y = 0;
 int z = 1;
 int r = 255;
 int g = 0;
 int b = 0;
 int c = 0;
  do
  {
    engineLoopStartPoint = millis();
    {

     
matrix.drawPixel(x, y, matrix.Color333(0, 0, 0));

      if (buttonPlayer1RightPressed()) x++;
      if (buttonPlayer1LeftPressed())  x--;
      if (buttonPlayer1DownPressed()) y++;
      if (buttonPlayer1UpPressed()) y--;
      
      if (buttonPlayer1Fire1Pressed()) c++;
    
    
      
          if (x > 31) x = 0;  
    if (y > 31) y = 0;      
    if (x < 0) x = 31;  
    if (y < 0) y = 31;  
    if (c > 255)
    {
        c = 0;
        if (r == 255)
        {
          r = 0;
          b = 255;
        }
        else if (b == 255)
        {
          b = 0;
          g = 255;
        }
        else if (g == 255)
        {
          b = 0;
          r = 255;
        }
    }
      
      
    
          matrix.drawPixel(x, y, matrix.Color333(r, g, b));
        
        
    
      
    


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
