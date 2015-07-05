class Worm
{
    private:
        boolean      alive;
        unsigned int color;
        int          growCounter;
        int          growThreshold;
        int          lastDirection;
        void         moveQueue(int start, int count);
        void         offQueue(int start, int count);
        Point        queue[128u];
        int          queueLength;  
        int          x;
        int          y;
        void         addPosition(Point point, boolean grow);
 
    public:
        Worm();
        Worm(unsigned int newColor);
        void changeColor();
        void continueMoving();
        Point currentPosition();
        void die();
        boolean isAlive();
        void moved();
        void moveDown();
        void moveLeft();
        void moveRight();
        void moveToDirection(int newDirection);
        void moveUp();
        boolean pointIsOnWorm(Point point);
        boolean pointIsOnWorm(Point point, boolean skipHead);
        void reset();
        void setColor(unsigned int newColor);
        void shrinkByPercentAmoutOfLength(int percent);
     

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
    if (!grow)
    {
         Point queueEnd = queue[0];
        _OFF(queueEnd.x, queueEnd.y);
        
        moveQueue(0, queueLength);
    }
    
    if (grow)
    {
        queueLength++;
        
        dbg("Growing");
    }
    
    queue[queueLength - 1] = point;
    
       
    Point queueStart = queue[queueLength - 1];
    _P(queueStart.x, queueStart.y, color);
}

void Worm::changeColor ()
{
     color = randomColor();   
}

void Worm::continueMoving ()
{
    moveToDirection(lastDirection);
}

Point Worm::currentPosition()
{
    return { x, y };
}

void Worm::die()
{
    if (alive)
    {
        alive = false;
        
        tone(2, NOTE_C4, 50); // TODO soundmanager
        
        offQueue(0, queueLength);      
        queueLength = 0;
    }
};

boolean Worm::isAlive()
{
     return alive;
}

void Worm::moved()
{
    ++growCounter;
    
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
    moveToDirection(DIRECTION_DOWN);
}

void Worm::moveLeft()
{
    moveToDirection(DIRECTION_LEFT);
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
    moveToDirection(DIRECTION_RIGHT);
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
               
            if (x > 31)
            {
                x = 31;
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
               
            if (y > 31)
            {
                y = 31;
                die();
            }  
        }

        lastDirection = newDirection;
        
        if (alive)
        {
            moved();
        }
    }
    else
    {
        continueMoving();   
    }
}

void Worm::moveUp()
{
    moveToDirection(DIRECTION_UP);
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
    x = 3 + (rand() % 26);
    y = 3 + (rand() % 26);
    queue[0] = { x, y };
}

void Worm::setColor (unsigned int newColor)
{
    color = newColor;   
}

void Worm::shrinkByPercentAmoutOfLength(int percent)
{
    float factor = percent / 100.0;
    int pointsToRemove = factor * (float)queueLength;
    
    offQueue(0, pointsToRemove);
    
    for (int i = 0; i < pointsToRemove; ++i)
    {
        moveQueue (0, queueLength - 1);
        
        --queueLength;
    }
}
