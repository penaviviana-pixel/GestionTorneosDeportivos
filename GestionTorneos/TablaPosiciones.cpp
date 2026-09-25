#include "TablaPosiciones.h"
#include "Partido.h"

namespace GestionTorneosModel {
    TablaPosiciones::TablaPosiciones() {
        this->idTabla = 0;
        this->fechaActualizacion = String::Empty;
        this->filas = gcnew List<DetallePosicion^>();
    }

    TablaPosiciones::TablaPosiciones(int idTabla, String^ fechaActualizacion) {
        this->idTabla = idTabla;
        this->fechaActualizacion = fechaActualizacion;
        this->filas = gcnew List<DetallePosicion^>();
    }

    int TablaPosiciones::getIdTabla() { return this->idTabla; }
    void TablaPosiciones::setIdTabla(int idTabla) { this->idTabla = idTabla; }

    String^ TablaPosiciones::getFechaActualizacion() { return this->fechaActualizacion; }
    void TablaPosiciones::setFechaActualizacion(String^ fechaActualizacion) { this->fechaActualizacion = fechaActualizacion; }

    List<DetallePosicion^>^ TablaPosiciones::getFilas() { return this->filas; }
    void TablaPosiciones::setFilas(List<DetallePosicion^>^ filas) { this->filas = filas; }

    void TablaPosiciones::actualizar(Partido^ partido) {
        this->ordenarEquipos();
    }

    void TablaPosiciones::ordenarEquipos() {
        if (this->filas == nullptr || this->filas->Count < 2) return;
        for (int i = 0; i < this->filas->Count - 1; i++) {
            for (int j = 0; j < this->filas->Count - i - 1; j++) {
                DetallePosicion^ a = this->filas[j];
                DetallePosicion^ b = this->filas[j + 1];
                bool intercambiar = false;
                if (a->getPuntosTabla() < b->getPuntosTabla()) {
                    intercambiar = true;
                } else if (a->getPuntosTabla() == b->getPuntosTabla()) {
                    if (a->calcularDiferencia() < b->calcularDiferencia()) {
                        intercambiar = true;
                    }
                }
                if (intercambiar) {
                    this->filas[j] = b;
                    this->filas[j + 1] = a;
                }
            }
        }
    }

    List<DetallePosicion^>^ TablaPosiciones::consultarTabla() {
        return this->filas;
    }
}
