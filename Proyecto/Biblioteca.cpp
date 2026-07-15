#include "Biblioteca.h"
#include "rlutil.h"

Libro biblioteca[100];
int cantidadLibros = 0;

void registrarLibro() {

    rlutil::cls();
    rlutil::locate(2,2);

    cout << "===== REGISTRAR LIBRO =====\n\n";

    cout << "Codigo: ";
    cin >> biblioteca[cantidadLibros].codigo;

    cin.ignore();

    cout << "Titulo: ";
    getline(cin, biblioteca[cantidadLibros].titulo);

    cout << "Autor: ";
    getline(cin, biblioteca[cantidadLibros].autor);

    cout << "Categoria: ";
    getline(cin, biblioteca[cantidadLibros].categoria);

    cout << "Anio: ";
    cin >> biblioteca[cantidadLibros].anio;

    biblioteca[cantidadLibros].disponible = true;
    cantidadLibros++;

    cin.ignore();

    cout << "\nLibro registrado correctamente.";

    cout << "\n\nPresione cualquier tecla para continuar...";
    rlutil::anykey();
}

void mostrarLibros() {

    rlutil::cls();
    rlutil::locate(2,2);

    if (cantidadLibros == 0) {
        cout << "No hay libros registrados.\n";
        rlutil::anykey();
        return;
    }

    cout << "========== LISTA DE LIBROS ==========\n\n";

    for (int i = 0; i < cantidadLibros; i++) {
        cout << "Libro #" << i + 1 << endl;
        cout << "Codigo: " << biblioteca[i].codigo << endl;
        cout << "Titulo: " << biblioteca[i].titulo << endl;
        cout << "Autor: " << biblioteca[i].autor << endl;
        cout << "Categoria: " << biblioteca[i].categoria << endl;
        cout << "Anio: " << biblioteca[i].anio << endl;
        cout << "Disponible: " << (biblioteca[i].disponible ? "Si" : "No") << endl;
        cout << "-----------------------------\n";
    }

    cout << "\nPresione cualquier tecla para continuar...";
    rlutil::anykey();
}

void buscarLibro() {

    rlutil::cls();
    rlutil::locate(2,2);

    if (cantidadLibros == 0) {
        cout << "No hay libros registrados.\n";
        rlutil::anykey();
        return;
    }

    int codigoBuscado;
    bool encontrado = false;

    cout << "Ingrese el codigo del libro: ";
    cin >> codigoBuscado;

    for (int i = 0; i < cantidadLibros; i++) {
        if (biblioteca[i].codigo == codigoBuscado) {

            cout << "\nLibro encontrado.\n\n";
            cout << "Codigo: " << biblioteca[i].codigo << endl;
            cout << "Titulo: " << biblioteca[i].titulo << endl;
            cout << "Autor: " << biblioteca[i].autor << endl;
            cout << "Categoria: " << biblioteca[i].categoria << endl;
            cout << "Anio: " << biblioteca[i].anio << endl;
            cout << "Disponible: " << (biblioteca[i].disponible ? "Si" : "No") << endl;

            encontrado = true;
            break;
        }
    }

    if (!encontrado)
        cout << "\nNo existe un libro con ese codigo.\n";

    cout << "\nPresione cualquier tecla para continuar...";
    rlutil::anykey();
}

void modificarLibro() {

    rlutil::cls();
    rlutil::locate(2,2);

    if (cantidadLibros == 0) {
        cout << "No hay libros registrados.\n";
        rlutil::anykey();
        return;
    }

    int codigoBuscado;
    bool encontrado = false;

    cout << "Ingrese el codigo del libro a modificar: ";
    cin >> codigoBuscado;
    cin.ignore();

    for (int i = 0; i < cantidadLibros; i++) {

        if (biblioteca[i].codigo == codigoBuscado) {

            cout << "\n===== MODIFICAR LIBRO =====\n\n";

            cout << "Nuevo titulo: ";
            getline(cin, biblioteca[i].titulo);

            cout << "Nuevo autor: ";
            getline(cin, biblioteca[i].autor);

            cout << "Nueva categoria: ";
            getline(cin, biblioteca[i].categoria);

            cout << "Nuevo anio: ";
            cin >> biblioteca[i].anio;

            cout << "\nLibro modificado correctamente.\n";

            encontrado = true;
            break;
        }
    }

    if (!encontrado)
        cout << "\nNo existe un libro con ese codigo.\n";

    cout << "\nPresione cualquier tecla para continuar...";
    rlutil::anykey();
}

void eliminarLibro() {

    rlutil::cls();
    rlutil::locate(2,2);

    if (cantidadLibros == 0) {
        cout << "No hay libros registrados.\n";
        rlutil::anykey();
        return;
    }

    int codigoBuscado;
    bool encontrado = false;
    char confirmar;

    cout << "========== ELIMINAR LIBRO ==========\n\n";

    cout << "Ingrese el codigo del libro: ";
    cin >> codigoBuscado;

    for (int i = 0; i < cantidadLibros; i++) {

        if (biblioteca[i].codigo == codigoBuscado) {

            cout << "\nCodigo: " << biblioteca[i].codigo << endl;
            cout << "Titulo: " << biblioteca[i].titulo << endl;

            cout << "\nDesea eliminar este libro? (S/N): ";
            cin >> confirmar;

            if (confirmar == 'S' || confirmar == 's') {

                for (int j = i; j < cantidadLibros - 1; j++)
                    biblioteca[j] = biblioteca[j + 1];

                cantidadLibros--;

                cout << "\nLibro eliminado correctamente.\n";
            }
            else
                cout << "\nOperacion cancelada.\n";

            encontrado = true;
            break;
        }
    }

    if (!encontrado)
        cout << "\nNo existe un libro con ese codigo.\n";

    cout << "\nPresione cualquier tecla para continuar...";
    rlutil::anykey();
}

void ordenarLibros() {

    rlutil::cls();
    rlutil::locate(2,2);

    if (cantidadLibros == 0) {
        cout << "No hay libros registrados.\n";
        rlutil::anykey();
        return;
    }

    for (int i = 0; i < cantidadLibros - 1; i++) {
        for (int j = 0; j < cantidadLibros - i - 1; j++) {

            if (biblioteca[j].codigo > biblioteca[j + 1].codigo) {

                Libro aux = biblioteca[j];
                biblioteca[j] = biblioteca[j + 1];
                biblioteca[j + 1] = aux;
            }
        }
    }

    cout << "Libros ordenados correctamente por codigo.\n";

    cout << "\nPresione cualquier tecla para continuar...";
    rlutil::anykey();
}