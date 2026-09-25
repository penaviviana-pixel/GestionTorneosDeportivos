#include "Incidencia.h"

namespace GestionTorneosModel {
    Incidencia::Incidencia()
    {
        this->idIncidencia = 0;
        this->minuto = 0;
        this->tipoIncidencia = String::Empty;
        this->descripcion = String::Empty;
        this->generaSuspension = false;
    }

    Incidencia::Incidencia(
        int idIncidencia,
        int minuto,
        String^ tipoIncidencia,
        String^ descripcion,
        bool generaSuspension
    )
    {
        if (minuto < 0){
            throw gcnew ArgumentException(
                "El minuto no puede ser negativo."
            );
        }

        this->idIncidencia = idIncidencia;
        this->minuto = minuto;
        this->tipoIncidencia = tipoIncidencia;
        this->descripcion = descripcion;
        this->generaSuspension = generaSuspension;
    }

    void Incidencia::registrar(){
        Console::WriteLine("Incidencia registrada correctamente.");
        Console::WriteLine("Minuto: {0} | Tipo: {1}", this->minuto, this->tipoIncidencia);
    }

    bool Incidencia::evaluarSuspension(){
        return this->generaSuspension;
    }

   
    int Incidencia::getIdIncidencia(){
        return this->idIncidencia;
    }

    int Incidencia::getMinuto(){
        return this->minuto;
    }

    String^ Incidencia::getTipoIncidencia(){
        return this->tipoIncidencia;
    }

    String^ Incidencia::getDescripcion(){
        return this->descripcion;
    }

    bool Incidencia::getGeneraSuspension(){
        return this->generaSuspension;
    }

    void Incidencia::setIdIncidencia(int idIncidencia){
        this->idIncidencia = idIncidencia;
    }

    void Incidencia::setMinuto(int minuto){
        if (minuto < 0){
            throw gcnew ArgumentException("El minuto no puede ser negativo.");
        }
        this->minuto = minuto;
    }

    void Incidencia::setTipoIncidencia(String^ tipoIncidencia){
        this->tipoIncidencia = tipoIncidencia;
    }

    void Incidencia::setDescripcion(String^ descripcion){
        this->descripcion = descripcion;
    }

    void Incidencia::setGeneraSuspension(bool generaSuspension){
        this->generaSuspension = generaSuspension;
    }
}