#pragma once

namespace GestionTorneosModel {
    using namespace System;
    using namespace System::Collections::Generic;

    ref class Deportista;

    public ref class Equipo {
    private:
        int idEquipo;
        String^ nombreEquipo;
        String^ facultad;
        List<Deportista^>^ jugadores;

    public:
        Equipo();
        Equipo(int idEquipo, String^ nombreEquipo, String^ facultad);

        int getIdEquipo();
        void setIdEquipo(int idEquipo);

        String^ getNombreEquipo();
        void setNombreEquipo(String^ nombreEquipo);

        String^ getFacultad();
        void setFacultad(String^ facultad);

        List<Deportista^>^ getJugadores();
        void setJugadores(List<Deportista^>^ jugadores);

        void agregarJugadores(Deportista^ deportista);
        void eliminarJugadores(Deportista^ deportista);
        Deportista^ obtenerCapitan();
        bool validarCantidadJugadores();
    };
}
