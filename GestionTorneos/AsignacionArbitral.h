#pragma once 

namespace GestionTorneosModel {

	using namespace System;

	public ref class AsignacionArbitral {
	private:
		int idAsignacion;
		DateTime fechaAsignacion;
		String^ rolArbitral;
		String^ estado;

	public:
		AsignacionArbitral();
		AsignacionArbitral(int idAsignacion, DateTime fechaAsignacion, String^ rolArbitral, String^ estado);

		void confirmarAsignacion();
		void cancelarAsignacion();

		int getIdAsignacion();
		void setIdAsignacion(int idAsignacion);

		DateTime getFechaAsignacion();
		void setFechaAsignacion(DateTime fechaAsignacion);

		String^ getRolArbitral();
		void setRolArbitral(String^ rolArbitral);

		String^ getEstado();
		void setEstado(String^ estado);

	};

}
