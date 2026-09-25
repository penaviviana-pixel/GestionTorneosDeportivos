/**
 * Project Untitled
 */


#ifndef _PARTIDO_H
#define _PARTIDO_H

class Partido {
public: 
    
/**
 * @param local
 * @param visitante
 */
void registrarResultado(int local, int visitante);
    
void actualizarEstado();
    
Equipo obtenerGanador();
    
void finalizarPartido();
private: 
    int idPartido;
    DateTime Fecha;
    DateTime Hora;
    int marcadorLocal;
    <List^>^ estadoPartido;
    int marcadorVisitante;
};

#endif //_PARTIDO_H