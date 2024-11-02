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
#include "automata.h"

Automata::Automata(Alphabet alphabet, int states, int start,
                   std::vector<std::string> info_states) {
  alphabet_ = alphabet;
  states_.resize(states);
  start_ = start;
  for (std::string line : info_states) {
    std::istringstream stream(line);
    int position;
    stream >> position;

    int accept;
    stream >> accept;
    states_[position].accept_state = accept;

    int n_transiciones;
    stream >> n_transiciones;
    states_[position].transitions.resize(n_transiciones);

    for (int i = 0; i < n_transiciones; ++i) {
      Transition transition;
      stream >> transition.symbol >> transition.next_state;
      if (!alphabet_.is_in(transition.symbol) && transition.symbol != '&') {
        std::cerr << "Error: symbol doesn't belong in the alphabet"
                  << std::endl;
        exit(EXIT_SUCCESS);
      }
      states_[position].transitions[i] = transition;
    }
  }
}

/*
  \brief: This functions receives a chain and inputs its symbols into the
          automata to see if it ends in an accepting state.
*/

bool Automata::ChainBelongs(Chain string) {
  std::vector<int> current_state;
  current_state.push_back(start_);
  std::string aux = string.GetChain();

  for (int i = 0; i < aux.size(); i++) {
    if (aux[i] == '&') {
      if (states_[current_state[0]].accept_state == 1) {
        return true;
      }
    }
  }

  // Sets up a vector of transitions
  for (int i = 0; i < aux.size(); i++) {
    current_state = transition_(current_state, aux[i]);
  }

  // Check if one of the states is an acceptance state
  for (int i = 0; i < current_state.size(); i++) {
    if (states_[current_state[i]].accept_state == 1) {
      return true;
    }
  }
  return false;
}

/*
  \brief: This function creates the vector that contains the transitions of the 
          automata, it has a safeguard that, if a '&' (epsilon) is found, 
          verifies that it won't create a loop in itself
*/

std::vector<int> Automata::transition_(std::vector<int> current_state, char symbol) {
  // Check for epsilon-transitions
  for (int i = 0; i < current_state.size(); i++) {
    for (int j = 0; j < states_[current_state[i]].transitions.size(); j++) {
      if (states_[current_state[i]].transitions[j].symbol == '&' ) {
        // Safeguard to no end up in an epsilon-transitions loop
        if (std::find(current_state.begin(), current_state.end(), 
                      states_[current_state[i]].transitions[j].next_state) == current_state.end()) {
          current_state.push_back(states_[current_state[i]].transitions[j].next_state);
        }
      }
    }
  }
  std::vector<int> next_state;
  for (int i = 0; i < current_state.size(); i++) {
    for (int j = 0; j < states_[current_state[i]].transitions.size(); j++) {
      if (states_[current_state[i]].transitions[j].symbol == symbol) {
        next_state.push_back(
            states_[current_state[i]].transitions[j].next_state);
      }
    }
  }
  return next_state;
}