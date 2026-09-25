#include "Pronostico.h"
#include "Partido.h"

namespace GestionTorneosModel {
    Pronostico::Pronostico() {
        this->idPronostico = 0;
        this->fechaRegistro = DateTime::Now;
        this->puntosApostada = 0;
        this->marcadorLocalPronosticado = 0;
        this->marcadorVisitantePronosticado = 0;
        this->puntosGanados = 0;
        this->estadoPronostico = gcnew List<String^>();
        this->estadoPronostico->Add("Pendiente");
    }

    Pronostico::Pronostico(int idPronostico, DateTime fechaRegistro, int puntosApostada, int marcadorLocalPronosticado, int marcadorVisitantePronosticado, List<String^>^ estadoPronostico, int puntosGanados) {
        this->idPronostico = idPronostico;
        this->fechaRegistro = fechaRegistro;
        this->puntosApostada = puntosApostada;
        this->marcadorLocalPronosticado = marcadorLocalPronosticado;
        this->marcadorVisitantePronosticado = marcadorVisitantePronosticado;
        this->estadoPronostico = estadoPronostico;
        this->puntosGanados = puntosGanados;
    }

    int Pronostico::getIdPronostico() {
        return this->idPronostico;
    }

    void Pronostico::setIdPronostico(int idPronostico) {
        this->idPronostico = idPronostico;
    }

    DateTime Pronostico::getFechaRegistro() {
        return this->fechaRegistro;
    }

    void Pronostico::setFechaRegistro(DateTime fechaRegistro) {
        this->fechaRegistro = fechaRegistro;
    }

    int Pronostico::getPuntosApostada() {
        return this->puntosApostada;
    }

    void Pronostico::setPuntosApostada(int puntosApostada) {
        this->puntosApostada = puntosApostada;
    }

    int Pronostico::getMarcadorLocalPronosticado() {
        return this->marcadorLocalPronosticado;
    }

    void Pronostico::setMarcadorLocalPronosticado(int marcadorLocalPronosticado) {
        this->marcadorLocalPronosticado = marcadorLocalPronosticado;
    }

    int Pronostico::getMarcadorVisitantePronosticado() {
        return this->marcadorVisitantePronosticado;
    }

    void Pronostico::setMarcadorVisitantePronosticado(int marcadorVisitantePronosticado) {
        this->marcadorVisitantePronosticado = marcadorVisitantePronosticado;
    }

    List<String^>^ Pronostico::getEstadoPronostico() {
        return this->estadoPronostico;
    }

    void Pronostico::setEstadoPronostico(List<String^>^ estadoPronostico) {
        this->estadoPronostico = estadoPronostico;
    }

    int Pronostico::getPuntosGanados() {
        return this->puntosGanados;
    }

    void Pronostico::setPuntosGanados(int puntosGanados) {
        this->puntosGanados = puntosGanados;
    }

    void Pronostico::evaluarResultado(Partido^ partido) {
        if (partido != nullptr && partido->getEstadoPartido() == "Finalizado") {
            if (partido->getMarcadorLocal() == this->marcadorLocalPronosticado &&
                partido->getMarcadorVisitante() == this->marcadorVisitantePronosticado) {
                marcarGanado();
            } else {
                marcarPerdido();
            }
        }
    }

    int Pronostico::calcularGanancia() {
        return this->puntosGanados;
    }

    void Pronostico::marcarGanado() {
        this->puntosGanados = this->puntosApostada * 3;
        if (this->estadoPronostico == nullptr) {
            this->estadoPronostico = gcnew List<String^>();
        }
        this->estadoPronostico->Clear();
        this->estadoPronostico->Add("Ganado");
    }

    void Pronostico::marcarPerdido() {
        this->puntosGanados = 0;
        if (this->estadoPronostico == nullptr) {
            this->estadoPronostico = gcnew List<String^>();
        }
        this->estadoPronostico->Clear();
        this->estadoPronostico->Add("Perdido");
    }
}