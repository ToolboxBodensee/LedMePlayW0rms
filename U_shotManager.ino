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
        void tick(Worm &player1, Worm &player2, Worm &player3, PowerUpManager &powerUpManager);

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
    if (player.canShoot())
    {
        player.shot();
        
        int wormDirection = player.getDirection();
        Point wormPosition = player.currentPosition();
        
        newShot(wormPosition, wormDirection);
    }
}

void ShotManager::removeShot(Shot &shot, int position)
{
    shot.remove();
           
    for (int i = position; i < shotCount; ++i)
    {
        shots[i] = shots[i + 1];
    } 
       
    --shotCount;
}

void ShotManager::tick(Worm &player1, Worm &player2, Worm &player3, PowerUpManager &powerUpManager)
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
        else if (player3.pointIsOnWorm(shotPosition))
        {
            player3.hitByShot();
        
            hit = playerHit = true;
        }
        
        if (!hit)
        {
            hit = powerUpManager.removePowerUpForPosition(shotPosition);   
        }
        
        if (hit)
        {
            removeShot(shot, i);
            
            explosionManager.newExplosion(shotPosition, 6 + (rand() % 2));
            
            if (playerHit)
            {
                player1.redraw();
                player2.redraw(); 
                player3.redraw();   
            }
        }
        else if (shot.isOutOfBounds())
        {
            removeShot(shot, i);
        }
    }
}
