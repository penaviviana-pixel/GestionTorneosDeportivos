#include "Partido.h"

namespace GestionTorneosModel {
    Partido::Partido(){
        this->idPartido = 0;
        this->fecha = DateTime::Now;
        this->hora = DateTime::Now;
        this->marcadorLocal = 0;
        this->marcadorVisitante = 0;
        this->estadoPartido = "Programado";
        this->equipoLocal = nullptr;
        this->equipoVisitante = nullptr;
    }

    Partido::Partido(
        int idPartido,
        DateTime fecha,
        DateTime hora,
        Equipo^ equipoLocal,
        Equipo^ equipoVisitante
    )
    {
        this->idPartido = idPartido;
        this->fecha = fecha;
        this->hora = hora;
        this->marcadorLocal = 0;
        this->marcadorVisitante = 0;
        this->estadoPartido = "Programado";
        this->equipoLocal = equipoLocal;
        this->equipoVisitante = equipoVisitante;
    }

    void Partido::registrarResultado(int local, int visitante)
    {
        if (local < 0 || visitante < 0)
        {
            throw gcnew ArgumentException("Los marcadores no pueden ser negativos.");
        }

        this->marcadorLocal = local;
        this->marcadorVisitante = visitante;
    }

    void Partido::actualizarEstado()
    {
        if (this->estadoPartido == "Finalizado")
        {
            return;
        }

        DateTime fechaHoraPartido =
            this->fecha.Date.Add(this->hora.TimeOfDay);

        if (DateTime::Now < fechaHoraPartido)
        {
            this->estadoPartido = "Programado";
        }
        else
        {
            this->estadoPartido = "En curso";
        }
    }

    Equipo^ Partido::obtenerGanador()
    {
        if (this->marcadorLocal > this->marcadorVisitante)
        {
            return this->equipoLocal;
        }

        if (this->marcadorVisitante > this->marcadorLocal)
        {
            return this->equipoVisitante;
        }
        return nullptr;
    }

    void Partido::finalizarPartido()
    {
        this->estadoPartido = "Finalizado";
    }

    int Partido::getIdPartido()
    {
        return this->idPartido;
    }

    DateTime Partido::getFecha()
    {
        return this->fecha;
    }

    DateTime Partido::getHora()
    {
        return this->hora;
    }

    int Partido::getMarcadorLocal()
    {
        return this->marcadorLocal;
    }

    int Partido::getMarcadorVisitante()
    {
        return this->marcadorVisitante;
    }

    String^ Partido::getEstadoPartido()
    {
        return this->estadoPartido;
    }

    Equipo^ Partido::getEquipoLocal()
    {
        return this->equipoLocal;
    }

    Equipo^ Partido::getEquipoVisitante()
    {
        return this->equipoVisitante;
    }

    void Partido::setIdPartido(int idPartido)
    {
        this->idPartido = idPartido;
    }

    void Partido::setFecha(DateTime fecha)
    {
        this->fecha = fecha;
    }

    void Partido::setHora(DateTime hora)
    {
        this->hora = hora;
    }

    void Partido::setEstadoPartido(String^ estadoPartido)
    {
        this->estadoPartido = estadoPartido;
    }

    void Partido::setEquipoLocal(Equipo^ equipoLocal)
    {
        this->equipoLocal = equipoLocal;
    }

    void Partido::setEquipoVisitante(Equipo^ equipoVisitante)
    {
        this->equipoVisitante = equipoVisitante;
    }
}