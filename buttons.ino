// Toolbox Bodensee e.V. Worm0r
// for the LEDmePlay
//
// by Thomas Kekeisen
//

// Joystick 1
int buttonU1 = 30;
int buttonD1 = 32;
int buttonL1 = 34;
int buttonR1 = 36;
int buttonFire1 = 38;

// Joystick 2 (2 player mode not supported)
int buttonU2 = 31;
int buttonD2 = 33;
int buttonL2 = 35;
int buttonR2 = 37;
int buttonFire2 = 39;

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
  pinMode(buttonFire1,      INPUT);
  pinMode(buttonFire2,      INPUT);
  pinMode(buttonReset,      INPUT);
  pinMode(buttonPause,      INPUT);

  // Activate internal pull-up resistors
  digitalWrite(buttonL1,    HIGH);
  digitalWrite(buttonR1,    HIGH);
  digitalWrite(buttonU1,    HIGH);
  digitalWrite(buttonD1,    HIGH);
  digitalWrite(buttonFire1, HIGH);
  digitalWrite(buttonFire2, HIGH);
  digitalWrite(buttonReset, HIGH);
  digitalWrite(buttonPause, HIGH);
}

boolean buttonPlayer1Fire1Pressed ()
{
    return digitalRead(buttonFire1) == LOW;
}

boolean buttonPlayer1Fire2Pressed ()
{
    return digitalRead(buttonFire2) == LOW;
}

boolean buttonPlayer1LeftPressed ()
{
    return digitalRead(buttonL1) == LOW;
}

boolean buttonPlayer1RightPressed ()
{
    return digitalRead(buttonR1) == LOW;
}

boolean buttonPlayer1UpPressed ()
{
    return digitalRead(buttonU1) == LOW;
}

boolean buttonPlayer1DownPressed ()
{
    return digitalRead(buttonD1) == LOW;
}

boolean buttonResetPressed ()
{
    return digitalRead(buttonReset) == LOW;
}

boolean buttonPausePressed ()
{
    return digitalRead(buttonPause) == LOW;
}
