// Toolbox Bodensee e.V. Worm0r
// for the LEDmePlay
//
// by Thomas Kekeisen
//

void menuLoop()
{
    unsigned long engineLoopStartPoint;
    
    int  arrowPosition  = 1;
    int  arrowThreshold = 20;
    int  arrowTickCount = 0;
    int  playerCount    = 1;
    bool redraw         = true;
    
    do
    {
        engineLoopStartPoint = millis();
        {
            ++arrowTickCount;
            
            if (arrowTickCount >= arrowThreshold)
            {
                arrowTickCount = 0;
                
                if (arrowPosition == 1)
                {
                    arrowPosition = 0;
                }
                else
                {
                    arrowPosition = 1;
                }
            }
            
            if (buttonPlayer1DownPressed() && playerCount < 4)
            {
                ++playerCount;
                redraw = true;
            }
            else if (buttonPlayer1UpPressed() && playerCount > 1)
            {
                --playerCount;
                redraw = true;
            }
            else if (buttonPlayer1Fire1Pressed())
            {
                gameLoop(playerCount);
            }
            
            if (playerCount < 1)
            {
                playerCount = 1;
            }
            else if (playerCount > 4)
            {
                playerCount = 4;
            }
                
            char playerCountString[15];
            sprintf(playerCountString, "%d", playerCount);
    
            char outputString[80];
            strcpy(outputString, playerCountString);
            strcat(outputString, "P");
            
            arrowUp(14, 7 - 0, COLOR_BLACK);
            arrowUp(14, 7 - 1, COLOR_BLACK);
            
            arrowDown(14, 23 + 0, COLOR_BLACK);
            arrowDown(14, 23 + 1, COLOR_BLACK);
            
            if (playerCount > 1)
            {
                arrowUp(14, 7 - arrowPosition, COLOR_BLUE);
            }
            
            if (playerCount < 4)
            {
                arrowDown(14, 23 + arrowPosition, COLOR_BLUE);
            }
            
            if (redraw)
            {    
                _C();
                
                matrix.setTextColor(matrix.Color333(3,0,0));
                matrix.setCursor(11, 12);
                matrix.println(outputString);
                
                while (buttonPlayer1DownPressed() || buttonPlayer1UpPressed())
                {
              
                };
                
                redraw = false;
            }
        }
        
        synchronizeFrames(engineLoopStartPoint);
    }
    while (true);
}

void arrowDown (int x, int y, unsigned int color)
{
    _L(x,     y,     x + 2, y + 2, color);
    _L(x + 2, y + 2, x + 4, y,     color); 
}

void arrowUp (int x, int y, unsigned int color)
{
    _L(x,     y,     x + 2, y - 2, color);
    _L(x + 2, y - 2, x + 4, y,     color); 
}
