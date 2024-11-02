/*
  Universidad de La Laguna
  Escuela Superior de Ingenieria y Tecnologia
  Grado en Ingenieria Informatica
  Asignatura: Computabilidad y Algoritmia
  Curso: 2º
  Practica 6: Automatas Finitos
  Autor: Juan Pablo Calzadilla Gonzalez
  Correo: alu0101651@ull.edu.es
  Fecha: 18/10/2024
  Archivo cy: programa cliente.
  	    Contiene la funcion main del proyecto que usa las clases X e Y
  	    para ... (indicar brevemente el objetivo)
  Referencias:
  	    Enlaces de interes

  Historial de revisiones
  18/10/2024 - Creacion (primera version) del codigo
*/
#include "alphabet.h"

Alphabet::Alphabet(std::string symbols) {
  for (int i = 0; i < symbols.size(); i++) {
    assert(symbols[i] != '&');
    if (symbols[i] != ' '){
     symbols_.insert(symbols[i]);
    }
  }
}

bool Alphabet::is_in(char symbol) {
  return symbols_.find(symbol) != symbols_.end();
}

std::ostream& operator<<(std::ostream& out, const Alphabet& other) {
  out << '{';
  for (auto i = other.symbols_.begin(); i != other.symbols_.end(); i++) {
    out << *i;
    if (std::next(i) != other.symbols_.end()) {
      out << ", ";
    }
  }
  out << '}';
  return out;
}