#include "Biblioteca.h"
void modificarLibro(Libro biblioteca[], int n){

    int codigo;
    bool encontrado = false;

    cout << "Ingrese el codigo del libro a modificar: ";
    cin >> codigo;
    cin.ignore();
    
    for(int i = 0; i < n; i++){

        if(biblioteca[i].codigo == codigo){

            cout << "Nuevo titulo: ";
            getline(cin, biblioteca[i].titulo);

            cout << "Nuevo autor: ";
            getline(cin, biblioteca[i].autor);

            cout << "Nueva categoria: ";
            getline(cin, biblioteca[i].categoria);

            cout << "Nuevo año: ";
            cin >> biblioteca[i].anio;

            encontrado = true;

            cout << "\nLibro modificado correctamente.\n";

            break;
        }
    }

    if(!encontrado)
        cout << "\nLibro no encontrado.\n";
}
void eliminarLibro(Libro biblioteca[], int &n){

    int codigo;
    bool encontrado = false;

    cout << "Ingrese el codigo del libro a eliminar: ";
    cin >> codigo;

    for(int i = 0; i < n; i++){

        if(biblioteca[i].codigo == codigo){

            for(int j = i; j < n - 1; j++){

                biblioteca[j] = biblioteca[j + 1];

            }

            n--;

            encontrado = true;

            cout << "\nLibro eliminado correctamente.\n";

            break;
        }
    }

    if(!encontrado)
        cout << "\nLibro no encontrado.\n";
}
void ordenarLibros(Libro biblioteca[], int n){

    Libro aux;

    for(int i = 0; i < n - 1; i++){

        for(int j = 0; j < n - i - 1; j++){

            if(biblioteca[j].titulo > biblioteca[j + 1].titulo){

                aux = biblioteca[j];
                biblioteca[j] = biblioteca[j + 1];
                biblioteca[j + 1] = aux;

            }
        }
    }

    cout << "\nLibros ordenados correctamente.\n";
}