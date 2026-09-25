#pragma once

namespace GestionTorneosModel {
    using namespace System;
    ref class Equipo;
    public ref class Partido{
    private:
        int idPartido;
        DateTime fecha;
        DateTime hora;
        int marcadorLocal;
        int marcadorVisitante;
        String^ estadoPartido;

        Equipo^ equipoLocal;
        Equipo^ equipoVisitante;

    public:
        Partido();
        Partido(int idPartido, DateTime fecha,DateTime hora,Equipo^ equipoLocal,Equipo^ equipoVisitante);

        void registrarResultado(int local, int visitante);
        void actualizarEstado();
        Equipo^ obtenerGanador();
        void finalizarPartido();

        int getIdPartido();
        DateTime getFecha();
        DateTime getHora();
        int getMarcadorLocal();
        int getMarcadorVisitante();
        String^ getEstadoPartido();
        Equipo^ getEquipoLocal();
        Equipo^ getEquipoVisitante();

        void setIdPartido(int idPartido);
        void setFecha(DateTime fecha);
        void setHora(DateTime hora);
        void setEstadoPartido(String^ estadoPartido);
        void setEquipoLocal(Equipo^ equipoLocal);
        void setEquipoVisitante(Equipo^ equipoVisitante);
    };
}