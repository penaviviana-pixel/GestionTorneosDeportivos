#pragma once

namespace GestionTorneosModel {
    using namespace System;
    using namespace System::Collections::Generic;

    ref class Equipo;
    ref class Partido;

    public ref class Fixture {
    private:
        int idFixture;
        DateTime fecha;
        String^ formato;
        List<Partido^>^ partidos;

    public:
        Fixture();
        Fixture(int idFixture, DateTime fecha, String^ formato);

        int getIdFixture();
        void setIdFixture(int idFixture);

        DateTime getFecha();
        void setFecha(DateTime fecha);

        String^ getFormato();
        void setFormato(String^ formato);

        List<Partido^>^ getPartidos();
        void setPartidos(List<Partido^>^ partidos);

        void generarPartidos(List<Equipo^>^ equipos);
        void reprogramarPartido();
        List<Partido^>^ consultarPartidos();
    };
}
