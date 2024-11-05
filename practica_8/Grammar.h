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
  Archivo: Grammar.h.
  	    Initializes the grammar class which holds the Set of terminals, nonterminals, productions and the start symbol

  Historial de revisiones
  02/11/2024 - Creacion (primera version) del codigo
*/

#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <string>
#include <vector>
#include <unordered_set>

struct Production {
    std::string lhs;                   // Left side of the productions
    std::vector<std::string> rhs;      // Right side of the productions
};

class Grammar {
public:
    std::unordered_set<std::string> terminals;      // Set of terminals
    std::unordered_set<std::string> non_terminals;  // Set of non-terminals
    std::string strarting_symbol;                   // Símbolo inicial
    std::vector<Production> productions;            // Productions

    bool readFromFile(const std::string& filename);      // Reads grammar from file
    bool writeToFile(const std::string& filename) const; // Writes grammar form file
};

#endif
