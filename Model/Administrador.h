/**
 * Project Untitled
 */


#ifndef _ADMINISTRADOR_H
#define _ADMINISTRADOR_H

#include "Usuario.h"


class Administrador: public Usuario {
public: 
    
void registrarUsuario();
    
void asignarRol();
    
void administrarLugares();
};

#endif //_ADMINISTRADOR_H