/**
 * Project Untitled
 */


#ifndef _PRONÓSTICO_H
#define _PRONÓSTICO_H

class Pronóstico {
public: 
    
/**
 * @param partido
 */
void evaluarResultado(Partido partido);
    
int calcularGanancia();
    
void marcarGanado();
    
void marcarPerdido();
private: 
    int idPronostico;
    DateTime fechaRegistro;
    int puntosApostada;
    int marcadorLocalPronosticado;
    int marcadorVisitantePronosticado;
    <List^>^ estadoPronostico;
    int puntosGanados;
};

#endif //_PRONÓSTICO_H