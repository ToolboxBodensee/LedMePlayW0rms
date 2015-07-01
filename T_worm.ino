class Worm
{
    private:
        boolean      alive;
        unsigned int color;
        int          growCounter;
        int          growThreshold;
        Point        queue[1024];
        int          queueLength;  
        int          x;
        int          y;
        
        void         addPosition(Point point);
 
    public:
        Worm();
        void draw();
        boolean isAlive();
        void moved();
        void moveDown();
        void moveLeft();
        void moveRight();
        void moveUp();
     

};

Worm::Worm()
{
    growCounter   = 0;
    growThreshold = 20;
    queueLength   = 1;
    x             = 20;
    y             = 20;
    queue[0]      = { x, y };
}

void Worm::addPosition (Point point)
{
    for (int i = 0; i < queueLength - 1; ++i)
    {
        queue[i] = queue[i + 1];
    }
    
    Point queueEnd = queue[0];
    _OFF(queueEnd.x, queueEnd.y);
    
    queue[queueLength - 1] = point;
    
 
    //queue[queueLength] = point;

    //++queueLength;
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
    
    Point queueStart = queue[queueLength - 1];
    _P_GREEN(queueStart.x, queueStart.y);
    
    
    _P_RED(0, 0);
 
    
}

boolean Worm::isAlive()
{
     return alive;
}

void Worm::moved()
{
    ++growCounter;
    
    addPosition({ x, y });
    
    if (growCounter >= growThreshold)
    {
        
       // ++queueLength;
        
       // queue[queueLength] = { x, y };
        
        
    }
    else
    {
           
    }
}

void Worm::moveDown()
{
    ++y;
       
    if (y > 32)
    {
        y = 32;
        alive = false;
    }
    else
    {
        moved();
    }
}

void Worm::moveLeft()
{
    --x;
    
    if (x < 0)
    {
        x = 0;
        alive = false;
    }
    else
    {
        moved();
    }
}

void Worm::moveRight()
{
    ++x;
       
    if (x > 32)
    {
        x = 32;
        alive = false;
    }
    else
    {
        moved();
    }
}

void Worm::moveUp()
{
    --y;
    
    if (y < 0)
    {
        y = 0;
        alive = false;
    }
    else
    {
        moved();
    }
}
