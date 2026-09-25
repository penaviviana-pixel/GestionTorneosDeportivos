#pragma once
#include "Usuario.h"

namespace GestionTorneosModel {
    using namespace System;
    using namespace System::Collections::Generic;

    ref class Partido;
    ref class Pronostico;

    public ref class Espectador : public Usuario {
    public:
        Espectador();
        Espectador(int id, String^ nombre, String^ codigo, bool seguroActivo,
            String^ correo, String^ facultad, String^ contrasena);

        Pronostico^ realizarPronostico(Partido^ partido);
        List<Pronostico^>^ consultarHistorial();
        void consultarRanking();
    };
}
