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
	Clase Language

  Historial de revisiones
  22/09/2024 - Creacion (primera version) del codigo
*/
#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "alphabet.h"
#include "chain.h"

class Language {
  public:
    Alphabet alpahbet_;

  Language(const Alphabet& alpahbet);
};

#endif