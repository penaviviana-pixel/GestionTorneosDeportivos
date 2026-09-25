/**
 * Project Untitled
 */


#ifndef _ESPECTADOR_H
#define _ESPECTADOR_H

#include "Usuario.h"


class Espectador: public Usuario {
public: 
    
/**
 * @param partido
 */
Pronostico realizarPronostico(Partido partido);
    
List<Pronostico> consultarHistorial();
    
void consultarRanking();
};

#endif //_ESPECTADOR_H