/**
 * Project Untitled
 */


#ifndef _NOTIFICACION_H
#define _NOTIFICACION_H

class Notificacion {
public: 
    
void enviar();
    
void marcarComoLeida();
private: 
    int idNotificacion;
    String mensaje;
    DateTime fechaHora;
    boolean leida;
    <List^>^ tipoNotificacion;
};

#endif //_NOTIFICACION_H