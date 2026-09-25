#include "Torneo.h"

namespace GestionTorneosModel {
    Torneo::Torneo()
    {
        this->idTorneo = 0;
        this->nombreTorneo = String::Empty;
        this->fechaInicio = DateTime::Now;
        this->fechaFin = DateTime::Now;
        this->estado = "Planificado";
        this->formato = String::Empty;

        this->disciplinas = gcnew List<Disciplina^>();
        this->listaEquiposAprobados = gcnew List<Equipo^>();
    }

    Torneo::Torneo(
        int idTorneo,
        String^ nombreTorneo,
        DateTime fechaInicio,
        DateTime fechaFin,
        String^ estado,
        String^ formato
    )
    {
        if (fechaFin < fechaInicio){
            throw gcnew ArgumentException("La fecha final no puede ser anterior a la fecha inicial.");
        }

        this->idTorneo = idTorneo;
        this->nombreTorneo = nombreTorneo;
        this->fechaInicio = fechaInicio;
        this->fechaFin = fechaFin;
        this->estado = estado;
        this->formato = formato;

        this->disciplinas = gcnew List<Disciplina^>();
        this->listaEquiposAprobados = gcnew List<Equipo^>();
    }

    void Torneo::generarFixture()
    {
        if (this->listaEquiposAprobados->Count < 2)
        {
            Console::WriteLine("No se puede generar el fixture: faltan equipos aprobados.");
            return;
        }

        Console::WriteLine("El fixture del torneo {0} fue generado correctamente.", this->nombreTorneo);
    }

    void Torneo::actualizarTablaPosiciones()
    {
        Console::WriteLine("La tabla de posiciones del torneo {0} fue actualizada.", this->nombreTorneo);
    }

    void Torneo::agregarDisciplina(Disciplina^ disciplina)
    {
        if (disciplina != nullptr){
            this->disciplinas->Add(disciplina);
        }
    }

    List<Equipo^>^ Torneo::equiposAprobados(){
        return this->listaEquiposAprobados;
    }

    void Torneo::agregarEquipoAprobado(Equipo^ equipo){
        if (equipo != nullptr){
            this->listaEquiposAprobados->Add(equipo);
        }
    }

    void Torneo::exportarEstadisticas(String^ formatoExportacion){
        if (String::IsNullOrWhiteSpace(formatoExportacion)){
            Console::WriteLine("Debe indicar un formato de exportación.");
            return;
        }
        Console::WriteLine("Las estadísticas del torneo {0} se exportaron en formato {1}.",this->nombreTorneo,formatoExportacion);
    }

    
    int Torneo::getIdTorneo()
    {
        return this->idTorneo;
    }

    String^ Torneo::getNombreTorneo()
    {
        return this->nombreTorneo;
    }

    DateTime Torneo::getFechaInicio()
    {
        return this->fechaInicio;
    }

    DateTime Torneo::getFechaFin()
    {
        return this->fechaFin;
    }

    String^ Torneo::getEstado()
    {
        return this->estado;
    }

    String^ Torneo::getFormato()
    {
        return this->formato;
    }

    List<Disciplina^>^ Torneo::getDisciplinas()
    {
        return this->disciplinas;
    }

    void Torneo::setIdTorneo(int idTorneo)
    {
        this->idTorneo = idTorneo;
    }

    void Torneo::setNombreTorneo(String^ nombreTorneo)
    {
        this->nombreTorneo = nombreTorneo;
    }

    void Torneo::setFechaInicio(DateTime fechaInicio)
    {
        if (fechaInicio > this->fechaFin)
        {
            throw gcnew ArgumentException(
                "La fecha inicial no puede ser posterior a la fecha final."
            );
        }

        this->fechaInicio = fechaInicio;
    }

    void Torneo::setFechaFin(DateTime fechaFin)
    {
        if (fechaFin < this->fechaInicio)
        {
            throw gcnew ArgumentException(
                "La fecha final no puede ser anterior a la fecha inicial."
            );
        }

        this->fechaFin = fechaFin;
    }

    void Torneo::setEstado(String^ estado)
    {
        this->estado = estado;
    }

    void Torneo::setFormato(String^ formato)
    {
        this->formato = formato;
    }
}