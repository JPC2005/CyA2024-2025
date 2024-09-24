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
	El main del proyecto, recibe por pantalla 2 archivos
	y un numero y llama a las funciones auxiliares que 
	se encuentran en "cadenas_tools.cc"
	
  Historial de revisiones
  22/09/2024 - Creacion (primera version) del codigo
*/
#include <iostream>

#include "cadenas_tools.h"

/**
  * print's the program's purpose
  */
void PrintPurpose() {
	std::cout << "This program takes the information of a chain and an alpahbet"
  << " give by the user and does 1 of 5 operations and prints the result in a"
  << " file the user specifies\n";
  std::cout << std::endl;
}

bool CorrectUsage(const int argc, char* argv[], const int kcorrect_numb) {
	if (argc != kcorrect_numb) {
		std::cout << "There has been an error with the number of parameters\n";
		std::cout << "Use '" << argv[0] << " --help' for more information";
    std::cout << std::endl;
		return false;
	}
	return true;
}

int main(const int argc, char *argv[]){
	PrintPurpose();
  if (argc == 1 || std::string(argv[1]) == "--help") {
    PrintHelp(argv);
    return 0;
  }
	
  if (!CorrectUsage(argc, argv, 4)) {
		return 345;
	}

  std::string input_file_name{argv[1]};
  std::string output_file_name{argv[2]};
  int opcode{std::stoi(argv[3])};
  SelectOperation(input_file_name, output_file_name, opcode);
  return 0;
}
