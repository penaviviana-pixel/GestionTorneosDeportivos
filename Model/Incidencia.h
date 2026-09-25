/**
 * Project Untitled
 */


#ifndef _INCIDENCIA_H
#define _INCIDENCIA_H

class Incidencia {
public: 
    
void registrar();
    
boolean evaluarSuspension();
private: 
    int idIncidencia;
    int minuto;
    String tipoIncidencia;
    String descripcion;
    boolean generaSuspension;
};

#endif //_INCIDENCIA_H