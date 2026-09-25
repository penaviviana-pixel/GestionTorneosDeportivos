/**
 * Project Untitled
 */


#ifndef _DEPORTISTA_H
#define _DEPORTISTA_H

#include "Usuario.h"
#include "MiembroEquipo.h"


class Deportista: public Usuario {
public: 
    MiembroEquipo 1   0..*;
    
List<Partido> consultarPartidos();
    
EstadisticaJugador consultarEstadisticas();
private: 
    int numeroCamiseta;
};

#endif //_DEPORTISTA_H