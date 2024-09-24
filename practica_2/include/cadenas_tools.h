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
	Inicializacion de las funciones auxiliares del main

  Historial de revisiones
  22/09/2024 - Creacion (primera version) del codigo
*/

#ifndef CADENAS_TOOLS_H
#define CADENAS_TOOLS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "chain.h"
#include "alphabet.h"
#include "language.h"

void PrintHelp(char* argv[]);

void SelectOperation(std::string& input_file, std::string& output_file, int opcode);

#endif
