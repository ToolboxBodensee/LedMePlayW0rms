// Toolbox Bodensee e.V. Worm0r
// for the LEDmePlay
//
// by Thomas Kekeisen
//

void menuLoop()
{
    _C();
    
    unsigned long engineLoopStartPoint;
    
    int     arrowPosition      = 1;
    int     arrowThreshold     = 20;
    int     arrowTickCount     = 0;
    boolean backFromGame       = false;
    boolean buttonDownLocked   = false;
    boolean buttonUpLocked     = false;
    boolean explostionActive   = false;
    int     explosionCount     = 0;
    int     explosionThreshold = 40;
    int     playerCount        = 1;
    int     lastPlayerCount    = 1;
    bool    redraw             = true;
    
    do
    {
        engineLoopStartPoint = millis();
        {
            if (arrowPosition == 1)
            {
                arrowUp(14, 7 - 0, COLOR_BLACK);
                arrowDown(14, 23 + 0, COLOR_BLACK);
            }
            else if (arrowPosition == 0)
            {
                arrowUp(14, 7 - 1, COLOR_BLACK);
                arrowDown(14, 23 + 1, COLOR_BLACK);
            }
            
            explostionActive = explosionManager.tick();
            
            ++arrowTickCount;
            ++explosionCount;
            
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
            
            if (explosionCount >= explosionThreshold)
            {
                explosionCount     = 0;
                explosionThreshold = 25 + (rand() % 60);
                explosionManager.newExplosion({ rand() % (FIELD_WIDTH - 1), rand() % (FIELD_HEIGHT - 1) }, 2 + (rand() % 6));
            }
            
            if (buttonPlayer1DownPressed() && playerCount < 4 && !buttonDownLocked)
            {
                ++playerCount;
                
                buttonDownLocked = redraw = true;
            }
            else if (buttonPlayer1UpPressed() && playerCount > 1 && !buttonUpLocked)
            {
                --playerCount;
                
                buttonUpLocked = redraw = true;
            }
            else if (buttonPlayer1Fire1Pressed())
            {
                backFromGame = gameLoop(playerCount);
            }
            
            if (!buttonPlayer1UpPressed())
            {
                buttonUpLocked = false;
            }
            
            if (!buttonPlayer1DownPressed())
            {
                buttonDownLocked = false;
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
            
            if (playerCount > 1)
            {
                arrowUp(14, 7 - arrowPosition, COLOR_BLUE);
            }
            
            if (playerCount < 4)
            {
                arrowDown(14, 23 + arrowPosition, COLOR_BLUE);
            }
            
            if (backFromGame)
            {
                backFromGame = false;
                
                _C();
                
                redraw = true;   
            }
            
            if (redraw || explostionActive)
            {   
                if (playerCount != lastPlayerCount)
                {
                    lastPlayerCount = playerCount;  
                    
                    _OFF_RECT(11, 12, 12, 8);
                }
                
                matrix.setTextColor(matrix.Color333(3,0,0));
                matrix.setCursor(11, 12);
                matrix.println(outputString);
                
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
