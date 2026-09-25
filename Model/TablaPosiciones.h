/**
 * Project Untitled
 */


#ifndef _TABLAPOSICIONES_H
#define _TABLAPOSICIONES_H

class TablaPosiciones {
public: 
    
/**
 * @param partido
 */
void actualizar(Partido partido);
    
void ordenarEquipos();
    
List<DetallePosicion> consultarTabla();
private: 
    int idTabla;
    DateTime fechaActualización;
};

#endif //_TABLAPOSICIONES_H