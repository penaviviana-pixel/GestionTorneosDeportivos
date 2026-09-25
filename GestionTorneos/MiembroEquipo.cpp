#include "MiembroEquipo.h"

namespace GestionTorneosModel {
    MiembroEquipo::MiembroEquipo() {
        this->idMiembro = 0;
        this->estadoJugador = String::Empty;
        this->esCapitan = false;
        this->numeroCamiseta = 0;
    }

    MiembroEquipo::MiembroEquipo(int idMiembro, String^ estadoJugador, bool esCapitan, int numeroCamiseta) {
        this->idMiembro = idMiembro;
        this->estadoJugador = estadoJugador;
        this->esCapitan = esCapitan;
        this->numeroCamiseta = numeroCamiseta;
    }

    int MiembroEquipo::getIdMiembro() { return this->idMiembro; }
    void MiembroEquipo::setIdMiembro(int idMiembro) { this->idMiembro = idMiembro; }

    String^ MiembroEquipo::getEstadoJugador() { return this->estadoJugador; }
    void MiembroEquipo::setEstadoJugador(String^ estadoJugador) { this->estadoJugador = estadoJugador; }

    bool MiembroEquipo::getEsCapitan() { return this->esCapitan; }
    void MiembroEquipo::setEsCapitan(bool esCapitan) { this->esCapitan = esCapitan; }

    int MiembroEquipo::getNumeroCamiseta() { return this->numeroCamiseta; }
    void MiembroEquipo::setNumeroCamiseta(int numeroCamiseta) { this->numeroCamiseta = numeroCamiseta; }

    void MiembroEquipo::designarCapitan() {
        this->esCapitan = true;
    }

    void MiembroEquipo::bloquearJugador() {
        this->estadoJugador = "Bloqueado";
    }

    bool MiembroEquipo::estadoDisponible() {
        return this->estadoJugador == "Disponible";
    }
}
