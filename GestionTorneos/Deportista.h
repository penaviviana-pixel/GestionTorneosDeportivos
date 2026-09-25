#pragma once
#include "Usuario.h"

namespace GestionTorneosModel {
    using namespace System;
    using namespace System::Collections::Generic;

    ref class Partido;
    ref class EstadisticasJugador;

    public ref class Deportista : public Usuario {
    private:
        int numeroCamiseta;

    public:
        Deportista();
        Deportista(int id, String^ nombre, String^ codigo, bool seguroActivo,
            String^ correo, String^ facultad, String^ contrasena, int numCamiseta);

        int getNumeroCamiseta();
        void setNumeroCamiseta(int numeroCamiseta);

        List<Partido^>^ consultarPartidos();
        EstadisticasJugador^ consultarEstadisticas();
    };
}
