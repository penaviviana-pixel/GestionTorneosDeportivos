#include "Notificacion.h"

using namespace System;
using namespace GestionTorneosModel;

Notificacion::Notificacion(int id, String^ msg, String^ tipo) {
    this->idNotificacion = id;
    this->mensaje = msg;
    this->tipoNotificacion = tipo;
    this->leida = false;
    this->fechaHora = DateTime::Now;
}

int Notificacion::getIdNotificacion() { return this->idNotificacion; }
String^ Notificacion::getMensaje() { return this->mensaje; }
DateTime Notificacion::getFechaHora() { return this->fechaHora; }
bool Notificacion::getLeida() { return this->leida; }
String^ Notificacion::getTipoNotificacion() { return this->tipoNotificacion; }

void Notificacion::setIdNotificacion(int id) { this->idNotificacion = id; }
void Notificacion::setMensaje(String^ msg) { this->mensaje = msg; }
void Notificacion::setFechaHora(DateTime fecha) { this->fechaHora = fecha; }
void Notificacion::setLeida(bool estadoLeida) { this->leida = estadoLeida; }
void Notificacion::setTipoNotificacion(String^ tipo) { this->tipoNotificacion = tipo; }

void Notificacion::enviar() {
}

void Notificacion::marcarComoLeida() {
    this->leida = true;
}