#pragma once 

namespace GestionTorneosModel {
	using namespace System;

	public ref class DetallePosicion {
	private:
		int partidosJugados;
		int partidosGanados;
		int partidosEmpatados;
		int partidosPerdidos;
		int puntosFavor;
		int puntosContra;
		int puntosTabla;


	public:
		DetallePosicion();

		DetallePosicion(int partidosJugados, int partidosGanados, int partidosEmpatados, int partidosPerdidos, int puntosFavor, int puntosContra, int puntosTabla);

		int calcularDiferencia();
		int calcularPuntaje();

		int getPartidosJugados();
		void setPartidosJugados(int partidosJugados);

		int getPartidosGanados();
		void setPartidosGanados(int partidosGanados);

		int getPartidosEmpatados();
		void setPartidosEmpatados(int partidosEmpatados);

		int getPartidosPerdidos();
		void setPartidosPerdidos(int partidosPerdidos);

		int getPuntosFavor();
		void setPuntosFavor(int puntosFavor);

		int getPuntosContra();
		void setPuntosContra(int puntosContra);

		int getPuntosTabla();
		void setPuntosTabla(int puntosTabla);

	};

}
