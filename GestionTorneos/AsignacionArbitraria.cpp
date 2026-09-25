#include "AsignacionArbitral.h"

namespace GestionTorneosModel {
    AsignacionArbitral::AsignacionArbitral() {
    }

    AsignacionArbitral::AsignacionArbitral(int idAsignacion, DateTime fechaAsignacion, String^ rolArbitral, String^ estado) {
        this->idAsignacion = idAsignacion;
        this->fechaAsignacion = fechaAsignacion;
        this->rolArbitral = rolArbitral;
        this->estado = estado;
    }

    void AsignacionArbitral::confirmarAsignacion() {
    }

    void AsignacionArbitral::cancelarAsignacion() {
    }

    int AsignacionArbitral::getIdAsignacion() {
        return this->idAsignacion;
    }

    void AsignacionArbitral::setIdAsignacion(int idAsignacion) {
        this->idAsignacion = idAsignacion;
    }

    DateTime AsignacionArbitral::getFechaAsignacion() {
        return this->fechaAsignacion;
    }

    void AsignacionArbitral::setFechaAsignacion(DateTime fechaAsignacion) {
        this->fechaAsignacion = fechaAsignacion;
    }

    String^ AsignacionArbitral::getRolArbitral() {
        return this->rolArbitral;
    }

    void AsignacionArbitral::setRolArbitral(String^ rolArbitral) {
        this->rolArbitral = rolArbitral;
    }

    String^ AsignacionArbitral::getEstado() {
        return this->estado;
    }

    void AsignacionArbitral::setEstado(String^ estado) {
        this->estado = estado;
    }
}