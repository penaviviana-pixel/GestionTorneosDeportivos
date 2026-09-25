#include "ControlAforo.h"

namespace GestionTorneosModel {
    ControlAforo::ControlAforo() {
        this->idControl = 0;
        this->cantidadActual = 0;
        this->aforoMax = 0;
    }

    ControlAforo::ControlAforo(int idControl, int cantidadActual, int aforoMax) {
        this->idControl = idControl;
        this->cantidadActual = cantidadActual;
        this->aforoMax = aforoMax;
    }

    int ControlAforo::getIdControl() { return this->idControl; }
    void ControlAforo::setIdControl(int idControl) { this->idControl = idControl; }

    int ControlAforo::getCantidadActual() { return this->cantidadActual; }
    void ControlAforo::setCantidadActual(int cantidadActual) { this->cantidadActual = cantidadActual; }

    int ControlAforo::getAforoMax() { return this->aforoMax; }
    void ControlAforo::setAforoMax(int aforoMax) { this->aforoMax = aforoMax; }

    bool ControlAforo::registrarIngreso() {
        if (!estaLleno()) {
            this->cantidadActual++;
            return true;
        }
        return false;
    }

    void ControlAforo::registrarSalida() {
        if (this->cantidadActual > 0) {
            this->cantidadActual--;
        }
    }

    bool ControlAforo::estaLleno() {
        return this->cantidadActual >= this->aforoMax;
    }

    int ControlAforo::calcularDisponibilidad() {
        return this->aforoMax - this->cantidadActual;
    }
}
