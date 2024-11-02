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
#include "chain.h"

Chain::Chain(std::string chain, Alphabet alphabet) : 
              length_(chain.size()), alphabet_(alphabet) {
  if (chain != "&") {
    for (int i = 0; i < chain.size(); i++) {
      if(!alphabet.is_in(chain[i])) {
        std::cerr << "Error: symbol doesn't belong in the alphabet\n"; 
        exit(EXIT_SUCCESS);
      }
      chains_.push_back(chain[i]);
    }
  } else {
    chains_.resize(0);
    length_ = 0;
  }
  
}

std::string Chain::GetChain() {
  if (chains_.size() == 0) {
    std::string empty = "&";
    return empty;
  }
  std::string string = "";
  for (char i : chains_) {
    string += i;
  }
  return string;
}

std::ostream& operator<<(std::ostream& out, const Chain& other) {
  if (other.length_ == 0) {
    out << '&';
  }
  for (int i = 0; i < other.length_; i++) {
    out << other.chains_[i];
  }
  return out;
}