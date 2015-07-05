void mithotronicIntroM(int x, int y)
{
    matrix.fillRect(x + 2, y + 2, 6,  1, matrix.Color333(0, 0, 0));
    matrix.fillRect(x,     y + 3, 10, 1, matrix.Color333(0, 0, 0));
    matrix.fillRect(x,     y + 4, 2,  6, matrix.Color333(3, 3, 3));
    matrix.fillRect(x + 2, y + 3, 2,  2, matrix.Color333(3, 3, 3));
    matrix.fillRect(x + 4, y + 4, 2,  6, matrix.Color333(3, 3, 3));
    matrix.fillRect(x + 6, y + 3, 2,  2, matrix.Color333(3, 3, 3));
    matrix.fillRect(x + 8, y + 4, 2,  6, matrix.Color333(3, 3, 3));
}

void mithotronicIntroT(int x, int y)
{
    matrix.fillRect(x,     y + 5,  6, 1,  matrix.Color333(0, 0, 0));
    matrix.fillRect(x + 2, y + 10, 3, 1,  matrix.Color333(0, 0, 0));
    matrix.fillRect(x,     y + 3,  6, 2,  matrix.Color333(0, 0, 7));
    matrix.fillRect(x + 2, y,      2, 10, matrix.Color333(0, 0, 7));
    matrix.fillRect(x + 4, y + 8,  1, 2,  matrix.Color333(0, 0, 7));
}

void mithotronicIntro ()
{
    for (int i = -10; i <= 11; ++i)
    {
        mithotronicIntroM(7,  i);
        mithotronicIntroT(19, 22 - i);

        delay(50);
    }

    tone(audio,NOTE_C4,200);
    delay(400+20);
   
    tone(audio,NOTE_C4,90);
    delay(200-20);
   
    tone(audio,NOTE_G4,140);
    delay(400+20);
   
    tone(audio,NOTE_G4,140);
    delay(200-20);
   
    tone(audio,NOTE_C5,450);
    delay(600);
   
    tone(audio,NOTE_AS4,140);
    delay(200-20);
   
    tone(audio,NOTE_A4,130);
    delay(200-10);
   
    tone(audio,NOTE_F4,120);
    delay(200);
   
    tone(audio,NOTE_G4,1000);
    delay(3000);
}
