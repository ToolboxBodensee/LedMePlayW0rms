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
        
        void         addPosition(Point point, boolean grow);
 
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
    _P_GREEN(queueStart.x, queueStart.y);
    
 
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
 
    
    _P_RED(0, 0);
 
    
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
    ++y;
       
    if (y > 31)
    {
        y = 31;
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
       
    if (x > 31)
    {
        x = 31;
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
