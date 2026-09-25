/**
 * Project Untitled
 */


#ifndef _MIEMBROEQUIPO_H
#define _MIEMBROEQUIPO_H

class MiembroEquipo {
public: 
    
void designarCapitan();
    
void bloquearJugador();
    
boolean estadoDisponible();
private: 
    int idMiembro;
    <List^>^ estadoJugador;
    boolean esCapitan;
    int numeroCamiseta;
};

#endif //_MIEMBROEQUIPO_H