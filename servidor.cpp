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

int main(int argc, char* argv[]) {
    SocketDatagrama  servidor = SocketDatagrama(6000);
    PaqueteDatagrama paqueteRecibido = PaqueteDatagrama(6000);
    cout << "Esperando Respuesta:\n";
           ofstream fs(argv[2]);
    while (1) {
        servidor.recibe(paqueteRecibido);
        cout << "Se recibio el voto: " <<paqueteRecibido.obtieneDatos()<<endl;
        cout << "Se recibio de IP: " <<paqueteRecibido.obtieneDireccion()<<endl;
        cout << "Usando el puerto: " <<paqueteRecibido.obtienePuerto()<<endl;
        servidor.envia(paqueteRecibido);
        fs << paqueteRecibido.obtieneDatos()<< endl;

    }

    fs.close();
    return 0;

}
