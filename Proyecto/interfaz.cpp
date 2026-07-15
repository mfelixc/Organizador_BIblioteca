#include <bits/stdc++.h>
#include "rlutil.h"
#include "Biblioteca.h"

using namespace std;


void prestarLibro(){

    rlutil::cls();

    cout << "========== PRESTAR LIBRO ==========\n\n";

    cout << "Aqui ira el prestamo.\n";

    cout << "\nPresione una tecla para volver...";
    rlutil::anykey();
}


void devolverLibro(){

    rlutil::cls();

    cout << "========== DEVOLVER LIBRO ==========\n\n";

    cout << "Aqui ira la devolucion.\n";

    cout << "\nPresione una tecla para volver...";
    rlutil::anykey();
}



void showItem(const char* text, int posx, int posy, bool selected){

    if(selected){
        rlutil::setBackgroundColor(rlutil::GREEN);
    }
    else{
        rlutil::setColor(rlutil::BLUE);
    }

    rlutil::locate(posx,posy);
    cout << text << endl;

    rlutil::setBackgroundColor(rlutil::WHITE);
}



void menu(){

    int op = 1;
    int y = 0;

    rlutil::hidecursor();


    do{

        rlutil::setBackgroundColor(rlutil::WHITE);
        rlutil::cls();

        rlutil::setColor(rlutil::BLUE);

        rlutil::locate(30,10);
        cout << "SELECCIONE UNA OPCION" << endl;


        showItem("Registrar Libro",30,11,y==0);
        showItem("Mostrar Libros",30,12,y==1);
        showItem("Buscar Libro",30,13,y==2);
        showItem("Prestar Libro",30,14,y==3);
        showItem("Devolver Libro",30,15,y==4);
        showItem("SALIR",30,16,y==5);



        rlutil::locate(28,11+y);
        cout << (char)175;


        int key = rlutil::getkey();


        switch(key){

            case 14: // arriba
                y--;

                if(y<0)
                    y=0;

                break;


            case 15: // abajo
                y++;

                if(y>5)
                    y=5;

                break;



            case 1: // enter

                switch(y){

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
                        prestarLibro();
                        break;


                    case 4:
                        devolverLibro();
                        break;


                    case 5:
                        op=0;
                        break;

                }

                break;

        }


    }while(op!=0);

}



int main(){

    menu();

    return 0;
}