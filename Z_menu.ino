// Toolbox Bodensee e.V. Worm0r
// for the LEDmePlay
//
// by Thomas Kekeisen
//

 

void menuLoop()
{
    unsigned long engineLoopStartPoint;
    
    int playerCount = 1;
    
    do
    {
        engineLoopStartPoint = millis();
        {
         
            
                bool redraw = false;
              
               if (buttonPlayer1DownPressed())
                {
                    ++playerCount;
                    
                   redraw = true;
                }
                else if (buttonPlayer1UpPressed())
                {
                    --playerCount;
                    
                   redraw = true;
                }
                       if (playerCount < 1) playerCount = 1;
                if (playerCount > 4) playerCount = 4;
                
                
                       char ccc[15];
    sprintf(ccc, "%d", playerCount);
    
    
            char str[80];
strcpy(str, ccc);
strcat(str, "P");
                
         
              
              if (redraw)
              {
                  _C();
                  matrix.setTextSize(1);
              matrix.setTextWrap(false);
              matrix.setTextColor(matrix.Color333(3,0,0));
              matrix.setCursor(8, 8);
              matrix.println(str);
              
              while (buttonPlayer1DownPressed() || buttonPlayer1UpPressed())
              {};
              }
            
        }
        
        
        _P_GREEN(1, 1);
          



      synchronizeFrames(engineLoopStartPoint);
  }
  while (true);
}
