#include <iostream>
#include <fstream>

using namespace std;

class Proveedor{
	private://atributos
			/*Profe, aqui utilizo la palabra que ingresa el usuario como base para todo el codigo,
			ya que primero debe seleccionar la opcion que necesite y luego llamo a la funcion la cual
			se ejecuta con la palabra ingresada buscando el nro de pedido, el codigo de producto o la fecha*/
		string buscar;
	public://metodos
		Proveedor(string);//constructor
		/*aqui los inicialice como integer porque dan el resultado a la busqueda mediante los cout,
		pero no podia dejar sin return la funcion o podia hacerlo void pero pense que asi seria una buena idea*/
		int validarPedido();//metodo 1
		int validarProducto();//metodo 2
		int validarFecha();//metodo 3
};
//creo mi constructor
Proveedor::Proveedor(string _buscar){
	buscar = _buscar;	
}
//metodo 1
/*mi metodo es sencillo, abro el archivo mediante el ifstream, luego con un while y getline recorro linea a linea
el documento buscando con un if la coincidencia con el atributo previamente ingresado por consola (mi variable buscar),
una vez encontrada extraigo todos los datos necesarios en base a su posicion en la linea y tambien agregue los "/" a la fecha*/
int Proveedor::validarPedido(){
	string linea;
	ifstream archivo("proveedores.txt");
	while (getline(archivo, linea)) {

	    if (buscar == linea.substr(0,10)) {
	    	cout << "El registro fue encontrado, los datos son los siguientes:\n" << endl;
	      
	    	cout << "Pedido nro		: " << linea.substr(0,10) << " <---------------" << endl;
			cout << "Codigo producto		: " << linea.substr(10,10) << endl; 
			cout << "Empresa			: " << linea.substr(20,30) << endl;
			cout << "Fecha de entrega	: " << linea.substr(52,2) <<"/" << linea.substr(54,2) << "/" << linea.substr(56,4) << endl;
			cout << "Stock			: " << linea.substr(60,5) << endl << endl;
			
	    	return 0;
	    }
	}
	cout << "El registro no fue encontrado\n" << endl ;
	return 0;
}
//metodo 2
/*aqui basicamente replico el metodo anterior pero ahora la coincidencia que estoy buscando es otra (codigo de producto),
que comenzaria en la posicion 10 de la linea con una extension de 10 caracteres*/
int Proveedor::validarProducto(){
	string linea;
	ifstream archivo("proveedores.txt");
	while (getline(archivo, linea)) {

	    if (buscar == linea.substr(10,10)) {
			cout << "El registro fue encontrado, los datos son los siguientes:\n" << endl;
	      
	    	cout << "Pedido nro		: " << linea.substr(0,10) << endl;
			cout << "Codigo producto		: " << linea.substr(10,10) << " <---------------" << endl;
			cout << "Empresa			: " << linea.substr(20,30) << endl;
			cout << "Fecha de entrega	: " << linea.substr(52,2) <<"/" << linea.substr(54,2) << "/" << linea.substr(56,4) << endl;
			cout << "Stock			: " << linea.substr(60,5) << endl << endl;
			
	    	return 0;
	    }
	}
	cout << "El registro no fue encontrado\n" << endl ;
	return 0;
}
//metodo 3
/*en este mantengo o el mismo modus operandi pero con algunas diferencias, ya que para dejar mas estetica la fecha
a la hora de mostrar una vez encontrada agrego los slash  y para lograr eso tuve que dividir la fecha en tres partes.
Una de la posicion 52 con extension de dos para el dia, de la 54 con dos tambien y luego la 56 con una extesion de cuatro para el anio*/
int Proveedor::validarFecha(){
	string linea;
	ifstream archivo("proveedores.txt");
	while (getline(archivo, linea)) {

	    if (buscar == linea.substr(52,8)) {
	    	cout << "El registro fue encontrado, los datos son los siguientes:\n" << endl;
	      
	    	cout << "Pedido nro		: " << linea.substr(0,10) << endl;
			cout << "Codigo producto		: " << linea.substr(10,10) << endl; 
			cout << "Empresa			: " << linea.substr(20,30) << endl;
			cout << "Fecha de entrega	: " << linea.substr(52,2) <<"/" << linea.substr(54,2) << "/" << linea.substr(56,4) << " <---------------" << endl;
			cout << "Stock			: " << linea.substr(60,5) << endl << endl;
			
	    	return 0;
	    }
	}
	cout << "El registro no fue encontrado\n" << endl;
	return 0;
}
//menu
/*aqui hago un menu sencillo que retorna un numero que necesitara mi funcion main para saber que metodo iniciar*/
int menu(){
	int opcion;
	cout << "<<			Trabajo Individual Modulo 4			>>" << endl << endl;
	
	cout << "1.- Buscar un Nro de Pedido" << endl;
	cout << "2.- Buscar un Cod de Producto" << endl;
	cout << "3.- Buscar por Fecha" << endl;
	cout << "4.- Salir" << endl << endl;
	cout << "Digite una opcion: "; cin >> opcion;
	cout << endl;
	return opcion;
}

int main(){
	//inicio mis variables
	/*la variable buscar tendra la palabra clave que quiere encontrar el usuario y las otras (a, b y c)
	son para poder llamar a mis metodos segun sea necesario. La variable opcion es la que llama al menu y
	luego obtiene el valor resultante que filtrara mi if para saber que metodo llamar*/
  	string buscar, a, b , c;
  	int opcion;
  	//llamo a mi menu
  	opcion = menu();
  	//segun la opcion seleccionada trabajara mi if (probe con switch pero no me resulto :c)
  	/*una vez filtrada la opcion elegida por el usuario el if ejecuta segun sea el caso el metodo necesario y crea
	un objeto de la clase Proveedor con el atributo a buscar para luego llamar al metodo necesario*/
  	if(opcion==1){
  		cout << "Si el nro de pedido contiene letras" << endl << "Porfavor utilice mayusculas." << endl << endl;
  		cout << "Buscar el nro de pedido: "; cin >> buscar; cout << endl;
  		Proveedor prov1 = Proveedor(buscar);
  		prov1.validarPedido();
	  }else if(opcion == 2){
	  	cout << "El codigo debe contener 10 numeros." << endl << "Si son menos debe completar con ceros." << endl << "ej: 0000012345." << endl << endl;
	  	cout << "Buscar el codigo de producto: "; cin >> buscar; cout << endl;
  		Proveedor prov1 = Proveedor(buscar);
  		prov1.validarProducto();
	  }else if(opcion == 3){
	  	cout << "Se solicita porfavor ingresar la fecha sin '/' ni '-'" << endl << "ej: ddmmyy." << endl << endl;
	  	cout << "Buscar por la fecha: "; cin >> buscar; cout << endl;
  		Proveedor prov1 = Proveedor(buscar);
  		prov1.validarFecha();
	  }else{
	  	return 0;
	  }
  	
	//la buena practica xD
	system("pause");
  	return 0;
}