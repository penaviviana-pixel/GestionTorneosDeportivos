#include "Pago.h"

using namespace System;
using namespace GestionTorneosModel;

Pago::Pago(int id, double monto, String^ codigo) {
    this->idPago = id;
    this->monto = monto;
    this->codigoOperacion = codigo;
    this->estado = "Pendiente";
    this->fechaPago = DateTime::Now;
}

int Pago::getIdPago() { return this->idPago; }
double Pago::getMonto() { return this->monto; }
DateTime Pago::getFechaPago() { return this->fechaPago; }
String^ Pago::getEstado() { return this->estado; }
String^ Pago::getCodigoOperacion() { return this->codigoOperacion; }

void Pago::setIdPago(int id) { this->idPago = id; }
void Pago::setMonto(double m) { this->monto = m; }
void Pago::setFechaPago(DateTime fecha) { this->fechaPago = fecha; }
void Pago::setEstado(String^ est) { this->estado = est; }
void Pago::setCodigoOperacion(String^ codigo) { this->codigoOperacion = codigo; }

void Pago::registrarPago() {
    this->estado = "Registrado";
}

bool Pago::validarPago() {
    if (this->monto > 0 && !String::IsNullOrEmpty(this->codigoOperacion)) {
        this->estado = "Pagado";
        return true;
    }
    return false;
}