#include "Usuario.h"

namespace GestionTorneosModel {
    Usuario::Usuario()
    {
        this->idUsuario = 0;
        this->nombre = String::Empty;
        this->codigo = String::Empty;
        this->seguroActivo = false;
        this->correoElectronico = String::Empty;
        this->facultad = String::Empty;
        this->contrasena = String::Empty;
    }

    Usuario::Usuario(int idUsuario, String^ nombre, String^ codigo, bool seguroActivo, String^ correo, String^ facultad, String^ password)
    {
        this->idUsuario = idUsuario;
        this->nombre = nombre;
        this->codigo = codigo;
        this->seguroActivo = seguroActivo;
        this->correoElectronico = correo;
        this->facultad = facultad;
        this->contrasena = password;
    }

    Usuario::Usuario(int idUsuario, String^ nombre, String^ codigo, bool seguroActivo, String^ correo, String^ facultad, String^ password)
    {
        this->idUsuario = idUsuario;
        this->nombre = nombre;
        this->codigo = codigo;
        this->seguroActivo = seguroActivo;
        this->correoElectronico = correo;
        this->facultad = facultad;
        this->contrasena = password;
    }

    bool Usuario::validarSeguro()
    {
        return this->seguroActivo;
    }

    bool Usuario::autenticar(String^ correoIngresado, String^ contrasenaIngresada) {
        bool correoCorrecto = String::Equals(
            this->correoElectronico,
            correoIngresado,
            StringComparison::OrdinalIgnoreCase
        );

        bool contrasenaCorrecta = String::Equals(
            this->contrasena,
            contrasenaIngresada
        );

        return correoCorrecto && contrasenaCorrecta;
    }

    void Usuario::actualizarDatos(String^ nuevoNombre, String^ nuevoCorreo, String^ nuevaFacultad, bool nuevoSeguroActivo) {
        this->nombre = nuevoNombre;
        this->correoElectronico = nuevoCorreo;
        this->facultad = nuevaFacultad;
        this->seguroActivo = nuevoSeguroActivo;
    }

    int Usuario::getIdUsuario()
    {
        return this->idUsuario;
    }

    void Usuario::setIdUsuario(int idUsuario)
    {
        this->idUsuario = idUsuario;
    }

    String^ Usuario::getNombre()
    {
        return this->nombre;
    }

    void Usuario::setNombre(String^ nombre)
    {
        this->nombre = nombre;
    }

    String^ Usuario::getCodigo()
    {
        return this->codigo;
    }

    void Usuario::setCodigo(String^ codigo)
    {
        this->codigo = codigo;
    }

    int Usuario::getCódigo()
    {
        int res = 0;
        Int32::TryParse(this->codigo, res);
        return res;
    }

    void Usuario::setCódigo(int codigo)
    {
        this->codigo = codigo.ToString();
    }

    bool Usuario::getSeguroActivo()
    {
        return this->seguroActivo;
    }

    void Usuario::setSeguroActivo(bool seguroActivo)
    {
        this->seguroActivo = seguroActivo;
    }

    String^ Usuario::getCorreoElectronico()
    {
        return this->correoElectronico;
    }

    void Usuario::setCorreoElectronico(String^ correo)
    {
        this->correoElectronico = correo;
    }

    String^ Usuario::getFacultad()
    {
        return this->facultad;
    }

    void Usuario::setFacultad(String^ facultad)
    {
        this->facultad = facultad;
    }

    String^ Usuario::getContrasena()
    {
        return this->contrasena;
    }

    void Usuario::setContrasena(String^ contrasena)
    {
        this->contrasena = contrasena;
    }

    String^ Usuario::getContraseña()
    {
        return this->contrasena;
    }

    void Usuario::setContraseña(String^ contrasena)
    {
        this->contrasena = contrasena;
    }
}