/*
  Universidad de La Laguna
  Escuela Superior de Ingenieria y Tecnologia
  Grado en Ingenieria Informatica
  Asignatura: Computabilidad y Algoritmia
  Curso: 2º
  Practica 7: Forma Canonica de Chomsky
  Autor: Juan Pablo Calzadilla Gonzalez
  Correo: alu0101651@ull.edu.es
  Fecha: 06/11/2024
  Archivo: CNFConverter.cc.
  	    Contains the methods and the definitions for the class CNFConverter.h

  Historial de revisiones
  02/11/2024 - Creacion (primera version) del codigo
  04/11/2024 - Modificado los comentarios
*/

#include <iostream>
#include <unordered_map>
#include "CNFConverter.h"

void CNFConverter::RemoveEmptyProductions(Grammar& grammar) {
    std::unordered_set<std::string> nullable_symbol;

    // Step 1: Finds all of the nullable productions (productions that only generate the empty chain &)
    bool new_nullable = true;
    while (new_nullable) {
      new_nullable = false;
      for (const auto& productions : grammar.productions) {
        if (productions.rhs.size() == 1 && productions.rhs[0] == "&") {
          if (nullable_symbol.insert(productions.lhs).second) {
            new_nullable = true;
          }
        } else {
            bool is_nullable = true;
            for (const auto& symbol : productions.rhs) {
              if (nullable_symbol.find(symbol) == nullable_symbol.end()) {
                is_nullable = false;
                break;
              }
            }
            if (is_nullable && nullable_symbol.insert(productions.lhs).second) {
              new_nullable = true;
            }
        }
      }
    }

    // Step 2: Generates new productions eliminating the empty productions
    std::vector<Production> new_productions;
    for (const auto& productions : grammar.productions) {
      if (productions.rhs.size() == 1 && productions.rhs[0] == "&") {
        continue; // Skips empty productions
      }
      std::vector<std::vector<std::string>> combinations = {productions.rhs};
      for (size_t i = 0; i < productions.rhs.size(); ++i) {
        if (nullable_symbol.count(productions.rhs[i])) {
          size_t currentSize = combinations.size();
          for (size_t j = 0; j < currentSize; ++j) {
            std::vector<std::string> combo = combinations[j];
            combo.erase(combo.begin() + i);
            if (!combo.empty()) {
              combinations.push_back(combo);
            }
          }
        }
      }
      for (const auto& combo : combinations) {
        new_productions.push_back({productions.lhs, combo});
      }
    }
    grammar.productions = new_productions;
}

/*
 *  @Brief: This function finds the productions that only generate a 
 *          non-terminal and eliminates them, adding the elements of
 *          the non-terminal to its production's productions
 */

void CNFConverter::RemoveUnitProductions(Grammar& grammar) {
    std::unordered_map<std::string, std::unordered_set<std::string>> unit_pairs;

    // Step 1: Identify unitary transitions
    for (const auto& productions : grammar.productions) {
        if (productions.rhs.size() == 1 && grammar.non_terminals.count(productions.rhs[0]) > 0) {
            unit_pairs[productions.lhs].insert(productions.rhs[0]);
        }
    }

    // Step 2: Transitive cloesure on the unitary transitions
    bool changed = true;
    while (changed) {
      changed = false;
      for (const auto& [non_term_one, non_term_one_prods] : unit_pairs) {
        std::unordered_set<std::string> new_set = non_term_one_prods;
        for (const auto& non_term_two : non_term_one_prods) {
          for (const auto& non_term_two_prods : unit_pairs[non_term_two]) {
            if (new_set.insert(non_term_two_prods).second) {
              changed = true;
            }
          }
        }
        unit_pairs[non_term_one] = new_set;
      }
    }

    // Step 3: Adds productions from B to A for each unitary pair (A, B)
    std::vector<Production> new_productions;
    for (const auto& productions : grammar.productions) {
      if (!(productions.rhs.size() == 1 && grammar.non_terminals.count(productions.rhs[0]) > 0)) {
        new_productions.push_back(productions); // Mantains non-unitary productions
      }
    }

    for (const auto& [non_term_one, non_term_one_prods] : unit_pairs) {
      for (const auto& non_term_two : non_term_one_prods) {
        for (const auto& productions : grammar.productions) {
          if (productions.lhs == non_term_two && !(productions.rhs.size() == 1 && grammar.non_terminals.count(productions.rhs[0]) > 0)) {
            new_productions.push_back({non_term_one, productions.rhs});
          }
        }
      }
    }
    grammar.productions = new_productions;
}

void CNFConverter::ConvertToCNF(Grammar& grammar) {
    // Step 1: Creates unitary productions (non_term_two_prods(a) -> a)
    std::unordered_map<std::string, std::string> terminalMap;
    std::vector<Production> new_productions;
    int non_terminal_counter{1};
    for (const auto& productions : grammar.productions) {
      if (productions.rhs.size() >= 2) { // If the production has more than one symbol
        std::vector<std::string> newRHS;
        for (const auto& symbol : productions.rhs) {
          if (grammar.terminals.count(symbol)) {
            // Creates a new symbol for the terminal
            if (terminalMap.find(symbol) == terminalMap.end()) {
              std::string newNonTerminal = "C(" + symbol + ")";
              terminalMap[symbol] = newNonTerminal;
              grammar.non_terminals.insert(newNonTerminal);
              new_productions.push_back({newNonTerminal, {symbol}});
            }
            newRHS.push_back(terminalMap[symbol]);
            } else {
                newRHS.push_back(symbol);
            }
          }
          new_productions.push_back({productions.lhs, newRHS});
      } else {
          new_productions.push_back(productions); // Mantains the productions with only one symbol
      }
    }
    grammar.productions = new_productions;

    // Step 2: Divides the long chains in binaries (non_term_one -> B1 B2 ... Bn)
    new_productions.clear();
    for (const auto& productions : grammar.productions) {
      if (productions.rhs.size() > 2) {
        std::string currentLHS = productions.lhs;
        for (size_t i = 0; i < productions.rhs.size() - 2; ++i) {
          std::string newNonTerminal = "D" + std::to_string(non_terminal_counter++);
          grammar.non_terminals.insert(newNonTerminal);
          new_productions.push_back({currentLHS, {productions.rhs[i], newNonTerminal}});
          currentLHS = newNonTerminal;
        }
        new_productions.push_back({currentLHS, {productions.rhs[productions.rhs.size() - 2], productions.rhs[productions.rhs.size() - 1]}});
        } else {
            new_productions.push_back(productions); // Mantains the binary or unitary productions
        }
    }
    grammar.productions = new_productions;
}
