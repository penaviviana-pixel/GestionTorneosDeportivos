#include "Alineacion.h"
#include "Deportista.h" 

namespace GestionTorneosModel {

    Alineacion::Alineacion() {
        this->confirmada = false;
    }

    Alineacion::Alineacion(int idAlineacion, DateTime fechaModificacion, bool confirmada) {
        this->idAlineacion = idAlineacion;
        this->fechaModificacion = fechaModificacion;
        this->confirmada = confirmada;
    }


    bool Alineacion::agregarTitular(Deportista^ deportista) {

        return true;
    }

    void Alineacion::retirarTitular(Deportista^ deportista) {

    }

    bool Alineacion::validarHoraLimite() {

        return true;
    }

    void Alineacion::confirmar() {
        this->confirmada = true;
    }

    int Alineacion::getIdAlineacion() {
        return this->idAlineacion;
    }

    void Alineacion::setIdAlineacion(int idAlineacion) {
        this->idAlineacion = idAlineacion;
    }

    DateTime Alineacion::getFechaModificacion() {
        return this->fechaModificacion;
    }

    void Alineacion::setFechaModificacion(DateTime fechaModificacion) {
        this->fechaModificacion = fechaModificacion;
    }

    bool Alineacion::getConfirmada() {
        return this->confirmada;
    }

    void Alineacion::setConfirmada(bool confirmada) {
        this->confirmada = confirmada;
    }

}