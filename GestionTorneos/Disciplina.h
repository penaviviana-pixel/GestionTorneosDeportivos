#pragma once
namespace GestionTorneosModel {

    using namespace System;

    public ref class Disciplina {
    private:
        int idDisciplina;
        String^ NombreDisciplina;
        bool esColectivo;
        int MinJugadores;
        int MaxJugadores;

    public:
        Disciplina(int id, String^ nombre, bool colectivo, int min, int max);

        // Getters
        int getIdDisciplina();
        String^ getNombreDisciplina();
        bool getEsColectivo();
        int getMinJugadores();
        int getMaxJugadores();

        // Setters
        void setIdDisciplina(int id);
        void setNombreDisciplina(String^ nombre);
        void setEsColectivo(bool colectivo);
        void setMinJugadores(int min);
        void setMaxJugadores(int max);

        // Métodos de negocio
        bool validarCantidadJugadores(int cantidad);
    };
}