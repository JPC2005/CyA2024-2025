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
	Clase Language

  Historial de revisiones
  22/09/2024 - Creacion (primera version) del codigo
  24/09/2024 - Apartado de modificaciones
*/
#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "alphabet.h"
#include "chain.h"

class Language {
  public:

    Language(const Alphabet& alpahbet, const Chain& chain);

    Alphabet& get_alphabet() { return alphabet_;}
    Chain& get_chains() { return chain_;}

// posible modification
//    void Palindrome(std::ofstream& output);
    
  private:  
    Alphabet alphabet_;
    Chain chain_;
};

#endif
