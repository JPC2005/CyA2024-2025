/*
  Universidad de La Laguna
  Escuela Superior de Ingenieria y Tecnologia
  Grado en Ingenieria Informatica
  Asignatura: Computabilidad y Algoritmia
  Curso: 2º
  Practica 2: Cadenas y lenguajes
  Autor: Juan Pablo Calzadilla Gonzalez
  Correo: alu0101651@ull.edu.es
  Fecha: 22/09/2024
  Archivo cy: programa cliente.
  	    Clase Alphabet

  Historial de revisiones
  22/09/2024 - Creacion (primera version) del codigo
*/
#ifndef ALPHABET_H
#define ALPHABET_H

#include <iostream>
#include <set>
#include <vector>
#include <fstream>

#include "symbol.h"

class Alphabet {
  public:
    std::set<Symbol> symbols;

    Alphabet(const std::vector<char>& SymbolList);

    void PrintAlphabet(std::ofstream& output);
    void PrintInverse(std::ofstream& output);
};

#endif
