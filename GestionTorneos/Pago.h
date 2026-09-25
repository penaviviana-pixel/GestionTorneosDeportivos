#pragma once

namespace GestionTorneosModel {
    using namespace System;

    public ref class Pago {
    private:
        int idPago;
        double monto;
        DateTime fechaPago;
        String^ estado;
        String^ codigoOperacion;

    public:
        Pago(int id, double monto, String^ codigo);

        // Getters
        int getIdPago();
        double getMonto();
        DateTime getFechaPago();
        String^ getEstado();
        String^ getCodigoOperacion();

        // Setters
        void setIdPago(int id);
        void setMonto(double m);
        void setFechaPago(DateTime fecha);
        void setEstado(String^ est);
        void setCodigoOperacion(String^ codigo);

        // Métodos de negocio
        void registrarPago();
        bool validarPago();
    };
}