#include "Disciplina.h"

using namespace System;
using namespace GestionTorneosModel;

Disciplina::Disciplina(int id, String^ nombre, bool colectivo, int min, int max) {
    this->idDisciplina = id;
    this->NombreDisciplina = nombre;
    this->esColectivo = colectivo;
    this->MinJugadores = min;
    this->MaxJugadores = max;
}

int Disciplina::getIdDisciplina() { return this->idDisciplina; }
String^ Disciplina::getNombreDisciplina() { return this->NombreDisciplina; }
bool Disciplina::getEsColectivo() { return this->esColectivo; }
int Disciplina::getMinJugadores() { return this->MinJugadores; }
int Disciplina::getMaxJugadores() { return this->MaxJugadores; }

void Disciplina::setIdDisciplina(int id) { this->idDisciplina = id; }
void Disciplina::setNombreDisciplina(String^ nombre) { this->NombreDisciplina = nombre; }
void Disciplina::setEsColectivo(bool colectivo) { this->esColectivo = colectivo; }
void Disciplina::setMinJugadores(int min) { this->MinJugadores = min; }
void Disciplina::setMaxJugadores(int max) { this->MaxJugadores = max; }

bool Disciplina::validarCantidadJugadores(int cantidad) {
    if (cantidad >= MinJugadores && cantidad <= MaxJugadores) {
        return true;
    }
    return false;
}