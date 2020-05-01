#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>
#include <stdlib.h>

#include <cstdlib>
#include <string>

#include <stdio.h>

using namespace std;
char* loadData(string fileName, int& longitud)
{
    char* arrayTemp = NULL;
    ifstream file;
    file.open(fileName);
    if(file.fail())
    {
        perror(fileName.c_str());
        system("pause");
        exit(1);
    }

    string line;
    string line2;
    while(getline(file, line))
    {
        line2 += line;
    }
    longitud = line2.size() + 1;
    arrayTemp = new char[longitud];
    for(int i = 0; i <longitud; i++)
    {
        arrayTemp[i] = line2[i];
    }
    file.close();

    return arrayTemp;
}
int main(int argc, char* argv[]) {
  long length;

  int longitud = 0;
    char* arrayTemp = loadData("bd.txt", longitud);

		SocketDatagrama cliente = SocketDatagrama(6666);
		PaqueteDatagrama paquete = PaqueteDatagrama(arrayTemp, sizeof(arrayTemp), argv[1], 6000);
    cliente.envia(paquete);
		cliente.recibe(paquete);
		cout << "\nSe envio el registro:"<<endl;
    cout<<arrayTemp<<endl;
    return 0;
}
