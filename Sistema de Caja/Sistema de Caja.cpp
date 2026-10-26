#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cmath>

using namespace std;

int main() {
    int opcion;
    int CantidadVentas = 0;
    double TotalDia = 0;
	double Descuentos = 0;
	double VentaMayor = 0;
	double VentaMenor = 0;

    cout << fixed << setprecision(2);

    do {
        cout << "\n===== SISTEMA DE CAJA =====" << endl;
        cout << "1. Registrar venta" << endl;
        cout << "2. Ver resumen parcial del dia" << endl;
        cout << "3. Cerrar caja y salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;

        // Valida el menu: letras, decimales o texto extra (ej. 1abc)
        if (cin.fail() || cin.peek() != '\n') {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opcion = 0;   // cae en el default, que muestra un solo error
        }

        switch (opcion) {
        case 1: {
            double Subtotal = 0;
            double PrecioUnitario = 0;
            int Cantidad = 0;

            cout << "\n--- Nueva venta ---" << endl;

            do {
                cout << "Ingrese precio unitario del producto (0 para terminar): ";
                cin >> PrecioUnitario;

                if (cin.fail() || cin.peek() != '\n') {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada invalida. Por favor ingrese un numero." << endl;
                    PrecioUnitario = -1;   // evita que el ciclo termine
                }
                else if (PrecioUnitario < 0) {
                    cout << "El precio unitario no puede ser negativo. Intente de nuevo." << endl;
                }
                else if (PrecioUnitario > 0) {
                    bool cantidadValida = false;

                    do {
                        cout << "Ingrese la cantidad del producto (1 a 100, 0 para terminar): ";
                        cin >> Cantidad;

                        if (cin.fail() || cin.peek() != '\n') {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Cantidad invalida. Ingrese un numero entero." << endl;
                        }
                        else if (Cantidad == 0) {
                            PrecioUnitario = 0;      // termina el ingreso de productos
                            cantidadValida = true;   // sale del ciclo de la cantidad
                        }
                        else if (Cantidad < 1 || Cantidad > 100) {
                            cout << "Cantidad invalida. Ingrese un numero entre 1 y 100." << endl;
                        }
                        else {
                            cantidadValida = true;
                        }

                    } while (!cantidadValida);

                    Subtotal += PrecioUnitario * Cantidad;   // si la cantidad fue 0, suma 0
                }

            } while (PrecioUnitario != 0);

            if (Subtotal == 0) {
                cout << "No se registraron productos. Venta cancelada." << endl;
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

            // --------------- Calculo del descuento y total de la venta ---------------//
            double Descuento = round(Subtotal * Porcentaje * 100) / 100;
            double MontoconDescuento = Subtotal - Descuento;
            double IVA = round(MontoconDescuento * 0.12 * 100) / 100;
            double TotalaPagar = MontoconDescuento + IVA;

            cout << "Total a pagar: Q. " << TotalaPagar << endl;

			double MontoRecibido;

            do {
                cout << "\nMonto recibido: Q. ";
				cin >> MontoRecibido;

				if (cin.fail() || cin.peek() != '\n') {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Monto invalido. Por favor ingrese un numero." << endl;
					MontoRecibido = 0; // evita que el ciclo termine

				}
				else if (MontoRecibido < TotalaPagar) {
					cout << "El monto recibido es menor al total a pagar. Intente de nuevo." << endl;
				}
			} while (MontoRecibido < TotalaPagar);

            double Cambio = round((MontoRecibido - TotalaPagar) * 100) / 100;

            cout << "\n--- Recibo ---" << endl;
            cout << "Subtotal: Q. " << Subtotal << endl;
            cout << "Descuento: Q. " << Descuento << endl;
            cout << "IVA: Q. " << IVA << endl;
            cout << "Total a pagar: Q. " << TotalaPagar << endl;
			cout << "Monto recibido: Q. " << MontoRecibido << endl;
			cout << "Cambio: Q. " << Cambio << endl;

            TotalDia += TotalaPagar;
            CantidadVentas++;

            break;
        }

        case 2:
            cout << "\n--- Resumen parcial del dia ---" << endl;
            cout << "Cantidad de ventas: " << CantidadVentas << endl;
            cout << "Total del dia: Q. " << TotalDia << endl;
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
            cout << "Gracias por usar el sistema de caja. Hasta luego!" << endl;
            break;

        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
            break;
        }

    } while (opcion != 3);

    return 0;
}