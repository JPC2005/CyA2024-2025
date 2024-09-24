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
	Clase lenguaje que guarda el alphabeto

  Historial de revisiones
  22/09/2024 - Creacion (primera version) del codigo
  24/09/2024 - Apartado de modificaciones
*/

#include "language.h"

Language::Language(const Alphabet& alphabet, const Chain& chain) : alphabet_(alphabet)
, chain_(chain) {}

// possible modifications
/*
void Language::Palindrome(std::ofstream& output) {
  bool palindrome{true};
  for (size_t i{0}; i < get_chains().get_size(); i++) {
    if (get_chains().get_chain()[i].get_value() 
    != get_chains().get_chain()[get_chains().get_size() - i - 1].get_value()) {
      palindrome = false;
    }
  }
  if (palindrome) {
    output << "true" << std::endl;
  } else {
    output << "false" << std::endl;
  }
}
*/