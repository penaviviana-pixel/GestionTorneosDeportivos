#include "Inscripcion.h"
#include "Pago.h"

namespace GestionTorneosModel {

    Inscripcion::Inscripcion() {
        this->estadoInscripcion = gcnew List<String^>();
        this->observaciones = "";
        this->objPago = nullptr;
    }

    Inscripcion::Inscripcion(int idInscripcion, DateTime fechaRegistro, List<String^>^ estadoInscripcion, String^ observaciones, Pago^ objPago) {
        this->idInscripcion = idInscripcion;
        this->fechaRegistro = fechaRegistro;
        this->estadoInscripcion = estadoInscripcion;
        this->observaciones = observaciones;
        this->objPago = objPago;
    }

    bool Inscripcion::validarRequisitos() {
        return true;
    }

    void Inscripcion::aprobar() {

    }

    void Inscripcion::rechazar(String^ motivo) {
        this->observaciones = motivo;
    }

    bool Inscripcion::verificarPago() {
        return (this->objPago != nullptr);
    }

    bool Inscripcion::verificarSeguros() {
        return true;
    }

    int Inscripcion::getIdInscripcion() {
        return this->idInscripcion;
    }

    void Inscripcion::setIdInscripcion(int idInscripcion) {
        this->idInscripcion = idInscripcion;
    }

    DateTime Inscripcion::getFechaRegistro() {
        return this->fechaRegistro;
    }

    void Inscripcion::setFechaRegistro(DateTime fechaRegistro) {
        this->fechaRegistro = fechaRegistro;
    }

    List<String^>^ Inscripcion::getEstadoInscripcion() {
        return this->estadoInscripcion;
    }

    void Inscripcion::setEstadoInscripcion(List<String^>^ estadoInscripcion) {
        this->estadoInscripcion = estadoInscripcion;
    }

    String^ Inscripcion::getObservaciones() {
        return this->observaciones;
    }

    void Inscripcion::setObservaciones(String^ observaciones) {
        this->observaciones = observaciones;
    }

    Pago^ Inscripcion::getObjPago() {
        return this->objPago;
    }

    void Inscripcion::setObjPago(Pago^ objPago) {
        this->objPago = objPago;
    }

}