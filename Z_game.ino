// Toolbox Bodensee e.V. Worm0r
// for the LEDmePlay
//
// by Thomas Kekeisen
//

void gameLoop()
{
    unsigned long engineLoopStartPoint;
    
    Worm *player1 = new Worm();
    
    do
    {
        engineLoopStartPoint = millis();
        {
            
            
            
            if (buttonPlayer1RightPressed())
            {
                
                player1->moveRight();    
            }
            
            if (buttonPlayer1LeftPressed())
            {
                player1->moveLeft();
            }
            
            if (buttonPlayer1DownPressed())
            {
                player1->moveDown();
            }
            
            if (buttonPlayer1UpPressed())
            {
                player1->moveUp();
            }
            
        
            
            player1->draw();
            
            
            
            
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
