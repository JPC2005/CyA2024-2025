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
  	    Contiene la clase 
  Referencias:
  	    Enlaces de interes

  Historial de revisiones
  05/10/2024 - Creacion (primera version) del codigo
*/

#include <iostream>

#include "regex_patterns.h"

std::regex RegexPatterns::GetCommentPattern() const {
  return std::regex(R"(\s\/\/.*|\/\*[\s\S]*?\*\/)");
}
std::regex RegexPatterns::GetVariablePattern() const {
  return std::regex(R"(\b(int|char|double|float|string)\s+([a-zA-Z_]\w*)\s*(\[\w*\])*(=|(\{\s*[^;]+\}))?\s*;)");
}

std::regex RegexPatterns::GetLoopsPattern() const {
  return std::regex(R"(\b(for|while)\b\s*\(.*?\))");
}

/*
std::regex RegexPatterns::GetFunctionPattern() const {
  return std::regex(R"(\b\w+\s+\w+\(.*\)\s*\{)");
}
*/
