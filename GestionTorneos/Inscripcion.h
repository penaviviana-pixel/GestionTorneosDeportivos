#pragma once

namespace GestionTorneosModel {
    using namespace System;
    using namespace System::Collections::Generic;

    // -------
    ref class Pago;
    public ref class Inscripcion {
    private:
        int idInscripcion;
        DateTime fechaRegistro;
        List<String^>^ estadoInscripcion;
        String^ observaciones;
        Pago^ objPago;

    public:
        // -----
        Inscripcion();
        Inscripcion(int idInscripcion, DateTime fechaRegistro, List<String^>^ estadoInscripcion, String^ observaciones, Pago^ objPago);

        bool validarRequisitos();
        void aprobar();
        void rechazar(String^ motivo);
        bool verificarPago();
        bool verificarSeguros();

        int getIdInscripcion();
        void setIdInscripcion(int idInscripcion);

        DateTime getFechaRegistro();
        void setFechaRegistro(DateTime fechaRegistro);

        List<String^>^ getEstadoInscripcion();
        void setEstadoInscripcion(List<String^>^ estadoInscripcion);

        String^ getObservaciones();
        void setObservaciones(String^ observaciones);

        Pago^ getObjPago();
        void setObjPago(Pago^ objPago);
    };

}