#include <iostream>
//librería para leer y escribir en archivos
#include <fstream>
int main()
{
	//declaramos un objeto ifstream apuntando a "archivo.txt"
	std::ifstream flujo ("proveedores.txt", std::ifstream::binary);
	if(flujo)
	{
		//obtenemos el tamaño del archivo
		flujo.seekg(0,flujo.end);
		int largo = flujo.tellg();
		flujo.seekg(0,flujo.beg);
		//creamos un puntero a un arregllo de caracteres para almacenar la lectura
		char * caracteres = new char[largo];
		//guardamos la lectura en el arreglo
		flujo.read(caracteres,largo);
		//mostramos lo leído
		int i = 0;
		while(i<largo)
		std::cout << "Caracter: " << caracteres[i++] << std::endl;
	}
	else
		std::cout << "No se pudo crear el flujo";
	return 0;
}