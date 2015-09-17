class Shot
{
    private:
        Point position;
        int   direction;
        
    public:
        Point getPosition();
        void goToNextPosition();
        boolean isOutOfBounds();
        void move();
        void remove();
        Shot();
        Shot(Point newPosition, int newDirection);
};

Point Shot::getPosition()
{
    return position;   
}

void Shot::goToNextPosition()
{
    if (direction == DIRECTION_UP)
    {
        --position.y;  
        
        if (!WALLS_ENABLED_SHOTS)
        {
            if (position.y < 0)
            {
                position.y = (FIELD_HEIGHT - 1);
            }
        }
    }
    else if (direction == DIRECTION_DOWN)
    {
         ++position.y;
        
        if (!WALLS_ENABLED_SHOTS)
        {
            if (position.y > (FIELD_HEIGHT - 1))
            {
                position.y = 0;
            }
        }
    }
    else if (direction == DIRECTION_LEFT)
    {
        --position.x;
        
        if (!WALLS_ENABLED_SHOTS)
        {
            if (position.x < 0)
            {
                position.x = (FIELD_WIDTH - 1);
            }
        }
    }
    else if (direction == DIRECTION_RIGHT)
    {
        ++position.x;
        
        if (!WALLS_ENABLED_SHOTS)
        {
            if (position.x > (FIELD_WIDTH - 1))
            {
                position.x = 0;
            }
        }
    }
}

boolean Shot::isOutOfBounds()
{
    if (WALLS_ENABLED_SHOTS)
    {
        return position.x < 0 || position.x > (FIELD_WIDTH - 1) || position.y < 0 || position.y > (FIELD_HEIGHT - 1);
    }
    
    return false;
};

void Shot::move()
{
    remove();
    goToNextPosition();
    
    _P_YELLOW(position.x, position.y);
}

void Shot::remove()
{
    _OFF(position.x, position.y);
}

Shot::Shot()
{
    
}

Shot::Shot(Point newPosition, int newDirection)
{
    direction = newDirection;
    position  = newPosition;
    
    goToNextPosition();
}
