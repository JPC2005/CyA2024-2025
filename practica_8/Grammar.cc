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
  Archivo: Grammar.cc.
  	    Contains the methods and the definitions for the class Grammar.h

  Historial de revisiones
  02/11/2024 - Creacion (primera version) del codigo
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include "Grammar.h"

bool Grammar::readFromFile(const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return false;
    }

    int terminal_amount{-1}, non_terminal_amount{-1}, productions_amount{-1};
    std::string line;

    // Reads the terminals
    infile >> terminal_amount;
    if (terminal_amount == -1) {
      std::cout << "There isn't an amount of terminals specified\n";
      return false;
    }
    for (int i = 0; i < terminal_amount; ++i) {
        infile >> line;
        char symbol = line[0];
        if (!std::islower(symbol)) {
          std::cout << "The character received is not a valid terminal for this program\n";
          return false;
        }
        terminals.insert(line);
    }

    // Reads the non-terminals
    infile >> non_terminal_amount;
    if (non_terminal_amount == -1) {
      std::cout << "There isn't an amount of non-terminals specified or there " << "were more terminals than specified\n";
      return false;
    }
    bool is_start = true;
    for (int i = 0; i < non_terminal_amount; ++i) {
        infile >> line;
        char symbol = line[0];
        if (!std::isupper(symbol)) {
          std::cout << "The character received is not a valid non-terminal for "
          << "this program\n";
          return false;
        }
        non_terminals.insert(line);
        if (is_start) {
            strarting_symbol = line;
            is_start = false;
        }
    }

    // Reads the productions
    infile >> productions_amount;
        if (productions_amount == -1) {
      std::cout << "There isn't an amount of productions specified or there" 
       << " were more non-terminals than specified\n";
      return false;
    }
    infile.ignore();
    for (int i = 0; i < productions_amount; ++i) {
        getline(infile, line);
        std::stringstream ss(line);
        std::string lhs;
        ss >> lhs;
        Production prod{lhs, {}};
        for (size_t j{1}; j < line.size(); ++j) {
            char symbol = line[j];
            if (symbol != ' ') {
              if (line.size() > 3 && symbol == '&') {
                  std::cout << "ERROR: found the empty chain symbol in a chain"
                  << " with terminals and/or non-terminals\n";
                  return false;
              }
              
              std::string symbol_str(1, symbol);
              if (terminals.count(symbol_str) > 0 || non_terminals.count(symbol_str) > 0 || symbol == '&') {
                prod.rhs.push_back(symbol_str);
              }
              else {
                std::cout << "one of the productions has a symbol that isn't a terminal\n";
                return false;
              }
            }
        }
        productions.push_back(prod);
    }

    infile.close();
    return true;
}

bool Grammar::writeToFile(const std::string& filename) const {
    std::ofstream outfile(filename);
    std::vector<Production> starting_productions;
    std::vector<Production> rest_productions;
    if (!outfile.is_open()) {
        std::cerr << "Error: Could not write to file " << filename << std::endl;
        return false;
    }

    // Writes the terminals
    outfile << terminals.size() << "\n";
    for (const auto& term : terminals) {
        outfile << term << "\n";
    }

    // Writes the non-terminals
    outfile << non_terminals.size() << "\n";
    for (const auto& nonTerm : non_terminals) {
        outfile << nonTerm << "\n";
    }

    // Separates the productions of the starting productions from the rest
    outfile << productions.size() << "\n";
    for (const auto& prod : productions) {
      if (prod.lhs == strarting_symbol) {
        starting_productions.push_back(prod);
      } else {
        rest_productions.push_back(prod);
      }
    }

    // Prints the starting symbol's productions first
    for (const auto& prod : starting_productions) {
      outfile << prod.lhs << " ";
      for (const auto& sym : prod.rhs) {
        outfile << sym;
      }
      outfile << "\n";
    }

    // Prints the rest of the productions
    for (const auto& prod: rest_productions) {
      outfile << prod.lhs << " ";
      for (const auto& sym : prod.rhs) {
        outfile << sym;
      }
      outfile << "\n";
    }

    outfile.close();
    return true;
}
