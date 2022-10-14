#include <iostream>
#include <fstream>

//#include <cstdlib>
//#include <iomanip>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class Proveedor{
	private://atributos
		string linea;
	public://metodos
		Proveedor(string);//constructor
		bool validarPedido(string);//metodo 1
		bool validarProducto(string);//metodo 2
		bool validarFecha(string);//metodo 3
};

Proveedor::Proveedor(string _linea){
	linea = _linea;
}

//metodo 1
bool Proveedor::validarPedido(string nroPedido){
	string temporal;
	ifstream archivo("proveedores.txt");
	int i = 0;
	for(i=0; i<=100; i++){
		if(getline(archivo, temporal)){
		
			if(temporal.substr(0,10)==nroPedido){
				return 1;
				break;
			}else{
				return 0;
				break;
			}
		}
	}
	/*while(getline(archivo, temporal)){
		if(temporal.substr(0,10)==nroPedido){
			return 1;
			break;
		}else{
			return 0;
			break;
		}
	}*/
}

//metodo 2
bool Proveedor::validarProducto(string codProd){
	
	if(linea.substr(10,10)==codProd){
		return 1;
	}else{
		return 0;
	}
}

//metodo 3
bool Proveedor::validarFecha(string fecha){
	
	if(linea.substr(50,10)==fecha){
		return 1;
	}else{
		return 0;
	}
}

int main(int argc, char** argv) {
	string linea, temporal, nroPedido, codProd, fecha;
	int a, b, c = 0;
	int contador = 0;
	/*ifstream archivo("proveedores.txt");
	
	if(archivo){
		cout<< "Se ha leido correctamente el .txt" <<endl;
		
		while(getline(archivo, temporal)){
			linea += temporal+"\n";
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
	}*/
	
	Proveedor prov1 = Proveedor(linea);
	cout<< "Ingrese numero de pedido a consultar: "; cin>>nroPedido; cout<<endl;
	//cout<< "Ingrese codigo de producto a consultar: "; cin>>codProd; cout<<endl;
	//cout<< "Ingrese fecha a consultar: "; cin>>fecha; cout<<endl;
	a = prov1.validarPedido(nroPedido);
	//b = prov1.validarProducto(codProd);
	//c = prov1.validarFecha(fecha);
	cout<<a<<endl;
	//cout<<b<<endl;
	//cout<<c<<endl;
}