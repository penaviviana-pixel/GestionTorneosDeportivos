/**
 * Project Untitled
 */


#ifndef _DETALLEPOSICION_H
#define _DETALLEPOSICION_H

class DetallePosicion {
public: 
    int partidosJugados;
    int partidosGanados;
    int partidosEmpatados;
    int partidosPerdidos;
    int puntosFavor;
    int puntosContra;
    int puntosTabla;
    
int calcularDiferencia();
    
int calcularPuntaje();
};

#endif //_DETALLEPOSICION_H