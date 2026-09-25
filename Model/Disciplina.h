/**
 * Project Untitled
 */


#ifndef _DISCIPLINA_H
#define _DISCIPLINA_H

#include "Torneo.h"


class Disciplina {
public: 
    Torneo 1  0..*;
    
/**
 * @param cantidad
 */
boolean validarCantidadJugadores(int cantidad);
private: 
    int idDisciplina;
    String NombreDisciplina;
    boolean esColectivo;
    int MinJugadores;
    int MaxJugadores;
};

#endif //_DISCIPLINA_H