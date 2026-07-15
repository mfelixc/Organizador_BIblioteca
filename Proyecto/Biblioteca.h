#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
#include <string>

using namespace std;

struct Libro{
    int codigo;
    string titulo;
    string autor;
    string categoria;
    int anio;
    bool disponible;
};

void registrarLibro(Libro biblioteca[], int &n);
void mostrarLibros(Libro biblioteca[], int n);
void buscarLibro(Libro biblioteca[], int n);

void modificarLibro(Libro biblioteca[], int n);
void eliminarLibro(Libro biblioteca[], int &n);
void ordenarLibros(Libro biblioteca[], int n);

#endif