#include <iostream>
#include <iomanip>  
#include <string>
#include <limits>

using namespace std;

int main() {
    int opcion;
	int CantidadVentas = 0;
    double TotalDia = 0;

	cout << fixed << setprecision(2);

    do {
        cout << "\n ===== SISTEMA DE CAJA =====" << endl;
        cout << "1. Registrar venta" << endl;
        cout << "2. Ver resumen parcial del dia" << endl;
        cout << "3. Cerrar caja y salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Entrada invalida. Por favor ingrese un numero." << endl;
			continue;
			opcion = 0; // Reinicia la opción para evitar que se ejecute un caso no válido
		}

        switch (opcion) {
        case 1: {
            double Subtotal = 0;
            double PrecioUnitario = 0;
            int Cantidad = 0;

            do {
                cout << "Ingrese precio unitario del producto (0 para terminar): ";
                cin >> PrecioUnitario;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Entrada invalida. Por favor ingrese un numero." << endl;
					PrecioUnitario = -1; // Evita que se salga del bucle si la entrada es inválida
					continue;
				}

                else if (PrecioUnitario != 0) {
                    cout << "Ingrese cantidad del producto: ";
                    cin >> Cantidad;

					while (cin.fail()) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Entrada invalida. Por favor ingrese un numero valido." << endl;
						cout << "Ingrese cantidad del producto: ";
						cin >> Cantidad;
					}
                    Subtotal += PrecioUnitario * Cantidad;
                }

            } while (PrecioUnitario != 0);

            if (Subtotal == 0) {
                cout << "No se registraron productos. Venta cancelada." << endl;
                cout << "Subtotal de la venta: " << Subtotal << endl;

                break;
            }

            double Porcentaje;
            if (Subtotal >= 500) {
                Porcentaje = 0.10;
            }
            else if (Subtotal >= 100) {
                Porcentaje = 0.05;
            }
            else {
                Porcentaje = 0.00;
            }


			// ---------------Calculo del descuento y total de la venta-----------------//
			double Descuento = Subtotal * Porcentaje;
			double MontoconDescuento = Subtotal - Descuento;
			double IVA = MontoconDescuento * 0.12;
			double TotalaPagar = MontoconDescuento + IVA;


			//-------------------Resumen de la venta-------------------//
			cout << "\n--- Resumen de la venta Q. ---"<<endl;
			cout << "Subtotal: Q. " << Subtotal << endl;
			cout << "Descuento: Q. " << Descuento << endl;
			cout << "Monto con descuento: Q. " << MontoconDescuento << endl;
			cout << "IVA: Q. " << IVA << endl;
			cout << "Total a pagar: Q. " << TotalaPagar << endl;

            TotalDia += TotalaPagar;
            CantidadVentas++;

			break;
        }
        
        case 2:
            cout << "\n--- Resumen parcial del dia --- " << endl;
            cout << "Cantidad de ventas: " << CantidadVentas << endl;
            cout << "Total del dia: " << TotalDia << endl;
			if (CantidadVentas > 0) {
				double Promedio = TotalDia / CantidadVentas;
				cout << "Promedio de ventas: Q. " << Promedio << endl;
			}
			else {
				cout << "No se han registrado ventas." << endl;
			}
            break;

        case 3:
            cout << "\n--- Cerrando caja ---" << endl;
			cout << "Cantidad de ventas: " << CantidadVentas << endl;
			cout << "Total del dia: Q. " << TotalDia << endl;
			cout << 
                " Gracias por usar el sistema de caja. Hasta luego!" << endl;
            break;

        default:

            cout << "Opcion invalida. Intente de nuevo." << endl;
            break;
        }

    } while (opcion != 3);

    return 0;
}