void dbg (String output)
{
   // Serial.println(output);
}

void dbgInt (int output)
{
    char str[15];
    sprintf(str, "%d", output);
    
    dbg(str);
}
