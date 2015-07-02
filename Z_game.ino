// Toolbox Bodensee e.V. Worm0r
// for the LEDmePlay
//
// by Thomas Kekeisen
//

 
     Worm player1 = Worm(COLOR_RED);

      Worm player2 = Worm(COLOR_GREEN); 



void gameLoop()
{
    unsigned long engineLoopStartPoint;
    
    int tickCounter   = 0;
    int tickThreshold = 20;
    

   
   
    do
    {
        engineLoopStartPoint = millis();
        {
            dbg("Tick");
            
            ++tickCounter;
            
            if (tickCounter >= tickThreshold)
            {
                tickCounter = 0;
            
            
            
                //*
                if (buttonPlayer1RightPressed())
                {
                    player1.moveRight();    
                }
                else if (buttonPlayer1LeftPressed())
                {
                    player1.moveLeft();
                }
                else if (buttonPlayer1DownPressed())
                {
                    player1.moveDown();
                }
                else if (buttonPlayer1UpPressed())
                {
                    player1.moveUp();
                }
                else
                {
                    player1.continueMoving();
                }
               
                if (buttonPlayer1Fire1Pressed())
                {
                    player1.changeColor();
                }
                //*/
      
                
                //*
                if (buttonPlayer2RightPressed())
                {
                    player2.moveRight();    
                }
                else if (buttonPlayer2LeftPressed())
                {
                    player2.moveLeft();
                }
                else if (buttonPlayer2DownPressed())
                {
                    player2.moveDown();
                }
                else if (buttonPlayer2UpPressed())
                {
                    player2.moveUp();
                }
                else
                {
                    player2.continueMoving();
                }
               
                if (buttonPlayer2Fire1Pressed())
                {
                    player2.changeColor();
                }
            }
            //*/
        
          _P_RED(0, 0);
            
            
            
    /* 
matrix.drawPixel(x, y, matrix.Color333(0, 0, 0));


      
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
        
        
    */
    //_P_RED(10, 10);
    
    //_L(12, 12, 50, 50, COLOR_RED);      
    


      }
      synchronizeFrames(engineLoopStartPoint);
  }
  while (true);
}
