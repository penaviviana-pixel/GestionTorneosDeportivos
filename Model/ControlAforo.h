/**
 * Project Untitled
 */


#ifndef _CONTROLAFORO_H
#define _CONTROLAFORO_H

class ControlAforo {
public: 
    int aforoMax;
    
boolean registrarIngreso();
    
void registrarSalida();
    
boolean estaLleno();
    
int calcularDisponibilidad();
private: 
    int idControl;
    int cantidadActual;
};

#endif //_CONTROLAFORO_H