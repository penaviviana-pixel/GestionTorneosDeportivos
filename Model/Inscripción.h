/**
 * Project Untitled
 */


#ifndef _INSCRIPCIÓN_H
#define _INSCRIPCIÓN_H

class Inscripción {
public: 
    
boolean validarRequisitos();
    
void aprobar();
    
/**
 * @param motivo
 */
void rechazar(String motivo);
    
boolean verificarPago();
    
boolean verificarSeguros();
private: 
    int idInscripcion;
    DateTime FechaRegistro;
    <List^>^ estadoInscripcion;
    String Observaciones;
};

#endif //_INSCRIPCIÓN_H