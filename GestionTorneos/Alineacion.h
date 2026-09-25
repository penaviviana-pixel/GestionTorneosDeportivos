#pragma once

namespace GestionTorneosModel {
    using namespace System;

    ref class Deportista;

    public ref class Alineacion {
    private:
        int idAlineacion;
        DateTime fechaModificacion;
        bool confirmada;

    public:
        Alineacion();
        Alineacion(int idAlineacion, DateTime fechaModificacion, bool confirmada);

        bool agregarTitular(Deportista^ deportista);
        void retirarTitular(Deportista^ deportista);
        bool validarHoraLimite();
        void confirmar();

        int getIdAlineacion();
        void setIdAlineacion(int idAlineacion);

        DateTime getFechaModificacion();
        void setFechaModificacion(DateTime fechaModificacion);

        bool getConfirmada();
        void setConfirmada(bool confirmada);
    };

}