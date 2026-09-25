/**
 * Project Untitled
 */


#ifndef _LUGAR_H
#define _LUGAR_H

#include "Partido.h"


class Lugar {
public: 
    Partido 1  0..*;
    
/**
 * @param fechaHora
 */
boolean estaDisponible(DateTime fechaHora);
private: 
    int idLugar;
    String NombreLugar;
    int AforoMax;
    String ubicacion;
};

#endif //_LUGAR_H