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
*/
#ifndef REGEX_PATTERNS_H
#define REGEX_PATTERNS_H

#include <regex>

class RegexPatterns {

  public:

    std::regex GetCommentPattern() const;
    std::regex GetVariablePattern() const;
    std::regex GetLoopsPattern() const;
    std::regex GetFunctionPattern() const;
};

#endif