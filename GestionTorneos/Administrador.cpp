#include "Administrador.h"

namespace GestionTorneosModel {
    Administrador::Administrador()
        : Usuario()
    {
    }

    Administrador::Administrador(
        int idUsuario,
        String^ nombre,
        String^ codigo,
        bool seguroActivo,
        String^ correo,
        String^ facultad,
        String^ contrasena
    )
        : Usuario(
            idUsuario,
            nombre,
            codigo,
            seguroActivo,
            correo,
            facultad,
            contrasena
        )
    {
    }

    void Administrador::registrarUsuario(){
        Console::WriteLine("El administrador está registrando un nuevo usuario.");
    }

    void Administrador::asignarRol(){
        Console::WriteLine("El administrador está asignando un rol.");
    }

    void Administrador::administrarLugares(){
        Console::WriteLine("El administrador está gestionando los lugares deportivos.");
    }
}