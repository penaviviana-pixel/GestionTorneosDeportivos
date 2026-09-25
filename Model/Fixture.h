/**
 * Project Untitled
 */


#ifndef _FIXTURE_H
#define _FIXTURE_H

class Fixture {
public: 
    
/**
 * @param equipos
 */
void generarPartidos(List<Equipos> equipos);
    
void reprogramarPartido();
    
List<Partido> consultarPartidos();
private: 
    int idFixture;
    DateTime Fecha;
    FormatoTorneo formato;
};

#endif //_FIXTURE_H