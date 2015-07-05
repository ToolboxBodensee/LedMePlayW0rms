class ShotManager
{
    private:
        int  shotCount;
        Shot shots[24];
        
    public:
        void newShot(Point position, int direction);
        void newShot(Worm &player);
        ShotManager(); 
        void removeShot(Shot &shot, int position); 
        void tick(Worm &player1, Worm &player2, PowerUpManager &powerUpManager);

};

ShotManager::ShotManager()
{
    shotCount = 0;
}

void ShotManager::newShot(Point position, int direction)
{
    if (shotCount < 23)
    {
        Shot shot = Shot(position, direction);
        shots[shotCount] = shot;
        ++shotCount;
    }
}

void ShotManager::newShot(Worm &player)
{
    int wormDirection = player.getDirection();
    Point wormPosition = player.currentPosition();
    
    newShot(wormPosition, wormDirection);
}

void ShotManager::removeShot(Shot &shot, int position)
{
    shot.remove();
           
    for (int ii = position; ii < shotCount; ++ii)
    {
        shots[ii] = shots[ii + 1];
    } 
       
    --shotCount;
}

void ShotManager::tick(Worm &player1, Worm &player2, PowerUpManager &powerUpManager)
{
    for (int i = 0; i < shotCount; ++i)
    {
        Shot &shot = shots[i];
        shot.move();
        
        Point shotPosition = shot.getPosition();
        boolean hit = false;
        boolean playerHit = false;
        
        if (player1.pointIsOnWorm(shotPosition))
        {
            player1.hitByShot();
        
            hit = playerHit = true;
        }
        else if (player2.pointIsOnWorm(shotPosition))
        {
            player2.hitByShot();
        
            hit = playerHit = true;
        }
        
        if (!hit)
        {
            hit = powerUpManager.removePowerUpForPosition(shotPosition);   
        }
        
        if (hit)
        {
            removeShot(shot, i);
            
            if (playerHit)
            {
                player1.redraw();
                player2.redraw();   
            }
        }
        else if (shot.isOutOfBounds())
        {
            removeShot(shot, i);
        }
    }
}
