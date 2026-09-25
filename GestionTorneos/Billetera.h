#pragma once
namespace GestionTorneosModel {
    public ref class Billetera {
    private:
        int idBilletera;
        int saldo;

    public:
        Billetera(int id, int saldoInicial);

        // Getters y Setters
        int getIdBilletera();
        void setIdBilletera(int id);
        int getSaldo();
        void setSaldo(int nuevoSaldo);

        // Métodos de negocio
        void sumarPuntos(int cantidad);
        bool descontarPuntos(int cantidad);
        int consultarSaldo();
    };
}