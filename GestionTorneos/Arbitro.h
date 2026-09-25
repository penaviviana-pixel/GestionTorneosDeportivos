#pragma once 
#include "Usuario.h"
namespace GestionTorneosModel {

	using namespace System;

	public ref class Arbitro : public Usuario {

	public:
		void registrarIncidencia();
		void registrarTarjeta();
		void registrarFalta();

	};

}
