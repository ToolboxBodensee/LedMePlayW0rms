class Worm
{
    private:
        boolean      alive;
        unsigned int color;
        boolean      forceGrow;
        int          growCounter;
        int          growThreshold;
        int          lastDirection;
        int          nextDirection;
        void         moveQueue(int start, int count);
        void         offQueue(int start, int count);
        int          points;
        Point        queue[128u];
        int          queueLength;  
        int          shotCooldown;
        boolean      willDie;
        int          x;
        int          y;
        void         addPosition(Point point, boolean grow);
 
    public:
                    Worm();
                    Worm(unsigned int newColor);
        boolean     canShoot();
        void        changeColor();
        void        continueMoving();
        Point       currentPosition();
        void        die();
        void        dieIfPossible();
        int         getDirection();
        int         getPoints();
        void        hitByShot();
        boolean     isAlive();
        void        moved();
        void        moveDown();
        void        moveLeft();
        void        moveRight();
        void        moveToDirection(int newDirection);
        void        moveUp();
        boolean     pointIsOnWorm(Point point);
        boolean     pointIsOnWorm(Point point, boolean skipHead);
        void        reset();
        void        setColor(unsigned int newColor);
        void        shrinkByPercentAmoutOfLength(int percent);
        void        shot();
        void        tick();
        void        redraw();
};

Worm::Worm()
{
    reset();
}

Worm::Worm(unsigned int newColor)
{
    color = newColor;
    
    reset();
}

void Worm::addPosition (Point point, boolean grow)
{
    if (forceGrow)
    {
        forceGrow = false;
        grow = true;
    }
    
    if (!grow)
    {
         Point queueEnd = queue[0];
        _OFF(queueEnd.x, queueEnd.y);
        
        moveQueue(0, queueLength);
    }
    
    if (grow)
    {
        queueLength++;
        
        // dbg("Growing");
    }
    
    queue[queueLength - 1] = point;
    
    Point queueStart = queue[queueLength - 1];
    _P(queueStart.x, queueStart.y, color);
}

boolean Worm::canShoot()
{
    return shotCooldown == 0;
}

void Worm::changeColor ()
{
     color = randomColor();   
}

void Worm::continueMoving ()
{
    moveToDirection(nextDirection);
}

Point Worm::currentPosition()
{
    return { x, y };
}

void Worm::die()
{
    if (!willDie)
    {
        willDie = true;
        
        tone(2, NOTE_C4, 50); // TODO soundmanager
    }
};

void Worm::dieIfPossible()
{
    if (willDie)
    {
        offQueue(0, queueLength);      
        queueLength = 0; 
        
        alive = false;
    } 
};

int Worm::getDirection()
{
    return lastDirection;
}

int Worm::getPoints()
{
    return points;
}

void Worm::hitByShot()
{
    forceGrow = true;
    
    points -= 10;
  
    // TODO sound=   
}

boolean Worm::isAlive()
{
     return !willDie || alive;
}

void Worm::moved()
{
    ++growCounter;
    ++points;
    
    bool grow = false;
    
    if (growCounter >= growThreshold)
    {
        grow = true;
        
        growCounter = 0;
    }
    
    addPosition({ x, y }, grow);
}

void Worm::moveDown()
{
    if (nextDirection == DIRECTION_DOWN) return;
    
    nextDirection = DIRECTION_DOWN;
}

void Worm::moveLeft()
{
    if (nextDirection == DIRECTION_LEFT) return;
    
    nextDirection = DIRECTION_LEFT;
}

void Worm::moveQueue(int start, int count)
{
    for (int i = start; i < count; ++i)
    {
        queue[i] = queue[i + 1];
    }
}

void Worm::offQueue(int start, int count)
{
    for (int i = start; i < count; ++i)
    {
        Point point = queue[i];
        _OFF(point.x, point.y);
    }
}

void Worm::moveRight()
{
    if (nextDirection == DIRECTION_RIGHT) return;
    
    nextDirection = DIRECTION_RIGHT;
}

void Worm::moveToDirection(int newDirection)
{
    if
    (
        (newDirection == DIRECTION_UP    && lastDirection != DIRECTION_DOWN)  ||
        (newDirection == DIRECTION_DOWN  && lastDirection != DIRECTION_UP)    ||
        (newDirection == DIRECTION_LEFT  && lastDirection != DIRECTION_RIGHT) ||
        (newDirection == DIRECTION_RIGHT && lastDirection != DIRECTION_LEFT)
    )
    {
        if (newDirection == DIRECTION_UP)
        {
            --y;
            
            if (y < 0)
            {
                y = 0;
                die();
            } 
        }
        else if (newDirection == DIRECTION_RIGHT)
        {
            ++x;
               
            if (x > (FIELD_WIDTH - 1))
            {
                x = (FIELD_WIDTH - 1);
                die();
            }   
        }
        else if (newDirection == DIRECTION_LEFT)
        {
            --x;
            
            if (x < 0)
            {
                x = 0;
                die();
            }    
        }
        else if (newDirection == DIRECTION_DOWN)
        {
            ++y;
               
            if (y > (FIELD_HEIGHT - 1))
            {
                y = (FIELD_HEIGHT - 1);
                die();
            }  
        }

        lastDirection = newDirection;
        
        if (isAlive())
        {
            moved();
        }
    }
    else
    {
        // TODO: wenn auskommentiert = stop
        nextDirection = lastDirection;
        
        moveToDirection(nextDirection);
    }
}

void Worm::moveUp()
{
    if (nextDirection == DIRECTION_UP) return;
    
    nextDirection = DIRECTION_UP;
}

boolean Worm::pointIsOnWorm(Point point)
{
    if (!isAlive())
    {
        return false;
    }
    
    return Worm::pointIsOnWorm(point, false);
}

boolean Worm::pointIsOnWorm(Point point, boolean skipHead)
{
    int limit = queueLength - (skipHead ? 1 : 0);
    
    for (int i = 0; i < limit; ++i)
    {
         Point currentPoint = queue[i];
         
         if (currentPoint.x == point.x && currentPoint.y == point.y)
         {
             return true;
         } 
    }

    return false;
}

void Worm::reset()
{
    alive         = true;
    growCounter   = 0;
    growThreshold = 10;
    queueLength   = 1;
    points        = 0;
    x             = 3 + (rand() % (FIELD_WIDTH - 6));
    y             = 3 + (rand() % (FIELD_HEIGHT - 6));
    queue[0]      = { x, y };
    willDie       = false;
}

void Worm::setColor (unsigned int newColor)
{
    color = newColor;   
}

void Worm::shrinkByPercentAmoutOfLength(int percent)
{
    float factor = percent / 100.0;
    int pointsToRemove = factor * (float)queueLength;
    
    points += pointsToRemove;
    
    offQueue(0, pointsToRemove);
    
    for (int i = 0; i < pointsToRemove; ++i)
    {
        moveQueue (0, queueLength - 1);
        
        --queueLength;
    }
}

void Worm::redraw()
{
    for (int i = 0; i < queueLength; ++i)
    {
        Point currentPoint = queue[i];
        _P(currentPoint.x, currentPoint.y, color);
    }
}

void Worm::shot()
{
    ++points;
    
    shotCooldown = 5;
};

void Worm::tick()
{
    if (shotCooldown > 0)
    {
        --shotCooldown;
    }   
}
