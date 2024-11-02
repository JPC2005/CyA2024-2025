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
#ifndef ALPHABET_H
#define ALPHABET_H

#include <cassert>
#include <iostream>
#include <set>
#include <string>
#include <vector>

class Alphabet {
 public:
  Alphabet() = default;            
  Alphabet(std::string symbols);  
  bool is_in(char symbol); 
  friend std::ostream& operator<<(
      std::ostream& out, const Alphabet& other);

 private:
  std::set<char> symbols_;
};

#endif