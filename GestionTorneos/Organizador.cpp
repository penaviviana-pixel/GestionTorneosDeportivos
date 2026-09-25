#include "Organizador.h"
#include "Torneo.h"
#include "Inscripcion.h"
#include "Partido.h"
#include "Arbitro.h"

namespace GestionTorneosModel {
    Organizador::Organizador() : Usuario() {}

    Organizador::Organizador(int id, String^ nombre, String^ codigo, bool seguroActivo,
        String^ correo, String^ facultad, String^ contrasena)
        : Usuario(id, nombre, codigo, seguroActivo, correo, facultad, contrasena) {
    }

    Torneo^ Organizador::crearTorneo() {
        return nullptr;
    }

    void Organizador::aprobarInscripcion(Inscripcion^ inscripcion) {}

    void Organizador::generarFixture(Torneo^ torneo) {}

    void Organizador::asignarArbitro(Partido^ partido, Arbitro^ arbitro) {}

    void Organizador::registrarResultados(Partido^ partido) {}
}
