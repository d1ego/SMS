#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>
#include <stdlib.h>
#include <fstream>


using namespace std;

int main() {
    SocketDatagrama  servidor = SocketDatagrama(6000);
    PaqueteDatagrama paqueteRecibido = PaqueteDatagrama(500);
    cout << "Esperando Respuesta:\n";
    PaqueteDatagrama aux = PaqueteDatagrama(500);

    char cadena[128];
       // Crea un fichero de salida
       ofstream fs("salidaServidor.txt");

       // Enviamos una cadena al fichero de salida:
       // Cerrar el fichero,
       // para luego poder abrirlo para lectura:



    while (1) {
        servidor.recibe(paqueteRecibido);
        cout << "Se recibio el mensaje: " <<paqueteRecibido.obtieneDatos()<<endl;
        cout << "Se recibio de IP: " <<paqueteRecibido.obtieneDireccion()<<endl;
        cout << "Usando el puerto: " <<paqueteRecibido.obtienePuerto()<<endl;
        servidor.envia(paqueteRecibido);

        fs << paqueteRecibido.obtieneDatos()<< endl;
    }
    fs.close();
    return 0;

}
