#pragma once

namespace GestionTorneosModel {
    using namespace System;

    public ref class Notificacion {
    private:
        int idNotificacion;
        String^ mensaje;
        DateTime fechaHora;
        bool leida;
        String^ tipoNotificacion;

    public:
        Notificacion(int id, String^ msg, String^ tipo);

        // Getters
        int getIdNotificacion();
        String^ getMensaje();
        DateTime getFechaHora();
        bool getLeida();
        String^ getTipoNotificacion();

        // Setters
        void setIdNotificacion(int id);
        void setMensaje(String^ msg);
        void setFechaHora(DateTime fecha);
        void setLeida(bool estadoLeida);
        void setTipoNotificacion(String^ tipo);

        // Métodos de negocio
        void enviar();
        void marcarComoLeida();
    };
}