/**
 * Project Untitled
 */


#ifndef _BILLETERA_H
#define _BILLETERA_H

class Billetera {
public: 
    
/**
 * @param cantidad
 */
void sumarPuntos(int cantidad);
    
/**
 * @param cantidad
 */
boolean descontarPuntos(int cantidad);
    
int consultarSaldo();
private: 
    int idBilletera;
    int saldo;
};

#endif //_BILLETERA_H