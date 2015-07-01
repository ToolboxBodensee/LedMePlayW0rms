class Worm
{
    private:
        boolean      alive;
        unsigned int color;
        int          x;
        int          y; 
 
    public:
        Worm();
        void draw();
        boolean isAlive();
        void moveDown();
        void moveLeft();
        void moveRight();
        void moveUp();
     

};

Worm::Worm()
{
    x = 20;
    y = 20;
}

void Worm::draw ()
{
    _P_GREEN(x, y);
}

boolean Worm::isAlive()
{
     return alive;
}

void Worm::moveDown()
{
    ++y;
       
    if (y > 32)
    {
        y = 32;
        alive = false;
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
}

void Worm::moveRight()
{
    ++x;
       
    if (x > 32)
    {
        x = 32;
        alive = false;
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
}
