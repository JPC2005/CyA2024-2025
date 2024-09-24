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
	Herramientas auxiliares del main, aqui se
	encuentra la funcion de ayuda y la seleccion de
	la operacion

  Historial de revisiones
  22/09/2024 - Creacion (primera version) del codigo
  24/09/2024 - Inclusion de un contador para saber si el proceso se cumplio
               para cada cadena
*/

#include "cadenas_tools.h"
#include "chain.h"
#include "alphabet.h"
#include "language.h"


/*
  @Brief: prints the help guide and explains what each opcode does
*/
void PrintHelp(char* argv[]) {
  std::cout << argv[0] << " Needs you to input the name of a .txt file that "
                       <<  "will work as the input file, a second .txt file "
                       <<  "that will work as the output file and lastly a "
                       << "number that will work as the code for what operation"
                       <<  " to do.\n";
  std::cout << std::endl;
  std::cout << "The codes are:\n" << "1. Alphabet: prints the alphabet associated"
  << " with each chain in the output file\n" << "2. Length: prints in the output"
  << " file the length of each chain\n" << "3: Inverse: prints in the output"
  << " file the inverse of the chain (the reverse)\n" << "4: Prefix: prints"
  << " in the output file all of the prefix chains for each chain\n"
  << "5: Sufix: in the output file all of the sufix chains for each chain\n"
  << std::endl;
}


/*
  @Brief: Takes the files the user provided and opens them, then it call the 
  function the opcode provided points to
*/
void SelectOperation(std::string& input_file, std::string& output_file, int opcode) {
  std::ifstream input(input_file);
  std::ofstream output(output_file);
  std::string ChainLine, AlphabetLine;
  int tally{1};
  if (!input.is_open()) {
    std::cerr << "ERROR: input file couldn't open\n";
    return;
  }
  while (input >> ChainLine >> AlphabetLine) {
    std::vector<char> AlphabetChars(AlphabetLine.begin(), AlphabetLine.end());
    Alphabet alphabet(AlphabetChars);
    Chain chain(ChainLine);
    Language language(alphabet);
    switch(opcode) {
      case 1:
        alphabet.PrintAlphabet(output);
        std::cout << "Printed the alphabet of line " << tally << " in " 
         << output_file << std::endl;
        break;
      case 2:
        chain.Length(output);
        std::cout << "Printed the length of chain " << tally << " in " 
        << output_file << std::endl;
        break;
      case 3:
        chain.PrintInverse(output);
        std::cout << "Printed the inverse of chain " << tally << " in " 
        << output_file << std::endl;
        break;
      case 4:
        chain.Prefix(output);
        std::cout << "Printed all of the possible prefixes of chain " << tally
        << " in " << output_file << std::endl;
        break;
      case 5:
        chain.Suffix(output);
        std::cout << "Printed all of the possible suffixes of chain " << tally
        << " in " << output_file << std::endl;
        break;
      default:
        std::cerr << "ERROR: invalid operation code, use a valid code (1-5)\n";
        return;
    }
      tally += 1;
  }
  input.close();
  output.close();
}
