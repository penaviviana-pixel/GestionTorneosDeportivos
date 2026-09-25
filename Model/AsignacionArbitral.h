/**
 * Project Untitled
 */


#ifndef _ASIGNACIONARBITRAL_H
#define _ASIGNACIONARBITRAL_H

class AsignacionArbitral {
public: 
    
void confirmarAsignacion();
    
void cancelarAsignacion();
private: 
    int idAsignacion;
    DateTime fechaAsignacion;
    String rolArbitral;
    String estado;
};

#endif //_ASIGNACIONARBITRAL_H