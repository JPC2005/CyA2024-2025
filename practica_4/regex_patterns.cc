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
  09/10/2024 - Modificacion
*/

#include <iostream>

#include "regex_patterns.h"

std::regex RegexPatterns::GetDescriptionPattern() const {
  return std::regex(R"(\s\/\/.*|(\/\*[\s\S]*?\*\S*\/))");
}

std::regex RegexPatterns::GetCommentPattern() const {
  return std::regex(R"(\s\/\/.*|(\/\*[\s\S]*?(\*\S*\/)*))");
}

std::regex RegexPatterns::GetVariablePattern() const {
  return std::regex(R"(\b(int|double)\s+(\w*)\s*(=\s*[^;]+|(\{\s*[^;]+\}))?\s*;)");
}

std::regex RegexPatterns::GetLoopsPattern() const {
  return std::regex(R"(\b(for|while)\s*\(.*?\))");
}