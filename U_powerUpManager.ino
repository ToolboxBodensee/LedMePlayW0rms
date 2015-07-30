class PowerUpManager
{
    private:
        Point positions[24];
        int powerUpCount;
        int powerUpLimit;
        int tickCounter;
        int tickThreshold;
        
    public:
        PowerUpManager();
        void redraw();
        void removePowerUpAtIndex(int index);
        bool removePowerUpForPosition(Point point);
        void reset();
        void spawnPowerUp(Worm &player1, Worm &player2, Worm &player3);
        void tick(Worm &player1, Worm &player2, Worm &player3);
        void tryPlayer(Worm &player);     

};

PowerUpManager::PowerUpManager()
{
    reset();
}

void PowerUpManager::redraw()
{
    for (int i = 0; i < powerUpCount; ++i)
    {
        Point powerUpPoint = positions[i];
        _P_BLUE(powerUpPoint.x, powerUpPoint.y); 
    }
};

boolean PowerUpManager::removePowerUpForPosition(Point point)
{
    for (int i = 0; i < powerUpCount; ++i)
    {
        Point powerUpPoint = positions[i];
      
        if (powerUpPoint.x == point.x && powerUpPoint.y == point.y)
        {
            removePowerUpAtIndex(i);
            
            return true;
        }  
    }
 
    return false;   
}

void PowerUpManager::removePowerUpAtIndex(int index)
{
    for (int i = index; i < powerUpCount; ++i)
    {
        positions[i] = positions[i + 1];
    }
    
    --powerUpCount;
}

void PowerUpManager::reset()
{
     powerUpCount  = 0;
     powerUpLimit  = 24;
     tickCounter   = 0;
     tickThreshold = 20;
}

void PowerUpManager::spawnPowerUp (Worm &player1, Worm &player2, Worm &player3)
{
    if (powerUpCount < powerUpLimit)
    {
        Point point;
            
        do
        {
            int x = rand() % (FIELD_WIDTH - 1);
            int y = rand() % (FIELD_HEIGHT - 1);
            point = { x, y };
            
            // dbg(F("Powerup position conflict"));
        }
        while (player1.pointIsOnWorm(point) || player2.pointIsOnWorm(point) || player3.pointIsOnWorm(point));
        
        positions[powerUpCount] = point;
        ++powerUpCount;

        _P_BLUE(point.x, point.y);
    }
}

void PowerUpManager::tick(Worm &player1, Worm &player2, Worm &player3)
{
    ++tickCounter;
    
    if (tickCounter >= tickThreshold)
    {
        tickCounter = 0;
        
        spawnPowerUp(player1, player2, player3);
    }
    
    tryPlayer(player1);
    tryPlayer(player2);
    tryPlayer(player3);
}

void PowerUpManager::tryPlayer (Worm &player)
{
    for (int i = 0; i < powerUpCount; ++i)
    {
        Point point = positions[i];
        
        boolean powerUpCollected = player.pointIsOnWorm(point);
        
        if (powerUpCollected)
        {
            tone(2, NOTE_C4, 50); // TODO soundmanager
            
            // dbg(F("Powerup collected"));
            
            int shrinkByPercent = 20 + (rand() % 10);
            
            
            
            player.shrinkByPercentAmoutOfLength(shrinkByPercent);
            
            removePowerUpAtIndex(i);
          
            
            return;
        }
    }
    
    
}
