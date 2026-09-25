#pragma once

namespace GestionTorneosModel {
    using namespace System;

    public ref class Lugar {
    private:
        int idLugar;
        String^ nombreLugar;
        int aforoMax;
        String^ ubicacion;

    public:
        Lugar();
        Lugar(int idLugar, String^ nombreLugar, int aforoMax, String^ ubicacion);

        int getidLugar();
        void setidLugar(int idLugar);

        String^ getubicacion();
        void setubicacion(String^ value);

        String^ getnombreLugar();
        void setnombreLugar(String^ nombreLugar);

        int getaforoMax();
        void setaforoMax(int aforoMax);

        bool estaDisponible(DateTime fechaHora);
    };
}
