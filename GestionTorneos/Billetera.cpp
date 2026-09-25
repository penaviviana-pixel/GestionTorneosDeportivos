#include "Billetera.h"

using namespace GestionTorneosModel;

Billetera::Billetera(int id, int saldoInicial) {
    this->idBilletera = id;
    this->saldo = saldoInicial;
}

int Billetera::getIdBilletera() { return this->idBilletera; }
void Billetera::setIdBilletera(int id) { this->idBilletera = id; }
int Billetera::getSaldo() { return this->saldo; }
void Billetera::setSaldo(int nuevoSaldo) { this->saldo = nuevoSaldo; }

void Billetera::sumarPuntos(int cantidad) {
    this->saldo += cantidad;
}

bool Billetera::descontarPuntos(int cantidad) {
    if (this->saldo >= cantidad) {
        this->saldo -= cantidad;
        return true;
    }
    return false;
}

int Billetera::consultarSaldo() {
    return this->saldo;
}