// Toolbox Bodensee e.V. Worm0r
// for the LEDmePlay
//
// by Thomas Kekeisen
// Used from http://stackoverflow.com/questions/14663543/memory-limits-on-arduino
//

int getFreeRam()
{
    extern int __heap_start, *__brkval; 
    int v;

    v = (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);

    // dbg("Free RAM = ");
    // dbgInt(v);

    return v;
}
