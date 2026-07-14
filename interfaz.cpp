#include<bits/stdc++.h>
#include "rlutil.h"
using namespace std;

void registrarLibro(){

    rlutil::cls();

    cout << "========== REGISTRAR LIBRO ==========\n\n";

    cout << "Aqui ira el codigo para registrar libros.\n";

    cout << "\nPresione una tecla para volver...";
    rlutil::anykey();
}

void mostrarLibros(){

    rlutil::cls();

    cout << "========== MOSTRAR LIBROS ==========\n\n";

    cout << "Aqui se mostraran los libros.\n";

    cout << "\nPresione una tecla para volver...";
    rlutil::anykey();
}

void buscarLibro(){

    rlutil::cls();

    cout << "========== BUSCAR LIBRO ==========\n\n";

    cout << "Aqui ira la busqueda.\n";

    cout << "\nPresione una tecla para volver...";
    rlutil::anykey();
}

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

void menu(){
	
	int op =1, y = 0 ;
	rlutil::hidecursor();
	do{
	rlutil::cls();
	rlutil::locate(30,10);
	cout << "MENU" << endl;
	rlutil::locate(30,11);
	cout << "1.Registrar libro " << endl;
	rlutil::locate(30,12);
	cout << "2.Mostrar libros  " << endl;
	rlutil::locate(30,13);
	cout << "3. Buscar libro " << endl;
	rlutil::locate(30,14);
	cout << "4. Prestar libro" << endl;
	rlutil::locate(30,15);
	cout << "5. Devolver libro" << endl;
	rlutil::locate(30,16);
	cout << "6. Salir" << endl;
	
	rlutil::locate(28,11 + y);
	cout << (char)175 << endl;
	
	int key = rlutil::getkey();
	
	switch(key){
		case 14: //arriba
			y--;
			if(y<0){
				y = 0;
			}
			break;
		case 15: // abajo
			y++;
			if(y>5){
				y = 5;
			}
			break;
		case 1: //enter
			switch(y)
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
				prestarLibro();
				break;
			case 4:
				devolverLibro();
				break;
			case 5:
				op = 0;
			default:
				break;
			} 
			break;
			
		default:
			break;
	}
	


	
	}while(op !=0);
	
}
int main(){
	menu();
	return 0;
}



