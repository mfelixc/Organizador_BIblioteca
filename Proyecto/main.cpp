#include <bits/stdc++.h>
#include "rlutil.h"
#include "Biblioteca.h"
#include "Prestamo.h"

using namespace std;

void showItem(const char* text, int posx, int posy, bool selected)
{
    if (selected)
    {
        rlutil::setBackgroundColor(rlutil::GREEN);
        rlutil::setColor(rlutil::BLACK);
    }
    else
    {
        rlutil::setBackgroundColor(rlutil::WHITE);
        rlutil::setColor(rlutil::BLUE);
    }

    rlutil::locate(posx, posy);
    cout << text;

    rlutil::setBackgroundColor(rlutil::WHITE);
    rlutil::setColor(rlutil::BLACK);
}

void menu()
{
    int op = 1;
    int y = 0;

    rlutil::hidecursor();

    do
    {
        rlutil::setBackgroundColor(rlutil::WHITE);
        rlutil::cls();

        rlutil::setColor(rlutil::BLUE);
        rlutil::locate(30, 9);
        cout << "SELECCIONE UNA OPCION";

        showItem("Registrar Libro",      30, 11, y == 0);
        showItem("Mostrar Libros",       30, 12, y == 1);
        showItem("Buscar Libro",         30, 13, y == 2);
        showItem("Modificar Libro",      30, 14, y == 3);
        showItem("Eliminar Libro",       30, 15, y == 4);
        showItem("Ordenar Libros",       30, 16, y == 5);
        showItem("Registrar Prestamo",   30, 17, y == 6);
        showItem("Registrar Devolucion", 30, 18, y == 7);
        showItem("Reporte de Libros",    30, 19, y == 8);
        showItem("SALIR",                30, 20, y == 9);

        rlutil::locate(28, 11 + y);
        cout << (char)175;

        int key = rlutil::getkey();

        switch (key)
        {
        case 14: // Flecha arriba
            if (y > 0)
                y--;
            break;

        case 15: // Flecha abajo
            if (y < 9)
                y++;
            break;

        case 1: // Enter

            switch (y)
            {
            case 0:
                registrarLibro();
                break;

            case 1:
                mostrarLibros();
                break;

            case 2:
                buscarLibro();
                break;

            case 3:
                modificarLibro();
                break;

            case 4:
                eliminarLibro();
                break;

            case 5:
                ordenarLibros();
                break;

            case 6:
                registrarPrestamo();
                break;

            case 7:
                registrarDevolucion();
                break;

            case 8:
                reporteLibros();
                break;

            case 9:
                op = 0;
                break;
            }

            break;
        }

    } while (op != 0);
}

int main()
{
    menu();
    return 0;
}