#include <iostream>
#include <fstream>

//#include <cstdlib>
//#include <iomanip>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	string linea;
	int contador = 0;
	ifstream archivo("proveedores.txt");
	if(archivo){
		cout<< "Se ha leido correctamente el .txt" <<endl;
		
		while(getline(archivo, linea)){
			cout<< linea <<endl<<endl;
			cout<< "Pedido Nro: "<< linea.substr(0,10) <<endl;
			cout<< "Cod Prod: "<< linea.substr(10,10) <<endl;
			cout<< "Empresa de Venta: "<< linea.substr(20,30) <<endl;
			cout<< "Fecha de Entrega: "<< linea.substr(50,10) <<endl;
			cout<< "Stock: "<< linea.substr(60,5) <<endl<<endl;
			contador ++;
		}
		cout<< "La cantidad de elementos es: "<< contador <<endl;
	}else{
		cout<< "Error en la lectura del .txt";
	}
	
	return 0;
}