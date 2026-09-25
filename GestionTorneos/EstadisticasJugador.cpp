#include "EstadisticasJugador.h"

using namespace GestionTorneosModel;

EstadisticasJugador::EstadisticasJugador(int id) {
    this->idEstadisticas = id;
    this->anotaciones = 0;
    this->faltas = 0;
    this->tarjetasAmarillas = 0;
    this->tarjetasRojas = 0;
    this->expulsiones = 0;
    this->esMVP = false;
}

int EstadisticasJugador::getIdEstadisticas() { return this->idEstadisticas; }
int EstadisticasJugador::getAnotaciones() { return this->anotaciones; }
int EstadisticasJugador::getFaltas() { return this->faltas; }
int EstadisticasJugador::getTarjetasAmarillas() { return this->tarjetasAmarillas; }
int EstadisticasJugador::getTarjetasRojas() { return this->tarjetasRojas; }
int EstadisticasJugador::getExpulsiones() { return this->expulsiones; }
bool EstadisticasJugador::getEsMVP() { return this->esMVP; }

void EstadisticasJugador::setIdEstadisticas(int id) { this->idEstadisticas = id; }
void EstadisticasJugador::setAnotaciones(int anot) { this->anotaciones = anot; }
void EstadisticasJugador::setFaltas(int faltas) { this->faltas = faltas; }
void EstadisticasJugador::setTarjetasAmarillas(int ta) { this->tarjetasAmarillas = ta; }
void EstadisticasJugador::setTarjetasRojas(int tr) { this->tarjetasRojas = tr; }
void EstadisticasJugador::setExpulsiones(int exp) { this->expulsiones = exp; }
void EstadisticasJugador::setEsMVP(bool mvp) { this->esMVP = mvp; }

void EstadisticasJugador::contadorAnotaciones() {
    this->anotaciones += 1;
}