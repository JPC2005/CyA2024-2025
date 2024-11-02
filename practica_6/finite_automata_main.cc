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
  Archivo cy: main.
  	    Holds the main function for the finite automata program, it uses the 
        "alphabet" class to hold the symbols for that automata's alphabet and
        checks to see if a received chain's symbols are in it, it also has the 
        "chain" class that contains the chains that are given through a .txt
        file


  Historial de revisiones
  18/10/2024 - Creacion (primera version) del codigo
*/
#include <sstream>

#include "automata.h"

bool CorrectUsage(const int argc, char* argv[], const int kcorrect_numb) {
  if (argc == 2) { 
    std::string parameter{argv[1]};
    if(parameter == "--help") {
      std::cout << "This program simulates a DFA/NFA starting from an .fa "
      
                << "file\nand then takes chains from a .txt file and applies the\n"
                << "automata on in to check if its accepted or rejected.\n";
      return false;
    }
  } else if (argc != 3) {
      std::cout << "Usage method: " << argv[0] << " input.fa input.txt"
                << std::endl;
      std::cout << "Try " << argv[0] << " --help for more info"
                << std::endl;
      return false;
  }
  return true;
}

int main(int argc, char* argv[]) {
  if (!CorrectUsage(argc, argv, 3)) {
    return 345;
  }

  std::ifstream automata_file{argv[1]};
  if (!automata_file.is_open()) {
    std::cerr << "Error: automata file couldn't open.\n";
    return 1;
  }
  
  std::string symbols;
  std::getline(automata_file, symbols);
  Alphabet alphabet(symbols);
  int number_states;
  automata_file >> number_states;
  int start;
  automata_file >> start;

  std::vector<std::string> info_states;
  std::string line;
  while (std::getline(automata_file, line)) {
    if (!line.empty()) {
      info_states.push_back(line);
    }
  }
  Automata automata_obj(alphabet, number_states, start, info_states);
  automata_file.close();


  std::ifstream chains{argv[2]};
  if (!chains.is_open()) {
    std::cerr << "Error: text file couldn't open.\n";
    return 1;
  }

  std::string aux;
  while (std::getline(chains, aux)) {
    Chain chainA(aux, alphabet);
    std::cout << chainA << " --- ";
    if (automata_obj.ChainBelongs(chainA)) {
      std::cout << " Accepted\n";
    } else {
      std::cout << " Rejected\n";
    }
  }
  chains.close();
  return 0;
}

