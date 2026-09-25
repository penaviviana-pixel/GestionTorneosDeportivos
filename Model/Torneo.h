/**
 * Project Untitled
 */


#ifndef _TORNEO_H
#define _TORNEO_H

class Torneo {
public: 
    
void generarFixture();
    
void actualizarTablaPosiciones();
    
void agregarDisciplina();
    
List<Equipo> equiposAprobados();
    
/**
 * @param formato
 */
void exportarEstadísticas(String formato);
private: 
    int idTorneo;
    String NombreTorneo;
    DateTime FechaInicio;
    DateTime FechaFin;
    String Estado;
    void Formato;
};

#endif //_TORNEO_H