// Toolbox Bodensee e.V. Worm0r
// for the LEDmePlay
//
// by Thomas Kekeisen
//

// Joystick 1
int buttonU1    = 30;
int buttonD1    = 32;
int buttonL1    = 34;
int buttonR1    = 36;
int buttonFire1 = 38;

// Joystick 2
int buttonU2    = 31;
int buttonD2    = 33;
int buttonL2    = 35;
int buttonR2    = 37;
int buttonFire2 = 39;

// Joystick 3
int buttonU3    = 40;
int buttonD3    = 42;
int buttonL3    = 44;
int buttonR3    = 46;
int buttonFire3 = 48;

// Other buttons
int buttonReset = 42;
int buttonPause = 43;

void initButtons()
{
    // Initialize joystick buttons
    pinMode(buttonL1,         INPUT);
    pinMode(buttonR1,         INPUT);
    pinMode(buttonU1,         INPUT);
    pinMode(buttonD1,         INPUT);
    pinMode(buttonL2,         INPUT);
    pinMode(buttonR2,         INPUT);
    pinMode(buttonU2,         INPUT);
    pinMode(buttonD2,         INPUT);
    pinMode(buttonL3,         INPUT);
    pinMode(buttonR3,         INPUT);
    pinMode(buttonU3,         INPUT);
    pinMode(buttonD3,         INPUT);
    pinMode(buttonFire1,      INPUT);
    pinMode(buttonFire2,      INPUT);
    pinMode(buttonFire3,      INPUT);
    pinMode(buttonReset,      INPUT);
    pinMode(buttonPause,      INPUT);
  
    // Activate internal pull-up resistors
    digitalWrite(buttonL1,    HIGH);
    digitalWrite(buttonR1,    HIGH);
    digitalWrite(buttonU1,    HIGH);
    digitalWrite(buttonD1,    HIGH);
    digitalWrite(buttonL2,    HIGH);
    digitalWrite(buttonR2,    HIGH);
    digitalWrite(buttonU2,    HIGH);
    digitalWrite(buttonD2,    HIGH);
    digitalWrite(buttonL3,    HIGH);
    digitalWrite(buttonR3,    HIGH);
    digitalWrite(buttonU3,    HIGH);
    digitalWrite(buttonD3,    HIGH);
    digitalWrite(buttonFire1, HIGH);
    digitalWrite(buttonFire2, HIGH);
    digitalWrite(buttonFire3, HIGH);
    digitalWrite(buttonReset, HIGH);
    digitalWrite(buttonPause, HIGH);
}

boolean buttonPlayer1Fire1Pressed ()
{
    boolean result = digitalRead(buttonFire1) == LOW;
    
    if (result)
    {
        dbg(F("Player 1 fire 1 pressed"));
    }
    
    return result;
}

boolean buttonPlayer1Fire1Wait ()
{
    while (buttonPlayer1Fire1Pressed())
    {
        
    }
}

boolean buttonPlayer1Fire2Pressed ()
{
    boolean result = digitalRead(buttonFire1) == LOW;
    
    if (result)
    {
        // dbg(F("Player 1 fire 2 pressed"));
    }
    
    return result;
}

boolean buttonPlayer1LeftPressed ()
{
    boolean result = digitalRead(buttonL1) == LOW;
    
    if (result)
    {
        // dbg(F("Player 1 left pressed"));
    }
    
    return result;
}

boolean buttonPlayer1RightPressed ()
{
    boolean result = digitalRead(buttonR1) == LOW;
    
    if (result)
    {
        // dbg(F("Player 1 right pressed"));
    }
    
    return result;
}

boolean buttonPlayer1UpPressed ()
{
    boolean result = digitalRead(buttonU1) == LOW;
    
    if (result)
    {
        // dbg(F("Player 1 up pressed"));
    }
    
    return result;
}

boolean buttonPlayer1DownPressed ()
{
    boolean result = digitalRead(buttonD1) == LOW;
    
    if (result)
    {
        // dbg(F("Player 1 down pressed"));
    }
    
    return result;
}








boolean buttonPlayer3Fire1Pressed ()
{
    boolean result = digitalRead(buttonFire3) == LOW;
    
    if (result)
    {
        //dbg(F("Player 3 fire 3 pressed"));
    }
    
    return result;
}

boolean buttonPlayer3Fire1Wait ()
{
    while (buttonPlayer3Fire1Pressed())
    {
        
    }
}

boolean buttonPlayer3Fire2Pressed ()
{
    boolean result = digitalRead(buttonFire3) == LOW;
    
    if (result)
    {
        // dbg(F("Player 1 fire 2 pressed"));
    }
    
    return result;
}

boolean buttonPlayer3LeftPressed ()
{
    boolean result = digitalRead(buttonL3) == LOW;
    
    if (result)
    {
        // dbg(F("Player 1 left pressed"));
    }
    
    return result;
}

boolean buttonPlayer3RightPressed ()
{
    boolean result = digitalRead(buttonR3) == LOW;
    
    if (result)
    {
        // dbg(F("Player 1 right pressed"));
    }
    
    return result;
}

boolean buttonPlayer3UpPressed ()
{
    boolean result = digitalRead(buttonU3) == LOW;
    
    if (result)
    {
        // dbg(F("Player 1 up pressed"));
    }
    
    return result;
}

boolean buttonPlayer3DownPressed ()
{
    boolean result = digitalRead(buttonD3) == LOW;
    
    if (result)
    {
        // dbg(F("Player 1 down pressed"));
    }
    
    return result;
}






boolean buttonResetPressed ()
{
    boolean result = digitalRead(buttonReset) == LOW;
    
    if (result)
    {
        // dbg(F("Reset pressed"));
    }
    
    return result;
}

boolean buttonPausePressed ()
{
    boolean result = digitalRead(buttonPause) == LOW;
    
    if (result)
    {
        // dbg(F("Pause pressed"));
    }
    
    return result;
}

boolean buttonPlayer2Fire1Pressed ()
{
    boolean result = digitalRead(buttonFire2) == LOW;
    
    if (result)
    {
        // dbg(F("Player 2 fire 1 pressed"));
    }
    
    return result;
}

boolean buttonPlayer2Fire2Pressed ()
{
    boolean result = digitalRead(buttonFire2) == LOW;
    
    if (result)
    {
        // dbg("Player 2 fire 2 pressed");
    }
    
    return result;
}

boolean buttonPlayer2LeftPressed ()
{
    boolean result = digitalRead(buttonL2) == LOW;
    
    if (result)
    {
        // dbg("Player 2 left pressed");
    }
    
    return result;
}

boolean buttonPlayer2RightPressed ()
{
    boolean result = digitalRead(buttonR2) == LOW;
    
    if (result)
    {
        // dbg(F("Player 2 right pressed"));
    }
    
    return result;
}

boolean buttonPlayer2UpPressed ()
{
    boolean result = digitalRead(buttonU2) == LOW;
    
    if (result)
    {
        // dbg("Player 2 up pressed");
    }
    
    return result;
}

boolean buttonPlayer2DownPressed ()
{
    boolean result = digitalRead(buttonD2) == LOW;
    
    if (result)
    {
        // dbg(F("Player 2 down pressed"));
    }
    
    return result;
}
