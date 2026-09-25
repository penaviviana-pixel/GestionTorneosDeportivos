#include "DetallePosicion.h"

namespace GestionTorneosModel {

    DetallePosicion::DetallePosicion() {
    }

    DetallePosicion::DetallePosicion(int partidosJugados, int partidosGanados, int partidosEmpatados, int partidosPerdidos, int puntosFavor, int puntosContra, int puntosTabla) {
        this->partidosJugados = partidosJugados;
        this->partidosGanados = partidosGanados;
        this->partidosEmpatados = partidosEmpatados;
        this->partidosPerdidos = partidosPerdidos;
        this->puntosFavor = puntosFavor;
        this->puntosContra = puntosContra;
        this->puntosTabla = puntosTabla;
    }

    int DetallePosicion::calcularDiferencia() {
        return this->puntosFavor - this->puntosContra;
    }

    int DetallePosicion::calcularPuntaje() {
        //3 puntos por ganar, 1 por empatar
        this->puntosTabla = (this->partidosGanados * 3) + (this->partidosEmpatados * 1);
        return this->puntosTabla;
    }

    int DetallePosicion::getPartidosJugados() {
        return this->partidosJugados;
    }

    void DetallePosicion::setPartidosJugados(int partidosJugados) {
        this->partidosJugados = partidosJugados;
    }

    int DetallePosicion::getPartidosGanados() {
        return this->partidosGanados;
    }

    void DetallePosicion::setPartidosGanados(int partidosGanados) {
        this->partidosGanados = partidosGanados;
    }

    int DetallePosicion::getPartidosEmpatados() {
        return this->partidosEmpatados;
    }

    void DetallePosicion::setPartidosEmpatados(int partidosEmpatados) {
        this->partidosEmpatados = partidosEmpatados;
    }

    int DetallePosicion::getPartidosPerdidos() {
        return this->partidosPerdidos;
    }

    void DetallePosicion::setPartidosPerdidos(int partidosPerdidos) {
        this->partidosPerdidos = partidosPerdidos;
    }

    int DetallePosicion::getPuntosFavor() {
        return this->puntosFavor;
    }

    void DetallePosicion::setPuntosFavor(int puntosFavor) {
        this->puntosFavor = puntosFavor;
    }

    int DetallePosicion::getPuntosContra() {
        return this->puntosContra;
    }

    void DetallePosicion::setPuntosContra(int puntosContra) {
        this->puntosContra = puntosContra;
    }

    int DetallePosicion::getPuntosTabla() {
        return this->puntosTabla;
    }

    void DetallePosicion::setPuntosTabla(int puntosTabla) {
        this->puntosTabla = puntosTabla;
    }

}