/**
 * Project Untitled
 */


#ifndef _PAGO_H
#define _PAGO_H

class Pago {
public: 
    
void registrarPago();
    
boolean validarPago();
private: 
    int idPago;
    double monto;
    DateTime fechaPago;
    EstadoPago estado;
    string codigoOperacion;
};

#endif //_PAGO_H