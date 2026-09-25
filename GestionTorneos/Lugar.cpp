#include "Lugar.h"

namespace GestionTorneosModel {
    Lugar::Lugar() {
        this->idLugar = 0;
        this->nombreLugar = String::Empty;
        this->aforoMax = 0;
        this->ubicacion = String::Empty;
    }

    Lugar::Lugar(int idLugar, String^ nombreLugar, int aforoMax, String^ ubicacion) {
        this->idLugar = idLugar;
        this->nombreLugar = nombreLugar;
        this->aforoMax = aforoMax;
        this->ubicacion = ubicacion;
    }

    int Lugar::getidLugar() { return this->idLugar; }
    void Lugar::setidLugar(int value) { this->idLugar = value; }

    String^ Lugar::getubicacion() { return this->ubicacion; }
    void Lugar::setubicacion(String^ value) { this->ubicacion = value; }

    String^ Lugar::getnombreLugar() { return this->nombreLugar; }
    void Lugar::setnombreLugar(String^ nombreLugar) { this->nombreLugar = nombreLugar; }

    int Lugar::getaforoMax() { return this->aforoMax; }
    void Lugar::setaforoMax(int aforoMax) { this->aforoMax = aforoMax; }

    bool Lugar::estaDisponible(DateTime fechaHora) {
        return true;
    }
}