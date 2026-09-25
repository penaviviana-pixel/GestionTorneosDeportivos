/**
 * Project Untitled
 */


#ifndef _ALINEACION_H
#define _ALINEACION_H

class Alineacion {
public: 
    
/**
 * @param deportista
 */
boolean agregarTitular(Deportista deportista);
    
/**
 * @param deportista
 */
void retirarTitular(Deportista deportista);
    
boolean validarHoraLimite();
    
void confirmar();
private: 
    int idAlineacion;
    DateTime fechaModificacion;
    boolean confirmada;
};

#endif //_ALINEACION_H