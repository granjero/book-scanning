
#include <stdlib.h>

const char BIT_BOTTOM       = 2;    // Fin de carrera Inferior IN pin2
const char BIT_TOP          = 3;    // Fin de carrera Superior IN pin3
const char BIT_DIRECTION    = 4;    // Bobina del relay inversor OUT pin4
const char BIT_MOVE         = 5;    // Bobina del releay on/off OUT pin5
const char BIT_FAN          = 6;    // Ventilador sopla hojas OUT pin6

const char PLATE_STATE_ERROR    = 0; 
const char PLATE_STATE_UP       = 1;    
const char PLATE_STATE_DOWN     = 2;
const char PLATE_STATE_MIDDLE   = 3;

const char CYCLE_STATE_ERROR          = 0;
const char CYCLE_STATE_GOING_UP       = 1;
const char CYCLE_STATE_GOING_DOWN     = 2;
const char CYCLE_STATE_PAGE_FIX       = 3;
const char CYCLE_STATE_SCANNING       = 4;
const char CYCLE_STATE_PAGE_TURN      = 5;

// Setup del Arduino corre una sola vez al inicio
void setup( )
{
    pinMode(BIT_BOTTOM      , INPUT);   // Fin de carrera Inferior IN pin2
    pinMode(BIT_TOP         , INPUT);   // Fin de carrera Superior IN pin3
    pinMode(BIT_DIRECTION   , OUTPUT);  // Bobina del relay inversor OUT pin4
    pinMode(BIT_MOVE        , OUTPUT);  // Bobina del releay on/off OUT pin5
    pinMode(BIT_FAN         , OUTPUT);  // Ventilador sopla hojas OUT pin6

}

// Obtiene la posicion del plato
char check_plate_state()
{
    char bottom = digitalRead( BIT_BOTTOM );    // Estado del fin de carrera inferior pin2
    char top    = digitalRead( BIT_TOP );       // Estado del fin de carrera superior pin3
    char ret    = PLATE_STATE_ERROR;
    
    if (bottom && !top) 
    {
        ret = PLATE_STATE_DOWN;
    }
    else if (!bottom && top)
    {
        ret = PLATE_STATE_UP;
    }
    else if (!bottom && !top)
    {
        ret = PLATE_STATE_MIDDLE;
    }
    
    return ret;
}



void loop( )
{
    
}
