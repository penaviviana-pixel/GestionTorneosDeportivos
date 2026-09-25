#pragma once
#include "Usuario.h"

namespace GestionTorneosModel {
    using namespace System;
    public ref class Administrador : public Usuario
    {
    public:
        Administrador();
        Administrador(
            int idUsuario,
            String^ nombre,
            String^ codigo,
            bool seguroActivo,
            String^ correo,
            String^ facultad,
            String^ contrasena
        );

        void registrarUsuario();
        void asignarRol();
        void administrarLugares();
    };
}