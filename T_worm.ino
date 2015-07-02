class Worm
{
    private:
        boolean      alive;
        unsigned int color;
        int          growCounter;
        int          growThreshold;
        int          lastDirection;
        Point        queue[512];
        int          queueLength;  
        int          x;
        int          y;
        
        void         addPosition(Point point, boolean grow);
 
    public:
        Worm(unsigned int newColor);
        void changeColor();
        void continueMoving();
        void draw();
        boolean isAlive();
        void moved();
        void moveDown();
        void moveLeft();
        void moveRight();
        void moveToDirection(int newDirection);
        void moveUp();
        void setColor(unsigned int newColor);
     

};

Worm::Worm(unsigned int newColor)
{
    color         = newColor;
    growCounter   = 0;
    growThreshold = 10;
    queueLength   = 1;
    x = 31;
    y = 31;
    queue[0] = {31, 31};
}

void Worm::addPosition (Point point, boolean grow)
{
    
    
   // grow = false;
    if (!grow)
    {
         Point queueEnd = queue[0];
        _OFF(queueEnd.x, queueEnd.y);
        
        for (int i = 0; i < queueLength - 1; ++i)
        {
            queue[i] = queue[i + 1];
        }
    
       
    
    }
    
    
    
    if (grow)
    {
        queueLength++;
        
        dbg("Growing");
    }
    
    queue[queueLength - 1] = point;
    
       
    Point queueStart = queue[queueLength - 1];
    _P(queueStart.x, queueStart.y, color);
    
 
    //queue[queueLength] = point;

    //++queueLength;
}

void Worm::changeColor ()
{
     color = randomColor();   
}

void Worm::continueMoving ()
{
    moveToDirection(lastDirection);
}

void Worm::draw ()
{
    // turn of first
    // rebuild array
    // draw latest
    
    //clearMatrix();
    

    
  //  removeLastQueueEntry();
    
  /*  for (int i = 0; i < queueLength; ++i)
    {
        Point currentPoint = queue[i];
        
       _P_GREEN(currentPoint.x, currentPoint.y);
    }*/
 
    
  //  
 
    
}

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

void Worm::moveRight()
{
    moveToDirection(DIRECTION_RIGHT);
}

void Worm::moveToDirection(int newDirection)
{
    if (newDirection == DIRECTION_UP)
    {
        --y;
        
        if (y < 0)
        {
            y = 0;
            alive = false;
        } 
    }
    else if (newDirection == DIRECTION_RIGHT)
    {
        ++x;
           
        if (x > 31)
        {
            x = 31;
            alive = false;
        }   
    }
    else if (newDirection == DIRECTION_LEFT)
    {
        --x;
        
        if (x < 0)
        {
            x = 0;
            alive = false;
        }    
    }
    else if (newDirection == DIRECTION_DOWN)
    {
        ++y;
           
        if (y > 31)
        {
            y = 31;
            alive = false;
        }  
    }
    alive = true;
    lastDirection = newDirection;
    
    if (alive)
    {
        moved();
    }
}

void Worm::moveUp()
{
    moveToDirection(DIRECTION_UP);
}

void Worm::setColor (unsigned int newColor)
{
     color = newColor;   
}
