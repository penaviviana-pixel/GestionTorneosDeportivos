#pragma once
#include "Usuario.h"

namespace GestionTorneosModel {
    using namespace System;

    ref class Torneo;
    ref class Inscripcion;
    ref class Partido;
    ref class Arbitro;

    public ref class Organizador : public Usuario {
    public:
        Organizador();
        Organizador(int id, String^ nombre, String^ codigo, bool seguroActivo,
            String^ correo, String^ facultad, String^ contrasena);

        Torneo^ crearTorneo();
        void aprobarInscripcion(Inscripcion^ inscripcion);
        void generarFixture(Torneo^ torneo);
        void asignarArbitro(Partido^ partido, Arbitro^ arbitro);
        void registrarResultados(Partido^ partido);
    };
}
