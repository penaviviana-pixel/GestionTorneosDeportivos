#include "Equipo.h"
#include "Deportista.h"

namespace GestionTorneosModel {
    Equipo::Equipo() {
        this->idEquipo = 0;
        this->nombreEquipo = String::Empty;
        this->facultad = String::Empty;
        this->jugadores = gcnew List<Deportista^>();
    }

    Equipo::Equipo(int idEquipo, String^ nombreEquipo, String^ facultad) {
        this->idEquipo = idEquipo;
        this->nombreEquipo = nombreEquipo;
        this->facultad = facultad;
        this->jugadores = gcnew List<Deportista^>();
    }

    int Equipo::getIdEquipo() { return this->idEquipo; }
    void Equipo::setIdEquipo(int idEquipo) { this->idEquipo = idEquipo; }

    String^ Equipo::getNombreEquipo() { return this->nombreEquipo; }
    void Equipo::setNombreEquipo(String^ nombreEquipo) { this->nombreEquipo = nombreEquipo; }

    String^ Equipo::getFacultad() { return this->facultad; }
    void Equipo::setFacultad(String^ facultad) { this->facultad = facultad; }

    List<Deportista^>^ Equipo::getJugadores() { return this->jugadores; }
    void Equipo::setJugadores(List<Deportista^>^ jugadores) { this->jugadores = jugadores; }

    void Equipo::agregarJugadores(Deportista^ deportista) {
        if (deportista != nullptr) {
            this->jugadores->Add(deportista);
        }
    }

    void Equipo::eliminarJugadores(Deportista^ deportista) {
        if (deportista != nullptr) {
            this->jugadores->Remove(deportista);
        }
    }

    Deportista^ Equipo::obtenerCapitan() {
        if (this->jugadores != nullptr && this->jugadores->Count > 0) {
            return this->jugadores[0];
        }
        return nullptr;
    }

    bool Equipo::validarCantidadJugadores() {
        return (this->jugadores != nullptr && this->jugadores->Count >= 5);
    }
}
