// Toolbox Bodensee e.V. Worm0r
// for the LEDmePlay
//
// by Thomas Kekeisen
//

boolean scoreLoop()
{
    _C();
    
    unsigned long engineLoopStartPoint;
    
    do
    {
        engineLoopStartPoint = millis();
        {
            if (buttonPlayer1Fire1Pressed())
            {
                buttonPlayer1Fire1Wait();
                
                return true;
            }
            
            matrix.setTextColor(matrix.Color333(3,0,0));
            matrix.setCursor(5, 12);
            matrix.println("TODO");
        }
        
        synchronizeFrames(engineLoopStartPoint);
    }
    while (true);
}
