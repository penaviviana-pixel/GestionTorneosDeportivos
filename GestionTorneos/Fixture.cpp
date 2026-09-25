#include "Fixture.h"
#include "Equipo.h"
#include "Partido.h"

namespace GestionTorneosModel {
    Fixture::Fixture() {
        this->idFixture = 0;
        this->fecha = DateTime::Now;
        this->formato = String::Empty;
        this->partidos = gcnew List<Partido^>();
    }

    Fixture::Fixture(int idFixture, DateTime fecha, String^ formato) {
        this->idFixture = idFixture;
        this->fecha = fecha;
        this->formato = formato;
        this->partidos = gcnew List<Partido^>();
    }

    int Fixture::getIdFixture() { return this->idFixture; }
    void Fixture::setIdFixture(int idFixture) { this->idFixture = idFixture; }

    DateTime Fixture::getFecha() { return this->fecha; }
    void Fixture::setFecha(DateTime fecha) { this->fecha = fecha; }

    String^ Fixture::getFormato() { return this->formato; }
    void Fixture::setFormato(String^ formato) { this->formato = formato; }

    List<Partido^>^ Fixture::getPartidos() { return this->partidos; }
    void Fixture::setPartidos(List<Partido^>^ partidos) { this->partidos = partidos; }

    void Fixture::generarPartidos(List<Equipo^>^ equipos) {
        if (equipos == nullptr || equipos->Count < 2) return;
        int idPart = 1;
        for (int i = 0; i < equipos->Count; i++) {
            for (int j = i + 1; j < equipos->Count; j++) {
                Partido^ p = gcnew Partido(idPart++, this->fecha, this->fecha, equipos[i], equipos[j]);
                this->partidos->Add(p);
            }
        }
    }

    void Fixture::reprogramarPartido() {
    }

    List<Partido^>^ Fixture::consultarPartidos() {
        return this->partidos;
    }
}
