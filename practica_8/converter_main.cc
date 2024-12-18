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
  Archivo: converter_main.
  	    Contains the main of the project which uses the Grammar.cc and CNFConverter.cc to receive a context free grammar from a .gra file and then output the Chomsky's normal form for that grammar.

  Historial de revisiones
  02/11/2024 - Creacion (primera version) del codigo
*/

#include <iostream>
#include "Grammar.h"
#include "CNFConverter.h"

void showHelp() {
    std::cout << "Usage: ./Grammar2CNF input.gra output.gra\n";
    std::cout << "Transforms the CFG written in a .gra file to its Chomsky Normal Form and writes it in another .gra file \n";
    std::cout << "Options:\n";
    std::cout << "  --help   Show this help message.\n";
    std::cout << "Format:\n";
    std::cout << "number of terminals\n terminals (must be lowercase letters)\n"
    << "number of non-terminals\n terminals (must be uppercase letters)\n"
    << "number of productions\n productions (each production has to be its own"
    << "line)\n";
}
bool CorrectUsage(const int argc, char* argv[], const int kcorrect_numb) {
        if (argc != kcorrect_numb) {
                std::cout << "There has been an error with the number of parameters\n";
                std::cout << "'use " << argv[0] << " --help' for more information\n";
    std::cout << std::endl;
                return false;
        }
        return true;
}

int main(int argc, char* argv[]) {
    if (argc == 2 && std::string(argv[1]) == "--help") {
      showHelp();
      return 0;
    }
    if (!CorrectUsage(argc, argv, 3)) {
      return 345;
    }

    std::string inputFile = argv[1];
    std::string outputFile = argv[2];
    char caution_proceed;
    Grammar grammar;
    if (!grammar.readFromFile(inputFile)) {
        return 1;
    }
    if (inputFile == outputFile) {
      std::cout << "CAUTION: the given files are the same file, this could end in a broken CNF, proceed?(y/n)\n";
      while (caution_proceed != 'y' && caution_proceed != 'n') {
        std::cin >> caution_proceed;
      }
      if (caution_proceed == 'n') {
        return 0;
      } else {
        CNFConverter converter;
        converter.RemoveEmptyProductions(grammar);
        converter.RemoveUnitProductions(grammar);
        converter.ConvertToCNF(grammar);
      }
    } else {
    CNFConverter converter;
    converter.RemoveEmptyProductions(grammar);
    converter.RemoveUnitProductions(grammar);
    converter.ConvertToCNF(grammar);
  }
    if (!grammar.writeToFile(outputFile)) {
        return 1;
    }
    return 0;
}
