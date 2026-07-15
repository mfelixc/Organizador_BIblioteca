#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
#include <string>

using namespace std;

struct Libro
{
    int codigo;
    string titulo;
    string autor;
    string categoria;
    int anio;
    bool disponible;
};

extern Libro biblioteca[100];
extern int cantidadLibros;

void registrarLibro();
void mostrarLibros();
void buscarLibro();

void modificarLibro();
void eliminarLibro();
void ordenarLibros();

#endif