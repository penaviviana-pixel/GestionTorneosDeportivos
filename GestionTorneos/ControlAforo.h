#pragma once

namespace GestionTorneosModel {
    public ref class ControlAforo {
    private:
        int idControl;
        int cantidadActual;
        int aforoMax;

    public:
        ControlAforo();
        ControlAforo(int idControl, int cantidadActual, int aforoMax);

        int getIdControl();
        void setIdControl(int idControl);

        int getCantidadActual();
        void setCantidadActual(int cantidadActual);

        int getAforoMax();
        void setAforoMax(int aforoMax);

        bool registrarIngreso();
        void registrarSalida();
        bool estaLleno();
        int calcularDisponibilidad();
    };
}
