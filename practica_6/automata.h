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

  Historial de revisiones
  18/10/2024 - Creacion (primera version) del codigo
*/
#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <algorithm>
#include <sstream>

#include "alphabet.h"
#include "chain.h"

struct Transition {
  char symbol;
  int next_state;
};

struct State {
  int accept_state; 
  std::vector<Transition> transitions;
};

class Automata {
 public:
  Automata(Alphabet alphabet, int states, int start,
           std::vector<std::string> info_states);
  bool ChainBelongs(Chain string);
                                         
 private:
  Alphabet alphabet_;
  std::vector<State> states_;
  int start_;
  std::vector<int> transition_(std::vector<int> current_state,
                               char symbol);
};

#endif