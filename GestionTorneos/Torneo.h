#pragma once

namespace GestionTorneosModel{
    using namespace System;
    using namespace System::Collections::Generic;

    ref class Equipo;
    ref class Disciplina;

    public ref class Torneo{
    private:
        int idTorneo;
        String^ nombreTorneo;
        DateTime fechaInicio;
        DateTime fechaFin;
        String^ estado;
        String^ formato;

        List<Disciplina^>^ disciplinas;
        List<Equipo^>^ listaEquiposAprobados;

    public:
        Torneo();
        Torneo(
            int idTorneo,
            String^ nombreTorneo,
            DateTime fechaInicio,
            DateTime fechaFin,
            String^ estado,
            String^ formato
        );

        void generarFixture();
        void actualizarTablaPosiciones();
        void agregarDisciplina(Disciplina^ disciplina);
        List<Equipo^>^ equiposAprobados();
        void exportarEstadisticas(String^ formatoExportacion);

        void agregarEquipoAprobado(Equipo^ equipo);

        int getIdTorneo();
        String^ getNombreTorneo();
        DateTime getFechaInicio();
        DateTime getFechaFin();
        String^ getEstado();
        String^ getFormato();
        List<Disciplina^>^ getDisciplinas();

        void setIdTorneo(int idTorneo);
        void setNombreTorneo(String^ nombreTorneo);
        void setFechaInicio(DateTime fechaInicio);
        void setFechaFin(DateTime fechaFin);
        void setEstado(String^ estado);
        void setFormato(String^ formato);
    };
}