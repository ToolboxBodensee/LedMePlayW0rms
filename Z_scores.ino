// Toolbox Bodensee e.V. Worm0r
// for the LEDmePlay
//
// by Thomas Kekeisen
//

boolean scoreLoop(int player1Points, int player2Points)
{
    _C();
    
    unsigned long engineLoopStartPoint;
    
    char player1PointsString[15];
    sprintf(player1PointsString, "%d", player1Points);
    
    char player2PointsString[15];
    sprintf(player2PointsString, "%d", player2Points);
    
    do
    {
        engineLoopStartPoint = millis();
        {
            if (buttonPlayer1Fire1Pressed())
            {
                buttonPlayer1Fire1Wait();
                
                return true;
            }
            
            matrix.setTextColor(COLOR_RED);
            matrix.setCursor(2, 2);
            //matrix.println("P1");
            //matrix.setCursor(16, 2);
            matrix.println(player1PointsString);
       
            matrix.setTextColor(COLOR_BLUE);
            matrix.setCursor(2, 11);
            //matrix.println("P2");
            //matrix.setCursor(16, 20);
            matrix.println(player2PointsString);
        }
        
        synchronizeFrames(engineLoopStartPoint);
    }
    while (true);
}
