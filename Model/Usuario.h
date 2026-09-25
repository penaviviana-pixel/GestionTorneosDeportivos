/**
 * Project Untitled
 */


#ifndef _USUARIO_H
#define _USUARIO_H

class Usuario {
public: 
    
boolean validarSeguro();
    
List<Notificacion> consultarNotificaciones();
    
/**
 * @param correo
 * @param contraseña
 */
boolean autenticar(String correo, String contraseña);
    
void actualizarDatos();
private: 
    string Nombre;
    String Código;
    boolean SeguroActivo;
    String Correo;
    String Facultad;
    int idUsuario;
    String Contraseña;
};

#endif //_USUARIO_H