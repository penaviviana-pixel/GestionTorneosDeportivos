/**
 * Project Untitled
 */


#ifndef _ORGANIZADOR_H
#define _ORGANIZADOR_H

#include "Usuario.h"


class Organizador: public Usuario {
public: 
    
Torneo crearTorneo();
    
/**
 * @param inscripcion
 */
void aprobarInscripcion(Inscripcion inscripcion);
    
/**
 * @param torneo
 */
void generarFixture(Torneo torneo);
    
/**
 * @param partido
 * @param arbitro
 */
void asignarArbitro(Partido partido, Arbitro arbitro);
    
/**
 * @param partido
 */
void registrarResultados(Partido partido);
};

#endif //_ORGANIZADOR_H