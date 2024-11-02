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
#ifndef CHAIN_H
#define CHAIN_H

#include <fstream>
#include <vector>

#include "alphabet.h"

class Chain {
 public:
  Chain() = default; 
  Chain(std::string chain, Alphabet alphabet); 
  Alphabet ShowAlphabet() { return alphabet_;} 
  std::string GetChain(); 
  int GetLength() { return length_; } 
  friend std::ostream& operator<<(std::ostream& out, const Chain& other); 
  
 private:
  std::vector<char> chains_;
  Alphabet alphabet_;
  int length_;
};

#endif