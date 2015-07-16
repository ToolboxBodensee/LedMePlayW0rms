// Toolbox Bodensee e.V. Worm0r
// for the LEDmePlay
//
// by Thomas Kekeisen
//


Worm player1 = Worm(COLOR_RED);

Worm player2 = Worm(COLOR_GREEN);

PowerUpManager powerUpManager = PowerUpManager();

ShotManager shotManager = ShotManager();



boolean gameLoop(int playerCount)
{
    explosionManager.clearAll();
  
    _C();

  unsigned long engineLoopStartPoint;

  int  tickCounter      = 0;
  int  tickCounterHalf  = 0;
  int  tickThreshold    = 20;
  int  speedUpCounter   = 0;
  int  speedUpThreshold = 500;
  
  player1.reset();
  player2.reset();
    powerUpManager.reset();

  do
  {
    engineLoopStartPoint = millis();
    {
      // dbg("Tick");

      ++tickCounter;
      ++tickCounterHalf;
      ++speedUpCounter;

      if (speedUpCounter >= speedUpThreshold)
      {
        speedUpCounter = 0;

        if (tickThreshold > 4)
        {
          --tickThreshold;
        }
      }
      
      boolean explosionActive = explosionManager.tick();

    if (player1.isAlive())
        {
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
    
            if (buttonPlayer1Fire1Pressed())
            {
              shotManager.newShot(player1);
            }
        }
        //*/


        //*
         if (player2.isAlive())
        {
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
    
            if (buttonPlayer2Fire1Pressed())
            {
              shotManager.newShot(player2);
            }
        }

      if (tickCounter >= tickThreshold)
      {
        tickCounter = 0;

        player1.tick();
        player2.tick();

      if (player1.isAlive())
        {
            player1.continueMoving();
        }
        
        if (player2.isAlive())
        {
            player2.continueMoving();
        }
        
        
        powerUpManager.tick(player1, player2);
        

     if (player2.pointIsOnWorm(player1.currentPosition()))
    {
        player1.die();
    }
    else if (player1.pointIsOnWorm(player1.currentPosition(), true))
    {
        player1.die();
    }
    
    if (player1.pointIsOnWorm(player2.currentPosition()))
    {
        player2.die();
    }
    else if (player2.pointIsOnWorm(player2.currentPosition(), true))
    {
        player2.die();
    }


        //tone(2, NOTE_FS5, 20);
      }
            if ((tickCounterHalf * 2) >= tickThreshold)
      {
        tickCounterHalf = 0;
        
        shotManager.tick(player1, player2, powerUpManager);
        
      }
      //*/
      
      
      if (explosionActive)
      {
          player1.redraw();
          player2.redraw();
          powerUpManager.redraw();
      }

      _P_RED(1, 1);



    if (!stillPlayerAlive())
    {
        return scoreLoop(player1.getPoints(), player2.getPoints());
    }


    }
    synchronizeFrames(engineLoopStartPoint);
  }
  while (true);
}

boolean stillPlayerAlive ()
{
    if (player1.isAlive()) return true;
    if (player2.isAlive()) return true;
    
    return false;
};
