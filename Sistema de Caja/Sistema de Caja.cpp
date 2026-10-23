#include <iostream>
#include <string>

#include <string>
				
int main() {
	std::string nombre;
	double monto;
	std::cout << "Ingrese su nombre: ";
	std::getline(std::cin, nombre);
	std::cout << "Ingrese el monto a depositar: ";
	std::cin >> monto;
	std::cout << "Hola, " << nombre << ". Has depositado: $" << monto << std::endl;
	return 0;
}