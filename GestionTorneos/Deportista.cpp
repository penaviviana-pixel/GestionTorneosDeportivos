#include "Deportista.h"
#include "Partido.h"
#include "EstadisticasJugador.h"

namespace GestionTorneosModel {
    Deportista::Deportista() : Usuario() {
        this->numeroCamiseta = 0;
    }

    Deportista::Deportista(int id, String^ nombre, String^ codigo, bool seguroActivo,
        String^ correo, String^ facultad, String^ contrasena, int numCamiseta)
        : Usuario(id, nombre, codigo, seguroActivo, correo, facultad, contrasena) {
        this->numeroCamiseta = numCamiseta;
    }

    int Deportista::getNumeroCamiseta() {
        return this->numeroCamiseta;
    }

    void Deportista::setNumeroCamiseta(int numeroCamiseta) {
        this->numeroCamiseta = numeroCamiseta;
    }

    List<Partido^>^ Deportista::consultarPartidos() {
        return gcnew List<Partido^>();
    }

    EstadisticasJugador^ Deportista::consultarEstadisticas() {
        return nullptr;
    }
}
