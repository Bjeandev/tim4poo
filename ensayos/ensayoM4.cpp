#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(){
  ifstream indata("proveedores.txt");
  string line;
  string search;

  cout << "Busca un nombre\n";
  cin >> search;

  while (getline(indata, line)) {
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

  cout << "El registro no fue encontrado\n";

  return 0;
}