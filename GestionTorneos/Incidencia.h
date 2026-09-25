#pragma once
namespace GestionTorneosModel {
    using namespace System;

    public ref class Incidencia{
    private:
        int idIncidencia;
        int minuto;
        String^ tipoIncidencia;
        String^ descripcion;
        bool generaSuspension;

    public:
        Incidencia();
        Incidencia(
            int idIncidencia,
            int minuto,
            String^ tipoIncidencia,
            String^ descripcion,
            bool generaSuspension
        );

        void registrar();
        bool evaluarSuspension();

        int getIdIncidencia();
        int getMinuto();
        String^ getTipoIncidencia();
        String^ getDescripcion();
        bool getGeneraSuspension();

        void setIdIncidencia(int idIncidencia);
        void setMinuto(int minuto);
        void setTipoIncidencia(String^ tipoIncidencia);
        void setDescripcion(String^ descripcion);
        void setGeneraSuspension(bool generaSuspension);
    };
}