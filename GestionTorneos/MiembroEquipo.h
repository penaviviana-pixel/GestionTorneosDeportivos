#pragma once

namespace GestionTorneosModel {
    using namespace System;

    public ref class MiembroEquipo {
    private:
        int idMiembro;
        String^ estadoJugador;
        bool esCapitan;
        int numeroCamiseta;

    public:
        MiembroEquipo();
        MiembroEquipo(int idMiembro, String^ estadoJugador, bool esCapitan, int numeroCamiseta);

        int getIdMiembro();
        void setIdMiembro(int idMiembro);

        String^ getEstadoJugador();
        void setEstadoJugador(String^ estadoJugador);

        bool getEsCapitan();
        void setEsCapitan(bool esCapitan);

        int getNumeroCamiseta();
        void setNumeroCamiseta(int numeroCamiseta);

        void designarCapitan();
        void bloquearJugador();
        bool estadoDisponible();
    };
}
