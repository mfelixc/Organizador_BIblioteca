#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
#include <string>

using namespace std;

const int MAX_LIBROS = 100;

struct Libro{
    int codigo;
    string titulo;
    string autor;
    string categoria;
    int anio;
    bool disponible;
};

extern Libro biblioteca[MAX_LIBROS];
extern int n;

void registrarLibro();
void mostrarLibros();
void buscarLibro();

#endif