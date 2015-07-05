// Toolbox Bodensee e.V. Worm0r
// for the LEDmePlay
//
// by Thomas Kekeisen
// inspired by Michael Rosskopfs explosion function, thanks!
// http://mithotronic.de/downloads/Gigapede.ino
//

class Explosion
{
    private:
        int   coolDown;
        Point point;
        int   size;
        int   state;
        
    public:
        Explosion();
        Explosion(Point newPoint, int size);
        boolean isDone();
        void    performNextState();
};

Explosion::Explosion()
{
    coolDown = 0;
    state    = 0;
}

Explosion::Explosion(Point newPoint, int newSize)
{
    coolDown = 0;
    point    = newPoint;
    size     = newSize;
    state    = 0;
}

boolean Explosion::isDone()
{
    return state >= size * 2;
}

void Explosion::performNextState()
{
    if (coolDown == 0)
    {
        coolDown = 2;
    
        if (state == 0)
        {
            matrix.fillCircle(point.x, point.y, 1, matrix.Color888(127, 127, 127));
            tone(audio, 2048, 40);
        }
        else if (state == 1 && size >= 2)
        {
            matrix.fillCircle(point.x, point.y, 2, matrix.Color888(127, 127, 112));
            tone(audio, 1024, 40);
        }
        else if (state == 2 && size >= 3)
        {
            matrix.fillCircle(point.x, point.y, 3, matrix.Color888(112, 112, 92));
            tone(audio,512,40);
        }
        else if (state == 3 && size >= 4)
        {
            matrix.fillCircle(point.x, point.y, 4, matrix.Color888(92, 92, 72));
            tone(audio,256,40);
        }
        else if (state == 4 && size >= 5)
        {
            matrix.fillCircle(point.x, point.y, 5, matrix.Color888(74, 74, 40));
            tone(audio,128,40);
        }
        else if (state == 5 && size >= 6)
        {
            matrix.fillCircle(point.x, point.y, 6, matrix.Color888(40, 40, 20));
            tone(audio,64,40);
        }
        else if (state == 6 && size >= 7)
        {
            matrix.fillCircle(point.x, point.y, 7, matrix.Color888(20, 20, 10));
            tone(audio,32,40);
        }
        else if (state == 7 && size >= 8)
        {
            matrix.fillCircle(point.x, point.y, 8, matrix.Color888(10, 10, 0));
            tone(audio,16,40);
        }
        else
        {
            matrix.fillCircle(point.x, point.y, state - size, matrix.Color888(0, 0, 0));
        }
        
        ++state;
    }
    else
    {
        --coolDown;   
    }
}

class ExplosionManager
{
    private:
        int       explosionCounter;
        Explosion explosions[10];
        
    public:
        ExplosionManager();
        void newExplosion(Point point, int size);
        boolean tick(); 

};

ExplosionManager::ExplosionManager()
{
    explosionCounter = 0;
}

void ExplosionManager::newExplosion(Point point, int size)
{
    if (explosionCounter < 9)
    {
        Explosion explosion = Explosion(point, size);
        explosions[explosionCounter] = explosion;
        ++explosionCounter;
    }
}

boolean ExplosionManager::tick()
{
    boolean animationProcessed = false;
    
    for (int i = 0; i < explosionCounter; ++i)
    {
        Explosion &explosion = explosions[i];
        explosion.performNextState();

        if (explosion.isDone())
        {
            for (int ii = i; ii < explosionCounter; ++ii)
            {
                explosions[i] = explosions[ii + 1];
            }
            
            --explosionCounter;
        }
        
        animationProcessed = true;
    }
    
    return animationProcessed;
}

ExplosionManager explosionManager = ExplosionManager();
