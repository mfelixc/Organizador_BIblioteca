#include "Biblioteca.h"
#include "rlutil.h"

Libro biblioteca[MAX_LIBROS];
int n = 0;

void registrarLibro(){

    rlutil::cls();

    if(n >= MAX_LIBROS){
        cout << "La biblioteca esta llena.\n";
        rlutil::anykey();
        return;
    }

    cout << "========== REGISTRAR LIBRO ==========\n\n";

    cout << "Codigo: ";
    cin >> biblioteca[n].codigo;
    cin.ignore();

    cout << "Titulo: ";
    getline(cin,biblioteca[n].titulo);

    cout << "Autor: ";
    getline(cin,biblioteca[n].autor);

    cout << "Categoria: ";
    getline(cin,biblioteca[n].categoria);

    cout << "Anio: ";
    cin >> biblioteca[n].anio;

    biblioteca[n].disponible = true;

    n++;

    cout << "\nLibro registrado correctamente.";

    rlutil::anykey();
}

void mostrarLibros(){

    rlutil::cls();

    cout << "========== LISTA DE LIBROS ==========\n\n";

    if(n == 0){

        cout << "No hay libros registrados.\n";

    }else{

        for(int i=0;i<n;i++){

            cout << "Codigo: " << biblioteca[i].codigo << endl;
            cout << "Titulo: " << biblioteca[i].titulo << endl;
            cout << "Autor: " << biblioteca[i].autor << endl;
            cout << "Categoria: " << biblioteca[i].categoria << endl;
            cout << "Anio: " << biblioteca[i].anio << endl;

            if(biblioteca[i].disponible)
                cout << "Estado: Disponible\n";
            else
                cout << "Estado: Prestado\n";

            cout << "-----------------------------\n";
        }

    }

    rlutil::anykey();
}

void buscarLibro(){

    rlutil::cls();

    int codigo;
    bool encontrado = false;

    cout << "========== BUSCAR LIBRO ==========\n\n";

    cout << "Ingrese el codigo: ";
    cin >> codigo;

    for(int i=0;i<n;i++){

        if(biblioteca[i].codigo == codigo){

            cout << "\nLibro encontrado\n\n";

            cout << "Codigo: " << biblioteca[i].codigo << endl;
            cout << "Titulo: " << biblioteca[i].titulo << endl;
            cout << "Autor: " << biblioteca[i].autor << endl;
            cout << "Categoria: " << biblioteca[i].categoria << endl;
            cout << "Anio: " << biblioteca[i].anio << endl;

            encontrado = true;
            break;
        }

    }

    if(!encontrado){

        cout << "\nLibro no encontrado.\n";

    }

    rlutil::anykey();
}