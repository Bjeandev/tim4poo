#include <iostream>
#include <fstream>

using namespace std;

class Proveedor{
	private://atributos
		string search;
	public://metodos
		Proveedor(string);//constructor
		int validarPedido();//metodo 1
		int validarProducto();//metodo 2
		int validarFecha();//metodo 3
};

Proveedor::Proveedor(string _search){
	search = _search;	
}

//metodo 1
int Proveedor::validarPedido(){
	string line;
	ifstream indata("proveedores.txt");
	while (getline(indata, line)) {

	    if (search == line.substr(0,10)) {
	    	cout << "El registro fue encontrado, los datos son los siguientes:\n" << endl;
	      
	    	cout << "Pedido nro		: " << line.substr(0,10) << endl;
			cout << "Codigo producto		: " << line.substr(10,10) << endl; 
			cout << "Empresa			: " << line.substr(20,30) << endl;
			cout << "Fecha de entrega	: " << line.substr(52,2) <<"/" << line.substr(54,2) << "/" << line.substr(56,4) << endl;
			cout << "Stock			: " << line.substr(60,5) << endl;
			
	    	return 0;
	    }
	}
	cout << "El registro no fue encontrado\n";
	return 0;
}
//metodo 2
int Proveedor::validarProducto(){
	string line;
	ifstream indata("proveedores.txt");
	while (getline(indata, line)) {

	    if (search == line.substr(10,10)) {
			cout << "El registro fue encontrado, los datos son los siguientes:\n" << endl;
	      
			cout << "Codigo producto		: " << line.substr(10,10) << endl; 
	    	cout << "Pedido nro		: " << line.substr(0,10) << endl;
			cout << "Empresa			: " << line.substr(20,30) << endl;
			cout << "Fecha de entrega	: " << line.substr(52,2) <<"/" << line.substr(54,2) << "/" << line.substr(56,4) << endl;
			cout << "Stock			: " << line.substr(60,5) << endl;
			
	    	return 0;
	    }
	}
	cout << "El registro no fue encontrado\n";
	return 0;
}
//metodo 3
int Proveedor::validarFecha(){
	string line;
	ifstream indata("proveedores.txt");
	while (getline(indata, line)) {

	    if (search == line.substr(52,8)) {
	    	cout << "El registro fue encontrado, los datos son los siguientes:\n" << endl;
	      
			cout << "Fecha de entrega	: " << line.substr(52,2) <<"/" << line.substr(54,2) << "/" << line.substr(56,4) << endl;
	    	cout << "Pedido nro		: " << line.substr(0,10) << endl;
			cout << "Codigo producto		: " << line.substr(10,10) << endl; 
			cout << "Empresa			: " << line.substr(20,30) << endl;
			cout << "Stock			: " << line.substr(60,5) << endl;
			
	    	return 0;
	    }
	}
	cout << "El registro no fue encontrado\n";
	return 0;
}
//menu
int menu(){
	int opcion;
	cout << "<<			Trabajo Individual Modulo 4			>>" << endl << endl;
	cout << "1.- Buscar un pedido" << endl;
	cout << "2.- Buscar un cod producto" << endl;
	cout << "3.- Buscar por fecha" << endl;
	cout << "4.- Salir" << endl << endl;
	cout << "Digite una opcion: "; cin >> opcion;
	cout << endl;
	return opcion;
}

int main(){
	//ifstream indata("proveedores.txt");
  	//string line;
  	string search;
  	string a, b, c;
  	int opcion;
  	opcion = menu();
  	if(opcion==1){
  		cout << "Buscar el pedido: ";
  		cin >> search;
  		cout << endl;
  		Proveedor prov1 = Proveedor(search);
  		a = prov1.validarPedido();
  		cout << a << endl;
	  }else if(opcion == 2){
	  	cout << "Buscar el codigo: ";
  		cin >> search;
  		cout << endl;
  		Proveedor prov1 = Proveedor(search);
  		b = prov1.validarProducto();
  		cout << b << endl;
	  }else if(opcion == 3){
	  	cout << "Buscar por la fecha: ";
  		cin >> search;
  		cout << endl;
  		Proveedor prov1 = Proveedor(search);
  		c = prov1.validarFecha();
  		cout << c << endl;
	  }else{
	  	return 0;
	  }
  	

  	return 0;
}