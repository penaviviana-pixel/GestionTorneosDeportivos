/**
 * Project Untitled
 */


#ifndef _EQUIPO_H
#define _EQUIPO_H

#include "MiembroEquipo.h"


class Equipo {
public: 
    int idEquipo;
    String NombreEquipo;
    String Facultad;
    MiembroEquipo 1    1..*;
    
/**
 * @param deportista
 */
void agregarJugadores(Deportista deportista);
    
/**
 * @param deportista
 */
void eliminarJugadores(Deportista deportista);
    
Deportista obtenerCapitan();
    
boolean validarCantidadJugadores();
};

#endif //_EQUIPO_H