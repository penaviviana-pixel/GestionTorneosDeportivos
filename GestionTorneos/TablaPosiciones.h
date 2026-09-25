#pragma once
#include "DetallePosicion.h"

namespace GestionTorneosModel {
    using namespace System;
    using namespace System::Collections::Generic;

    ref class Partido;

    public ref class TablaPosiciones {
    private:
        int idTabla;
        String^ fechaActualizacion;
        List<DetallePosicion^>^ filas;

    public:
        TablaPosiciones();
        TablaPosiciones(int idTabla, String^ fechaActualizacion);

        int getIdTabla();
        void setIdTabla(int idTabla);

        String^ getFechaActualizacion();
        void setFechaActualizacion(String^ fechaActualizacion);

        List<DetallePosicion^>^ getFilas();
        void setFilas(List<DetallePosicion^>^ filas);

        void actualizar(Partido^ partido);
        void ordenarEquipos();
        List<DetallePosicion^>^ consultarTabla();
    };
}
