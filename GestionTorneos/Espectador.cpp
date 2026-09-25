#include "Espectador.h"
#include "Partido.h"
#include "Pronostico.h"

namespace GestionTorneosModel {
    Espectador::Espectador() : Usuario() {}

    Espectador::Espectador(int id, String^ nombre, String^ codigo, bool seguroActivo,
        String^ correo, String^ facultad, String^ contrasena)
        : Usuario(id, nombre, codigo, seguroActivo, correo, facultad, contrasena) {
    }

    Pronostico^ Espectador::realizarPronostico(Partido^ partido) {
        return nullptr;
    }

    List<Pronostico^>^ Espectador::consultarHistorial() {
        return gcnew List<Pronostico^>();
    }

    void Espectador::consultarRanking() {
        // Lógica para mostrar ranking
    }
}
