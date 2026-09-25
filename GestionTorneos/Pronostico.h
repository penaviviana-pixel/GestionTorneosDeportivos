#pragma once

namespace GestionTorneosModel {
    using namespace System;
    using namespace System::Collections::Generic;

    ref class Partido;

    public ref class Pronostico {
    private:
        int idPronostico;
        DateTime fechaRegistro;
        int puntosApostada;
        int marcadorLocalPronosticado;
        int marcadorVisitantePronosticado;
        List<String^>^ estadoPronostico;
        int puntosGanados;

    public:
        Pronostico();
        Pronostico(int idPronostico, DateTime fechaRegistro, int puntosApostada, int marcadorLocalPronosticado, int marcadorVisitantePronosticado, List<String^>^ estadoPronostico, int puntosGanados);

        int getIdPronostico();
        void setIdPronostico(int idPronostico);

        DateTime getFechaRegistro();
        void setFechaRegistro(DateTime fechaRegistro);

        int getPuntosApostada();
        void setPuntosApostada(int puntosApostada);

        int getMarcadorLocalPronosticado();
        void setMarcadorLocalPronosticado(int marcadorLocalPronosticado);

        int getMarcadorVisitantePronosticado();
        void setMarcadorVisitantePronosticado(int marcadorVisitantePronosticado);

        List<String^>^ getEstadoPronostico();
        void setEstadoPronostico(List<String^>^ estadoPronostico);

        int getPuntosGanados();
        void setPuntosGanados(int puntosGanados);

        void evaluarResultado(Partido^ partido);
        int calcularGanancia();
        void marcarGanado();
        void marcarPerdido();
    };
}
