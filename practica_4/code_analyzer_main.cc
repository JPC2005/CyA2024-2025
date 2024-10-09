/*
  Universidad de La Laguna
  Escuela Superior de Ingenieria y Tecnologia
  Grado en Ingenieria Informatica
  Asignatura: Computabilidad y Algoritmia
  Curso: 2º
  Practica 4: Cadenas y lenguajes
  Autor: Juan Pablo Calzadilla Gonzalez
  Correo: alu0101651@ull.edu.es
  Fecha: 17/09/2024
  Archivo cy: programa cliente.
  	    Contiene la funcion main del proyecto que usa las clases X e Y
  	    para ... (indicar brevemente el objetivo)
  Referencias:
  	    Enlaces de interes

  Historial de revisiones
  05/10/2024 - Creacion (primera version) del codigo
  09/10/2024 - Modificacion
*/
#include <iostream>

#include "code_analyzer.h"


/**
  * print's the program's purpose
  */
void PrintPurpose() {
	std::cout << "This program takes an input of a .cc or .cpp file and a .txt\n";
  std::cout << "file and prints in the .txt file a analysis of the code file\n";
  std::cout << "including the descripiton of it, the variables, loops and \n";
  std::cout << "comments, it also says on what line each can be found and if\n";
  std::cout << "there is a main statement\n";
  std::cout << std::endl;
}

bool CorrectUsage(const int argc, char* argv[], const int kcorrect_numb) {
	if (argc != kcorrect_numb) {
		std::cout << "There has been an error with the number of parameters\n";
		std::cout << argv[0] << " need you to imput at least 2 parameters\n";
    std::cout << std::endl;
		return false;
	}
	return true;
}

int main(const int argc, char *argv[]){
	PrintPurpose();
	if (!CorrectUsage(argc, argv, 3)){
		return 345;
	}

  CodeAnalyzer code(argv[1]);
  std::string output_file(argv[2]);
  code.ReadFile();
  code.WriteAnalysis(output_file);
	return 0;
}

