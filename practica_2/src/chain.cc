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
	Clase chain cual contiene la primera cadena
	recibida del documento de entrada y que 
	permite llamar a las funciones de longitud,
	inversa, prefijo y sufijo
	
  Historial de revisiones
  22/09/2024 - Creacion (primera version) del codigo
  25/09/2024 - Modificacion en clase
*/
#include "chain.h"

Chain::Chain(const std::string& ChainStr) {
  for (char ch : ChainStr) {
    chain_.push_back(Symbol(ch));
  }
}

/*
  @Brief: Gets the size of the chain and prints it in the output file
*/
void Chain::Length(std::ofstream& output) const {
  output << get_size() << "\n";
}

/*
  @Brief: Gets the first chain and prints it in reverse in the output file
*/
void Chain::PrintInverse(std::ofstream& output) const {
  for (size_t i{get_size()}; 0 < i; i--) {
    output << get_chain()[i - 1].get_value();
  }
  output << "\n";
}

/*
  @Brief: Gets the first chain and prints the prefixes one by one, by only taking
  from the start of the chain up to i, which goes up every iteration until
  the size of the chain
*/
void Chain::Prefix(std::ofstream& output) const {
    output << "{&";  
    for (size_t i{1}; i <= get_size(); ++i) {
      output << ", ";
      for (size_t j{0}; j < i; ++j) {
        output << get_chain()[j].get_value();
      }
    }
  output << "}\n";
}

/*
  @Brief: Gets the first chain and prints the suffixes one by one, by taking 
  the last element of the chain and reducing by 1 every iteration
*/
void Chain::Suffix(std::ofstream& output) const {
    output << "{&";  
    for (size_t i{get_size()}; 0 < i; --i) {
      output << ", ";
      for (size_t j{i - 1}; j < get_size(); ++j) {
        output << get_chain()[j].get_value();
      }
    }
  output << "}\n";
}

/*
  @Brief : Takes a length given by the user and prints in the output file
  the suffix and prefix of the chain
*/

void Chain::NumberLength(std::ofstream& output, int length) const {
  if (get_size() < length)
    output << '&';
  for (size_t i{1}; i <= get_size(); ++i) {
    for (size_t j{0}; j < i; ++j) {
      if (i == length)
        output << get_chain()[j].get_value();
    }
  }
  output << ' ';
  if (get_size() < length)
    output << '&';
  for (size_t i{get_size()}; 0 < i; --i) {
    for (size_t j{i - 1}; j < get_size(); ++j) {
      if (get_size() - i + 1 == length) 
        output << get_chain()[j].get_value();
    }
  }
    output << std::endl;
}