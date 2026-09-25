#pragma once

namespace GestionTorneosModel {

    public ref class EstadisticasJugador {
    private:
        int idEstadisticas;
        int anotaciones;
        int faltas;
        int tarjetasAmarillas;
        int tarjetasRojas;
        int expulsiones;
        bool esMVP;

    public:
        EstadisticasJugador(int id);

        // Getters
        int getIdEstadisticas();
        int getAnotaciones();
        int getFaltas();
        int getTarjetasAmarillas();
        int getTarjetasRojas();
        int getExpulsiones();
        bool getEsMVP();

        // Setters
        void setIdEstadisticas(int id);
        void setAnotaciones(int anot);
        void setFaltas(int faltas);
        void setTarjetasAmarillas(int ta);
        void setTarjetasRojas(int tr);
        void setExpulsiones(int exp);
        void setEsMVP(bool mvp);

        // Métodos de negocio
        void contadorAnotaciones();
    };
}