#include <iostream>
#include <fstream>

using namespace std;

class Proveedor{
	private://atributos
		string a;
	public://metodos
		Proveedor(string);//constructor
		string validarPedido();//metodo 1
		string validarProducto();//metodo 2
		string validarFecha();//metodo 3
};

Proveedor::Proveedor(string _a){
	a = _a;	
}

//metodo 1
string Proveedor::validarPedido(){
	string line;
	ifstream indata("proveedores.txt");
	while (getline(indata, line)) {

	    if (a == line.substr(0,10)) {
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
string Proveedor::validarProducto(){
	string line;
	ifstream indata("proveedores.txt");
	while (getline(indata, line)) {

	    if (a == line.substr(10,10)) {
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
string Proveedor::validarFecha(){
	string line;
	ifstream indata("proveedores.txt");
	while (getline(indata, line)) {

	    if (a == line.substr(52,8)) {
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
	system("cls");
	int opcion;
	cout << "<<			Trabajo Individual Modulo 4			>>" << endl << endl;
	cout << "1.- Buscar un pedido" << endl;
	cout << "2.- Buscar un cod producto" << endl;
	cout << "3.- Buscar por fecha" << endl;
	cout << "4.- Salir" << endl << endl;
	cout << "Digite una opcion: "; cin >> opcion;
	return opcion;
}

int main(){
	ifstream indata("proveedores.txt");
  	string line;
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
  		Proveedor prov2 = Proveedor(search);
  		b = prov2.validarProducto();
  		cout << b << endl;
	  }else if(opcion == 3){
	  	cout << "Buscar por la fecha: ";
  		cin >> search;
  		cout << endl;
  		Proveedor prov3 = Proveedor(search);
  		c = prov3.validarFecha();
  		cout << c << endl;
	  }else{
	  	return 0;
	  }
  	
  	
  	/*int op;
  	
  	do{
	  	system("cls");
	  	op = menu();
	  	switch(op){
	  			
		  	case 1:
	  			cout << "Buscar un pedido\n";
  				cin >> search;
  				Proveedor prov1 = Proveedor(search);
  				a = prov1.validarPedido();
  				cout << a << endl;	
  			break;
  			case 2:
  				//cout << "Buscar un codigo\n";
  				//cin >> search;
  				//Proveedor prov2 = Proveedor(search);
  				//b = prov2.validarProducto();
  				//cout << b << endl;
  			break;
  			case 3:
  				cout << "Buscar una fecha\n";
  				cin >> search;
  				//Proveedor prov3 = Proveedor(search);
  				//c = prov3.validarFecha();
  				//cout << c << endl;
  			break;
  			case 4:
  				return 0;
  			break;
		}
  	}while(op != 3);
  	return 0;*/

  	/*cout << "Buscar un pedido\n";
  	cin >> search;
  
  	Proveedor prov1 = Proveedor(search);
  	a = prov1.validarPedido();
  	b = prov1.validarProducto();
  	c = prov1.validarFecha();
  
  	cout << a << endl;
  	cout << b << endl;
  	cout << c << endl;*/

	/*while (getline(indata, line)) {
    	//istringstream aux(line);	
    	string a, b;

    //if (!(aux)) { break; }
	
    if (search == line.substr(0,10)) {
      	cout << "El registro fue encontrado!\n";
      	cout << a << endl << b << endl;
    	cout << line;
    	return 0;
    	}
  	}

  	cout << "El registro no fue encontrado\n";*/

  	//return 0;
}