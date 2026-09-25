#pragma once

namespace GestionTorneosModel {
	using namespace System;
	using namespace System::Collections::Generic;

	public ref class Usuario {
	private:
		int idUsuario;
		String^ nombre;
		String^ codigo;
		bool seguroActivo;
		String^ correoElectronico;
		String^ facultad;
		String^ contrasena;

	public:
		Usuario();
		Usuario(int idUsuario, String^ nombre, String^ codigo, bool seguroActivo, String^ correo, String^ facultad, String^ password);

		int getIdUsuario();
		void setIdUsuario(int id);

		String^ getNombre();
		void setNombre(String^ nombre);

		String^ getCodigo();
		void setCodigo(String^ codigo);

		int getCódigo();
		void setCódigo(int codigo);

		bool getSeguroActivo();
		void setSeguroActivo(bool seguroActivo);

		String^ getCorreoElectronico();
		void setCorreoElectronico(String^ correo);

		String^ getFacultad();
		void setFacultad(String^ facultad);

		String^ getContrasena();
		void setContrasena(String^ password);

		String^ getContraseña();
		void setContraseña(String^ password);

		// Métodos
		bool validarSeguro();

		bool autenticar(
			String^ correoIngresado,
			String^ contrasenaIngresada
		);

		void actualizarDatos(
			String^ nuevoNombre,
			String^ nuevoCorreo,
			String^ nuevaFacultad,
			bool nuevoSeguroActivo
		);
	};
}