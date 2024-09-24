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
	Clase alphabet que contiene el alphabeto que se recibe
	de la segunda cadena del archivo de entrada, tambien
	contiene la funcion de imprimir el alphabeto en el
	documento de salida

  Historial de revisiones
  22/09/2024 - Creacion (primera version) del codigo
*/

#include "alphabet.h"

Alphabet::Alphabet(const std::vector<char>& SymbolList) {
  for (char sym : SymbolList) {
    symbols.insert(Symbol(sym));
  }
}

/*
  @Brief: Gets the alphabet (the second chain) and prints it in the output file
*/
void Alphabet::PrintAlphabet(std::ofstream& output) {
  output << "{";
  for (const Symbol& sym : symbols) {
    output << sym.get_value() << ", ";
  }
  output << "}\n";
}
