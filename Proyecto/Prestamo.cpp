#include "Prestamo.h"
#include "Biblioteca.h"
#include "rlutil.h"

#include <iostream>

using namespace std;

void registrarPrestamo() {

    rlutil::cls();
    rlutil::locate(2,2);

    if (cantidadLibros == 0) {
        cout << "No hay libros registrados.\n";
        cout << "\nPresione cualquier tecla para continuar...";
        rlutil::anykey();
        return;
    }

    int codigo;

    cout << "============= REGISTRAR PRESTAMO =============\n\n";
    cout << "Ingrese el codigo del libro: ";
    cin >> codigo;

    bool encontrado = false;

    for (int i = 0; i < cantidadLibros; i++) {
        if (biblioteca[i].codigo == codigo) {

            encontrado = true;

            if (biblioteca[i].disponible) {
                biblioteca[i].disponible = false;
                cout << "\nPrestamo registrado correctamente.\n";
            }
            else {
                cout << "\nEl libro ya se encuentra prestado.\n";
            }

            break;
        }
    }

    if (!encontrado)
        cout << "\nNo existe un libro con ese codigo.\n";

    cout << "\nPresione cualquier tecla para continuar...";
    rlutil::anykey();
}

void registrarDevolucion() {

    rlutil::cls();
    rlutil::locate(2,2);

    if (cantidadLibros == 0) {
        cout << "No hay libros registrados.\n";
        cout << "\nPresione cualquier tecla para continuar...";
        rlutil::anykey();
        return;
    }

    int codigo;

    cout << "============= REGISTRAR DEVOLUCION =============\n\n";
    cout << "Ingrese el codigo del libro: ";
    cin >> codigo;

    bool encontrado = false;

    for (int i = 0; i < cantidadLibros; i++) {
        if (biblioteca[i].codigo == codigo) {

            encontrado = true;

            if (!biblioteca[i].disponible) {
                biblioteca[i].disponible = true;
                cout << "\nLibro devuelto correctamente.\n";
            }
            else {
                cout << "\nEse libro ya estaba disponible.\n";
            }

            break;
        }
    }

    if (!encontrado)
        cout << "\nNo existe un libro con ese codigo.\n";

    cout << "\nPresione cualquier tecla para continuar...";
    rlutil::anykey();
}

void reporteLibros() {

    rlutil::cls();
    rlutil::locate(2,2);

    if (cantidadLibros == 0) {
        cout << "No hay libros registrados.\n";
        cout << "\nPresione cualquier tecla para continuar...";
        rlutil::anykey();
        return;
    }

    cout << "============= REPORTE DE LIBROS =============\n\n";

    for (int i = 0; i < cantidadLibros; i++) {

        cout << "Codigo : " << biblioteca[i].codigo << endl;
        cout << "Titulo : " << biblioteca[i].titulo << endl;
        cout << "Estado : ";

        if (biblioteca[i].disponible)
            cout << "Disponible";
        else
            cout << "Prestado";

        cout << "\n----------------------------------------\n";
    }

    cout << "\nPresione cualquier tecla para continuar...";
    rlutil::anykey();
}